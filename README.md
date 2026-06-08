# Bases du C aux normes 42

Site pédagogique statique qui enseigne **les bases de la programmation en C aux normes de l'École 42**, conçu comme outil de préparation à la piscine 42 et complément aux formations BTS CIEL.

Auteur : **Rémy Denimal** — [remy.denimal@gmail.com](mailto:remy.denimal@gmail.com)

## Développement local

### Prérequis

- Python >= 3.10
- pip

### Installation

```bash
bash scripts/setup-dev.sh
```

### Lancer le serveur de développement

```bash
source .venv/bin/activate
mkdocs serve
```

Le site est alors accessible sur [http://localhost:8000](http://localhost:8000).

### Valider les exemples C

```bash
bash scripts/validate-norm.sh   # Vérifie la Norm 42
bash scripts/compile-all.sh     # Compile tous les .c
```

## CI/CD

- **norminette.yml** — vérifie la Norm 42 sur tout `examples/` à chaque push/PR.
- **build.yml** — lance `mkdocs build --strict` pour détecter les liens cassés.
- Déploiement automatique sur **Vercel** à chaque push sur `main`.

## Licences

- Contenu pédagogique (Markdown, illustrations) : [CC BY-SA 4.0](LICENSE-CONTENT)
- Code des exemples C et scripts : [MIT](LICENSE)
