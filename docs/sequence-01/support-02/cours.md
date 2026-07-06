# Support 02 — Caractères et affichage

> **Prérequis :** [Support 01 — Premier programme](../support-01/cours.md)
> **Objectif :** À la fin de ce support, tu sauras manipuler des caractères en C, lire et utiliser la table ASCII, et tu auras écrit ta première fonction : `ft_putchar`.

---

## A. Le type `char`

### 1. Un caractère est un nombre

En C, un caractère n'est pas une entité magique : c'est juste un **petit nombre entier**. Le type qui le représente s'appelle `char`. Il occupe **1 octet** (8 bits) en mémoire, ce qui permet de stocker une valeur entre `-128` et `127` (ou `0` à `255` selon les machines).

À chaque caractère « visible » (lettre, chiffre, ponctuation, espace…) correspond un nombre unique défini par une convention universelle appelée la **table ASCII** (voir section B).

### 2. Déclarer une variable `char`

La syntaxe est simple :

```c
char	c;

c = 'A';
```

À la Norm 42, tu **dois** déclarer tes variables en **haut** de la fonction, sur des lignes séparées des affectations :

```c
int	main(void)
{
	char	c;

	c = 'A';
	/* ... reste du code ... */
}
```

!!! warning "À la Norm 42"
    - Déclaration **et** affectation sur la même ligne (`char c = 'A';`) est **interdit**.
    - Une déclaration par ligne, en haut de la fonction.
    - Une **ligne vide** sépare les déclarations du reste du code.

### 3. Apostrophes simples ou doubles ?

C'est un piège classique pour les débutants. La règle est stricte :

| Délimiteur | Type | Exemple |
|---|---|---|
| Apostrophes simples `' '` | **un seul caractère** (`char`) | `'A'`, `'\n'`, `'7'` |
| Guillemets doubles `" "` | **une chaîne de caractères** | `"A"`, `"Hello\n"` |

```c
char	c;
c = 'A';      /* OK : 'A' est un char */
c = "A";      /* ERREUR : "A" est une chaîne, pas un char */
```

!!! note "À retenir"
    - `'A'` = un caractère, occupe 1 octet, valeur = 65.
    - `"A"` = une chaîne de 2 caractères : le `A` et un caractère invisible de fin de chaîne (`\0`).
    - Les deux ne sont **pas** interchangeables.

---

## B. La table ASCII

### 1. Qu'est-ce que l'ASCII ?

**ASCII** (*American Standard Code for Information Interchange*) est la convention qui associe un nombre unique à chaque caractère de base. Elle date des années 1960 mais elle est toujours universellement utilisée : ton fichier `.c`, ton terminal, ton compilateur, tout parle ASCII.

Quand tu écris `'A'` dans ton code, le compilateur le remplace par le nombre `65`. Pour la machine, `'A'` et `65` sont **rigoureusement identiques**.

### 2. Les codes ASCII essentiels à connaître

Tu n'as pas à apprendre la table par cœur, mais ces repères doivent devenir des réflexes :

| Caractère | Code ASCII | Remarque |
|---|---|---|
| `'\0'` | 0 | **Fin de chaîne** (caractère nul) |
| `'\n'` | 10 | Saut de ligne |
| `'\t'` | 9 | Tabulation |
| `' '` (espace) | 32 | |
| `'0'` à `'9'` | 48 à 57 | Les chiffres |
| `'A'` à `'Z'` | 65 à 90 | Majuscules |
| `'a'` à `'z'` | 97 à 122 | Minuscules |

### 3. Conséquence : tu peux faire de l'arithmétique sur les caractères

Comme un `char` est un nombre, tu peux additionner, soustraire, comparer :

```c
char	c;

c = 'A';
c = c + 1;          /* c vaut maintenant 'B' (66) */

c = 'a' - 32;       /* c vaut 'A' : conversion minuscule -> majuscule */
```

!!! tip "Astuce piscine"
    L'écart entre une majuscule et sa minuscule correspondante est **toujours 32** (`'a' - 'A' == 32`). Beaucoup d'exercices de la piscine utilisent ce fait. Mémorise-le.

### 4. Afficher un caractère via son code

L'exemple `ex02_codes_ascii.c` montre comment afficher `ABC\n` en utilisant uniquement des nombres :

```c
char	c;

c = 65;          /* 'A' */
write(1, &c, 1);
c = 66;          /* 'B' */
write(1, &c, 1);
c = 67;          /* 'C' */
write(1, &c, 1);
c = 10;          /* '\n' */
write(1, &c, 1);
```

Sortie : `ABC` suivi d'un retour à la ligne.

---

## C. Afficher un caractère avec `write`

### 1. `write` veut une **adresse**, pas une **valeur**

Souviens-toi de la signature de `write` :

```c
write(1, "Hello\n", 6);
```

Le deuxième argument est ce que `write` doit lire en mémoire. Une chaîne (`"Hello\n"`) est un **tableau de caractères** : son nom désigne déjà une adresse mémoire. Aucun problème.

Mais une variable simple comme `char c;` ne désigne **pas** une adresse, elle désigne une **valeur**. Pour passer son adresse à `write`, il faut utiliser l'opérateur `&`.

### 2. L'opérateur `&`

`&` se lit « adresse de ». Devant un nom de variable, il renvoie l'emplacement mémoire où cette variable est stockée :

```c
char	c;

c = 'X';
write(1, &c, 1);    /* "donne à write l'adresse de c, et lis 1 octet" */
```

!!! warning "Erreur fréquente"
    Si tu écris `write(1, c, 1);` (sans le `&`), le compilateur va interpréter la valeur de `c` (par exemple 88 pour `'X'`) comme une **adresse mémoire**. Tu vas accéder à l'octet 88 en mémoire, qui contient n'importe quoi. Avec `-Werror`, le compilateur refusera de compiler ce code. C'est l'une des protections du flag `-Werror`.

### 3. Pourquoi `1` et pas un autre nombre ?

Le troisième argument est le nombre d'octets à écrire. Un `char` fait **exactement 1 octet**, donc on passe `1`. Si tu mettais `2`, `write` lirait l'octet suivant en mémoire (n'importe quoi), et l'afficherait aussi.

---

## D. Écrire ta première fonction : `ft_putchar`

Répéter `write(1, &c, 1);` à chaque caractère, c'est lourd. Tu vas écrire une **fonction** qui fait ça pour toi : `ft_putchar`.

### 1. Anatomie d'une fonction

Une fonction en C, c'est un bloc de code nommé et réutilisable. Elle peut recevoir des **paramètres** et renvoyer une **valeur**.

```c
void	ft_putchar(char c)
{
	write(1, &c, 1);
}
```

Décomposons :

| Élément | Signification |
|---|---|
| `void` | **Type de retour** : `void` veut dire « cette fonction ne renvoie rien ». |
| `ft_putchar` | **Nom** de la fonction. |
| `(char c)` | **Paramètre** : la fonction reçoit un `char` qu'elle appelle `c` en interne. |
| `{ ... }` | Le **corps** de la fonction, ce qu'elle exécute. |

### 2. Comment l'appeler

Une fois la fonction définie, tu peux l'utiliser n'importe où dans le même fichier (après sa définition) :

```c
int	main(void)
{
	ft_putchar('H');
	ft_putchar('e');
	ft_putchar('l');
	ft_putchar('l');
	ft_putchar('o');
	ft_putchar('\n');
	return (0);
}
```

Sortie : `Hello`.

C'est nettement plus lisible que d'écrire 6 fois `write(1, &c, 1);` avec 6 affectations différentes de `c`.

### 3. Pourquoi le préfixe `ft_` ?

À 42, **toutes** les fonctions que tu écris doivent commencer par `ft_` (« forty-two »). C'est une convention qui sert deux objectifs :

- **Éviter les conflits** avec les fonctions de la bibliothèque standard (`putchar`, `printf`, `strlen`…). Tu sais immédiatement, en lisant un nom, si c'est une fonction de la libc ou une fonction maison.
- **Identifier ton code** dans les projets collectifs.

!!! note "À retenir"
    `ft_putchar` n'est pas la même fonction que `putchar` (de la bibliothèque standard). C'est ta version, écrite uniquement avec `write`, sans utiliser `stdio.h`.

### 4. Et `main` alors ? Pourquoi pas `ft_main` ?

Bonne question : `main` est une exception. Le système d'exploitation cherche **précisément** une fonction nommée `main` pour démarrer ton programme. Tu n'as pas le droit de la renommer.

---

## E. Les caractères d'échappement

### 1. Pourquoi l'échappement ?

Certains caractères ne peuvent pas être tapés directement dans une chaîne :

- Comment écrire un retour à la ligne dans le code source ?
- Comment écrire un guillemet `"` dans une chaîne délimitée par des guillemets ?
- Comment écrire un antislash, qui sert justement à introduire l'échappement ?

La réponse : la **syntaxe d'échappement**. On utilise un **antislash `\`** suivi d'un caractère pour représenter un caractère spécial.

### 2. Les principaux échappements

| Syntaxe | Caractère représenté | Code ASCII |
|---|---|---|
| `\n` | Saut de ligne | 10 |
| `\t` | Tabulation horizontale | 9 |
| `\r` | Retour chariot (rare aujourd'hui) | 13 |
| `\0` | Caractère nul (fin de chaîne) | 0 |
| `\\` | Un antislash `\` | 92 |
| `\'` | Une apostrophe `'` | 39 |
| `\"` | Un guillemet `"` | 34 |
| `\a` | Bip système (alerte) | 7 |

!!! tip "Combien d'octets ?"
    Chaque séquence d'échappement, malgré ses 2 caractères dans ton code source, représente **un seul caractère** en mémoire et compte pour **1 octet**.

    `"a\tb\n"` contient 4 caractères : `'a'`, `'\t'`, `'b'`, `'\n'`. Tu passes donc `4` à `write`, pas `6`.

### 3. Échapper dans une chaîne vs dans un caractère

La règle diffère un peu entre chaîne (`"..."`) et caractère (`'...'`) :

| Caractère | Dans `'...'` (char) | Dans `"..."` (chaîne) |
|---|---|---|
| Antislash | `'\\'` | `"\\"` |
| Guillemet | `'"'` ou `'\"'` | `"\""` (obligatoire) |
| Apostrophe | `'\''` (obligatoire) | `"'"` ou `"\'"` |

Autrement dit : tu échappes uniquement le délimiteur qui pose problème. Dans une chaîne, c'est le `"` ; dans un char, c'est le `'`. L'antislash, lui, doit toujours être échappé partout.

### 4. Caractères non imprimables

Certains caractères existent mais ne « s'affichent » pas visiblement. Ils contrôlent l'affichage :

- `\n` ne **dessine** rien, il **demande** au terminal de passer à la ligne.
- `\t` n'est pas N espaces : c'est un caractère unique qui demande au terminal d'aller à la prochaine **tabulation** (généralement multiple de 8 colonnes).
- `\0` est invisible et a une fonction spéciale : il marque la **fin d'une chaîne** (on verra ça en détail au Support 08).

---

## Bilan

À la fin de ce support, tu sais :

- Déclarer et utiliser une variable de type `char`.
- Distinguer apostrophes (`'A'` = un caractère) et guillemets (`"A"` = une chaîne).
- Lire et utiliser la table ASCII : les chiffres `'0'`–`'9'`, les majuscules `'A'`–`'Z'`, les minuscules `'a'`–`'z'`.
- Comprendre qu'un `char` est un nombre entier et faire de l'arithmétique dessus.
- Afficher un caractère avec `write(1, &c, 1)` et expliquer le rôle de `&`.
- Écrire et appeler une fonction simple : **`ft_putchar`**.
- Utiliser les caractères d'échappement (`\n`, `\t`, `\\`, `\'`, `\"`, `\0`).

## Pour aller plus loin

- Table ASCII complète et interactive : [`man ascii`](https://man7.org/linux/man-pages/man7/ascii.7.html) dans ton terminal.
- Norme C99 (chapitre sur les caractères) : [open-std.org/JTC1/SC22/WG14](https://www.open-std.org/JTC1/SC22/WG14/).

---

➡️ **Exercices du support :** [voir la page exercices](./exercices.md)
➡️ **Support suivant :** [Support 03 — Variables et types](../support-03/cours.md)
