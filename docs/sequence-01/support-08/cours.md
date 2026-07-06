# Support 08 — Tableaux et chaînes

> **Prérequis :** [Support 07 — Fonctions](../support-07/cours.md)
> **Objectif :** À la fin de ce support, tu sauras déclarer et manipuler des tableaux d'entiers, comprendre le concept de chaîne en C (un tableau de caractères terminé par `'\0'`), et écrire `ft_strlen` et `ft_putstr`.

---

## A. Pourquoi des tableaux ?

Imagine que tu veuilles stocker les notes des 30 élèves d'une classe. Avec ce que tu sais aujourd'hui, tu déclarerais 30 variables : `note1`, `note2`, …, `note30`. C'est absurde. Tu ne peux pas non plus écrire une boucle qui passerait sur des variables qui s'appellent différemment.

Solution : un **tableau**. C'est une collection de valeurs **du même type**, stockées **consécutivement** en mémoire, accessibles par un **indice**.

```c
int	notes[30];      /* un tableau de 30 entiers, numérotés de 0 à 29 */
```

---

## B. Déclarer un tableau

### 1. Syntaxe

```c
type	nom[taille];
```

Exemples :

```c
int		notes[30];      /* 30 entiers */
char	lettres[26];    /* 26 caractères */
```

La **taille** entre crochets doit être une **constante** connue à la compilation. Tu ne peux pas écrire `int tab[n];` où `n` est une variable (sauf cas avancés qu'on ne verra pas en piscine).

### 2. Indexation

Les éléments d'un tableau de taille `N` sont **numérotés de `0` à `N-1`** :

```c
int	notes[5];

notes[0] = 12;      /* premier élément */
notes[1] = 15;
notes[2] = 8;
notes[3] = 17;
notes[4] = 14;      /* dernier élément (indice N-1) */
```

!!! warning "L'indexation commence à ZÉRO"
    C'est la convention en C (et dans presque tous les langages modernes). Si tu déclares `int tab[5];`, les indices valides sont `0, 1, 2, 3, 4`. Accéder à `tab[5]` est une **erreur** : tu lis ou écris dans la mémoire au-delà du tableau, ce qui peut planter le programme ou produire un bug subtil.

### 3. Norm 42 — Pas d'initialisation à la déclaration

À 42 :

❌ **Interdit** :
```c
int	tab[5] = {10, 20, 30, 40, 50};
```

(Erreur `DECL_ASSIGN_LINE`.)

✅ **Correct** :
```c
int	tab[5];

tab[0] = 10;
tab[1] = 20;
tab[2] = 30;
tab[3] = 40;
tab[4] = 50;
```

C'est verbeux, mais c'est la règle. **Exception** : les variables `static` peuvent être initialisées à la déclaration, mais on n'en parlera pas en Séquence 1.

---

## C. Parcourir un tableau avec `while`

C'est l'usage le plus courant. Maintenant que tu connais les boucles, c'est trivial.

```c
int	tab[5];
int	i;
int	somme;

tab[0] = 10;
tab[1] = 20;
tab[2] = 30;
tab[3] = 40;
tab[4] = 50;
i = 0;
somme = 0;
while (i < 5)
{
	somme = somme + tab[i];
	i++;
}
/* somme = 150 */
```

C'est l'exemple `ex01_tableau_int.c`. Le pattern est universel :

- Compteur `i` qui démarre à `0`.
- Condition `i < TAILLE`.
- À l'intérieur, accès à `tab[i]`.
- `i++` à la fin de chaque itération.

---

## D. Les chaînes de caractères

### 1. Une chaîne = un tableau de `char`… avec une convention

En C, **il n'existe pas de type `string` natif**. Une chaîne, c'est simplement un **tableau de caractères**, avec une convention cruciale : le dernier élément utile est suivi d'un caractère **nul `'\0'`** qui marque la fin.

```
Index :   0    1    2    3    4    5    6
Valeur :  'H'  'e'  'l'  'l'  'o'  '\0' ???
```

Tout ce qui suit le `'\0'` est ignoré. Le `'\0'` lui-même n'est **pas affiché**, c'est juste un marqueur de fin.

### 2. Littéral de chaîne

Quand tu écris `"Hello"` dans ton code, le compilateur :

1. Stocke en mémoire les 5 caractères `'H'`, `'e'`, `'l'`, `'l'`, `'o'`.
2. Ajoute **automatiquement** un `'\0'` à la fin.
3. Te donne l'**adresse** du premier caractère.

Donc `"Hello"` occupe **6 octets** en mémoire (5 lettres + le `'\0'`).

### 3. Passer une chaîne à une fonction

Pour recevoir une chaîne en paramètre, on utilise la syntaxe **`char *str`** :

```c
void	ft_putstr(char *str)
{
	/* ... */
}

int	main(void)
{
	ft_putstr("Hello");
}
```

L'étoile `*` indique que `str` est un **pointeur** — concept qu'on verra en détail au Support 09. Pour l'instant, retiens cette équivalence pratique :

- `char *str` = « ce paramètre est une chaîne »
- À l'intérieur de la fonction, `str[i]` te donne le i-ème caractère.

!!! note "À retenir"
    Tu peux passer directement un littéral à une fonction : `ft_putstr("Hello\n")`. C'est le pattern courant en piscine. **Ce que tu ne peux pas**, à la Norm, c'est déclarer une chaîne localement avec `char str[] = "Hello";`.

### 4. Parcourir une chaîne : la boucle « jusqu'au `\0` »

Tu ne connais pas la longueur d'une chaîne à l'avance (sauf si tu la calcules). Mais grâce au `'\0'`, tu peux la parcourir avec un simple `while` :

```c
i = 0;
while (str[i] != '\0')
{
	/* traiter str[i] */
	i++;
}
```

C'est le pattern le plus utilisé en C dès qu'on touche aux chaînes. Mémorise-le.

---

## E. `ft_strlen` — calculer la longueur d'une chaîne

La longueur d'une chaîne, c'est le **nombre de caractères avant** le `'\0'` (le `'\0'` lui-même n'est pas compté).

```c
int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}
```

C'est l'exemple `ex03_ft_strlen.c`. Trace pour `"Hi"` :

- `i = 0`, `str[0] = 'H'`, pas `'\0'` → `i = 1`.
- `i = 1`, `str[1] = 'i'`, pas `'\0'` → `i = 2`.
- `i = 2`, `str[2] = '\0'`, on sort.
- Retour : `2`.

Cas particulier : `ft_strlen("")` retourne `0` (la chaîne vide n'a aucun caractère avant son `'\0'`).

!!! tip "Astuce"
    Une chaîne **vide** `""` n'est pas la même chose qu'une chaîne **non initialisée**. La chaîne vide existe et fait 1 octet (juste le `'\0'`). Une variable non initialisée pointe vers n'importe quoi — c'est un bug.

---

## F. `ft_putstr` — afficher une chaîne

```c
void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		ft_putchar(str[i]);
		i++;
	}
}
```

C'est l'exemple `ex04_ft_putstr.c`. Une fois que tu as `ft_putstr`, tu peux remplacer plein de `ft_putchar` consécutifs par un seul appel :

❌ **Avant** :
```c
ft_putchar('B');
ft_putchar('o');
ft_putchar('n');
ft_putchar('j');
ft_putchar('o');
ft_putchar('u');
ft_putchar('r');
```

✅ **Avec `ft_putstr`** :
```c
ft_putstr("Bonjour");
```

C'est exactement le genre d'outil qu'on construit progressivement en piscine pour avoir une boîte à outils personnelle (la fameuse **libft**).

---

## G. Tableaux à 2 dimensions (mention)

Tu peux aussi avoir des tableaux à 2 dimensions, comme une **grille** :

```c
int	grille[3][3];

grille[0][0] = 1;
grille[0][1] = 2;
/* etc. */
```

Indexation : `grille[ligne][colonne]`. Très utile pour représenter des matrices, des plateaux de jeu (échecs, démineur), des images.

On ne fera pas d'exercice là-dessus en Séquence 1, mais sache que ça existe.

---

## H. Pièges classiques

### 1. Dépassement d'indice

```c
int	tab[5];

tab[5] = 999;       /* OUT OF BOUNDS — comportement indéfini */
```

Le compilateur **ne vérifie pas** que l'indice est valide. Ton programme peut tourner « normalement » et corrompre une autre variable, ou planter avec un **segmentation fault**, ou pire : tourner correctement aujourd'hui et bugger demain. C'est l'une des causes principales de bugs en C.

**Règle :** quand tu écris `tab[i]`, demande-toi : « Est-ce que `i` est garanti d'être entre `0` et `taille - 1` ? »

### 2. Modification d'une chaîne littérale

```c
char	*str;

str = "Hello";
str[0] = 'J';       /* COMPORTEMENT INDÉFINI — souvent : segfault */
```

Les littéraux de chaîne (`"Hello"`) sont stockés dans une zone mémoire **en lecture seule**. Essayer d'y écrire crashe le programme.

Si tu veux pouvoir modifier ta chaîne, tu dois la **copier** dans un tableau modifiable :

```c
char	str[6];

str[0] = 'H';
str[1] = 'e';
str[2] = 'l';
str[3] = 'l';
str[4] = 'o';
str[5] = '\0';
str[0] = 'J';       /* OK : str est un tableau, pas un littéral */
```

### 3. Oublier le `'\0'`

Si tu construis une chaîne caractère par caractère sans mettre le `'\0'` final, tes fonctions qui parcourent la chaîne (comme `ft_strlen`) vont continuer à lire au-delà du tableau jusqu'à tomber par hasard sur un `'\0'` en mémoire. Résultat : longueur incorrecte, affichage de caractères aléatoires, crash.

**Règle :** quand tu écris dans un tableau de char pour en faire une chaîne, **n'oublie jamais** d'écrire `'\0'` à la fin.

### 4. La taille passée en paramètre

Tu te demandes peut-être : « Comment `ft_strlen` sait-il quand s'arrêter, si je ne lui passe pas la taille ? »

Réponse : grâce au `'\0'`. C'est la **différence fondamentale** entre une chaîne et un tableau d'entiers.

```c
int	ft_somme_tab(int *tab, int taille)
{
	/* on DOIT passer la taille pour un tableau d'int : */
	/* il n'y a pas de "fin de tableau" naturelle. */
}
```

Pour les tableaux d'`int`, la convention est de passer la taille en paramètre. Pour les chaînes, le `'\0'` suffit.

---

## Bilan

À la fin de ce support, tu sais :

- Déclarer un tableau d'entiers ou de caractères : `int tab[N];`.
- Comprendre que l'indexation va de `0` à `N-1`.
- Parcourir un tableau avec `while` et le compteur `i`.
- Comprendre qu'une chaîne C est un tableau de `char` terminé par `'\0'`.
- Passer une chaîne à une fonction avec `char *str`.
- Parcourir une chaîne avec la boucle `while (str[i] != '\0')`.
- Écrire `ft_strlen` et `ft_putstr` de mémoire.
- Éviter les pièges : dépassement d'indice, modification de littéral, oubli du `'\0'`.

## Pour aller plus loin

- Page de manuel `man 3 strlen` (la version libc).
- Les fonctions à reproduire pour la libft : `ft_strcpy`, `ft_strcmp`, `ft_strcat`, `ft_strstr`. Tu auras tout l'outillage nécessaire dès la fin du Support 09.

---

➡️ **Exercices du support :** [voir la page exercices](./exercices.md)
➡️ **Support suivant :** [Support 09 — Pointeurs (initiation)](../support-09/cours.md)
