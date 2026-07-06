# Support 09 — Pointeurs (initiation)

> **Prérequis :** [Support 08 — Tableaux et chaînes](../support-08/cours.md)
> **Objectif :** À la fin de ce support, tu sauras ce qu'est un pointeur, comment le déclarer, l'initialiser, le déréférencer, et tu pourras écrire des fonctions qui **modifient les variables de l'appelant**, comme `ft_swap`.

---

## A. Pourquoi des pointeurs ?

Souviens-toi du Support 03 : on avait montré qu'une fonction ne peut **pas modifier** une variable de l'appelant, parce que les paramètres sont des **copies**.

```c
void	ft_modifier(int n)
{
	n = 999;
}

int	main(void)
{
	int	x;

	x = 5;
	ft_modifier(x);
	/* x vaut toujours 5 — ft_modifier a modifié sa copie locale */
}
```

C'est embêtant : comment écrire une fonction `ft_swap` qui échange deux variables ? Avec ce qu'on sait, c'est **impossible**.

```c
void	ft_swap(int a, int b)        /* Marche pas : a et b sont des COPIES */
{
	int	tmp;

	tmp = a;
	a = b;
	b = tmp;
	/* Les vraies variables de l'appelant ne sont pas affectées */
}
```

**Les pointeurs** sont la solution. Au lieu de passer la **valeur** d'une variable, on passe son **adresse mémoire**. La fonction peut alors aller modifier la variable « à distance ».

---

## B. La mémoire et les adresses

### 1. Chaque variable a une adresse

Quand tu écris `int x;`, le compilateur réserve 4 octets quelque part en mémoire. Ces octets ont une **adresse** — un numéro qui les identifie de façon unique dans la mémoire de ton programme.

Tu n'as jamais besoin de connaître la valeur exacte de cette adresse (genre `0x7ffe9c5b30a4`), mais elle existe.

### 2. L'opérateur `&` : « adresse de »

Pour obtenir l'adresse d'une variable, on utilise l'opérateur `&` (vu dès le Support 02 avec `write(1, &c, 1)`) :

```c
int	x;

x = 42;
/* &x est l'adresse mémoire où x est stocké */
```

`&x` est une **valeur** (l'adresse), pas la variable elle-même. C'est de cette valeur qu'on peut faire quelque chose : la stocker dans un autre type de variable spécial, le **pointeur**.

---

## C. Le type pointeur

### 1. Déclaration

Un pointeur se déclare en ajoutant `*` entre le type et le nom :

```c
int		*p;     /* p est un pointeur vers un int */
char	*s;     /* s est un pointeur vers un char */
```

Le `*` se rattache au **nom**, pas au type. C'est pour ça qu'à 42 on écrit `int *p`, avec l'étoile collée au nom.

!!! warning "À retenir"
    Une déclaration comme `int *p` ne **crée pas** d'`int` quelque part. Elle crée juste **un pointeur**, c'est-à-dire une variable qui peut **contenir l'adresse** d'un `int`. Mais cette adresse n'est pas définie tant que tu ne l'affectes pas.

### 2. Initialiser un pointeur

```c
int	x;
int	*p;

x = 42;
p = &x;             /* p contient maintenant l'adresse de x */
```

À ce point, on dit que **`p` pointe vers `x`**.

!!! note "Norm 42 — alignement"
    Comme pour les autres types, les pointeurs dans un bloc de déclarations doivent être alignés. `int<TAB>x;` et `int<TAB>*p;` sont déjà alignés (le `*` ne change pas l'alignement du nom). Si tu mélanges `int` et `char *`, fais attention aux tabulations.

---

## D. Lire la valeur pointée : l'opérateur `*`

### 1. Déréférencement

Pour **accéder à la valeur** située à l'adresse contenue dans un pointeur, on utilise l'opérateur `*` devant le nom du pointeur. C'est le **déréférencement**.

```c
int	x;
int	*p;

x = 42;
p = &x;
/* *p donne la valeur stockée à l'adresse pointée par p */
/* Comme p pointe vers x, *p vaut 42. */
```

### 2. Modifier via le pointeur

Le déréférencement marche **dans les deux sens** : on peut lire **et écrire** à travers `*p`.

```c
int	x;
int	*p;

x = 7;
p = &x;
*p = 9;             /* On modifie la valeur à l'adresse pointée par p */
/* Maintenant x vaut 9 ! */
```

C'est exactement ce que fait l'exemple `ex01_premier_pointeur.c`. Il affiche `79` : d'abord la valeur initiale de `*p` (qui est `x`, donc `7`), puis la valeur de `x` après `*p = 9` (donc `9`).

### 3. La distinction `&x`, `x`, `*p`

Schéma mental à graver :

| Notation | Signification |
|---|---|
| `x` | La **valeur** de la variable `x` |
| `&x` | L'**adresse** où `x` est stocké |
| `p` | La **valeur** du pointeur `p` (c'est-à-dire une adresse) |
| `*p` | La **valeur** stockée à l'adresse pointée par `p` |

Et après `p = &x;` : **`*p` et `x` sont la même chose** (même emplacement mémoire, deux façons d'y accéder).

---

## E. Le pattern `ft_swap` — pourquoi les pointeurs existent

Maintenant, on peut écrire une fonction qui **modifie réellement** les variables de l'appelant :

```c
void	ft_swap(int *a, int *b)
{
	int	tmp;

	tmp = *a;       /* on lit ce que pointe a */
	*a = *b;        /* on écrit dans ce que pointe a, la valeur que pointe b */
	*b = tmp;       /* on écrit dans ce que pointe b, l'ancienne valeur de *a */
}

int	main(void)
{
	int	x;
	int	y;

	x = 3;
	y = 7;
	ft_swap(&x, &y);    /* on passe les ADRESSES de x et y */
	/* maintenant x vaut 7 et y vaut 3 */
}
```

C'est l'exemple `ex02_ft_swap.c`. Sortie : `73`.

Décortiquons l'appel `ft_swap(&x, &y)` :

1. `&x` est l'adresse de `x` dans `main`.
2. `&y` est l'adresse de `y` dans `main`.
3. Ces deux adresses sont **copiées** dans les paramètres `a` et `b` de `ft_swap`.
4. À l'intérieur de `ft_swap`, `*a` désigne **la même case mémoire** que `x` dans `main`. Modifier `*a` modifie donc directement `x`.
5. Idem pour `*b` et `y`.

!!! tip "À retenir"
    Pour qu'une fonction modifie une variable de l'appelant :

    1. Le **paramètre** de la fonction est un **pointeur** (`int *p`).
    2. L'**appel** se fait avec l'**adresse** de la variable (`f(&x)`).
    3. À l'**intérieur** de la fonction, on **déréférence** avec `*p`.

    C'est l'idiome le plus important du C. Tu vas le retrouver partout.

---

## F. Lien entre pointeurs et tableaux

C'est là qu'on comprend ce qu'on faisait depuis le Support 08.

### 1. Un tableau « est » un pointeur vers son premier élément

Quand tu écris `int tab[3];` puis que tu utilises `tab` (sans crochet), le nom `tab` est traité par le compilateur **comme un pointeur vers `tab[0]`**.

```c
int	tab[3];
int	*p;

tab[0] = 1;
tab[1] = 2;
tab[2] = 3;
p = tab;            /* OK : p pointe maintenant vers tab[0] */
/* p est équivalent à &tab[0] */
```

!!! warning "Ce n'est pas EXACTEMENT pareil"
    Un tableau et un pointeur diffèrent sur quelques points fins : `sizeof(tab)` donne la taille du tableau entier, `sizeof(p)` donne la taille d'un pointeur (généralement 8 octets). Mais dans la majorité des usages courants, ils s'utilisent de la même façon.

### 2. Arithmétique de pointeurs

Tu peux **avancer** un pointeur en lui ajoutant un entier :

```c
p = tab;
*p          /* équivalent à tab[0] */
*(p + 1)    /* équivalent à tab[1] */
*(p + 2)    /* équivalent à tab[2] */
```

C'est l'exemple `ex03_pointeur_tableau.c`. La sortie est `123`.

**Important :** quand tu fais `p + 1` sur un `int *`, le pointeur n'avance pas de 1 octet mais de `sizeof(int)` octets (4 sur la plupart des machines). Le compilateur calcule automatiquement pour que `*(p + 1)` désigne bien le **prochain élément**, pas le prochain octet brut.

### 3. La notation `tab[i]` est **équivalente** à `*(tab + i)`

C'est la révélation : les crochets `[]` ne sont qu'un **sucre syntaxique** pour le déréférencement avec décalage.

```c
tab[0]  ==  *(tab + 0)  ==  *tab
tab[1]  ==  *(tab + 1)
tab[i]  ==  *(tab + i)
```

Tu peux écrire l'un ou l'autre — ils produisent exactement le même code. La notation `tab[i]` est plus lisible, c'est celle qu'on utilise au quotidien.

### 4. Avancer un pointeur dans une chaîne

Au Support 08, on parcourait une chaîne avec `while (str[i] != '\0') { ...; i++; }`.

Avec les pointeurs, on peut faire la même chose en **avançant le pointeur lui-même** :

```c
void	ft_putstr_pointer(char *str)
{
	while (*str != '\0')
	{
		ft_putchar(*str);
		str++;              /* avance le pointeur d'un caractère */
	}
}
```

C'est l'exemple `ex04_pointeur_chaine.c`. À chaque tour, `str` pointe vers un caractère différent de la chaîne, jusqu'au `'\0'`.

Cette version est plus condensée que celle avec compteur `i`. Les deux sont valides et acceptées à 42. À toi de choisir selon la lisibilité.

---

## G. `NULL` — le pointeur nul

Un pointeur peut avoir une valeur spéciale : `NULL` (qui vaut 0). C'est utilisé pour dire « ce pointeur ne pointe vers rien de valide ».

```c
int	*p;

p = NULL;       /* p ne pointe vers rien */
*p = 5;         /* CRASH : segmentation fault */
```

Beaucoup de fonctions de la libc renvoient `NULL` pour signaler une erreur. Tu dois **toujours** vérifier avant de déréférencer un pointeur qui pourrait être `NULL` :

```c
if (p != NULL)
{
	*p = 5;     /* sûr */
}
```

!!! note "À retenir"
    `NULL` est ton ami : il te permet de signaler une erreur sans avoir à utiliser une valeur magique comme `-1`. Tu le verras partout en piscine, surtout dès qu'on aura `malloc`.

---

## H. Pièges classiques

### 1. Le déréférencement d'un pointeur non initialisé

```c
int	*p;

*p = 5;     /* p contient n'importe quoi : CRASH ou pire */
```

Un pointeur **non initialisé** contient une valeur indéfinie. Le déréférencer, c'est **lire ou écrire à une adresse aléatoire**. Souvent ça crashe, parfois ça corrompt silencieusement la mémoire — beaucoup plus dangereux.

**Règle :** un pointeur doit **toujours** être initialisé avant d'être déréférencé. Soit `p = &qqch;` (il pointe vers une variable existante), soit `p = NULL;` (pour pouvoir tester avant déréférence).

### 2. Le pointeur qui survit à sa cible

```c
int	*ft_dangereux(void)
{
	int	x;

	x = 42;
	return (&x);    /* DANGER : on retourne l'adresse d'une variable locale */
}
```

Après que `ft_dangereux` retourne, sa variable locale `x` n'existe plus. L'appelant reçoit une adresse qui pointe vers une zone mémoire **invalide**. Comportement indéfini.

À éviter absolument. Si tu veux qu'une fonction renvoie une valeur, retourne-la directement (`return (x);`), ne renvoie pas son adresse.

### 3. Confondre `int *p, q;` et `int *p, *q;`

```c
int	*p, q;          /* p est un int *, q est un int */
```

L'`*` se rattache au **nom**, pas au type. Cette ligne ne déclare **pas** deux pointeurs.

À la Norm 42, **une variable par ligne**, donc ce piège ne te concerne pas. Mais tu le rencontreras dans du code extérieur.

### 4. Modifier une chaîne littérale via un pointeur

```c
char	*str;

str = "Hello";
*str = 'J';     /* CRASH : "Hello" est en lecture seule */
```

Déjà vu au Support 08, mais ça vaut le coup de le redire ici : les littéraux de chaîne sont en mémoire **non modifiable**, même via un pointeur.

---

## Bilan

À la fin de ce support, tu sais :

- Expliquer ce qu'est une **adresse mémoire**.
- Déclarer un pointeur : `int *p`.
- Initialiser un pointeur avec une adresse : `p = &x`.
- Déréférencer un pointeur pour lire : `*p`.
- Déréférencer pour écrire : `*p = 5`.
- Écrire `ft_swap` et comprendre pourquoi ça marche.
- Expliquer l'équivalence `tab[i]` ↔ `*(tab + i)`.
- Avancer un pointeur dans une chaîne avec `str++`.
- Reconnaître `NULL` et savoir qu'il faut vérifier avant de déréférencer.
- Éviter les pièges : pointeur non initialisé, adresse de variable locale retournée, modification de littéral.

## Pour aller plus loin

- Le concept de **pointeur vers pointeur** (`char **`) est utile pour les tableaux de chaînes — tu le verras au moment d'`main(int argc, char **argv)`.
- L'**allocation dynamique** avec `malloc` (hors Séquence 1) te permettra de créer des tableaux et des chaînes dont la taille n'est connue qu'à l'exécution.
- Le projet **libft** de 42 t'amènera à manipuler les pointeurs sur tous les angles : recopie, comparaison, recherche, allocation.

---

➡️ **Exercices du support :** [voir la page exercices](./exercices.md)
➡️ **Support suivant :** [Bilan de la Séquence 1](../Bilan/bilan.md)
