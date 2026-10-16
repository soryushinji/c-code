# ============================================================================
#  初始化仓库.ps1 —— 把 D:\code 变成 git 仓库，并推送到 GitHub
# ----------------------------------------------------------------------------
#  用法：
#      powershell -ExecutionPolicy Bypass -File "D:\code\初始化仓库.ps1" -UserName 你的GitHub用户名
#
#  可选参数：
#      -RepoName  仓库名（默认 c-code）
#      -Branch    分支名（默认 main）
# ============================================================================

param(
    [Parameter(Mandatory = $true)][string]$UserName,
    [string]$RepoName = "c-code",
    [string]$Branch   = "main"
)

$RepoDir = "D:\code"
Set-Location $RepoDir

Write-Host "=== 1. 初始化本地仓库 ===" -ForegroundColor Cyan
if (Test-Path (Join-Path $RepoDir ".git")) {
    Write-Host "  已经是 git 仓库，跳过 init"
} else {
    git init -b $Branch
}

Write-Host ""
Write-Host "=== 2. 设置提交身份（只对本仓库生效）===" -ForegroundColor Cyan
if (-not (git config user.name)) {
    git config user.name  $UserName
    Write-Host "  user.name  = $UserName"
}
if (-not (git config user.email)) {
    $email = Read-Host "  请输入你的 GitHub 邮箱（用于记录提交者）"
    git config user.email $email
}
Write-Host "  user.name  = $(git config user.name)"
Write-Host "  user.email = $(git config user.email)"

Write-Host ""
Write-Host "=== 3. 首次提交 ===" -ForegroundColor Cyan
git add -A
git commit -m "首次提交：C 语言练习代码（自测册综合题 + 课本练习）"
if ($LASTEXITCODE -ne 0) { Write-Host "  （没有需要提交的内容）" }

Write-Host ""
Write-Host "=== 4. 关联远程仓库 ===" -ForegroundColor Cyan
$url = "https://github.com/$UserName/$RepoName.git"
$existing = git remote get-url origin 2>$null
if ($existing) {
    Write-Host "  已有 origin：$existing"
    git remote set-url origin $url
} else {
    git remote add origin $url
}
Write-Host "  origin = $url"

Write-Host ""
Write-Host "=== 5. 推送 ===" -ForegroundColor Cyan
Write-Host "  提示：第一次推送会弹出浏览器让你登录 GitHub" -ForegroundColor Yellow
git push -u origin $Branch

Write-Host ""
if ($LASTEXITCODE -eq 0) {
    Write-Host "✅ 完成！仓库地址：$url" -ForegroundColor Green
    Write-Host ""
    Write-Host "下一步：运行 说明_自动同步.txt 里的命令，设置成每 10 分钟自动同步。"
} else {
    Write-Host "⚠ 推送失败。常见原因：" -ForegroundColor Yellow
    Write-Host "   · GitHub 上还没有这个仓库 → 先去 https://github.com/new 建一个空的"
    Write-Host "     仓库名：$RepoName   不要勾选 Add README / .gitignore"
    Write-Host "   · 没有登录 → 再跑一次，按提示在浏览器里授权"
}
