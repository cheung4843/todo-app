import platform
import subprocess
import sys
import os

def run_script_win(script_name):
    """Run script on Windows. Supports .ps1 or .bat."""
    if script_name.endswith('.ps1'):
        # Run PowerShell script
        cmd = ["powershell", "-ExecutionPolicy", "Bypass", "-File", script_name]
    else:
        # Run Batch script
        cmd = [script_name]
    try:
        subprocess.run(cmd, check=True, shell=True)
    except subprocess.CalledProcessError as e:
        print(f"Failed to run {script_name}. Error:", e)
        sys.exit(1)

def run_script_unix(script_name):
    """Run shell script on Linux/macOS."""
    try:
        subprocess.run(["bash", script_name], check=True)
    except subprocess.CalledProcessError as e:
        print(f"Failed to run {script_name}. Error:", e)
        sys.exit(1)

if __name__ == "__main__":
    sys_platform = platform.system()
    print(f"Detected platform: {sys_platform}")
    if sys_platform == "Windows":
        # Prefer PowerShell, fallback to batch
        if os.path.exists("build.ps1"):
            print("Running build.ps1 (PowerShell)...")
            run_script_win("build.ps1")
        elif os.path.exists("build.bat"):
            print("Running build.bat (Batch)...")
            run_script_win("build.bat")
        else:
            print("No build.ps1 or build.bat found!")
            sys.exit(1)
    elif sys_platform in ("Darwin", "Linux"):
        if os.path.exists("build.sh"):
            print("Running build.sh ...")
            run_script_unix("build.sh")
        else:
            print("No build.sh found!")
            sys.exit(1)
    else:
        print(f"Unknown system: {sys_platform}. Please build manually.")
        sys.exit(1)
