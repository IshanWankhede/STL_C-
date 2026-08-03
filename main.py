import os
import subprocess
from datetime import datetime

def run_command(command):
    """Run a shell command and return output."""
    result = subprocess.run(command, shell=True, capture_output=True, text=True)
    if result.returncode != 0:
        print(f"Error: {result.stderr}")
    return result.stdout.strip()

def auto_commit():
    # Step 1: Add all changes
    run_command("git add .")

    # Step 2: Create commit message with timestamp
    commit_message = f"Auto commit on {datetime.now().strftime('%Y-%m-%d %H:%M:%S')}"
    run_command(f'git commit -m "{commit_message}"')

    # Step 3: Push to remote
    run_command("git push")

    print("✅ Auto commit and push completed!")

if __name__ == "__main__":
    auto_commit()
