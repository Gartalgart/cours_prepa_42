# Support 06 — Boucles

> **Prérequis :** [Support 05 — Conditions](../support-05/cours.md)
> **Objectif :** À la fin de ce support, tu sauras utiliser des boucles `while` pour répéter du code, parcourir des plages de valeurs, et résoudre des problèmes algorithmiques qui demandent de la répétition.

---

## A. Pourquoi des boucles ?

Jusqu'ici, pour afficher 10 caractères, tu écrivais 10 lignes de `ft_putchar`. Pour afficher 1000 caractères, ça deviendrait absurde.

Une **boucle** permet de répéter un bloc de code **tant qu'une condition reste vraie**. Trois exemples typiques :

- Afficher l'alphabet de `'a'` à `'z'` : 26 répétitions.
- Calculer la somme des nombres de 1 à 100 : 100 répétitions.
- Lire une chaîne caractère par caractère jusqu'au `'\0'` : nombre inconnu d'avance.

Sans boucle, ces problèmes seraient impossibles à résoudre proprement.

---

## B. À 42, on n'utilise **que** `while`

Le langage C offre trois types de boucles :

- `while` — boucle « tant que ».
- `do { ... } while` — boucle « répète au moins une fois ».
- `for` — boucle compacte avec compteur intégré.

À 42, **seul `while` est autorisé**. La `norminette` rejette `for` (`FORBIDDEN_CS`) et `do…while` également.

!!! warning "À retenir absolument"
    **Tout au long de la piscine et du tronc commun 42, tu n'écris jamais `for` ni `do…while`.** Tu vas les voir partout dans du code C extérieur, mais à 42 c'est `while` exclusivement.

    On en parlera quand même à la section F pour que tu saches les **lire** quand tu les croises.

---

## C. La boucle `while`

### 1. Syntaxe

```c
while (condition)
{
	/* code répété tant que la condition est vraie */
}
```

Le déroulement est simple :

1. La `condition` est évaluée.
2. Si elle est **vraie** (non nulle), le bloc s'exécute.
3. À la fin du bloc, on revient à l'étape 1.
4. Quand la condition devient **fausse** (zéro), on sort de la boucle et on continue le code qui suit.

### 2. Premier exemple : afficher 1 à 9

```c
int	i;

i = 1;
while (i <= 9)
{
	ft_putchar('0' + i);
	i++;
}
ft_putchar('\n');
```

Sortie : `123456789`.

C'est l'exemple `ex01_while_basique.c`. Décortiquons :

- `i = 1` : on initialise notre **compteur** à 1.
- `while (i <= 9)` : on continue tant que `i` est inférieur ou égal à 9.
- Dans le bloc : on affiche le caractère correspondant, puis on **incrémente** `i`.
- Quand `i` devient 10, la condition `i <= 9` est fausse, on sort.

### 3. Le trio essentiel d'une boucle bien faite

Toute boucle `while` propre repose sur trois ingrédients :

| Ingrédient | Rôle |
|---|---|
| **Initialisation** | Mettre la variable de boucle dans son état de départ (`i = 1`). Faite **avant** le `while`. |
| **Condition de continuation** | Quand la boucle doit-elle s'arrêter ? Évaluée à chaque itération. |
| **Mise à jour** | Modifier la variable pour faire avancer la boucle (`i++`). Sans ça, **boucle infinie**. |

Oublie l'un des trois, et ton code ne fait pas ce que tu veux. La mise à jour est l'oubli le plus fréquent.

### 4. Style Norm 42

Identique au `if` : style **Allman**, accolades **obligatoires** dans le bon style.

```c
while (i < 10)
{
	/* corps */
}
```

❌ Rejeté par `norminette` :
```c
while (i < 10) {      /* accolade sur la même ligne */
	/* corps */
}
```

---

## D. Patterns classiques avec `while`

Voici les schémas que tu vas rencontrer **constamment** en piscine. Mémorise-les.

### 1. Parcourir une plage de nombres

```c
int	i;

i = 0;
while (i < N)
{
	/* traiter i */
	i++;
}
```

Démarre à `0`, va jusqu'à `N-1` (exclu `N`). C'est l'indexation standard en informatique.

### 2. Parcourir une plage de caractères

```c
char	c;

c = 'a';
while (c <= 'z')
{
	ft_putchar(c);
	c++;
}
```

C'est l'exemple `ex02_alphabet.c`. Le `char` est un nombre, on peut donc l'incrémenter comme un `int`.

### 3. Compter à rebours

```c
int	i;

i = 10;
while (i > 0)
{
	/* traiter i */
	i--;
}
```

### 4. Accumuler une somme

```c
int	i;
int	somme;

i = 1;
somme = 0;
while (i <= 100)
{
	somme = somme + i;
	i++;
}
/* somme contient 1+2+...+100 = 5050 */
```

### 5. Boucle « jusqu'à un certain état »

Quand tu ne connais pas le nombre d'itérations à l'avance :

```c
while (c != '\0')       /* parcourir une chaîne jusqu'à la fin */
{
	/* ... */
}
```

Tu vas voir ce pattern **partout** dès qu'on parlera de chaînes au Support 08.

---

## E. Boucles imbriquées

Une boucle peut contenir une autre boucle. C'est très puissant : tu peux parcourir des **grilles**, générer des **tableaux 2D**, créer des **patterns**.

### Exemple : grille 3×3 de `X`

```c
int	i;
int	j;

i = 0;
while (i < 3)
{
	j = 0;
	while (j < 3)
	{
		ft_putchar('X');
		j++;
	}
	ft_putchar('\n');
	i++;
}
```

Sortie :

```
XXX
XXX
XXX
```

C'est l'exemple `ex03_boucles_imbriquees.c`.

!!! tip "À retenir"
    - La boucle externe (`i`) gère les **lignes**.
    - La boucle interne (`j`) gère les **colonnes**.
    - **`j` est réinitialisée à `0` à chaque itération externe** : c'est facile à oublier et c'est un bug classique.

### Conventions de nommage

En programmation, les compteurs imbriqués s'appellent traditionnellement :

- Boucle externe : `i` (de l'anglais *index*).
- Boucle interne : `j`.
- Si une troisième : `k`.

Au-delà de 3 niveaux, tu devrais probablement repenser ton algorithme.

---

## F. `break` et `continue`

Deux instructions modifient le flux d'une boucle.

### 1. `break` : sortir de la boucle

`break` interrompt **immédiatement** la boucle, peu importe la condition. Le code passe directement à l'instruction qui suit le `while`.

```c
while (i < 100)
{
	if (i == 42)
	{
		break ;     /* on sort dès qu'on trouve 42 */
	}
	i++;
}
```

### 2. `continue` : passer à l'itération suivante

`continue` saute le reste du bloc et revient à l'évaluation de la condition. **Attention** : si tu utilises `continue`, assure-toi que la variable de boucle est mise à jour **avant** le `continue`, sinon boucle infinie.

```c
while (i < 10)
{
	if (i % 2 == 0)
	{
		i++;
		continue ;          /* saute les nombres pairs */
	}
	ft_putchar('0' + i);
	i++;
}
/* affiche : 13579 */
```

### 3. Exemple combiné

C'est l'exemple `ex04_break_continue.c` :

```c
int	i;

i = 0;
while (i < 10)
{
	if (i == 7)
	{
		break ;
	}
	if (i == 3)
	{
		i++;
		continue ;
	}
	ft_putchar('0' + i);
	i++;
}
```

Sortie : `012456`.

- `0`, `1`, `2` : affichés normalement.
- `3` : skipé par `continue` (mais `i` est bien incrémenté avant).
- `4`, `5`, `6` : affichés.
- `7` : `break` → on sort de la boucle.

!!! note "Norm 42 — espace avant `;`"
    Tu remarques `break ;` et `continue ;` avec **un espace avant le point-virgule**. C'est ce que `norminette` attend (le `;` est sur sa propre « unité » quand l'instruction est seule). Pour les autres instructions (`i++;`, `return (0);`), pas d'espace : juste le `;` collé.

---

## G. Les boucles interdites à 42 (pour ta culture)

### 1. La boucle `for`

```c
for (i = 0; i < 10; i++)
{
	ft_putchar('0' + i);
}
```

`for` regroupe en une ligne l'initialisation, la condition, et la mise à jour. C'est plus concis qu'un `while` équivalent.

**Équivalent en `while` (à utiliser à 42) :**

```c
i = 0;
while (i < 10)
{
	ft_putchar('0' + i);
	i++;
}
```

### 2. La boucle `do…while`

```c
do
{
	/* code exécuté AU MOINS une fois */
	i++;
} while (i < 10);
```

`do…while` garantit au moins une exécution du corps, même si la condition est fausse dès le départ.

**Équivalent en `while` :**

```c
i = 0;
while (1)               /* boucle « infinie » contrôlée par break */
{
	/* corps */
	i++;
	if (!(i < 10))
	{
		break ;
	}
}
```

Pas joli, mais c'est la seule manière de simuler `do…while` à 42. Heureusement, le besoin de `do…while` est rare.

---

## H. Pièges classiques

### 1. La boucle infinie

```c
int	i;

i = 0;
while (i < 10)
{
	ft_putchar('0' + i);
	/* OUPS : pas de i++ */
}
```

Tu affiches `0` à l'infini. Le terminal se remplit, ton processeur chauffe, tu tapes `Ctrl-C` pour arrêter.

**Règle :** chaque boucle `while` doit avoir une **garantie de progression**. Si la variable de boucle ne change jamais, c'est suspect.

### 2. L'erreur off-by-one

```c
i = 1;
while (i <= 10)
{
	/* itère 10 fois : i = 1, 2, ..., 10 */
}

i = 0;
while (i < 10)
{
	/* itère 10 fois : i = 0, 1, ..., 9 */
}

i = 0;
while (i <= 10)
{
	/* itère 11 fois : i = 0, 1, ..., 10 — souvent une erreur ! */
}
```

L'« off-by-one error » est l'erreur la plus fréquente en informatique. Sois précis sur ta condition : `<` ou `<=` selon ce que tu veux.

### 3. Modifier la mauvaise variable

```c
i = 0;
while (i < 10)
{
	j++;            /* OUPS : j, pas i */
}
```

Classique des boucles imbriquées : tu incrémentes la mauvaise variable et la boucle tourne à vide.

---

## Bilan

À la fin de ce support, tu sais :

- Écrire une boucle `while` aux normes 42 (style Allman, accolades).
- Identifier les **trois ingrédients** d'une boucle propre : initialisation, condition, mise à jour.
- Parcourir une plage de nombres ou de caractères.
- Compter à rebours.
- Accumuler une somme dans un compteur.
- Imbriquer des boucles pour parcourir des grilles 2D.
- Utiliser `break` pour sortir, et `continue` pour sauter une itération.
- Reconnaître `for` et `do…while` dans du code et savoir qu'ils sont **interdits à 42**.
- Éviter les pièges : boucle infinie, off-by-one, modification de la mauvaise variable.

## Pour aller plus loin

- Article Wikipédia *Off-by-one error* — pour comprendre pourquoi cette erreur est si fréquente.
- Le « gotcha » de Dijkstra : il préférait l'indexation `0` à `N-1` (avec `<`) pour des raisons mathématiques précises. Tu sais maintenant pourquoi.

---

➡️ **Exercices du support :** [voir la page exercices](./exercices.md)
➡️ **Support suivant :** [Support 07 — Fonctions](../support-07/cours.md)
