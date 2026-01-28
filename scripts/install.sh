#!/bin/bash

# Define onde instalar os links (padrão do usuário)
BIN_DIR="$HOME/.local/bin"
COMP_DIR="$HOME/.zsh/completions"
REPO_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"

echo "--- Instalando cp-cli ---"

# 1. Garante que as pastas de destino existem
mkdir -p "$BIN_DIR"
mkdir -p "$COMP_DIR"

# 2. Linka o executável (substitui o alias)
echo "Criando link simbólico para o executável..."
ln -sf "$REPO_DIR/cp-cli" "$BIN_DIR/cp-cli"
chmod +x "$REPO_DIR/cp-cli"

# 3. Linka o autocomplete
echo "Criando link simbólico para o autocomplete..."
ln -sf "$REPO_DIR/completions/_cp-cli" "$COMP_DIR/_cp-cli"

echo "--- Sucesso! ---"
echo "Certifique-se que ~/.local/bin está no seu PATH."
