# Support 09 — Exercices

> **Objectif :** Manipuler les pointeurs : déclaration, initialisation, déréférencement, et écrire des fonctions qui modifient les variables de l'appelant.

Compile chaque exercice avec `cc -Wall -Wextra -Werror`, valide avec `norminette`, vérifie la sortie.

---

## Partie 1 — Quiz

<div class="quiz-question" data-correct="1">
<p class="quiz-number">Question 1.1</p>
<p class="quiz-prompt">Que signifie cette déclaration ?<br><br><code>int *p;</code></p>
<ul class="quiz-options">
  <li class="quiz-option"><span class="quiz-option-marker">A</span> Un entier nommé <code>p</code> multiplié par quelque chose.</li>
  <li class="quiz-option"><span class="quiz-option-marker">B</span> Un pointeur vers un entier, nommé <code>p</code>.</li>
  <li class="quiz-option"><span class="quiz-option-marker">C</span> Un tableau d'entiers.</li>
  <li class="quiz-option"><span class="quiz-option-marker">D</span> Une fonction qui retourne un entier.</li>
</ul>
<button class="quiz-check" disabled>Vérifier</button>
<div class="quiz-feedback quiz-feedback-correct" hidden>✅ Correct ! <code>int *p</code> déclare une variable <code>p</code> qui est un <strong>pointeur vers un <code>int</code></strong> : elle peut contenir l'adresse d'un <code>int</code>.</div>
<div class="quiz-feedback quiz-feedback-incorrect" hidden>❌ Pas tout à fait. La bonne réponse est <strong>B</strong>. L'étoile à la déclaration signifie « pointeur vers » : <code>p</code> stocke une adresse d'<code>int</code>.</div>
</div>

<div class="quiz-question" data-correct="1">
<p class="quiz-number">Question 1.2</p>
<p class="quiz-prompt">Que vaut <code>*p</code> après ce code ?<br><br><code>int x;<br>int *p;<br>x = 42;<br>p = &amp;x;</code></p>
<ul class="quiz-options">
  <li class="quiz-option"><span class="quiz-option-marker">A</span> L'adresse de <code>x</code>.</li>
  <li class="quiz-option"><span class="quiz-option-marker">B</span> <code>42</code>.</li>
  <li class="quiz-option"><span class="quiz-option-marker">C</span> <code>0</code>.</li>
  <li class="quiz-option"><span class="quiz-option-marker">D</span> Indéfini.</li>
</ul>
<button class="quiz-check" disabled>Vérifier</button>
<div class="quiz-feedback quiz-feedback-correct" hidden>✅ Correct ! <code>42</code>. <code>p</code> pointe vers <code>x</code>, donc <code>*p</code> (la valeur à l'adresse pointée) est la valeur de <code>x</code>, soit <code>42</code>.</div>
<div class="quiz-feedback quiz-feedback-incorrect" hidden>❌ Pas tout à fait. La bonne réponse est <strong>B — <code>42</code></strong>. <code>*p</code> déréférence <code>p</code> et lit la valeur de <code>x</code>. <code>p</code> seul (sans <code>*</code>) vaudrait l'adresse.</div>
</div>

<div class="quiz-question" data-correct="1">
<p class="quiz-number">Question 1.3</p>
<p class="quiz-prompt">Quelle est la différence entre <code>&amp;x</code> et <code>*p</code> ?</p>
<ul class="quiz-options">
  <li class="quiz-option"><span class="quiz-option-marker">A</span> Aucune, c'est la même chose.</li>
  <li class="quiz-option"><span class="quiz-option-marker">B</span> <code>&amp;x</code> est une <strong>adresse</strong>, <code>*p</code> est la <strong>valeur</strong> à une adresse.</li>
  <li class="quiz-option"><span class="quiz-option-marker">C</span> <code>&amp;x</code> est plus rapide.</li>
  <li class="quiz-option"><span class="quiz-option-marker">D</span> L'un est obsolète.</li>
</ul>
<button class="quiz-check" disabled>Vérifier</button>
<div class="quiz-feedback quiz-feedback-correct" hidden>✅ Correct ! <code>&amp;x</code> donne l'<strong>adresse</strong> où <code>x</code> est stocké ; <code>*p</code> donne la <strong>valeur</strong> à l'adresse contenue dans <code>p</code>. <code>&amp;</code> va du nom vers l'adresse, <code>*</code> de l'adresse vers la valeur.</div>
<div class="quiz-feedback quiz-feedback-incorrect" hidden>❌ Pas tout à fait. La bonne réponse est <strong>B</strong>. <code>&amp;</code> et <code>*</code> sont des opérations opposées : adresse d'une part, valeur de l'autre.</div>
</div>

<div class="quiz-question" data-correct="1">
<p class="quiz-number">Question 1.4</p>
<p class="quiz-prompt">Quelle est la sortie de ce programme ?<br><br><code>x = 5;<br>p = &amp;x;<br>*p = *p + 1;<br>ft_putchar('0' + x);</code></p>
<ul class="quiz-options">
  <li class="quiz-option"><span class="quiz-option-marker">A</span> <code>5</code></li>
  <li class="quiz-option"><span class="quiz-option-marker">B</span> <code>6</code></li>
  <li class="quiz-option"><span class="quiz-option-marker">C</span> <code>7</code></li>
  <li class="quiz-option"><span class="quiz-option-marker">D</span> Comportement indéfini</li>
</ul>
<button class="quiz-check" disabled>Vérifier</button>
<div class="quiz-feedback quiz-feedback-correct" hidden>✅ Correct ! <code>6</code>. <code>*p = *p + 1</code> lit <code>x</code> (5), ajoute 1, et écrit le résultat à l'adresse pointée, c'est-à-dire dans <code>x</code>. Après ça, <code>x</code> vaut <code>6</code>.</div>
<div class="quiz-feedback quiz-feedback-incorrect" hidden>❌ Pas tout à fait. La bonne réponse est <strong>B — <code>6</code></strong>. Modifier <code>*p</code> modifie <code>x</code> lui-même, qui passe de 5 à 6.</div>
</div>

<div class="quiz-question" data-correct="1">
<p class="quiz-number">Question 1.5</p>
<p class="quiz-prompt">Pour qu'une fonction modifie une variable de l'appelant, quelle est la bonne syntaxe ?</p>
<ul class="quiz-options">
  <li class="quiz-option"><span class="quiz-option-marker">A</span> Déclarer le paramètre avec <code>int n</code> et appeler avec <code>f(x)</code>.</li>
  <li class="quiz-option"><span class="quiz-option-marker">B</span> Déclarer le paramètre avec <code>int *n</code> et appeler avec <code>f(&amp;x)</code>.</li>
  <li class="quiz-option"><span class="quiz-option-marker">C</span> Déclarer le paramètre avec <code>int *n</code> et appeler avec <code>f(x)</code>.</li>
  <li class="quiz-option"><span class="quiz-option-marker">D</span> C'est impossible en C.</li>
</ul>
<button class="quiz-check" disabled>Vérifier</button>
<div class="quiz-feedback quiz-feedback-correct" hidden>✅ Correct ! Le paramètre doit être un <strong>pointeur</strong> (<code>int *n</code>), et on lui passe <strong>l'adresse</strong> de la variable (<code>f(&amp;x)</code>). À l'intérieur, on utilise <code>*n</code> pour lire ou écrire la valeur.</div>
<div class="quiz-feedback quiz-feedback-incorrect" hidden>❌ Pas tout à fait. La bonne réponse est <strong>B</strong>. Il faut un paramètre pointeur <em>et</em> passer l'adresse avec <code>&amp;</code>. Passer <code>f(x)</code> à un <code>int *n</code> ne compilerait pas.</div>
</div>

<div class="quiz-question" data-correct="2">
<p class="quiz-number">Question 1.6</p>
<p class="quiz-prompt">Quel est le danger d'un pointeur non initialisé ?</p>
<ul class="quiz-options">
  <li class="quiz-option"><span class="quiz-option-marker">A</span> Le programme ne compile pas.</li>
  <li class="quiz-option"><span class="quiz-option-marker">B</span> Le compilateur émet un warning.</li>
  <li class="quiz-option"><span class="quiz-option-marker">C</span> Le déréférencement lit ou écrit à une adresse aléatoire — crash ou corruption mémoire.</li>
  <li class="quiz-option"><span class="quiz-option-marker">D</span> Aucun danger.</li>
</ul>
<button class="quiz-check" disabled>Vérifier</button>
<div class="quiz-feedback quiz-feedback-correct" hidden>✅ Correct ! Un pointeur non initialisé contient une valeur <strong>indéterminée</strong>. Le déréférencer accède à une adresse aléatoire : souvent ça crashe (<em>segmentation fault</em>), parfois ça corrompt d'autres variables — un bug très difficile à diagnostiquer.</div>
<div class="quiz-feedback quiz-feedback-incorrect" hidden>❌ Pas tout à fait. La bonne réponse est <strong>C</strong>. Le code compile, mais déréférencer un pointeur non initialisé accède à une adresse aléatoire : crash ou corruption.</div>
</div>

<p id="quiz-score" class="quiz-score"></p>

---

## Partie 2 — Exercices pratiques

### Exercice 2.1 — Test mental sur `*` et `&`

Sans compiler, donne la sortie de ce programme :

```c
int	main(void)
{
	int	a;
	int	b;
	int	*p;

	a = 4;
	b = 9;
	p = &a;
	*p = b;
	ft_putchar('0' + a);
	ft_putchar('0' + b);
	ft_putchar('\n');
	return (0);
}
```

??? success "Réponse"
    Décortiquons :

    - `a = 4`, `b = 9`.
    - `p = &a` : `p` pointe vers `a`.
    - `*p = b` : on lit `b` (= 9) et on l'écrit à l'adresse pointée par `p` (donc dans `a`). Maintenant `a` vaut `9`.
    - Affichage : `'0' + a` = `'9'`, puis `'0' + b` = `'9'`.

    Sortie : **`99\n`**.

### Exercice 2.2 — `ft_double_ptr`

Écris une fonction `ft_double_ptr(int *n)` qui double la valeur pointée. Teste avec `int x = 3;` puis `ft_double_ptr(&x);` puis affiche `x`.

Sortie attendue : `6\n`.

??? success "Solution"
    ```c
    /* en-tête 42 ici */

    #include <unistd.h>

    void	ft_putchar(char c)
    {
    	write(1, &c, 1);
    }

    void	ft_double_ptr(int *n)
    {
    	*n = *n * 2;
    }

    int	main(void)
    {
    	int	x;

    	x = 3;
    	ft_double_ptr(&x);
    	ft_putchar('0' + x);
    	ft_putchar('\n');
    	return (0);
    }
    ```

### Exercice 2.3 — `ft_swap` revisitée

Implémente `ft_swap(int *a, int *b)` (vu en cours), et utilise-la pour échanger deux variables `x = 1` et `y = 9`. Affiche ensuite `x` puis `y`.

Sortie attendue : `91\n`.

??? success "Solution"
    ```c
    /* en-tête 42 ici */

    #include <unistd.h>

    void	ft_putchar(char c)
    {
    	write(1, &c, 1);
    }

    void	ft_swap(int *a, int *b)
    {
    	int	tmp;

    	tmp = *a;
    	*a = *b;
    	*b = tmp;
    }

    int	main(void)
    {
    	int	x;
    	int	y;

    	x = 1;
    	y = 9;
    	ft_swap(&x, &y);
    	ft_putchar('0' + x);
    	ft_putchar('0' + y);
    	ft_putchar('\n');
    	return (0);
    }
    ```

### Exercice 2.4 — `ft_min_max`

Écris une fonction `ft_min_max(int *min, int *max, int a, int b)` qui :

- Place dans `*min` la plus petite des deux valeurs `a` et `b`.
- Place dans `*max` la plus grande des deux valeurs.

Teste avec `a = 8`, `b = 3`. Affiche `min` puis `max`.

Sortie attendue : `38\n`.

??? success "Solution"
    ```c
    /* en-tête 42 ici */

    #include <unistd.h>

    void	ft_putchar(char c)
    {
    	write(1, &c, 1);
    }

    void	ft_min_max(int *min, int *max, int a, int b)
    {
    	if (a < b)
    	{
    		*min = a;
    		*max = b;
    	}
    	else
    	{
    		*min = b;
    		*max = a;
    	}
    }

    int	main(void)
    {
    	int	min;
    	int	max;

    	ft_min_max(&min, &max, 8, 3);
    	ft_putchar('0' + min);
    	ft_putchar('0' + max);
    	ft_putchar('\n');
    	return (0);
    }
    ```

    Cet exemple montre la **vraie puissance** des pointeurs : une fonction peut renvoyer **plusieurs valeurs** via des pointeurs en sortie, là où `return` ne peut en renvoyer qu'une seule.

### Exercice 2.5 — Parcours pointeur

Réécris `ft_putstr` en utilisant un **pointeur qui avance** (`str++`) au lieu d'un compteur `i`. Démontre-la avec `ft_putstr("Salut !\n");`.

Sortie attendue : `Salut !\n`.

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
    	while (*str != '\0')
    	{
    		ft_putchar(*str);
    		str++;
    	}
    }

    int	main(void)
    {
    	ft_putstr("Salut !\n");
    	return (0);
    }
    ```

    Note que `str++` modifie la **copie locale** de `str` (le pointeur lui-même est passé par valeur). La chaîne pointée n'est pas modifiée. C'est OK : on veut juste se déplacer dedans.

### Exercice 2.6 — Trouve l'erreur

Ce code essaie d'utiliser un pointeur, mais il ne compile pas (ou crashe). Trouve les **deux problèmes**.

```c
int	main(void)
{
	int	*p;

	*p = 42;
	ft_putchar('0' + *p);
	ft_putchar('\n');
	return (0);
}
```

??? success "Réponse"
    Deux problèmes :

    1. **`p` n'est jamais initialisé.** Il contient une valeur indéterminée (une adresse aléatoire). `*p = 42` essaie d'écrire à cette adresse aléatoire → crash garanti (ou corruption mémoire).
    2. (Conséquence du 1.) `ft_putchar('0' + *p)` lit à la même adresse aléatoire.

    **Correction :**

    ```c
    int	x;
    int	*p;

    x = 42;
    p = &x;             /* p pointe maintenant vers une vraie variable */
    ft_putchar('0' + *p);
    ft_putchar('\n');
    ```

    Ou alors, on n'utilise pas du tout de pointeur si on n'en a pas besoin :

    ```c
    int	x;

    x = 42;
    ft_putchar('0' + x);
    ft_putchar('\n');
    ```

---

## Partie 3 — Bonus

### Exercice 3.1 — `ft_strlen` avec pointeur

Réécris `ft_strlen` en utilisant la technique du **pointeur qui avance**, sans utiliser de compteur `i`. Indice : compare l'adresse finale à l'adresse de départ.

Teste avec `ft_strlen("piscine")` → doit retourner `7`.

Sortie attendue : `7\n`.

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
    	char	*debut;

    	debut = str;
    	while (*str != '\0')
    	{
    		str++;
    	}
    	return (str - debut);
    }

    int	main(void)
    {
    	ft_putchar('0' + ft_strlen("piscine"));
    	ft_putchar('\n');
    	return (0);
    }
    ```

    Astuce : la **soustraction de deux pointeurs** du même type donne le nombre d'éléments entre eux. Ici, `str - debut` est le nombre de caractères qu'on a avancé jusqu'au `'\0'`, c'est-à-dire la longueur.

### Exercice 3.2 — `ft_sort_two`

Écris une fonction `ft_sort_two(int *a, int *b)` qui trie deux variables : à la fin, `*a` contient la plus petite et `*b` la plus grande.

Teste avec `x = 7`, `y = 2`. Appelle `ft_sort_two(&x, &y)`. Affiche `x` puis `y`.

Sortie attendue : `27\n`.

**Bonus pour les courageux :** essaie de réutiliser `ft_swap` à l'intérieur de `ft_sort_two`.

??? success "Solution"
    ```c
    /* en-tête 42 ici */

    #include <unistd.h>

    void	ft_putchar(char c)
    {
    	write(1, &c, 1);
    }

    void	ft_swap(int *a, int *b)
    {
    	int	tmp;

    	tmp = *a;
    	*a = *b;
    	*b = tmp;
    }

    void	ft_sort_two(int *a, int *b)
    {
    	if (*a > *b)
    	{
    		ft_swap(a, b);
    	}
    }

    int	main(void)
    {
    	int	x;
    	int	y;

    	x = 7;
    	y = 2;
    	ft_sort_two(&x, &y);
    	ft_putchar('0' + x);
    	ft_putchar('0' + y);
    	ft_putchar('\n');
    	return (0);
    }
    ```

    Note : on passe `a` et `b` directement à `ft_swap` (pas `&a` et `&b`), parce qu'ils sont déjà des pointeurs.

### Exercice 3.3 — Trace mentale finale

Sans compiler, donne la sortie de ce programme :

```c
void	ft_mystere(int *p, int *q)
{
	*p = *p + *q;
	*q = *p - *q;
	*p = *p - *q;
}

int	main(void)
{
	int	a;
	int	b;

	a = 5;
	b = 3;
	ft_mystere(&a, &b);
	ft_putchar('0' + a);
	ft_putchar('0' + b);
	ft_putchar('\n');
	return (0);
}
```

??? success "Réponse"
    Trace pas à pas (avec `*p = a`, `*q = b`) :

    - Départ : `a = 5`, `b = 3`.
    - `*p = *p + *q` → `a = 5 + 3 = 8`.
    - `*q = *p - *q` → `b = 8 - 3 = 5`.
    - `*p = *p - *q` → `a = 8 - 5 = 3`.

    Résultat : `a = 3`, `b = 5`. Sortie : **`35\n`**.

    Cette fonction réalise un **échange de variables sans variable temporaire**, juste avec des additions et des soustractions. C'est un classique d'entretien.

---

## Validation finale

Tu as terminé la Séquence 1 ! Avant de passer au Bilan, assure-toi de savoir faire **sans hésiter** :

- [ ] Déclarer un pointeur (`int *p`).
- [ ] Obtenir l'adresse d'une variable avec `&`.
- [ ] Déréférencer un pointeur avec `*`.
- [ ] Distinguer mentalement `x`, `&x`, `p`, `*p`.
- [ ] Écrire `ft_swap` de mémoire.
- [ ] Comprendre pourquoi une fonction doit recevoir un pointeur pour modifier l'appelant.
- [ ] Faire une trace mentale d'un programme avec pointeurs.
- [ ] Reconnaître les pièges : pointeur non initialisé, retour d'adresse locale, déréférencement de `NULL`.

Si tu butes, refais l'exercice 3.3 (trace mentale) — il est le test ultime de ta compréhension des pointeurs.

---

➡️ **Retour au cours :** [Support 09 — Pointeurs (initiation)](./cours.md)
➡️ **Support suivant :** [Bilan de la Séquence 1](../Bilan/bilan.md)
