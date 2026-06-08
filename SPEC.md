# SPEC — Site pédagogique « Bases du C aux normes 42 »

> **Version :** 1.0
> **Date :** 8 juin 2026
> **Auteur :** Rémy Denimal
> **Statut :** Spec figée, prête pour démarrage. Seule la **§7 (progression pédagogique de la Séquence 1)** reste à finaliser en session de travail dédiée avec Claude.

---

## 1. Vision et objectifs

### 1.1 Objectif principal

Créer un site pédagogique statique qui enseigne **les bases de la programmation en C aux normes de l'École 42**, conçu comme un outil de préparation à la piscine 42 et de complément aux formations BTS CIEL.

Le projet est **entièrement original** : le contenu, les exemples, les exercices et la progression sont écrits par Rémy, sans reprendre matériel ni formulation du support LINK de Dorian Jacquot ou de toute autre source protégée.

### 1.2 Public cible

- Étudiants préparant la **piscine 42**.
- Étudiants BTS CIEL souhaitant compléter leur formation Python par une initiation au C.
- Auto-apprenants débutants en C.

### 1.3 Objectifs secondaires

- Projet portfolio pour les dossiers École 42 et ITII Beauvais.
- Démonstration de compétences techniques (Markdown structuré, MkDocs Material, GitHub Actions, Vercel, validation `norminette` en CI).
- Apprentissage personnel : la rédaction d'un cours est un excellent moyen de maîtriser une matière.

### 1.4 Ce que ce projet **n'est pas**

- ❌ Pas une copie, traduction ou adaptation de LINK ni d'aucune autre source. Tout le contenu est original.
- ❌ Pas un substitut à la piscine 42 ni un cours officiel de l'École 42.
- ❌ Pas un évaluateur automatique d'exercices (envisagé en v2, voir §10).

---

## 2. Aspects juridiques

### 2.1 Originalité du contenu

Le contenu est écrit de zéro par Rémy. Aucune phrase, aucune liste d'exercices, aucune formulation ne doit être copiée depuis LINK ou toute autre source pédagogique existante. Si un concept est universel (par ex. la définition d'un algorithme), il doit être reformulé avec les mots de Rémy.

### 2.2 Licences

| Élément | Licence |
|---|---|
| Contenu pédagogique (Markdown, illustrations originales) | **CC BY-SA 4.0** |
| Code des exemples C et scripts d'outillage | **MIT** |

Le fichier `LICENSE` à la racine contient le texte de la licence MIT. Un fichier `LICENSE-CONTENT` (ou la mention en pied de page du site) référence CC BY-SA 4.0 avec lien vers le texte officiel.

### 2.3 Mentions légales

À publier sur le site :
- Auteur, contact, hébergeur (Vercel Inc., adresse).
- Conformité RGPD : pas de cookies non essentiels, pas de tracking analytique invasif (Plausible Analytics envisageable, ou aucun analytics du tout).
- Lien vers les licences.

---

## 3. Stack technique

### 3.1 Générateur de site statique

**Choix : MkDocs Material.**

- Langage : Python.
- Configuration : `mkdocs.yml` à la racine.
- Thème : `mkdocs-material` (dernière version stable au démarrage, à figer dans `requirements.txt`).
- Plugins envisagés :
  - `search` (intégré) — recherche full-text en français.
  - `mkdocs-material[imaging]` pour les social cards générées automatiquement.
  - `pymdown-extensions` pour les blocs `admonition`, `tabbed`, `superfences`.
- Coloration syntaxique : native via Pygments (langage `c` supporté nativement).
- Thème sombre + clair avec switch dans la barre supérieure.

### 3.2 Hébergement

**Choix : Vercel.**

- Déploiement automatique sur push vers `main`.
- Build command : `pip install -r requirements.txt && mkdocs build`.
- Output directory : `site/`.
- Variables d'environnement : néant pour la v1.
- Preview deployments sur les pull requests.

### 3.3 Domaine

**Choix : nouveau domaine dédié à acheter.**

Candidats à confirmer avant achat (vérifier disponibilité) :
- `bases-c42.fr`
- `piscine-prep.fr`
- `c-norme.fr`
- `apprendre-c.fr`
- Suggestions personnelles de Rémy bienvenues.

Configuration DNS pointant vers Vercel (CNAME + A record selon les instructions Vercel au moment de la mise en service).

### 3.4 Versionning et CI/CD

**Choix : GitHub.**

- Dépôt **public** dès le démarrage (visibilité portfolio).
- Branche principale : `main`.
- Workflows GitHub Actions à créer :
  - `.github/workflows/norminette.yml` : lance `norminette` sur tout `examples/**/*.c` à chaque push et PR. Échec du CI si une erreur Norm est détectée.
  - `.github/workflows/build.yml` : `mkdocs build --strict` pour attraper les liens cassés et erreurs de syntaxe Markdown.
  - Vercel gère nativement le déploiement, donc pas de workflow `deploy.yml` à écrire.
- Pre-commit hook local recommandé : validation `norminette` + `mkdocs build --strict` avant chaque commit.

---

## 4. Arborescence du projet

```
bases-c42/                       # (nom de repo à confirmer avec le domaine)
├── README.md                    # Présentation du projet
├── SPEC.md                      # Ce fichier
├── NORM_VERSION.md              # Version de la Norm 42 figée
├── LICENSE                      # MIT (pour le code)
├── LICENSE-CONTENT              # CC BY-SA 4.0 (pour le contenu)
├── mkdocs.yml                   # Config MkDocs Material
├── requirements.txt             # mkdocs-material + plugins
├── .gitignore                   # site/, __pycache__/, .venv/, examples/*.out
├── .github/
│   └── workflows/
│       ├── norminette.yml       # Validation Norm 42 en CI
│       └── build.yml            # mkdocs build --strict en CI
├── docs/
│   ├── index.md                 # Page d'accueil
│   ├── stylesheets/
│   │   └── extra.css            # Personnalisations CSS minimales
│   ├── assets/
│   │   └── images/              # Diagrammes, captures
│   ├── introduction/
│   │   └── index.md             # (contenu défini en session §7)
│   ├── sequence-01/
│   │   ├── index.md
│   │   ├── support-01/
│   │   │   ├── cours.md
│   │   │   └── exercices.md
│   │   └── ...                  # (autres supports définis en §7)
│   └── ressources/
│       ├── norm-42.md           # Synthèse de la Norm
│       ├── makefile.md
│       ├── compilation.md
│       └── glossaire.md
├── examples/                    # Code C source des exemples du site
│   ├── sequence-01/
│   │   ├── support-01/
│   │   │   ├── ex01_hello.c
│   │   │   ├── ex02_variables.c
│   │   │   └── Makefile
│   │   └── ...
│   └── README.md
└── scripts/
    ├── validate-norm.sh         # norminette sur tout examples/
    ├── compile-all.sh           # cc -Wall -Wextra -Werror sur tout examples/
    └── setup-dev.sh             # Installation locale (venv, deps, norminette)
```

---

## 5. Conventions

### 5.1 Nommage des fichiers

- Pages Markdown : `kebab-case.md` (ex : `instructions-de-base.md`).
- Fichiers C d'exemple : `exNN_description.c` (ex : `ex01_premier_programme.c`).
- Numérotation à deux chiffres pour le tri lexicographique (`01`, `02`, …, `99`).
- Dossiers : `kebab-case` également (`sequence-01`, `support-03`).

### 5.2 Rédaction du contenu (Markdown)

- **Ton : tutoiement.** L'apprenant est tutoyé directement (« tu vas écrire », « observe ce code », « à toi de jouer »). Cohérence sur tout le site.
- Une page = un objectif pédagogique unique.
- Hiérarchie des titres :
  - `#` titre de page (un seul par fichier).
  - `##` sections principales (A, B, C…).
  - `###` sous-sections numérotées (1, 2, 3…).
  - `####` détails ou variantes (à utiliser avec parcimonie).
- Code C dans des blocs ```` ```c ```` avec coloration syntaxique.
- Code shell dans des blocs ```` ```bash ````.
- Encarts pédagogiques (admonitions MkDocs Material) :
  - `!!! note "À retenir"` pour les synthèses.
  - `!!! tip "Astuce"` pour les bonnes pratiques.
  - `!!! warning "Attention"` pour les pièges courants.
  - `!!! info "Pour aller plus loin"` pour les compléments hors programme.
- Vocabulaire pédagogique mis en **gras** à la première occurrence.

### 5.3 Code C des exemples

Au-delà de la Norm 42 (qui est l'arbitre final) :

- **Préfixe `ft_`** pour toutes les fonctions custom (cohérence avec la libft).
- **Pas de `printf`** dans les premiers chapitres. Remplacement par `write()` directement, puis par des `ft_putchar` / `ft_putstr` codées au fur et à mesure (reflète la progression réelle de la piscine 42).
- Chaque exemple doit compiler avec : `cc -Wall -Wextra -Werror fichier.c`.
- Chaque exemple doit passer `norminette` sans erreur ni warning.
- **En-tête 42** (les 11 lignes de commentaires en haut de fichier) sur **tous** les `.c` et `.h` du dossier `examples/`. Nom d'auteur dans l'en-tête : `Rémy Denimal <email>` ou login 42 si attribué.
- Tabulations (pas d'espaces) pour l'indentation, conformément à la Norm.

---

## 6. Référence Norm 42

### 6.1 Version cible

**Dernière version officielle de la Norm 42** au moment du démarrage du projet, à **figer** dans le repo.

À la racine du projet, créer un fichier `NORM_VERSION.md` qui indique :
- Version exacte (ex : `Norm v3.X.Y` ou hash du commit du repo `42School/norminette`).
- Date de figement.
- Lien vers le PDF `en.norm.pdf` correspondant.
- Version de `norminette` (outil) utilisée pour la validation.

Si la Norm évolue ultérieurement, c'est une décision explicite de mettre à jour la version cible, qui implique de revalider tous les exemples du repo.

### 6.2 Outillage de validation

- Outil : `norminette` (package Python officiel `42School/norminette`).
- Installation : `pip install norminette`.
- Commande de validation locale : `norminette examples/`.
- Validation en CI : `.github/workflows/norminette.yml` lance `norminette` à chaque push.

### 6.3 Ressources à charger en contexte au démarrage

À fournir à Claude (ou à toute personne qui contribue) avant de coder :

- [ ] Le PDF officiel `en.norm.pdf` de la version figée.
- [ ] Le `README.md` du repo `42School/norminette`.
- [ ] 5 à 10 fichiers `.c` validés par `norminette` (idéalement écrits par Rémy lui-même) servant d'exemples de référence stylistique.

---

## 7. Progression pédagogique (à finaliser)

> **⏳ Cette section est délibérément laissée en placeholder.** Elle sera retravaillée avec Claude lors d'une session dédiée avant le démarrage de la rédaction des supports. L'objectif est de définir précisément :
>
> - La liste exacte des supports de la Séquence 1.
> - Pour chaque support : titre, objectifs pédagogiques, notions introduites, prérequis, durée estimée.
> - Le découpage cours / exercices.
> - L'ordre d'introduction des concepts (notamment : à quel moment introduire les pointeurs, les fonctions, les tableaux).

### 7.1 Première proposition à retravailler

À titre de base de discussion uniquement, voici un découpage initial. **Cette liste sera revue, complétée et corrigée en session de travail.**

| Support | Titre provisoire | Notions clés (à valider) |
|---|---|---|
| Intro | Découverte du C | Algorithme, programme, langages, place du C |
| 01 | Premier programme | Structure `.c`, `main`, compilation, `write()` minimal, en-tête 42 |
| 02 | Caractères et affichage | `write()`, `ft_putchar`, ASCII, échappement |
| 03 | Variables et types | `int`, `char`, déclaration, portée |
| 04 | Opérateurs | Arithmétiques, comparaison, logiques, priorité |
| 05 | Conditions | `if`, `else if`, ternaire |
| 06 | Boucles | `while`, `do…while`, `for` |
| 07 | Fonctions | Prototypes, paramètres, retour |
| 08 | Tableaux et chaînes | Tableaux statiques, `\0`, parcours |
| 09 | Pointeurs (initiation) | Adresse, déréférencement, lien tableaux |
| Bilan | Mini-projet récapitulatif | Synthèse |

### 7.2 Hors périmètre v1

Reporté à des séquences ultérieures (v2+) :

- Allocation dynamique (`malloc`, `free`).
- Structures (`struct`), `typedef`.
- Lecture/écriture fichiers.
- Compilation séparée, headers, Makefiles avancés.
- Projets piscine spécifiques (`get_next_line`, `printf` custom, `push_swap`, etc.).

---

## 8. Structure type d'une page de support

Chaque support de cours suit ce gabarit pour assurer la cohérence visuelle et pédagogique :

````markdown
# Support NN — Titre

> **Prérequis :** [lien vers le support précédent ou « aucun »]
> **Objectif :** En une phrase, ce que l'apprenant saura faire à la fin.

## A. Première section

### 1. Notion à introduire

Texte explicatif court. Vocabulaire mis en **gras** à la première occurrence.

Exemple minimal commenté :

```c
#include <unistd.h>

int main(void)
{
    write(1, "Bonjour\n", 8);
    return (0);
}
```

!!! note "À retenir"
    Synthèse de la notion en 1-2 phrases.

### 2. Complément ou variante

…

## B. Section suivante

…

## Bilan

Liste à puces des notions vues, et ce que tu sais faire à ce stade.

## Pour aller plus loin

Liens externes optionnels (man pages, articles complémentaires).

---

➡️ **Exercices du support :** [voir la page exercices](./exercices.md)
➡️ **Support suivant :** [Support NN+1](../support-NN+1/cours.md)
````

Chaque fichier `exercices.md` suit un format similaire avec : énoncés numérotés, alternance quiz + exercices de code, solutions dans une admonition repliable `??? success "Solution"`.

---

## 9. Workflow de travail avec Claude

Pour limiter au maximum les hallucinations et garder un rythme productif :

### 9.1 Principes

1. **Itérations courtes.** Une page à la fois, validée avant de passer à la suivante.
2. **Validation systématique** après chaque étape : `mkdocs build --strict`, `norminette`, `cc -Wall -Wextra -Werror`.
3. **Contexte fourni à chaque session** : le `SPEC.md`, le PDF de la Norm 42, l'arborescence à jour, l'objectif précis de la session.

### 9.2 Ordre des livrables

1. **Setup initial** (session unique)
   - Création du repo GitHub public.
   - Squelette MkDocs Material avec page d'accueil minimale qui build.
   - Configuration Vercel (déploiement automatique).
   - GitHub Actions de validation (`norminette.yml`, `build.yml`).
   - Achat du domaine et configuration DNS.

2. **Finalisation de la progression pédagogique** (session §7)
   - Atelier Claude/Rémy pour figer la §7 du SPEC.

3. **Premier support complet** (1 à 3 sessions)
   - Page d'accueil enrichie.
   - Support 01 : `cours.md` + `exercices.md` + exemples C dans `examples/`.

4. **Itération sur les supports suivants** (par support)
   - Cours + exercices + exemples C, validation, push.

5. **Polissage et lancement v1**
   - Relecture finale, pages « ressources », mentions légales, README de contribution.

### 9.3 Bonnes pratiques anti-hallucination

- **Aucune confiance aveugle sur la Norm.** L'arbitre, c'est `norminette`, pas Claude.
- **Toute commande non triviale est vérifiée** par Rémy avant exécution.
- **Doc officielle MkDocs Material consultée en direct** (via `web_fetch`) plutôt que générée de mémoire.
- **Un prompt = un livrable.** Pas de « génère tout d'un coup ».

---

## 10. Évolutions possibles (post-v1)

Idées notées pour mémoire, mais **hors périmètre v1** :

- **Évaluateur automatique d'exercices.** Backend dans un conteneur Docker isolé qui prend un fichier C, lance `norminette`, compile avec les flags 42, exécute des tests unitaires, retourne le résultat. Stack envisagée : FastAPI ou ASP.NET Core (Rémy connaît les deux). Le projet portfolio idéal pour ITII et 42.
- **Comptes utilisateurs et suivi de progression.** Quels exercices terminés, statistiques personnelles.
- **Séquences supplémentaires** : libft, get_next_line, ft_printf, structures et allocation dynamique, push_swap…
- **Internationalisation** : version anglaise.
- **Améliorations UX** : recherche full-text avancée, mode hors-ligne (PWA), exports PDF des supports.

---

## 11. Critères de succès de la v1

La v1 est considérée terminée et publiable quand :

- [ ] Le site est en ligne sur le domaine acheté.
- [ ] La Séquence 1 complète est disponible (intro + tous les supports validés en §7 + bilan).
- [ ] Tous les exercices ont un énoncé clair et au moins une solution proposée.
- [ ] Tous les exemples de code C passent `norminette` et compilent avec `-Wall -Wextra -Werror`.
- [ ] Le code est versionné sur GitHub public.
- [ ] Le déploiement Vercel est automatique sur push vers `main`.
- [ ] La CI GitHub valide `norminette` et `mkdocs build --strict` à chaque PR.
- [ ] Les licences MIT et CC BY-SA 4.0 sont en place avec mentions légales conformes.
- [ ] Un `README.md` explique comment contribuer (cloner, installer, tester localement).
- [ ] Rémy est satisfait du rendu visuel et de la qualité pédagogique.

---

## 12. Récapitulatif des décisions figées

| Sujet | Décision |
|---|---|
| Approche contenu | Réécriture intégrale, zéro emprunt à LINK ou autres |
| Ton apprenant | Tutoiement |
| Licence contenu | CC BY-SA 4.0 |
| Licence code | MIT |
| Générateur site | MkDocs Material |
| Hébergement | Vercel |
| Domaine | Nouveau, dédié, à acheter (nom à confirmer) |
| Plateforme Git | GitHub public |
| Version Norm 42 | Dernière officielle, à figer au démarrage |
| Progression Séquence 1 | À retravailler en session dédiée |

---

## 13. Prochaines actions

1. **Rémy** : choisir et acheter le nom de domaine.
2. **Rémy** : vérifier la dernière version officielle de la Norm 42 et télécharger le PDF.
3. **Rémy + Claude** : session dédiée pour finaliser la §7 (progression pédagogique).
4. **Rémy + Claude** : session de setup initial (création repo, squelette MkDocs, Vercel, GitHub Actions).
5. **Rémy + Claude** : première session de rédaction du Support 01.

---

## Historique des versions

| Version | Date | Changements |
|---|---|---|
| 1.0 | 8 juin 2026 | Première version figée. 9 décisions clés actées via questionnaire interactif. Section §7 (progression) en placeholder, à finaliser en session dédiée. |

---

*Fin du SPEC v1.0. Document vivant : toute évolution majeure incrémente la version et est tracée dans l'historique ci-dessus.*
