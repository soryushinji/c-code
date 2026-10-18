$OutputEncoding = [System.Text.Encoding]::UTF8
# ============================================================
#  DeepSeek Harness 图标自愈
#  作用：更新程序会重写快捷方式、覆盖安装目录里的图标文件，
#        导致"蓝色大肥鱼"变回默认图标。本脚本把三处都改回来。
#        可反复运行，幂等；没有变化时不写盘。
#  三处：
#    1) 开始菜单 / 桌面 / 任务栏 快捷方式的 IconLocation
#    2) <安装目录>\resources\icon.png     （窗口 / 任务栏图标）
#    3) <安装目录>\resources\tray.ico     （托盘图标）
# ============================================================

$ErrorActionPreference = 'SilentlyContinue'

$icoDir  = 'C:\Users\soryu\.dsh\icons'
$ico     = Join-Path $icoDir '蓝色大肥鱼.ico'
$mPng    = Join-Path $icoDir '蓝色大肥鱼.png'
$mTray   = Join-Path $icoDir 'tray-fish.ico'
$exe     = 'C:\Users\soryu\AppData\Local\Programs\DeepSeek Harness\DeepSeek Harness.exe'
$resDir  = 'C:\Users\soryu\AppData\Local\Programs\DeepSeek Harness\resources'
$log     = Join-Path $icoDir '图标修复.log'

if (-not (Test-Path $ico))  { exit 0 }
if (-not (Test-Path $exe))  { exit 0 }

$changed = @()

# ---------- 1) 快捷方式 ----------
$lnkDir = Join-Path $env:APPDATA 'Microsoft\Windows\Start Menu\Programs'
$target = "$ico,0"
$wsh = New-Object -ComObject WScript.Shell

$lnks = @( (Join-Path $lnkDir 'DeepSeek Harness.lnk') )
$desk = Join-Path ([Environment]::GetFolderPath('Desktop')) 'DeepSeek Harness.lnk'
if (Test-Path $desk) { $lnks += $desk }
$tbDir = Join-Path $env:APPDATA 'Microsoft\Internet Explorer\Quick Launch\User Pinned\TaskBar'
if (Test-Path $tbDir) {
    Get-ChildItem $tbDir -Filter *.lnk |
        Where-Object { $_.Name -match 'DeepSeek' } |
        ForEach-Object { $lnks += $_.FullName }
}

$needNotify = $false
foreach ($l in $lnks) {
    if (-not (Test-Path $l)) {
        if ($l -eq (Join-Path $lnkDir 'DeepSeek Harness.lnk')) {
            $sc = $wsh.CreateShortcut($l)
            $sc.TargetPath = $exe
            $sc.WorkingDirectory = Split-Path $exe -Parent
            $sc.Description = 'DeepSeek Harness'
            $sc.IconLocation = $target
            $sc.Save()
            $changed += "新建快捷方式 $(Split-Path $l -Leaf)"
            $needNotify = $true
        }
        continue
    }
    $sc = $wsh.CreateShortcut($l)
    $dirty = $false
    if ($sc.IconLocation -ne $target) { $sc.IconLocation = $target; $dirty = $true }
    if ($sc.TargetPath -ne $exe)      { $sc.TargetPath = $exe
                                        $sc.WorkingDirectory = Split-Path $exe -Parent
                                        $dirty = $true }
    if ($dirty) {
        $sc.Save()
        $changed += "快捷方式图标 $(Split-Path $l -Leaf)"
        $needNotify = $true
    }
}

# ---------- 2) / 3) 安装目录里的图标文件 ----------
function Sync-File($master, $target2, $label) {
    if (-not (Test-Path $master)) { return }
    if (-not (Test-Path (Split-Path $target2 -Parent))) { return }
    $hm = (Get-FileHash $master  -Algorithm SHA256).Hash
    $ht = if (Test-Path $target2) { (Get-FileHash $target2 -Algorithm SHA256).Hash } else { '' }
    if ($hm -ne $ht) {
        Copy-Item $master $target2 -Force
        $script:changed += $label
    }
}
Sync-File $mPng  (Join-Path $resDir 'icon.png') 'resources\icon.png'
Sync-File $mTray (Join-Path $resDir 'tray.ico') 'resources\tray.ico'

# ---------- 刷新图标缓存 ----------
if ($changed.Count -gt 0) {
    $sig = @'
[System.Runtime.InteropServices.DllImport("shell32.dll")]
public static extern void SHChangeNotify(int eventId, int flags, IntPtr item1, IntPtr item2);
'@
    $t = Add-Type -MemberDefinition $sig -Name Shell32 -Namespace Win32 -PassThru
    $t::SHChangeNotify(0x08000000, 0x0000, [IntPtr]::Zero, [IntPtr]::Zero)

    "[{0}] {1}" -f (Get-Date -Format 'yyyy-MM-dd HH:mm:ss'), ($changed -join '、') |
        Out-File -FilePath $log -Append -Encoding UTF8
}
