#!/usr/bin/env bash
set -e

EXAMPLES_DIR="$(dirname "$0")/../examples"
ERRORS=0

echo "==> Compilation de tous les .c dans $EXAMPLES_DIR..."

while IFS= read -r -d '' file; do
    echo -n "  Compilation de $file... "
    if cc -Wall -Wextra -Werror "$file" -o /dev/null 2>/tmp/cc_err; then
        echo "OK"
    else
        echo "ERREUR"
        cat /tmp/cc_err
        ERRORS=$((ERRORS + 1))
    fi
done < <(find "$EXAMPLES_DIR" -name "*.c" -print0)

if [ "$ERRORS" -gt 0 ]; then
    echo ""
    echo "==> $ERRORS fichier(s) ont échoué à la compilation."
    exit 1
fi

echo "==> Compilation : tous les fichiers OK"
