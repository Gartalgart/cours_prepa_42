# Support 05 — Conditions

> **Prérequis :** [Support 04 — Opérateurs](../support-04/cours.md)
> **Objectif :** À la fin de ce support, tu sauras faire prendre des décisions à ton programme avec `if`, `else if`, `else`, et tu connaîtras les pièges classiques liés aux conditions.

---

## A. Pourquoi conditionner du code ?

Jusqu'ici, tes programmes exécutent **toutes** leurs instructions, dans l'ordre, sans exception. Mais en pratique, un programme utile fait des choix :

- Si l'utilisateur a tapé `oui`, fais ceci, sinon fais cela.
- Si le diviseur est nul, ne divise pas — affiche une erreur.
- Si le caractère est une lettre, traite-le comme tel, sinon ignore-le.

C'est le rôle des **structures conditionnelles**. Tu connais déjà toute la logique côté opérateurs (Support 04 : `==`, `&&`, `||`, etc.). Il ne te manque qu'une syntaxe pour les utiliser : c'est `if`.

---

## B. La syntaxe `if`

### 1. Forme générale

```c
if (condition)
{
	/* code exécuté si la condition est vraie */
}
```

Si la `condition` est **vraie** (toute valeur **non nulle**), le bloc `{ ... }` est exécuté. Sinon, il est **sauté**.

```c
int	n;

n = 5;
if (n > 0)
{
	ft_putchar('P');
}
/* Si n est positif, on a affiché 'P'. Sinon, rien. */
```

### 2. La condition peut être n'importe quelle expression entière

`if` accepte **toute expression** qui renvoie un entier. Souviens-toi : `0` est faux, **tout le reste** est vrai.

```c
if (n)              /* vrai si n != 0 */
if (n == 0)         /* vrai si n vaut exactement 0 */
if (n > 0 && n < 10)/* vrai si n est entre 1 et 9 */
if (1)              /* toujours vrai */
if (0)              /* toujours faux (mais accepté à la compilation) */
```

### 3. Les accolades sont (presque) toujours recommandées

Le C autorise un `if` sans accolades si une seule instruction suit :

```c
if (n > 0)
	ft_putchar('P');
```

La Norm 42 **accepte** cette syntaxe, mais **je te recommande fortement de toujours mettre des accolades**, même pour une seule instruction. Trois raisons :

- Plus facile à modifier sans introduire de bug (si tu ajoutes une 2e instruction, tu n'oublieras pas d'ajouter les accolades).
- Visuellement clair : tout ce qui dépend du `if` est délimité.
- C'est la convention adoptée par la majorité des projets professionnels.

### 4. Style d'accolades à la Norm 42

L'accolade ouvrante `{` doit être sur sa **propre ligne**, sous le `if` :

❌ **Refusé par `norminette`** :
```c
if (n > 0) {
	ft_putchar('P');
}
```

✅ **Accepté** :
```c
if (n > 0)
{
	ft_putchar('P');
}
```

C'est le style **Allman**, le même que pour les fonctions.

!!! note "À retenir"
    Toutes les structures de contrôle en C (`if`, `else`, `while`, `for`, `do…while`) suivent le même style d'accolades à la Norm 42.

---

## C. `if` / `else`

### 1. Forme

```c
if (condition)
{
	/* code si vrai */
}
else
{
	/* code si faux */
}
```

`else` s'exécute uniquement si la condition du `if` était fausse. **Au plus un des deux blocs** s'exécute, **jamais les deux**, **jamais aucun**.

### 2. Exemple : pair ou impair

```c
int	n;

n = 7;
if (n % 2 == 0)
{
	ft_putchar('P');    /* pair */
}
else
{
	ft_putchar('I');    /* impair */
}
```

Sortie : `I`.

C'est l'exemple `ex02_if_else.c`.

### 3. Le `else` se rattache au `if` **le plus proche**

Si tu imbriques des `if`/`else`, le `else` s'associe toujours au `if` non-apparié le plus proche. Cela peut surprendre :

```c
if (a > 0)
	if (b > 0)
		ft_putchar('X');
else                        /* ATTENTION : ce else est lié au IF de b, pas de a */
	ft_putchar('Y');
```

L'indentation est trompeuse. Avec des accolades, c'est clair :

```c
if (a > 0)
{
	if (b > 0)
	{
		ft_putchar('X');
	}
	else
	{
		ft_putchar('Y');
	}
}
```

**Encore une raison d'utiliser les accolades.**

---

## D. `if` / `else if` / `else`

### 1. Cascade de conditions

Quand tu as plus de deux cas, tu enchaînes avec `else if` :

```c
if (n > 0)
{
	ft_putchar('+');
}
else if (n < 0)
{
	ft_putchar('-');
}
else
{
	ft_putchar('0');
}
```

C'est l'exemple `ex03_else_if.c`.

### 2. Comment ça marche

Les conditions sont évaluées **dans l'ordre**, de haut en bas. Dès qu'une est vraie, son bloc s'exécute, et **toutes les autres sont sautées**. Le `else` final est exécuté **uniquement** si aucune des conditions précédentes n'était vraie.

Tu peux enchaîner autant de `else if` que tu veux :

```c
if (note >= 16)         { /* mention TB   */ }
else if (note >= 14)    { /* mention B    */ }
else if (note >= 12)    { /* mention AB   */ }
else if (note >= 10)    { /* admis        */ }
else                    { /* recalé       */ }
```

!!! tip "Astuce : ordre des conditions"
    Quand tu enchaînes des `else if`, vérifie bien que **chaque condition exclut les précédentes**. Ici on teste `>= 16` en premier, puis `>= 14`, etc. Si on inversait l'ordre (testant `>= 10` en premier), tout le monde serait « admis », même les `TB`.

### 3. Trois cas exclusifs : `if`, `else if`, `else`

Avec trois cas, n'écris jamais :

❌ **Maladroit** :
```c
if (n > 0)
	ft_putchar('+');
if (n < 0)
	ft_putchar('-');
if (n == 0)
	ft_putchar('0');
```

✅ **Mieux** :
```c
if (n > 0)
	ft_putchar('+');
else if (n < 0)
	ft_putchar('-');
else
	ft_putchar('0');
```

La version maladroite **fonctionne**, mais elle teste les trois conditions à chaque fois, même quand la première est déjà vraie. Avec `else if`, l'évaluation s'arrête dès qu'une condition est trouvée.

---

## E. Conditions composées avec `&&`, `||`, `!`

Tu peux combiner des conditions dans un `if` à l'aide des opérateurs logiques vus au Support 04.

### 1. Tester une plage

```c
char	c;

c = 'k';
if (c >= 'a' && c <= 'z')
{
	/* c est une minuscule */
}
```

C'est l'idiome universel pour tester si un caractère est dans une plage. Tu vas l'utiliser **partout** en piscine.

### 2. Tester plusieurs cas distincts

```c
if (c == ' ' || c == '\t' || c == '\n')
{
	/* c est un espace blanc */
}
```

### 3. Nier une condition

```c
if (!(n > 0))
{
	/* n n'est PAS positif (donc négatif ou nul) */
}
```

Équivalent (souvent plus lisible) :

```c
if (n <= 0)
{
	/* n n'est PAS positif (donc négatif ou nul) */
}
```

Préfère la forme la plus lisible. La double négation (`!(!x)`) est généralement à éviter.

---

## F. L'opérateur ternaire `? :` — **INTERDIT À 42**

### 1. Ce que c'est (en C standard)

Le C a une syntaxe condensée pour les conditions qui produisent une valeur : l'**opérateur ternaire**.

```c
max = (a > b) ? a : b;
```

Cette ligne signifie « si `a > b`, alors `max = a`, sinon `max = b` ». Elle est équivalente à :

```c
if (a > b)
{
	max = a;
}
else
{
	max = b;
}
```

### 2. Pourquoi je t'en parle quand même

Tu **vas** rencontrer l'opérateur ternaire dans du code C qui traîne sur Internet, dans des bibliothèques système, dans des projets perso. Il faut que tu sois capable de **le lire** quand tu le croises.

### 3. Pourquoi tu ne l'utiliseras jamais à 42

`norminette` rejette l'opérateur ternaire avec l'erreur `TERNARY_FBIDDEN`. La raison officieuse : il rend le code moins lisible que la forme `if`/`else` équivalente. La raison officielle : c'est la règle.

!!! warning "À retenir"
    **À 42, tu écris toujours des `if`/`else`, jamais de ternaire.** Si tu en utilises un seul, `norminette` refuse ton fichier entier et le projet est noté zéro.

---

## G. Pièges classiques

### 1. `=` au lieu de `==`

C'est l'erreur n° 1 en C. On l'a déjà vue au Support 04 :

```c
if (n = 0)          /* AFFECTE 0 à n, condition toujours fausse */
if (n == 0)         /* COMPARE n et 0 */
```

À la Norm 42, **les affectations dans une condition sont interdites**, ce qui t'oblige à corriger cette erreur.

### 2. Conditions toujours vraies / toujours fausses

Le compilateur ne détecte pas toujours les conditions absurdes :

```c
if (n > 0 || n < 0 || n == 0)
{
	/* TOUJOURS vrai (sauf overflow exotique) — sert à rien */
}

unsigned int	u;

u = 5;
if (u < 0)
{
	/* JAMAIS vrai : un unsigned ne peut pas être négatif */
}
```

Relis tes conditions et demande-toi : « Existe-t-il une valeur qui rendrait cette condition fausse (ou vraie) ? »

### 3. Oublier le `else`

Quand tu enchaînes plusieurs `if` sans `else`, **tous** sont évalués indépendamment. Ce n'est pas toujours ce que tu veux.

```c
if (note >= 10)
{
	ft_putchar('A');    /* admis */
}
if (note < 10)
{
	ft_putchar('R');    /* recalé */
}
```

Ici, ça marche par chance (les deux conditions s'excluent). Mais c'est plus risqué et moins efficace que :

```c
if (note >= 10)
{
	ft_putchar('A');
}
else
{
	ft_putchar('R');
}
```

---

## Bilan

À la fin de ce support, tu sais :

- Écrire un `if (condition) { ... }` aux normes 42 (style Allman, accolades systématiques recommandées).
- Ajouter un `else` pour le cas inverse.
- Enchaîner plusieurs cas avec `else if`.
- Combiner des conditions avec `&& || !`.
- Tester si un caractère est dans une plage (`c >= 'a' && c <= 'z'`).
- Reconnaître l'opérateur ternaire `? :` quand tu le vois, et savoir qu'il est **interdit à 42**.
- Éviter les trois pièges classiques : `=` au lieu de `==`, conditions toujours vraies/fausses, oubli du `else`.

## Pour aller plus loin

- L'instruction `switch` du C : une alternative à `else if` quand on teste la même variable contre plusieurs valeurs. La Norm 42 l'**autorise** sous conditions (`break` obligatoire, structure stricte). On en reparlera plus tard.

---

➡️ **Exercices du support :** [voir la page exercices](./exercices.md)
➡️ **Support suivant :** [Support 06 — Boucles](../support-06/cours.md)
