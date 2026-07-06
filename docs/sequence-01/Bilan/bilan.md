# Bilan de la Séquence 1 — Bases du C aux normes 42

> **Prérequis :** [Support 09 — Pointeurs (initiation)](../support-09/cours.md)
> **Objectif :** Faire le point sur tout ce que tu as appris dans la Séquence 1, et le mettre en pratique avec un **mini-projet de synthèse** : `ft_atoi`.

---

## A. Ce que tu sais maintenant

Si tu as travaillé tous les supports avec sérieux, tu sais :

### Concepts fondamentaux

- **Compiler et exécuter** un programme C : `cc -Wall -Wextra -Werror fichier.c -o prog && ./prog`.
- **Valider la Norm 42** avec `norminette fichier.c`.
- Écrire un fichier C complet avec son **en-tête 42**, son `#include <unistd.h>`, sa fonction `main`.

### Types et variables

- Les types entiers : `char` (1 octet), `int` (4 octets), `unsigned int`.
- Les **5 ingrédients de l'ASCII** : `'0'`=48, `'A'`=65, `'a'`=97, `'\n'`=10, `'\0'`=0.
- L'astuce **`± 32`** pour convertir majuscules/minuscules.
- Le **débordement** des entiers (`INT_MAX + 1` → `INT_MIN`).

### Opérateurs

- Arithmétiques : `+ - * / %` (et la **division entière** des `int`).
- Comparaison : `== != < > <= >=` (renvoient `0` ou `1`).
- Logiques : `&& || !` (avec **évaluation court-circuit**).
- **Priorité** : utilise des parenthèses dès que le code devient long.

### Structures de contrôle

- `if` / `else if` / `else` (style Allman obligatoire).
- `while` — **seule boucle autorisée à 42** (`for` et `do…while` interdits).
- `break` et `continue` pour modifier le flux.
- **Ternaire `? :` interdit** par la Norm.

### Fonctions

- Déclaration, prototype, paramètres, valeur de retour.
- Limites Norm : 25 lignes max, 4 paramètres max, 5 variables locales max.
- Préfixe **`ft_`** sur toutes tes fonctions sauf `main`.
- **Récursivité** : cas de base + appel convergent.

### Tableaux et chaînes

- Déclaration `int tab[N]`, indexation de `0` à `N-1`.
- Une chaîne = un tableau de `char` terminé par `'\0'`.
- Parcours avec `while (str[i] != '\0')`.
- **Pas d'initialisation à la déclaration** (sauf `static`).

### Pointeurs

- `&x` donne l'**adresse** d'une variable.
- `int *p` déclare un **pointeur** vers un `int`.
- `*p` est la **valeur** à l'adresse pointée.
- Modifier `*p` modifie la variable pointée.
- Équivalence `tab[i]` ↔ `*(tab + i)`.

### Boîte à outils maison

Tu as écrit (et peux réécrire de mémoire) :

- `ft_putchar(char c)` — afficher un caractère.
- `ft_putstr(char *str)` — afficher une chaîne.
- `ft_putnbr(int n)` — afficher un entier (avec gestion `INT_MIN`).
- `ft_strlen(char *str)` — longueur d'une chaîne.
- `ft_strcpy(char *dest, char *src)` — copier une chaîne.
- `ft_strcmp(char *s1, char *s2)` — comparer deux chaînes.
- `ft_swap(int *a, int *b)` — échanger deux variables.

C'est l'embryon de ce qui deviendra ta **libft** en piscine.

---

## B. Antisèche Norm 42 — règles découvertes

Synthèse de toutes les règles `norminette` rencontrées au fil des supports :

| # | Règle | Détail |
|---|---|---|
| 1 | **En-tête 42 obligatoire** | 11 lignes générées par le plugin d'éditeur. |
| 2 | **Tabulations, pas d'espaces** | Pour toute indentation. `expandtab` interdit dans vim. |
| 3 | **80 colonnes max** | Par ligne. |
| 4 | **Style Allman** | Accolade `{` sur sa propre ligne, en colonne 0. |
| 5 | **Déclarations en haut** | Toutes les variables locales en début de fonction. |
| 6 | **Une variable par ligne** | Pas de `int a, b, c;`. |
| 7 | **Pas d'init à la déclaration** | `int x = 5;` interdit (sauf `static`). |
| 8 | **Alignement des déclarations** | Noms alignés via tabulations entre les types. |
| 9 | **Ligne vide entre décl. et code** | Une seule ligne vide. |
| 10 | **`int<TAB>nom`** entre type et nom | Tabulation, pas espace. |
| 11 | **`return (val);`** | Parenthèses obligatoires. |
| 12 | **Max 25 lignes par fonction** | Corps entre `{` et `}`. |
| 13 | **Max 4 paramètres** | Par fonction. |
| 14 | **Max 5 variables locales** | Par fonction. |
| 15 | **`for` interdit** | `FORBIDDEN_CS`. Utilise `while`. |
| 16 | **`do…while` interdit** | Non parsé par `norminette`. |
| 17 | **Ternaire `? :` interdit** | `TERNARY_FBIDDEN`. |
| 18 | **Affectation dans condition interdite** | `if (x = 5)` rejeté. |
| 19 | **`break ;` / `continue ;` solo** | Avec espace avant le `;`. |
| 20 | **`return ;` (sans valeur) solo** | Idem, espace avant `;`. |
| 21 | **Préfixe `ft_` sur tes fonctions** | Convention 42 (sauf `main`). |
| 22 | **Tabs strictement, pas printf** | `printf` interdit en piscine de base, utilise `write`. |

---

## C. Mini-projet de synthèse — `ft_atoi`

### 1. Présentation

`atoi` (*ASCII to integer*) est une fonction de la bibliothèque standard qui transforme une **chaîne de caractères** en l'**entier** qu'elle représente.

```c
ft_atoi("42")        ->  42
ft_atoi("-1234")     ->  -1234
ft_atoi("   +99")    ->  99      (espaces ignorés, + ignoré, OK)
ft_atoi("99abc")     ->  99      (s'arrête au premier non-chiffre)
ft_atoi("bonjour")   ->  0       (pas de chiffres trouvés)
ft_atoi("0")         ->  0
```

C'est l'**exercice canonique** de fin de Séquence 1, parce qu'il utilise **presque tout** ce qu'on a vu :

- **Chaînes** et parcours avec un indice (Support 08).
- **Boucles `while`** pour les espaces et pour les chiffres (Support 06).
- **Conditions** pour le signe et le test « est-ce un chiffre ? » (Support 05).
- **Arithmétique ASCII** : `str[i] - '0'` (Supports 02 et 04).
- **Variables et types** : `int signe`, `int resultat` (Support 03).
- **Norm 42** sur toute la fonction (Supports transversaux).

### 2. Spécification détaillée

`ft_atoi(char *str)` doit :

1. **Sauter les espaces blancs** au début : `' '`, `'\t'`, `'\n'`.
2. Lire un **signe optionnel** : `'+'` ou `'-'`. S'il y en a un, l'enregistrer. Avancer d'un caractère.
3. Lire les **chiffres** un par un (`'0'` à `'9'`), en construisant le nombre.
4. **S'arrêter** au premier caractère non-chiffre.
5. **Retourner** le nombre avec son signe.

### 3. La solution de référence

Voici l'implémentation conforme aux normes 42 :

```c
int	ft_atoi(char *str)
{
	int	i;
	int	signe;
	int	resultat;

	i = 0;
	signe = 1;
	resultat = 0;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n')
	{
		i++;
	}
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
		{
			signe = -1;
		}
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		resultat = resultat * 10 + (str[i] - '0');
		i++;
	}
	return (resultat * signe);
}
```

Voir le fichier `ft_atoi.c` pour la version complète avec `main` de test.

### 4. Décortiquons

Trace pour `ft_atoi("   +99abc")` :

| Étape | `i` | `str[i]` | Action |
|---|---|---|---|
| Init | 0 | `' '` | `signe = 1`, `resultat = 0` |
| Espaces | 0→3 | espaces sautés | `i` passe à 3 |
| Signe | 3 | `'+'` | signe reste `1`, `i = 4` |
| Chiffre `'9'` | 4 | `'9'` | `resultat = 0*10 + 9 = 9`, `i = 5` |
| Chiffre `'9'` | 5 | `'9'` | `resultat = 9*10 + 9 = 99`, `i = 6` |
| Non-chiffre | 6 | `'a'` | On sort de la boucle |
| Retour | | | `return 99 * 1 = 99` |

### 5. Le piège du débordement

Notre version ne gère pas le **débordement** si la chaîne représente un nombre plus grand que `INT_MAX` (`2147483647`) ou plus petit que `INT_MIN` (`-2147483648`). Par exemple, `ft_atoi("99999999999")` produira un résultat absurde dû au débordement.

La vraie `atoi` de la libc n'a pas de comportement standard pour ces cas (elle peut retourner n'importe quoi). Notre version a le même défaut, et c'est **acceptable pour la piscine** — le sujet officiel précise généralement « comportement indéfini en cas de dépassement ».

---

## D. Bonus — Tri à bulles

### Présentation

Le **tri à bulles** (*bubble sort*) est l'algorithme de tri le plus simple à coder. Le principe : on parcourt le tableau plusieurs fois, et à chaque parcours on échange les paires d'éléments adjacents dans le mauvais ordre. Les grands éléments « remontent à la surface » comme des bulles.

C'est une synthèse parfaite des **Supports 08 (tableaux) et 09 (pointeurs avec `ft_swap`)**.

### Solution

```c
void	ft_tri_bulles(int *tab, int taille)
{
	int	i;
	int	j;

	i = 0;
	while (i < taille - 1)
	{
		j = 0;
		while (j < taille - 1 - i)
		{
			if (tab[j] > tab[j + 1])
			{
				ft_swap(&tab[j], &tab[j + 1]);
			}
			j++;
		}
		i++;
	}
}
```

Voir `tri_tableau.c` pour le programme complet.

Sortie attendue avec `tab = {5, 2, 8, 1, 9, 3, 4}` :

```
5281934    <- avant tri
1234589    <- après tri
```

### Pourquoi `taille - 1 - i` ?

À chaque passe `i`, on garantit que le plus grand élément non-trié « remonte » à la fin. Donc à la passe `i`, les `i` derniers éléments sont déjà à leur place — pas besoin de les recomparer. `taille - 1 - i` est l'indice maximal à comparer.

C'est une **micro-optimisation** classique du tri à bulles. Sans elle, l'algo marche aussi (juste un peu plus lent).

---

## E. Pour continuer

### 1. Réécris la libft

Toutes les fonctions que tu as construites au fil de la séquence forment une mini-libft. En piscine, tu en réécriras des dizaines d'autres :

- `ft_isalpha`, `ft_isdigit`, `ft_isalnum`, `ft_isascii` (tests sur caractères).
- `ft_toupper`, `ft_tolower` (conversions).
- `ft_strncmp`, `ft_strchr`, `ft_strrchr`, `ft_strstr` (chaînes).
- `ft_memcpy`, `ft_memset`, `ft_bzero` (mémoire).

Aucune ne dépasse les concepts de la Séquence 1.

### 2. Apprends ce qui n'a pas été vu

Pour aller plus loin (au-delà de la Séquence 1), il te faut :

- **Allocation dynamique** (`malloc`, `free`) — débloque `ft_strdup`, `ft_strjoin`, etc.
- **Compilation séparée** (Makefiles avancés, headers `.h`).
- **Structures** (`struct`) — pour organiser des données complexes.
- **Fichiers** (`open`, `read`, `close`) — pour lire et écrire.
- **`get_next_line`**, **`ft_printf`**, **`push_swap`** — les projets emblématiques de la piscine.

### 3. Pratique, pratique, pratique

La piscine 42 dure environ **4 semaines à plein temps**. Le meilleur conseil : **code chaque jour**. Refais les exercices, écris des variantes, casse ton code et répare-le. La fluidité technique vient avec la répétition.

---

## F. Validation finale de la Séquence 1

Si tu coches **tout** ce qui suit sans hésiter, tu es prêt pour la piscine.

- [ ] Tu peux installer ton environnement de zéro (WSL ou VM, gcc, vim, norminette, plugin 42header).
- [ ] Tu peux écrire `ft_putchar`, `ft_putstr`, `ft_putnbr` de mémoire.
- [ ] Tu peux écrire `ft_strlen`, `ft_strcpy`, `ft_strcmp` de mémoire.
- [ ] Tu peux écrire `ft_swap` et expliquer pourquoi ça marche.
- [ ] Tu peux écrire `ft_atoi` complète (avec espaces, signe, chiffres).
- [ ] Tu sais expliquer la différence entre `x`, `&x`, `*p`.
- [ ] Tu sais utiliser `norminette` et corriger ses erreurs courantes.
- [ ] Tu n'utilises **jamais** `for`, `do…while`, ternaire, `printf`.
- [ ] Tu mets toujours des accolades autour de tes blocs.
- [ ] Tu donnes des noms explicites à tes variables et tes fonctions.

---

## G. Mot de la fin

Tu as parcouru 10 supports + ce bilan. C'est l'équivalent du contenu de la **première semaine de piscine 42**.

Tu n'es pas encore prêt à entrer en piscine et tout cartonner — il te reste beaucoup à apprendre, surtout en **autonomie** et en **vitesse**. Mais tu as les fondations. Le reste se construira par-dessus, et chaque concept que tu rencontreras sera plus facile parce que tu sauras déjà comment les bases s'articulent.

Bonne continuation. Et n'oublie pas la règle d'or du C :

> **Ce qui n'est pas testé ne marche pas.**

À chaque fonction que tu écris, écris aussi son test. C'est le meilleur investissement de ton temps.

---

➡️ **Retour à l'accueil de la Séquence 1 :** [Séquence 1](../index.md)
➡️ **Séquence 2 (à venir) :** Allocation dynamique et structures.
