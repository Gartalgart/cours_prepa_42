#!/usr/bin/env bash
set -e

echo "==> Création de l'environnement virtuel Python..."
python3 -m venv .venv
source .venv/bin/activate

echo "==> Mise à jour de pip..."
pip install --upgrade pip

echo "==> Installation des dépendances MkDocs..."
pip install -r requirements.txt

echo "==> Installation de norminette..."
pip install norminette

echo ""
echo "Setup terminé. Pour activer l'environnement :"
echo "  source .venv/bin/activate"
echo ""
echo "Pour lancer le serveur de développement :"
echo "  mkdocs serve"
