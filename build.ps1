# Check and create build folder
if (!(Test-Path -Path "./build")) {
    New-Item -ItemType Directory -Path "./build" | Out-Null
}

# Go into build folder
Set-Location -Path "./build"

# Clean old CMake cache if exists (to avoid generator mismatch)
if (Test-Path -Path "./CMakeCache.txt") {
    Remove-Item "./CMakeCache.txt" -Force
}
if (Test-Path -Path "./CMakeFiles") {
    Remove-Item "./CMakeFiles" -Recurse -Force
}

# Run CMake (MinGW Makefiles)
cmake .. -G "MinGW Makefiles"
if ($LASTEXITCODE -ne 0) {
    Write-Host "[Error] cmake configure failed!"
    Set-Location -Path ".."
    exit 1
}

# Build with mingw32-make
mingw32-make
if ($LASTEXITCODE -ne 0) {
    Write-Host "[Error] Build failed!"
    Set-Location -Path ".."
    exit 1
}

# Ask if run unit test
$runTest = Read-Host "Run unit test (test_todo.exe)? [y/N]"
if ($runTest -eq "y" -or $runTest -eq "Y") {
    Write-Host "Running unit test..."
    .\test_todo.exe
    Write-Host ""
}

# Ask if run main program
$runMain = Read-Host "Run main program (todo.exe)? [y/N]"
if ($runMain -eq "y" -or $runMain -eq "Y") {
    Write-Host "Running main program..."
    .\todo.exe
    Write-Host ""
}

# Go back to project root
Set-Location -Path ".."
Write-Host "===== Build & Test Finished ====="
Pause
