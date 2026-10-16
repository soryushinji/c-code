# ============================================================================
#  自动同步.ps1 —— 把 D:\code 的改动提交并推送到 GitHub
# ----------------------------------------------------------------------------
#  用法（手动跑一次）：
#      powershell -ExecutionPolicy Bypass -File "D:\code\自动同步.ps1"
#
#  设为定时自动跑：见 D:\code\说明_自动同步.txt
# ============================================================================

$ErrorActionPreference = "Continue"
$RepoDir = "D:\code"

Set-Location $RepoDir

# 日志文件（每次运行追加一行，方便排查）
$LogFile = Join-Path $RepoDir ".sync.log"
function Write-Log($msg) {
    $line = "[{0}] {1}" -f (Get-Date -Format "yyyy-MM-dd HH:mm:ss"), $msg
    Add-Content -Path $LogFile -Value $line -Encoding UTF8
    Write-Host $line
}

# ── 0. 确认这是 git 仓库 ──
if (-not (Test-Path (Join-Path $RepoDir ".git"))) {
    Write-Log "错误：D:\code 还不是 git 仓库，请先运行 初始化仓库.ps1"
    exit 1
}

# ── 1. 把所有改动加入暂存区 ──
git add -A 2>&1 | Out-Null

# ── 2. 有没有东西要提交？没有就安静退出 ──
$pending = git status --porcelain
if (-not $pending) {
    Write-Log "没有改动，跳过"
    exit 0
}

# ── 3. 提交 ──
$stamp = Get-Date -Format "yyyy-MM-dd HH:mm:ss"
git commit -m "auto: $stamp" 2>&1 | Out-Null
if ($LASTEXITCODE -ne 0) {
    Write-Log "提交失败"
    exit 1
}
$n = ($pending | Measure-Object).Count
Write-Log "已提交 $n 处改动"

# ── 4. 推送 ──
git push 2>&1 | Out-Null
if ($LASTEXITCODE -eq 0) {
    Write-Log "推送成功"
} else {
    Write-Log "推送失败（检查网络 / 登录状态），改动已安全保存在本地，下次会自动重试"
}
