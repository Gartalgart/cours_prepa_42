# Support 03 — Variables et types

> **Prérequis :** [Support 02 — Caractères et affichage](../support-02/cours.md)
> **Objectif :** À la fin de ce support, tu sauras déclarer et utiliser des variables de différents types entiers en C, respecter les règles de la Norm 42 sur les déclarations, et comprendre la **portée** d'une variable.

---

## A. Pourquoi des types ?

### 1. Pour la machine, tout est octet

Une machine ne « voit » pas les nombres ni les caractères. Elle ne voit que des **octets** : des paquets de 8 bits, chacun étant un 0 ou un 1.

Le même octet `01000001` peut représenter :

- Le **nombre entier** 65.
- Le **caractère** `'A'`.
- Une fraction de **nombre flottant** (comme `0.0…1`).

Comment savoir lequel ? C'est le **type** qui le dit. Le type est la façon dont tu **interprètes** les octets en mémoire.

### 2. Le rôle du type

Quand tu écris :

```c
char	c;
int		n;
```

Tu dis au compilateur :

- « Réserve 1 octet en mémoire et appelle-le `c`. Je traiterai ce qu'il contient comme un caractère. »
- « Réserve 4 octets en mémoire et appelle-les `n`. Je traiterai leur contenu comme un entier signé. »

Le compilateur saura alors :

- Combien d'octets réserver pour chaque variable.
- Comment **lire** sa valeur (par ex. afficher 65 ou `'A'`).
- Quelles **opérations** sont autorisées (additionner des entiers, oui ; additionner du texte, c'est plus compliqué).

---

## B. Les types entiers de base

À 42, dans la Séquence 1, tu vas surtout manipuler **trois types** :

| Type | Taille (Linux/macOS x86_64) | Plage de valeurs |
|---|---|---|
| `char` | 1 octet | de `-128` à `127` (signé) ou `0` à `255` (non signé) |
| `int` | 4 octets | de `-2 147 483 648` à `2 147 483 647` |
| `unsigned int` | 4 octets | de `0` à `4 294 967 295` |

D'autres types existent et tu les rencontreras plus tard :

- `short` : 2 octets (entier court).
- `long` : 8 octets sur Linux 64-bits.
- `long long` : 8 octets, garanti par le standard.
- `size_t` : entier non signé utilisé pour des tailles (souvent 8 octets en 64-bits).

!!! note "À retenir"
    - Le standard C **ne garantit pas** une taille fixe pour `int` ou `long` — il garantit seulement un **minimum**. En pratique, sur les machines 64-bits modernes : `int` = 4 octets, `long` = 8 octets.
    - Le seul type dont la taille est **garantie à 1 octet** par le standard, c'est `char`.

### 1. Signé ou non signé ?

Par défaut, `int` et `char` sont **signés** : ils peuvent contenir des valeurs négatives. Si tu veux uniquement des valeurs positives (et étendre le maximum), tu peux préciser `unsigned` :

```c
int				n;          /* -2 147 483 648 à 2 147 483 647 */
unsigned int	positif;    /* 0 à 4 294 967 295 */
```

!!! tip "Astuce"
    En piscine, tu n'as quasiment jamais besoin de `unsigned int`. Le `int` standard couvre tous les besoins. Connaître l'existence de `unsigned` suffit pour le moment.

---

## C. Déclarer une variable

### 1. La syntaxe de base

```c
type	nom;
```

Exemples :

```c
int		age;
char	initiale;
```

### 2. Les règles de la Norm 42 (à connaître par cœur)

C'est ici que beaucoup de débutants se font piéger. **Quatre règles** s'appliquent à toute déclaration de variable :

#### Règle 1 — En haut de la fonction, séparées du code par une ligne vide

```c
int	main(void)
{
	int		offset;     /* déclarations en haut */
	char	lettre;

	offset = 4;             /* code séparé par UNE ligne vide */
	lettre = 'A' + offset;
	/* ... */
}
```

#### Règle 2 — Une variable par ligne

❌ **Interdit** :
```c
int	a, b, c;
```

✅ **Correct** :
```c
int	a;
int	b;
int	c;
```

#### Règle 3 — Pas d'initialisation à la déclaration

❌ **Interdit** :
```c
int		x = 5;
char	c = 'A';
```

✅ **Correct** :
```c
int		x;
char	c;

x = 5;
c = 'A';
```

#### Règle 4 — Alignement des noms avec des tabulations

Tous les noms de variables d'un bloc doivent être **alignés** entre eux, en utilisant des **tabulations** (jamais d'espaces).

```c
int		offset;     /* int + DEUX tabulations  -> nom à la colonne 8 */
char	lettre;     /* char + UNE tabulation     -> nom à la colonne 8 */
```

!!! warning "Le piège classique"
    Si tu mets une seule tabulation après `int` et une seule après `char`, les noms ne seront **pas alignés** (`int` étant plus court d'un caractère que `char`). `norminette` te jettera avec une erreur `MISALIGNED_VAR_DECL`. La règle est : chaque ligne doit ajouter assez de tabulations pour que le nom de la variable arrive au même endroit que le plus long type du bloc.

### 3. Bonnes pratiques de nommage

- **`snake_case`** : mots en minuscules séparés par des underscores. `vitesse_max`, `nb_etudiants`, `c`.
- **Noms explicites** : préfère `nb_lignes` à `n` pour une variable qui contient un nombre de lignes.
- **Exceptions tolérées** : `i`, `j`, `k` pour les compteurs de boucles, `c` pour un caractère unique, `s` pour une chaîne.
- **Pas d'accents**, pas de caractères spéciaux : seulement `a-z`, `0-9` et `_`. Un nom ne peut pas commencer par un chiffre.

---

## D. Affecter et utiliser une variable

### 1. L'opérateur `=`

`=` n'est **pas** un signe d'égalité mathématique : c'est un opérateur **d'affectation**. Il signifie « mets à gauche ce qu'il y a à droite ».

```c
int	x;

x = 5;          /* x reçoit la valeur 5 */
x = x + 1;      /* x reçoit la valeur de (x + 1) — donc 6 */
```

La deuxième ligne paraît mathématiquement absurde (`x = x + 1` n'a aucune solution en maths). En C, elle veut dire : « calcule `x + 1`, et mets le résultat dans `x` ».

!!! note "À retenir"
    Le côté **gauche** de `=` doit être une variable (un emplacement modifiable).
    Le côté **droit** est une **expression** que le compilateur évalue pour produire une valeur.

### 2. Variables et arithmétique

Tu peux mélanger constantes et variables dans une expression :

```c
int		a;
int		b;
int		somme;

a = 3;
b = 5;
somme = a + b;          /* somme = 8 */
somme = somme * 2;      /* somme = 16 */
somme = a + b - 1;      /* somme = 7 */
```

Tu peux aussi mélanger types entre eux (`char` et `int`) tant qu'ils sont compatibles :

```c
int		offset;
char	lettre;

offset = 4;
lettre = 'A' + offset;  /* lettre = 'E', code ASCII 69 */
```

---

## E. La portée des variables (scope)

### 1. Une variable est **locale** à sa fonction

Quand tu déclares une variable à l'intérieur d'une fonction, elle **n'existe** que dans cette fonction. Les autres fonctions ne peuvent pas la voir.

```c
void	ft_modifier(int x)
{
	x = x + 5;
	ft_putchar('0' + x);
}

int	main(void)
{
	int	x;

	x = 1;
	ft_modifier(x);     /* affiche '6' (x + 5 dans ft_modifier) */
	ft_putchar('0' + x);/* affiche '1' (x dans main est INCHANGÉ) */
	ft_putchar('\n');
	return (0);
}
```

Sortie : `61\n`.

C'est l'exemple `ex04_portee_variables.c`. Décortiquons :

- Dans `main`, on déclare `x = 1`.
- On appelle `ft_modifier(x)`. La valeur `1` est **copiée** dans le paramètre `x` de `ft_modifier`. Ce paramètre est une **autre variable**, juste avec le même nom.
- `ft_modifier` modifie sa copie locale (`x = x + 5` → `6`) et l'affiche.
- De retour dans `main`, le `x` de `main` vaut **toujours `1`**, parce qu'il est totalement indépendant du `x` de `ft_modifier`.

!!! warning "Erreur de débutant fréquente"
    Ne pas comprendre la portée mène à des bugs comme : « j'ai modifié `x` dans la fonction, pourquoi il n'a pas changé dans `main` ? » → parce que tu as modifié une **copie**.

    Pour qu'une fonction puisse modifier une variable de l'appelant, il faut lui passer son **adresse** avec `&` et utiliser des **pointeurs**. On verra ça au Support 09.

### 2. Et les variables globales ?

Il existe des variables **globales** : déclarées en dehors de toute fonction, accessibles partout. **À 42, les variables globales sont presque toujours interdites** dans les projets de la piscine et du tronc commun. La raison : elles rendent le code beaucoup plus difficile à comprendre et à maintenir.

Garde cette règle : pour la piscine, **toutes tes variables sont locales**.

---

## F. Le débordement (overflow)

### 1. Tout type a une limite

`int` peut aller jusqu'à `2 147 483 647`. Que se passe-t-il si tu fais `2 147 483 647 + 1` ?

Réponse : **comportement indéfini** selon le standard C. En pratique, sur la plupart des machines, ça « boucle » à la valeur minimale : `-2 147 483 648`. C'est ce qu'on appelle un **débordement** (*overflow*).

```c
int	max;

max = 2147483647;
max = max + 1;          /* max vaut maintenant -2147483648 */
```

### 2. Pour `char`, c'est pareil mais plus vite

```c
char	c;

c = 127;                /* maximum d'un char signé */
c = c + 1;              /* c vaut -128 */
```

### 3. Conséquence pratique

Si tu manipules des nombres potentiellement grands (compteurs, sommes, produits), **choisis le bon type**. En général :

- Pour des compteurs ou des indices : `int` suffit largement.
- Pour des tailles de mémoire ou d'allocation : utilise `size_t` (on verra ça plus tard).
- Pour des très gros nombres : `long long` (8 octets garantis).

!!! note "À retenir"
    Le débordement ne provoque **pas une erreur** : le programme continue de tourner, avec une valeur fausse. C'est ce qui en fait un bug particulièrement vicieux.

---

## Bilan

À la fin de ce support, tu sais :

- Expliquer pourquoi C est un langage typé (interpréter des octets).
- Citer les principaux types entiers : `char` (1 octet), `int` (4 octets), `unsigned int`.
- Déclarer une variable selon les **4 règles de la Norm 42** :
  - Au début de la fonction.
  - Une par ligne.
  - Pas d'initialisation à la déclaration.
  - Noms alignés avec des tabulations.
- Affecter une valeur avec `=` et l'utiliser dans des expressions arithmétiques.
- Mélanger `int` et `char` dans une expression.
- Comprendre la **portée** : une variable est locale à sa fonction, et les paramètres sont des **copies**.
- Anticiper le débordement (*overflow*) quand tu manipules de grands nombres.

## Pour aller plus loin

- Page de manuel sur les types entiers C : [`man 3 stdint`](https://man7.org/linux/man-pages/man3/stdint.h.3.html).
- L'article Wikipedia *Integer overflow* pour les conséquences en sécurité informatique.

---

➡️ **Exercices du support :** [voir la page exercices](./exercices.md)
➡️ **Support suivant :** [Support 04 — Opérateurs](../support-04/cours.md)
