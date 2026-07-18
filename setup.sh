#!/bin/bash
# Setup competitive programming environment.
# Run this after cloning the repo on a new machine.

set -e

VSCODE_DIR="$(dirname "$0")/.vscode"
CPTOOLS_CONFIG="$HOME/.config/cptools/config.json"

# --- Detect OS and arch ---

OS="$(uname -s)"
ARCH="$(uname -m)"

case "$OS" in
    Darwin)
        PLATFORM="Mac"
        [ "$ARCH" = "arm64" ] && INTELLISENSE_MODE="macos-clang-arm64" \
                               || INTELLISENSE_MODE="macos-clang-x64"
        COMPILER_PATH=""
        for ver in 15 14 13 12 11; do
            if command -v "g++-$ver" &>/dev/null; then
                COMPILER_PATH="$(command -v "g++-$ver")"
                break
            fi
        done
        [ -z "$COMPILER_PATH" ] && COMPILER_PATH="/usr/bin/g++"
        ;;
    Linux)
        PLATFORM="Linux"
        INTELLISENSE_MODE="linux-gcc-x64"
        COMPILER_PATH="/usr/bin/g++"
        ;;
    MINGW*|CYGWIN*|MSYS*)
        PLATFORM="Win32"
        INTELLISENSE_MODE="windows-gcc-x64"
        COMPILER_PATH="$(command -v g++ 2>/dev/null || echo 'g++')"
        ;;
    *)
        PLATFORM="Linux"
        INTELLISENSE_MODE="linux-gcc-x64"
        COMPILER_PATH="/usr/bin/g++"
        ;;
esac

# --- Find lib ---

LIB_NAME="lgf-cplib"
LIB_PATH=""

for base in "$HOME/Source" "$HOME/source" "$HOME/src"; do
    if [ -d "$base/$LIB_NAME" ]; then
        LIB_PATH="$base/$LIB_NAME"
        break
    fi
done

if [ -z "$LIB_PATH" ]; then
    echo "Warning: $LIB_NAME not found in ~/Source, ~/source, or ~/src."
    echo "Is the lib installed? Enter its path (or press Enter to skip):"
    read -r CUSTOM_PATH
    if [ -z "$CUSTOM_PATH" ]; then
        echo "Skipping lib configuration."
    elif [ -d "$CUSTOM_PATH" ]; then
        LIB_PATH="$CUSTOM_PATH"
    else
        echo "Warning: '$CUSTOM_PATH' not found — skipping lib."
    fi
fi

[ -n "$LIB_PATH" ] && echo "Using lib at: $LIB_PATH"

# --- VSCode config ---

mkdir -p "$VSCODE_DIR"

PLATFORM="$PLATFORM" \
INTELLISENSE_MODE="$INTELLISENSE_MODE" \
COMPILER_PATH="$COMPILER_PATH" \
LIB_PATH="$LIB_PATH" \
VSCODE_DIR="$VSCODE_DIR" \
python3 << 'PYEOF'
import json, os

platform        = os.environ['PLATFORM']
intellisense    = os.environ['INTELLISENSE_MODE']
compiler_path   = os.environ['COMPILER_PATH']
lib_path        = os.environ.get('LIB_PATH', '')
vscode_dir      = os.environ['VSCODE_DIR']

include_paths = ['${workspaceFolder}/**']
if lib_path:
    include_paths.append(lib_path)

cpp_props = {
    'configurations': [{
        'name': platform,
        'includePath': include_paths,
        'compilerPath': compiler_path,
        'cStandard': 'c17',
        'cppStandard': 'c++17',
        'intelliSenseMode': intellisense,
    }],
    'version': 4,
}

args = ['-fdiagnostics-color=always', '-g', '-O2', '-std=c++17', '-DLOCAL']
if lib_path:
    args.append('-I' + lib_path)
args += ['${file}', '-o', '${fileDirname}/${fileBasenameNoExtension}']

tasks = {
    'tasks': [{
        'type': 'cppbuild',
        'label': 'C/C++: g++ build active file',
        'command': compiler_path,
        'args': args,
        'options': {'cwd': '${fileDirname}'},
        'problemMatcher': ['$gcc'],
        'group': {'kind': 'build', 'isDefault': True},
    }],
    'version': '2.0.0',
}

with open(os.path.join(vscode_dir, 'c_cpp_properties.json'), 'w') as f:
    json.dump(cpp_props, f, indent=4)
    f.write('\n')

with open(os.path.join(vscode_dir, 'tasks.json'), 'w') as f:
    json.dump(tasks, f, indent=4)
    f.write('\n')

print('VSCode config created.')
PYEOF

# --- cptools config ---

if [ -n "$LIB_PATH" ] && command -v cptools &>/dev/null; then
    if [ -f "$CPTOOLS_CONFIG" ]; then
        LIB_PATH="$LIB_PATH" CPTOOLS_CONFIG="$CPTOOLS_CONFIG" python3 << 'PYEOF'
import json, sys, os

lib_path  = os.environ['LIB_PATH']
cfg_path  = os.environ['CPTOOLS_CONFIG']

extra = ['-DLOCAL', '-I' + lib_path]
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
PYEOF
    else
        echo "cptools config not found, run 'cptools config' first."
    fi
elif command -v cptools &>/dev/null; then
    echo "Skipping cptools config (no lib path configured)."
else
    echo "cptools not installed, skipping cptools config."
fi

echo "Done!"
