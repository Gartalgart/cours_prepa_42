# Exemples de code C

Ce dossier contient tous les fichiers C utilisés comme exemples dans les supports du site.

## Organisation

```
examples/
└── sequence-01/
    └── support-01/
        ├── ex01_premier_programme.c
        └── Makefile
```

## Règles

- Tous les fichiers `.c` doivent passer `norminette` sans erreur.
- Tous les fichiers `.c` doivent compiler avec `cc -Wall -Wextra -Werror`.
- Chaque fichier porte l'en-tête 42 (11 lignes).
- Nommage : `exNN_description.c`.

## Validation locale

```bash
bash scripts/validate-norm.sh
bash scripts/compile-all.sh
```
