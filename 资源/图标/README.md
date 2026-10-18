# DeepSeek Harness 图标（蓝色大肥鱼）

## 文件

| 文件 | 用途 |
|---|---|
| `蓝色大肥鱼.ico` | 多尺寸图标（16/24/32/48/64/128/256），快捷方式用 |
| `蓝色大肥鱼.png` | 1024×1024 母版，程序 `resources\icon.png` 用 |
| `tray-fish.ico` | 托盘图标（16~64），程序 `resources\tray.ico` 用 |
| `修复图标.ps1` | 自愈脚本：把三处图标改回来 |
| `run-fix-hidden.vbs` | 隐藏窗口地调用上面的 ps1（防止闪控制台）|

## 为什么更新会丢图标

DSH 用 electron-updater，`nightly` 频道，**更新很频繁**。更新时：

1. 安装目录被重写 → `resources\icon.png`、`resources\tray.ico` **变回默认** ✗
2. 开始菜单快捷方式被重建 → `IconLocation` **变回默认** ✗

所以以前每次更新都要手动重设一遍。

## 现在的解决方案

**图标文件放在 `C:\Users\soryu\.dsh\icons\`** —— 这个目录**不在安装目录里**，更新不会碰它 ✓

**计划任务「DeepSeek Harness 图标自愈」** 负责把三处改回来：

| 什么时候跑 | 说明 |
|---|---|
| 登录时 | 重启后自动修 |
| 每 15 分钟 | 更新后最多 15 分钟内自动修 |

任务是**隐藏**的，用 `wscript.exe`（GUI 宿主）+ `Run(..., 0, ...)` 调 PowerShell，
**不会闪出黑色控制台窗口** ✓

脚本幂等：三处都是对的就什么也不做，不写盘。

## 手动修复

双击运行：

```powershell
powershell -NoProfile -ExecutionPolicy Bypass -File "C:\Users\soryu\.dsh\icons\修复图标.ps1"
```

或手动触发计划任务：

```powershell
Start-ScheduledTask -TaskName "DeepSeek Harness 图标自愈"
```

## 检查当前状态

```powershell
$sh = New-Object -ComObject WScript.Shell
($sh.CreateShortcut("$env:APPDATA\Microsoft\Windows\Start Menu\Programs\DeepSeek Harness.lnk")).IconLocation
```

应该输出 `C:\Users\soryu\.dsh\icons\蓝色大肥鱼.ico,0`

## 原版备份

程序原来的图标备份在 `C:\Users\soryu\.dsh\icons\程序原版图标\`
（`icon.png` 125.8 KB、`tray.ico` 15.3 KB）—— 想还原直接覆盖回去。

## 日志

`C:\Users\soryu\.dsh\icons\图标修复.log` —— 只在真的修过东西时才写