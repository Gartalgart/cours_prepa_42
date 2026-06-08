# Synthèse de la Norm 42

> Cette page est un aide-mémoire des règles les plus importantes de la Norm 42.
> L'arbitre final reste l'outil `norminette` et le PDF officiel de la Norm.

!!! warning "Attention"
    Cette synthèse est basée sur la version figée indiquée dans `NORM_VERSION.md`.
    En cas de doute, consulte toujours le PDF officiel.

## Fichiers

- Un fichier `.c` ne doit pas dépasser **5 fonctions**.
- Un fichier `.h` ne déclare que des prototypes, macros, `typedef`, structures.
- Chaque fichier commence par l'**en-tête 42** (11 lignes de commentaires).

## Fonctions

- Maximum **25 lignes** par fonction (accolades non comprises).
- Maximum **4 paramètres** par fonction.
- Pas de variable non utilisée.
- Pas de fonction vide (sauf `main` si nécessaire).

## Nommage

- Noms de fonctions et variables en **snake_case**.
- Noms de macros en **SCREAMING_SNAKE_CASE**.
- Préfixe `ft_` pour toutes les fonctions personnelles.

## Indentation et espacement

- **Tabulations** uniquement (pas d'espaces) pour l'indentation.
- Pas d'espace avant `;` ni `,`.
- Un espace après les mots-clés (`if`, `while`, `for`, `return`).
- Accolades ouvrantes sur la même ligne que la déclaration de fonction.

## Déclarations

- Variables déclarées **en début de bloc**, avant toute instruction.
- Pas de déclaration et d'assignation sur la même ligne (sauf `const`).
- Pas plus de **5 variables** par fonction.

## Interdictions

- `printf`, `puts`, `scanf` : interdits dans les projets 42 (utilise `write`).
- Goto, do-while (à vérifier selon la version de la Norm).
- Commentaires dans les fonctions (uniquement en dehors).

!!! tip "Astuce"
    Lance `norminette ton_fichier.c` pour vérifier instantanément.
    La CI du projet le fait automatiquement à chaque push.
