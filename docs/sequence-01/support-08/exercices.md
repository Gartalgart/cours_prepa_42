# Support 08 — Exercices

> **Objectif :** Manipuler des tableaux d'entiers, parcourir des chaînes, et écrire des fonctions utilitaires comme `ft_strlen` et `ft_putstr`.

Pour chaque exercice : compile avec `cc -Wall -Wextra -Werror`, valide avec `norminette`, vérifie la sortie.

---

## Partie 1 — Quiz

<div class="quiz-question" data-correct="1">
<p class="quiz-number">Question 1.1</p>
<p class="quiz-prompt">À partir de quel indice les éléments d'un tableau sont-ils numérotés en C ?</p>
<ul class="quiz-options">
  <li class="quiz-option"><span class="quiz-option-marker">A</span> 1</li>
  <li class="quiz-option"><span class="quiz-option-marker">B</span> 0</li>
  <li class="quiz-option"><span class="quiz-option-marker">C</span> -1</li>
  <li class="quiz-option"><span class="quiz-option-marker">D</span> Au choix du programmeur</li>
</ul>
<button class="quiz-check" disabled>Vérifier</button>
<div class="quiz-feedback quiz-feedback-correct" hidden>✅ Correct ! <strong>0</strong>. Si <code>int tab[5];</code>, les indices valides sont <code>0, 1, 2, 3, 4</code>. Accéder à <code>tab[5]</code> est une erreur (mais le compilateur ne te le dira pas).</div>
<div class="quiz-feedback quiz-feedback-incorrect" hidden>❌ Pas tout à fait. La bonne réponse est <strong>B — 0</strong>. En C, l'indexation commence toujours à 0.</div>
</div>

<div class="quiz-question" data-correct="1">
<p class="quiz-number">Question 1.2</p>
<p class="quiz-prompt">Que vaut <code>tab[2]</code> après ce code ?<br><br><code>tab[0] = 10; tab[1] = 20; tab[2] = 30;<br>tab[3] = 40; tab[4] = 50;<br>tab[2] = tab[0] + tab[4];</code></p>
<ul class="quiz-options">
  <li class="quiz-option"><span class="quiz-option-marker">A</span> <code>30</code></li>
  <li class="quiz-option"><span class="quiz-option-marker">B</span> <code>60</code></li>
  <li class="quiz-option"><span class="quiz-option-marker">C</span> <code>90</code></li>
  <li class="quiz-option"><span class="quiz-option-marker">D</span> <code>0</code></li>
</ul>
<button class="quiz-check" disabled>Vérifier</button>
<div class="quiz-feedback quiz-feedback-correct" hidden>✅ Correct ! <code>60</code>. <code>tab[0] + tab[4]</code> = <code>10 + 50</code> = <code>60</code>. On écrase la valeur précédente de <code>tab[2]</code>.</div>
<div class="quiz-feedback quiz-feedback-incorrect" hidden>❌ Pas tout à fait. La bonne réponse est <strong>B — <code>60</code></strong>. La dernière ligne remplace <code>tab[2]</code> par <code>10 + 50</code>.</div>
</div>

<div class="quiz-question" data-correct="2">
<p class="quiz-number">Question 1.3</p>
<p class="quiz-prompt">Combien d'octets occupe en mémoire la chaîne littérale <code>"42"</code> ?</p>
<ul class="quiz-options">
  <li class="quiz-option"><span class="quiz-option-marker">A</span> 1</li>
  <li class="quiz-option"><span class="quiz-option-marker">B</span> 2</li>
  <li class="quiz-option"><span class="quiz-option-marker">C</span> 3</li>
  <li class="quiz-option"><span class="quiz-option-marker">D</span> 4</li>
</ul>
<button class="quiz-check" disabled>Vérifier</button>
<div class="quiz-feedback quiz-feedback-correct" hidden>✅ Correct ! <strong>3 octets</strong> : <code>'4'</code>, <code>'2'</code>, <code>'\0'</code>. Le <code>'\0'</code> est ajouté automatiquement par le compilateur.</div>
<div class="quiz-feedback quiz-feedback-incorrect" hidden>❌ Pas tout à fait. La bonne réponse est <strong>C — 3</strong>. N'oublie pas le <code>'\0'</code> final, ajouté automatiquement.</div>
</div>

<div class="quiz-question" data-correct="0">
<p class="quiz-number">Question 1.4</p>
<p class="quiz-prompt">Que retourne <code>ft_strlen("")</code> (la chaîne vide) ?</p>
<ul class="quiz-options">
  <li class="quiz-option"><span class="quiz-option-marker">A</span> <code>0</code></li>
  <li class="quiz-option"><span class="quiz-option-marker">B</span> <code>1</code></li>
  <li class="quiz-option"><span class="quiz-option-marker">C</span> <code>-1</code></li>
  <li class="quiz-option"><span class="quiz-option-marker">D</span> Erreur</li>
</ul>
<button class="quiz-check" disabled>Vérifier</button>
<div class="quiz-feedback quiz-feedback-correct" hidden>✅ Correct ! <code>0</code>. La chaîne vide n'a aucun caractère avant son <code>'\0'</code>, donc sa longueur est nulle. Elle occupe quand même 1 octet en mémoire (le <code>'\0'</code>).</div>
<div class="quiz-feedback quiz-feedback-incorrect" hidden>❌ Pas tout à fait. La bonne réponse est <strong>A — <code>0</code></strong>. <code>ft_strlen</code> compte les caractères avant le <code>'\0'</code> : ici, aucun.</div>
</div>

<div class="quiz-question" data-correct="1">
<p class="quiz-number">Question 1.5</p>
<p class="quiz-prompt">Pourquoi cette ligne provoque-t-elle un crash ?<br><br><code>char *str;<br>str = "Hello";<br>str[0] = 'J';</code></p>
<ul class="quiz-options">
  <li class="quiz-option"><span class="quiz-option-marker">A</span> Parce que <code>str</code> n'est pas un tableau.</li>
  <li class="quiz-option"><span class="quiz-option-marker">B</span> Parce que les littéraux de chaîne sont en lecture seule.</li>
  <li class="quiz-option"><span class="quiz-option-marker">C</span> Parce que <code>'J'</code> n'est pas une lettre valide.</li>
  <li class="quiz-option"><span class="quiz-option-marker">D</span> Pas de crash, le code marche.</li>
</ul>
<button class="quiz-check" disabled>Vérifier</button>
<div class="quiz-feedback quiz-feedback-correct" hidden>✅ Correct ! Les littéraux comme <code>"Hello"</code> sont stockés dans une zone mémoire <strong>en lecture seule</strong>. Toute écriture provoque un <em>segmentation fault</em>. Pour modifier une chaîne, déclare-la comme un <strong>tableau de char</strong>.</div>
<div class="quiz-feedback quiz-feedback-incorrect" hidden>❌ Pas tout à fait. La bonne réponse est <strong>B</strong>. Le littéral <code>"Hello"</code> est en lecture seule : on ne peut pas écrire dedans.</div>
</div>

<div class="quiz-question" data-correct="2">
<p class="quiz-number">Question 1.6</p>
<p class="quiz-prompt">Quelle est la <strong>différence fondamentale</strong> entre un tableau d'<code>int</code> et une chaîne, du point de vue d'une fonction qui le reçoit ?</p>
<ul class="quiz-options">
  <li class="quiz-option"><span class="quiz-option-marker">A</span> Aucune, c'est pareil.</li>
  <li class="quiz-option"><span class="quiz-option-marker">B</span> Le tableau d'<code>int</code> est plus rapide.</li>
  <li class="quiz-option"><span class="quiz-option-marker">C</span> La chaîne se termine par <code>'\0'</code> ; pour le tableau d'<code>int</code>, on doit passer la taille en paramètre.</li>
  <li class="quiz-option"><span class="quiz-option-marker">D</span> Les chaînes ne peuvent pas être passées à une fonction.</li>
</ul>
<button class="quiz-check" disabled>Vérifier</button>
<div class="quiz-feedback quiz-feedback-correct" hidden>✅ Correct ! Une fonction qui reçoit une chaîne connaît sa fin grâce au <code>'\0'</code>. Pour un tableau d'<code>int</code>, pas de marqueur de fin naturel : il faut passer la taille séparément, comme <code>int ft_somme(int *tab, int taille);</code>.</div>
<div class="quiz-feedback quiz-feedback-incorrect" hidden>❌ Pas tout à fait. La bonne réponse est <strong>C</strong>. La chaîne s'auto-délimite avec <code>'\0'</code> ; un tableau d'<code>int</code> exige une taille explicite.</div>
</div>

<p id="quiz-score" class="quiz-score"></p>

---

## Partie 2 — Exercices pratiques

### Exercice 2.1 — Maximum d'un tableau

Écris une fonction `ft_max_tab(int *tab, int taille)` qui retourne le plus grand élément d'un tableau. Dans `main`, déclare un tableau de 5 entiers (10, 25, 3, 42, 17), appelle la fonction, affiche le résultat avec `ft_putnbr`.

Sortie attendue : `42\n`.

??? success "Solution"
    ```c
    /* en-tête 42 ici */

    #include <unistd.h>

    void	ft_putchar(char c)
    {
    	write(1, &c, 1);
    }

    void	ft_putnbr(int n)
    {
    	if (n < 0)
    	{
    		ft_putchar('-');
    		n = -n;
    	}
    	if (n >= 10)
    	{
    		ft_putnbr(n / 10);
    	}
    	ft_putchar('0' + n % 10);
    }

    int	ft_max_tab(int *tab, int taille)
    {
    	int	i;
    	int	max;

    	i = 1;
    	max = tab[0];
    	while (i < taille)
    	{
    		if (tab[i] > max)
    		{
    			max = tab[i];
    		}
    		i++;
    	}
    	return (max);
    }

    int	main(void)
    {
    	int	tab[5];

    	tab[0] = 10;
    	tab[1] = 25;
    	tab[2] = 3;
    	tab[3] = 42;
    	tab[4] = 17;
    	ft_putnbr(ft_max_tab(tab, 5));
    	ft_putchar('\n');
    	return (0);
    }
    ```

    L'initialisation `max = tab[0]` (et `i = 1`) évite de comparer le premier élément avec une valeur arbitraire.

### Exercice 2.2 — `ft_strlen` revisitée

Écris `ft_strlen` (rappel du cours), puis utilise-la pour afficher la longueur de trois chaînes :

- `"Bonjour"` → 7
- `"42 piscine"` → 10
- `""` → 0

Sortie attendue (un nombre par ligne) :

```
7
10
0
```

??? success "Solution"
    ```c
    /* en-tête 42 ici */

    #include <unistd.h>

    void	ft_putchar(char c)
    {
    	write(1, &c, 1);
    }

    void	ft_putnbr(int n)
    {
    	if (n < 0)
    	{
    		ft_putchar('-');
    		n = -n;
    	}
    	if (n >= 10)
    	{
    		ft_putnbr(n / 10);
    	}
    	ft_putchar('0' + n % 10);
    }

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

    int	main(void)
    {
    	ft_putnbr(ft_strlen("Bonjour"));
    	ft_putchar('\n');
    	ft_putnbr(ft_strlen("42 piscine"));
    	ft_putchar('\n');
    	ft_putnbr(ft_strlen(""));
    	ft_putchar('\n');
    	return (0);
    }
    ```

### Exercice 2.3 — Compter les voyelles

Écris une fonction `ft_compte_voyelles(char *str)` qui retourne le nombre de voyelles minuscules (`a, e, i, o, u, y`) dans une chaîne. Teste avec `"bonjour les amis"`.

`b o n j o u r   l e s   a m i s` — les voyelles minuscules : `o, o, u, e, a, i` → **6**.

Sortie attendue : `6\n`.

??? success "Solution"
    ```c
    /* en-tête 42 ici */

    #include <unistd.h>

    void	ft_putchar(char c)
    {
    	write(1, &c, 1);
    }

    int	ft_compte_voyelles(char *str)
    {
    	int	i;
    	int	nb;

    	i = 0;
    	nb = 0;
    	while (str[i] != '\0')
    	{
    		if (str[i] == 'a' || str[i] == 'e' || str[i] == 'i'
    			|| str[i] == 'o' || str[i] == 'u' || str[i] == 'y')
    		{
    			nb++;
    		}
    		i++;
    	}
    	return (nb);
    }

    int	main(void)
    {
    	ft_putchar('0' + ft_compte_voyelles("bonjour les amis"));
    	ft_putchar('\n');
    	return (0);
    }
    ```

### Exercice 2.4 — `ft_putstr` à l'envers

Écris une fonction `ft_putstr_reverse(char *str)` qui affiche une chaîne de droite à gauche, sans retour à la ligne. Teste avec `"42"`.

Sortie attendue : `24\n` (le `\n` est ajouté par le `main`).

??? success "Solution"
    ```c
    /* en-tête 42 ici */

    #include <unistd.h>

    void	ft_putchar(char c)
    {
    	write(1, &c, 1);
    }

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

    void	ft_putstr_reverse(char *str)
    {
    	int	i;

    	i = ft_strlen(str) - 1;
    	while (i >= 0)
    	{
    		ft_putchar(str[i]);
    		i--;
    	}
    }

    int	main(void)
    {
    	ft_putstr_reverse("42");
    	ft_putchar('\n');
    	return (0);
    }
    ```

    Note : on démarre à `ft_strlen(str) - 1` (le dernier caractère utile, pas le `'\0'`), et on descend jusqu'à `0` inclus.

### Exercice 2.5 — Recherche d'un caractère

Écris une fonction `ft_index(char *str, char c)` qui retourne **l'indice de la première occurrence** de `c` dans `str`, ou `-1` si `c` n'apparaît pas.

Teste avec `ft_index("Bonjour", 'j')` → doit retourner `3`. Affiche le résultat (chiffre unique).

Sortie attendue : `3\n`.

??? success "Solution"
    ```c
    /* en-tête 42 ici */

    #include <unistd.h>

    void	ft_putchar(char c)
    {
    	write(1, &c, 1);
    }

    int	ft_index(char *str, char c)
    {
    	int	i;

    	i = 0;
    	while (str[i] != '\0')
    	{
    		if (str[i] == c)
    		{
    			return (i);
    		}
    		i++;
    	}
    	return (-1);
    }

    int	main(void)
    {
    	int	pos;

    	pos = ft_index("Bonjour", 'j');
    	ft_putchar('0' + pos);
    	ft_putchar('\n');
    	return (0);
    }
    ```

    `'B'` à l'indice 0, `'o'` à 1, `'n'` à 2, `'j'` à 3 → retour `3`.

### Exercice 2.6 — Copie de chaîne dans un tableau

Écris une fonction `ft_strcpy(char *dest, char *src)` qui **copie** la chaîne `src` dans `dest` (en incluant le `'\0'`).

Dans `main`, déclare un tableau `char buffer[20];`, copie `"Coucou"` dedans, puis affiche `buffer` avec `ft_putstr`.

Sortie attendue : `Coucou\n`.

??? success "Solution"
    ```c
    /* en-tête 42 ici */

    #include <unistd.h>

    void	ft_putchar(char c)
    {
    	write(1, &c, 1);
    }

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

    void	ft_strcpy(char *dest, char *src)
    {
    	int	i;

    	i = 0;
    	while (src[i] != '\0')
    	{
    		dest[i] = src[i];
    		i++;
    	}
    	dest[i] = '\0';
    }

    int	main(void)
    {
    	char	buffer[20];

    	ft_strcpy(buffer, "Coucou");
    	ft_putstr(buffer);
    	ft_putchar('\n');
    	return (0);
    }
    ```

    **Clé** : ne pas oublier `dest[i] = '\0';` à la fin. Sans ça, `dest` n'est pas une chaîne valide et `ft_putstr` lira au-delà du contenu copié.

---

## Partie 3 — Bonus

### Exercice 3.1 — Inverser un tableau d'entiers en place

Écris une fonction `ft_reverse_tab(int *tab, int taille)` qui inverse l'ordre des éléments **dans le tableau lui-même** (pas une copie).

Dans `main`, déclare `int tab[5]` avec `{1, 2, 3, 4, 5}`, appelle `ft_reverse_tab(tab, 5)`, puis affiche le tableau (chiffres collés).

Sortie attendue : `54321\n`.

??? success "Solution"
    ```c
    /* en-tête 42 ici */

    #include <unistd.h>

    void	ft_putchar(char c)
    {
    	write(1, &c, 1);
    }

    void	ft_reverse_tab(int *tab, int taille)
    {
    	int	i;
    	int	j;
    	int	tmp;

    	i = 0;
    	j = taille - 1;
    	while (i < j)
    	{
    		tmp = tab[i];
    		tab[i] = tab[j];
    		tab[j] = tmp;
    		i++;
    		j--;
    	}
    }

    int	main(void)
    {
    	int	tab[5];
    	int	i;

    	tab[0] = 1;
    	tab[1] = 2;
    	tab[2] = 3;
    	tab[3] = 4;
    	tab[4] = 5;
    	ft_reverse_tab(tab, 5);
    	i = 0;
    	while (i < 5)
    	{
    		ft_putchar('0' + tab[i]);
    		i++;
    	}
    	ft_putchar('\n');
    	return (0);
    }
    ```

    **Note importante :** ici, `ft_reverse_tab` modifie effectivement le tableau de `main`. C'est parce qu'un tableau est passé **par référence** (en réalité, on passe l'adresse de son premier élément). Pour les variables simples comme `int n`, on doit utiliser des pointeurs explicitement (Support 09).

### Exercice 3.2 — Comparer deux chaînes

Écris une fonction `ft_strcmp(char *s1, char *s2)` qui retourne :

- `0` si les deux chaînes sont identiques.
- Un nombre **négatif** si `s1 < s2` (ordre lexicographique).
- Un nombre **positif** si `s1 > s2`.

C'est exactement le comportement de `strcmp` de la libc.

**Indice :** parcourir les deux chaînes en parallèle tant qu'elles sont identiques. Dès qu'on trouve une différence, retourner `s1[i] - s2[i]`. Si on arrive à la fin des deux en même temps, retourner `0`.

Teste avec :
- `ft_strcmp("abc", "abc")` → `0`
- `ft_strcmp("abc", "abd")` → négatif
- `ft_strcmp("abd", "abc")` → positif

Affiche les trois résultats avec un signe (`+`, `0` ou `-`).

Sortie attendue : `0-+\n` (0 pour égal, - pour le 2e, + pour le 3e).

??? success "Solution"
    ```c
    /* en-tête 42 ici */

    #include <unistd.h>

    void	ft_putchar(char c)
    {
    	write(1, &c, 1);
    }

    int	ft_strcmp(char *s1, char *s2)
    {
    	int	i;

    	i = 0;
    	while (s1[i] != '\0' && s2[i] != '\0' && s1[i] == s2[i])
    	{
    		i++;
    	}
    	return (s1[i] - s2[i]);
    }

    void	ft_putsign(int n)
    {
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
    }

    int	main(void)
    {
    	ft_putsign(ft_strcmp("abc", "abc"));
    	ft_putsign(ft_strcmp("abc", "abd"));
    	ft_putsign(ft_strcmp("abd", "abc"));
    	ft_putchar('\n');
    	return (0);
    }
    ```

### Exercice 3.3 — Lecture de code

Sans compiler, donne la sortie de ce programme :

```c
int	main(void)
{
	char	*str;
	int		i;
	int		count;

	str = "Salut, 42 !";
	i = 0;
	count = 0;
	while (str[i] != '\0')
	{
		if (str[i] >= '0' && str[i] <= '9')
		{
			count++;
		}
		i++;
	}
	ft_putchar('0' + count);
	ft_putchar('\n');
	return (0);
}
```

??? success "Réponse"
    On parcourt `"Salut, 42 !"`. Les caractères sont `S, a, l, u, t, ',', ' ', '4', '2', ' ', '!'`.

    Le test `str[i] >= '0' && str[i] <= '9'` détecte les chiffres ASCII. Dans cette chaîne : `'4'` et `'2'`. Donc `count = 2`.

    Sortie : **`2\n`**.

---

## Validation finale

Avant de passer au Support 09, assure-toi de savoir faire **sans hésiter** :

- [ ] Déclarer un tableau et le remplir élément par élément.
- [ ] Parcourir un tableau d'entiers avec `while` et la taille passée en paramètre.
- [ ] Expliquer ce qu'est le caractère `'\0'`.
- [ ] Écrire `ft_strlen` de mémoire.
- [ ] Écrire `ft_putstr` de mémoire.
- [ ] Parcourir une chaîne avec `while (str[i] != '\0')`.
- [ ] Comprendre pourquoi modifier `"Hello"` provoque un crash.
- [ ] Écrire une fonction qui modifie un tableau passé en paramètre.

Si tu butes, refais l'exercice 2.6 (`ft_strcpy`) en partant de zéro — c'est la fonction fondatrice de toute manipulation de chaînes.

---

➡️ **Retour au cours :** [Support 08 — Tableaux et chaînes](./cours.md)
➡️ **Support suivant :** [Support 09 — Pointeurs (initiation)](../support-09/cours.md)
