#!/usr/bin/env bash
set -e

EXAMPLES_DIR="$(dirname "$0")/../examples"

echo "==> Vérification norminette sur $EXAMPLES_DIR..."
norminette "$EXAMPLES_DIR"
echo "==> Norminette : OK"
