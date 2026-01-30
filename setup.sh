#!/bin/bash
# Setup competitive programming environment.
# Run this after cloning the repo on a new machine.

set -e

LIB_PATH="$HOME/src/lgf-cpLib"
VSCODE_DIR="$(dirname "$0")/.vscode"
CPTOOLS_CONFIG="$HOME/.config/cptools/config.json"

if [ ! -d "$LIB_PATH" ]; then
    echo "Error: cpLib not found at $LIB_PATH"
    echo "Clone it first: git clone <repo-url> $HOME/src/lgf-cpLib"
    exit 1
fi

# --- VSCode config ---

mkdir -p "$VSCODE_DIR"

cat > "$VSCODE_DIR/c_cpp_properties.json" << 'JSONEOF'
{
    "configurations": [
        {
            "name": "Linux",
            "includePath": [
                "${workspaceFolder}/**",
                "${env:HOME}/src/lgf-cpLib"
            ],
            "compilerPath": "/usr/bin/g++",
            "cStandard": "c17",
            "cppStandard": "c++17",
            "intelliSenseMode": "linux-gcc-x64"
        }
    ],
    "version": 4
}
JSONEOF

cat > "$VSCODE_DIR/tasks.json" << 'JSONEOF'
{
    "tasks": [
        {
            "type": "cppbuild",
            "label": "C/C++: g++ build active file",
            "command": "g++",
            "args": [
                "-fdiagnostics-color=always",
                "-g",
                "-O2",
                "-std=c++17",
                "-DLOCAL",
                "-I${env:HOME}/src/lgf-cpLib",
                "${file}",
                "-o",
                "${fileDirname}/${fileBasenameNoExtension}"
            ],
            "options": {
                "cwd": "${fileDirname}"
            },
            "problemMatcher": [
                "$gcc"
            ],
            "group": {
                "kind": "build",
                "isDefault": true
            }
        }
    ],
    "version": "2.0.0"
}
JSONEOF

echo "VSCode config created."

# --- cptools config ---

INCLUDE_FLAG="-I$HOME/src/lgf-cpLib"

if command -v cptools &> /dev/null; then
    if [ -f "$CPTOOLS_CONFIG" ]; then
        python3 -c "
import json, sys, os
cfg_path = os.path.expanduser('~/.config/cptools/config.json')
extra = ['-DLOCAL', '-I' + os.path.expanduser('~/src/lgf-cpLib')]
with open(cfg_path, 'r') as f:
    cfg = json.load(f)
flags = cfg.get('compiler_flags', ['-O2', '-std=c++17'])
added = [f for f in extra if f not in flags]
if not added:
    print('cptools config already up to date.')
    sys.exit(0)
flags.extend(added)
cfg['compiler_flags'] = flags
with open(cfg_path, 'w') as f:
    json.dump(cfg, f, indent=4)
    f.write('\n')
print('cptools config updated.')
"
    else
        echo "cptools config not found, run 'cptools config' first."
    fi
else
    echo "cptools not installed, skipping cptools config."
fi

echo "Done!"
