import subprocess
from datetime import datetime

def run_command(command):
    """Run a shell command and return output."""
    result = subprocess.run(command, shell=True, capture_output=True, text=True)
    if result.returncode != 0:
        print(f"Error: {result.stderr.strip()}")
    return result.stdout.strip()

def auto_commit():
    # Check if there are changes
    status = run_command("git status --porcelain")
    if not status:
        print("⚡ No changes to commit.")
        return

    # Stage all changes
    run_command("git add .")

    # Commit with timestamp
    commit_message = f"Auto commit on {datetime.now().strftime('%Y-%m-%d %H:%M:%S')}"
    run_command(f'git commit -m "{commit_message}"')

    # Push to remote (default branch)
    push_output = run_command("git push")
    print(push_output)
    print("✅ Auto commit and push completed!")

if __name__ == "__main__":
    auto_commit()
