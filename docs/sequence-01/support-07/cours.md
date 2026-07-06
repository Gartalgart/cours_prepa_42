# Support 07 — Fonctions

> **Prérequis :** [Support 06 — Boucles](../support-06/cours.md)
> **Objectif :** À la fin de ce support, tu sauras déclarer et utiliser des fonctions avec paramètres et valeur de retour, comprendre le rôle du **prototype**, et écrire des fonctions **récursives** (qui s'appellent elles-mêmes).

---

## A. Pourquoi des fonctions ?

Tu connais déjà `ft_putchar` depuis le Support 02. Mais on n'a vu que la moitié du concept : une fonction qui agit sans rien rendre (`void`).

Une **fonction**, en C, c'est trois choses combinées :

1. Un **nom** (pour pouvoir l'appeler).
2. Une **boîte de calcul** qui prend des **entrées** (les paramètres) et qui peut produire une **sortie** (la valeur de retour).
3. Une **action** (afficher, modifier l'état du programme…).

Les fonctions ont quatre rôles majeurs :

- **Réutiliser** du code (ne pas écrire 10 fois la même chose).
- **Découper** un gros problème en petits.
- **Nommer** une logique (ton code devient lisible).
- **Tester** une logique en isolation (chaque fonction peut être testée séparément).

---

## B. Anatomie d'une fonction

Voici une fonction qui calcule la valeur absolue d'un entier :

```c
int	ft_abs(int n)
{
	if (n < 0)
	{
		return (-n);
	}
	return (n);
}
```

Décomposons :

| Partie | Nom | Rôle |
|---|---|---|
| `int` | **Type de retour** | Cette fonction renvoie un `int` |
| `ft_abs` | **Nom** | Comment l'appeler |
| `(int n)` | **Paramètres** | Cette fonction prend un `int` qu'elle appelle `n` |
| `{ ... }` | **Corps** | Ce que la fonction fait |
| `return (n);` | **Instruction de retour** | Renvoie la valeur calculée |

C'est l'exemple `ex01_fonction_retour.c`.

### 1. Le type de retour

Tu as vu deux types de retour jusqu'ici :

| Type | Signification |
|---|---|
| `void` | « Ne retourne rien » — comme `ft_putchar` |
| `int`, `char`… | « Retourne une valeur de ce type » |

Tu peux retourner n'importe quel type C : `int`, `char`, plus tard des pointeurs, des chaînes, des structures…

### 2. Comment appeler une fonction qui retourne une valeur

```c
int	resultat;

resultat = ft_abs(-5);          /* resultat reçoit 5 */
ft_putchar('0' + resultat);     /* affiche '5' */
```

Quand `ft_abs(-5)` s'exécute :

1. La valeur `-5` est **copiée** dans le paramètre `n` à l'intérieur de la fonction.
2. La fonction fait son calcul.
3. Au `return (-n)`, elle « rend » la valeur `5`.
4. Cette valeur prend la place de l'appel : `resultat = ft_abs(-5)` devient effectivement `resultat = 5`.

### 3. Utiliser directement sans variable intermédiaire

```c
ft_putchar('0' + ft_abs(-5));
```

La valeur retournée par `ft_abs(-5)` est utilisée immédiatement dans l'expression. Pas besoin de la stocker.

---

## C. Le prototype

### 1. Le problème

En C, le compilateur lit ton fichier **de haut en bas**. Quand il rencontre l'appel `ft_abs(-5)`, il doit déjà connaître `ft_abs` : son nom, ses paramètres, son type de retour. Sinon, il proteste.

Solution la plus simple : **définir** la fonction **avant** son utilisation. C'est ce qu'on a fait dans `ex01` (la définition de `ft_abs` est avant `main`).

### 2. Le prototype : déclaration sans corps

Quand on a plein de fonctions, on ne peut pas toujours les ordonner pour que chacune apparaisse avant son utilisation. La solution : le **prototype**. C'est une déclaration sans corps :

```c
int	ft_abs(int n);          /* prototype, en haut du fichier */

int	main(void)
{
	ft_putchar('0' + ft_abs(-5));  /* OK : le prototype suffit au compilateur */
	return (0);
}

int	ft_abs(int n)           /* définition, plus bas */
{
	if (n < 0)
	{
		return (-n);
	}
	return (n);
}
```

Le prototype **promet** au compilateur que cette fonction existe quelque part. La **définition** (corps complet) peut alors apparaître plus tard.

### 3. Quand utiliser les prototypes

- **Petits fichiers (< 100 lignes) :** tu peux te passer de prototypes en définissant tes fonctions avant `main`.
- **Gros fichiers :** mets tous les prototypes en haut, puis les définitions en bas. C'est plus lisible.
- **Plusieurs fichiers :** les prototypes vivent dans des fichiers `.h` (les *headers*). On en reparlera plus tard.

!!! tip "À 42"
    Pour la piscine, place tes prototypes en haut du fichier juste après les `#include`. C'est la convention attendue.

---

## D. Paramètres et arguments

Petit lexique pour ne pas se mélanger :

- **Paramètre** : la variable déclarée dans la signature de la fonction (`int n` dans `ft_abs(int n)`).
- **Argument** : la valeur passée lors de l'appel (`-5` dans `ft_abs(-5)`).

### 1. Plusieurs paramètres

Tu peux avoir autant de paramètres que tu veux (à la Norm 42, **maximum 4**), séparés par des virgules :

```c
int	ft_max3(int a, int b, int c)
{
	int	plus_grand;

	plus_grand = ft_max(a, b);
	plus_grand = ft_max(plus_grand, c);
	return (plus_grand);
}
```

C'est l'exemple `ex02_plusieurs_parametres.c`. On y voit aussi qu'une fonction peut **appeler d'autres fonctions** (ici `ft_max3` appelle `ft_max`). C'est la base de la composition.

### 2. Passage par valeur (rappel)

Comme on l'a vu au Support 03 sur la portée : **les paramètres sont des copies**. Modifier le paramètre dans la fonction ne modifie pas la variable de l'appelant.

```c
void	ft_essaie_de_modifier(int n)
{
	n = 999;
}

int	main(void)
{
	int	x;

	x = 5;
	ft_essaie_de_modifier(x);
	/* x vaut toujours 5 ici */
}
```

Pour qu'une fonction modifie une variable de l'appelant, il faudra des **pointeurs** (Support 09).

---

## E. Valeur de retour

### 1. `return` quitte la fonction immédiatement

Dès que `return` est exécuté, la fonction se termine. Tout ce qui vient après est ignoré.

```c
int	ft_signe(int n)
{
	if (n > 0)
	{
		return (1);     /* on sort ici si n > 0 */
	}
	if (n < 0)
	{
		return (-1);    /* on sort ici si n < 0 */
	}
	return (0);         /* sinon, on sort ici */
}
```

Plusieurs `return` dans une même fonction sont autorisés (et la Norm 42 l'accepte). Utilisez-le pour rendre votre code plus clair quand c'est pertinent.

### 2. À la Norm 42 : parenthèses obligatoires

Comme pour `main` :

```c
return (n);             /* OK */
return n;               /* REFUSÉ par norminette */
```

### 3. `return ;` dans une fonction `void`

Dans une fonction `void`, tu peux utiliser `return ;` (sans valeur) pour sortir prématurément :

```c
void	ft_putnbr(int n)
{
	if (n == -2147483648)
	{
		write(1, "-2147483648", 11);
		return ;            /* on sort, le reste ne s'exécute pas */
	}
	/* ... */
}
```

!!! note "Norm 42 — espace avant `;`"
    Comme pour `break ;` et `continue ;` au Support 06, le `return ;` solo prend un espace avant le `;`. Mais `return (0);` (avec valeur) n'en prend pas.

---

## F. La récursivité

### 1. Une fonction qui s'appelle elle-même

Le C autorise une fonction à s'appeler **elle-même**. C'est la **récursivité**, une technique puissante pour résoudre certains problèmes très naturellement.

Exemple : la **factorielle** d'un nombre `n` est `n × (n-1) × (n-2) × … × 1`. La définition mathématique est récursive : `n! = n × (n-1)!`, avec `0! = 1` et `1! = 1`.

En C :

```c
int	ft_factorielle(int n)
{
	if (n <= 1)
	{
		return (1);
	}
	return (n * ft_factorielle(n - 1));
}
```

C'est l'exemple `ex04_factorielle.c`. Décortiquons `ft_factorielle(3)` :

```
ft_factorielle(3)
  = 3 * ft_factorielle(2)
  = 3 * (2 * ft_factorielle(1))
  = 3 * (2 * 1)
  = 6
```

### 2. Les deux ingrédients d'une fonction récursive

Toute fonction récursive correctement écrite contient **deux choses** :

1. **Un cas de base** : la condition d'arrêt. Sans elle, la récursion est infinie. Ici, c'est `if (n <= 1) return (1);`.
2. **Un appel récursif** qui rapproche du cas de base. Ici, on appelle `ft_factorielle(n - 1)` : `n` diminue à chaque étape, et finit par atteindre `1`.

Sans cas de base, ta fonction s'appelle à l'infini, la **pile d'appels** (stack) se remplit, et le programme crashe avec un *stack overflow*.

!!! tip "Quand utiliser la récursivité ?"
    La récursivité est élégante quand le problème **se définit naturellement** en termes de lui-même : factorielle, séquence de Fibonacci, parcours d'arbres, fractales, etc.

    Pour des problèmes simples (parcourir 1 à N), une boucle `while` est presque toujours plus claire et plus rapide. Ne forçons pas la récursivité partout.

### 3. `ft_putnbr` : un classique récursif

Comment afficher un entier comme `1234` caractère par caractère ?

Idée : afficher d'abord les chiffres **avant** le dernier (donc `123`), puis le dernier (`4`).

```c
void	ft_putnbr(int n)
{
	if (n == -2147483648)
	{
		write(1, "-2147483648", 11);
		return ;
	}
	if (n < 0)
	{
		ft_putchar('-');
		n = -n;
	}
	if (n >= 10)
	{
		ft_putnbr(n / 10);      /* récursion sur les chiffres avant */
	}
	ft_putchar('0' + n % 10);   /* le dernier chiffre */
}
```

C'est l'exemple `ex03_ft_putnbr.c`.

Décortiquons `ft_putnbr(123)` :

1. `n = 123`, `n >= 10`, on appelle `ft_putnbr(12)`.
2. Dans cet appel : `n = 12`, `n >= 10`, on appelle `ft_putnbr(1)`.
3. Dans cet appel : `n = 1`, `n < 10`, on saute la récursion. On affiche `'0' + 1 % 10` = `'1'`.
4. Retour à l'étape 2 : on affiche `'0' + 12 % 10` = `'2'`.
5. Retour à l'étape 1 : on affiche `'0' + 123 % 10` = `'3'`.

Résultat : `123`.

### 4. Le piège `INT_MIN`

Pourquoi le `if (n == -2147483648)` au début ?

Si tu reçois `-2147483648` (la valeur minimale d'un `int`), le `n = -n` plus loin produit `+2147483648`… qui **dépasse** le maximum d'un `int` (`+2147483647`). C'est un débordement, et le comportement est **indéfini**.

Solution : on traite ce cas particulier en premier, en écrivant la chaîne `-2147483648` directement.

!!! note "À retenir"
    À chaque fois que tu manipules `-n` sur un `int` qui peut valoir `INT_MIN`, tu dois te poser la question du débordement. C'est un piège classique en piscine et en exam.

---

## G. Règles Norm 42 sur les fonctions

Synthèse des règles à respecter (la plupart déjà mentionnées ailleurs) :

| Règle | Détail |
|---|---|
| **Max 25 lignes** | Le corps d'une fonction (entre `{` et `}`) ne doit pas dépasser 25 lignes. |
| **Max 4 paramètres** | Une fonction ne peut pas avoir plus de 4 paramètres. |
| **Max 5 variables** | Une fonction ne peut pas déclarer plus de 5 variables locales. |
| **Style Allman** | Accolade ouvrante `{` sur sa propre ligne, en colonne 0. |
| **Tabulation entre type et nom** | `int<TAB>ft_max(...)`, pas un espace. |
| **Parenthèses sur `return`** | `return (0);` et non `return 0;`. |
| **Une instruction par ligne** | Pas de `i++; j--;` sur la même ligne. |

Si tu respectes ces règles dès tes premières fonctions, elles deviendront automatiques.

---

## H. Bonnes pratiques

### 1. Une fonction = une responsabilité

Une fonction doit faire **une seule chose**, et la faire bien. Si tu trouves une fonction qui « calcule la somme puis l'affiche puis sauvegarde dans un fichier », découpe-la en trois.

### 2. Noms explicites

`ft_calculer_max_de_3` est plus clair que `ft_truc`. Sois descriptif. Si ton nom devient trop long, c'est peut-être que ta fonction fait trop de choses.

### 3. Préfixe `ft_`

À 42, **toutes** les fonctions que tu écris commencent par `ft_`. Pas d'exception, sauf `main`.

### 4. Pas d'effet de bord caché

Une fonction nommée `ft_max` ne devrait **rien afficher** ni modifier de variable globale. Elle reçoit des entrées, elle renvoie une sortie. C'est plus prévisible et plus testable.

Si tu as besoin d'effet de bord (afficher quelque chose), garde-le dans une fonction explicitement nommée pour ça : `ft_putnbr` affiche, `ft_max` calcule.

---

## Bilan

À la fin de ce support, tu sais :

- Définir une fonction complète : type de retour, nom, paramètres, corps, `return`.
- Distinguer **paramètre** (déclaré) et **argument** (passé).
- Comprendre le rôle d'un **prototype** et savoir quand l'utiliser.
- Écrire une fonction avec valeur de retour, et l'appeler comme une expression.
- Écrire une fonction **récursive** avec un cas de base et un appel récursif qui converge.
- Implémenter `ft_putnbr` qui gère les négatifs et `INT_MIN`.
- Respecter les règles Norm 42 sur les fonctions (25 lignes, 4 paramètres, 5 variables).

## Pour aller plus loin

- Wikipedia *Tail call* — une optimisation classique des appels récursifs.
- Le projet **libft** de 42 t'amènera à écrire des dizaines de fonctions de la libc à la main.

---

➡️ **Exercices du support :** [voir la page exercices](./exercices.md)
➡️ **Support suivant :** [Support 08 — Tableaux et chaînes](../support-08/cours.md)
