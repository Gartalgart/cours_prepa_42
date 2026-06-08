# Support 03 — Exercices

> **Objectif :** Maîtriser la déclaration et l'utilisation de variables `int` et `char` aux normes 42, et comprendre la portée.

Comme aux supports précédents : compile chaque exercice avec `cc -Wall -Wextra -Werror`, valide-le avec `norminette`, et vérifie la sortie.

---

## Partie 1 — Quiz

<div class="quiz-question" data-correct="2">
<p class="quiz-number">Question 1.1</p>
<p class="quiz-prompt">Combien d'octets occupe un <code>int</code> sur une machine Linux 64-bits classique ?</p>
<ul class="quiz-options">
  <li class="quiz-option"><span class="quiz-option-marker">A</span> 1</li>
  <li class="quiz-option"><span class="quiz-option-marker">B</span> 2</li>
  <li class="quiz-option"><span class="quiz-option-marker">C</span> 4</li>
  <li class="quiz-option"><span class="quiz-option-marker">D</span> 8</li>
</ul>
<button class="quiz-check" disabled>Vérifier</button>
<div class="quiz-feedback quiz-feedback-correct" hidden>✅ Correct ! <strong>4 octets</strong> (32 bits) sur les machines x86_64 modernes, soit une plage de -2 147 483 648 à 2 147 483 647. Le standard C ne garantit qu'un minimum de 16 bits — c'est la pratique qui fixe 4 octets.</div>
<div class="quiz-feedback quiz-feedback-incorrect" hidden>❌ Pas tout à fait. La bonne réponse est <strong>C — 4 octets</strong>. Sur les machines Linux 64-bits modernes, <code>int</code> fait 4 octets (32 bits). Ne pas confondre avec <code>long</code> qui fait 8 octets, ni avec <code>char</code> qui fait 1 octet.</div>
</div>

<div class="quiz-question" data-correct="2">
<p class="quiz-number">Question 1.2</p>
<p class="quiz-prompt">Laquelle de ces déclarations est conforme à la Norm 42 ?</p>
<ul class="quiz-options">
  <li class="quiz-option"><span class="quiz-option-marker">A</span> <code>int x = 5;</code></li>
  <li class="quiz-option"><span class="quiz-option-marker">B</span> <code>int x, y, z;</code></li>
  <li class="quiz-option"><span class="quiz-option-marker">C</span> <code>int&nbsp;&nbsp;&nbsp;&nbsp;x;</code> (avec tabulation)</li>
  <li class="quiz-option"><span class="quiz-option-marker">D</span> <code>int x;y = 3;</code></li>
</ul>
<button class="quiz-check" disabled>Vérifier</button>
<div class="quiz-feedback quiz-feedback-correct" hidden>✅ Correct ! <code>int&lt;tab&gt;x;</code> est la seule forme valide. Les autres violent chacune une règle : initialisation à la déclaration (A), plusieurs variables sur une ligne (B), et deux instructions sur la même ligne (D).</div>
<div class="quiz-feedback quiz-feedback-incorrect" hidden>❌ Pas tout à fait. La bonne réponse est <strong>C</strong>. Rappel des règles Norm : pas d'initialisation à la déclaration → <strong>A</strong> interdit ; une variable par ligne → <strong>B</strong> interdit ; une instruction par ligne → <strong>D</strong> interdit.</div>
</div>

<div class="quiz-question" data-correct="0">
<p class="quiz-number">Question 1.3</p>
<p class="quiz-prompt">Que va afficher ce programme ?<br><br><code>c = 'a' - 32;<br>ft_putchar(c);<br>ft_putchar('\n');</code></p>
<ul class="quiz-options">
  <li class="quiz-option"><span class="quiz-option-marker">A</span> <code>A</code></li>
  <li class="quiz-option"><span class="quiz-option-marker">B</span> <code>a</code></li>
  <li class="quiz-option"><span class="quiz-option-marker">C</span> <code>65</code></li>
  <li class="quiz-option"><span class="quiz-option-marker">D</span> <code>97</code></li>
</ul>
<button class="quiz-check" disabled>Vérifier</button>
<div class="quiz-feedback quiz-feedback-correct" hidden>✅ Correct ! <code>'a'</code> vaut 97. 97 − 32 = 65 = <code>'A'</code>. Soustraire 32 d'une minuscule donne toujours la majuscule correspondante — c'est un réflexe à avoir.</div>
<div class="quiz-feedback quiz-feedback-incorrect" hidden>❌ Pas tout à fait. La bonne réponse est <strong>A — <code>A</code></strong>. <code>'a'</code> = 97 en ASCII, et 97 − 32 = 65 = <code>'A'</code>. L'écart de 32 entre minuscule et majuscule est une constante à mémoriser.</div>
</div>

<div class="quiz-question" data-correct="2">
<p class="quiz-number">Question 1.4</p>
<p class="quiz-prompt">Que vaut <code>x</code> à la fin de cette séquence ?<br><br><code>x = 10; x = x + 5; x = x - 3; x = x * 2;</code></p>
<ul class="quiz-options">
  <li class="quiz-option"><span class="quiz-option-marker">A</span> 12</li>
  <li class="quiz-option"><span class="quiz-option-marker">B</span> 17</li>
  <li class="quiz-option"><span class="quiz-option-marker">C</span> 24</li>
  <li class="quiz-option"><span class="quiz-option-marker">D</span> 30</li>
</ul>
<button class="quiz-check" disabled>Vérifier</button>
<div class="quiz-feedback quiz-feedback-correct" hidden>✅ Correct ! Pas à pas : 10 → +5 = 15 → −3 = 12 → ×2 = <strong>24</strong>. Chaque affectation écrase la précédente — <code>x</code> n'accumule pas, il est remplacé à chaque ligne.</div>
<div class="quiz-feedback quiz-feedback-incorrect" hidden>❌ Pas tout à fait. La bonne réponse est <strong>C — 24</strong>. Trace pas à pas : <code>x = 10</code> → <code>x = 10 + 5 = 15</code> → <code>x = 15 − 3 = 12</code> → <code>x = 12 × 2 = 24</code>.</div>
</div>

<div class="quiz-question" data-correct="1">
<p class="quiz-number">Question 1.5</p>
<p class="quiz-prompt"><code>ft_increment</code> modifie son paramètre <code>n</code> (n = n + 1). Dans <code>main</code>, <code>n = 5</code>, puis on appelle <code>ft_increment(n)</code>. Qu'affiche ensuite <code>ft_putchar('0' + n)</code> dans <code>main</code> ?</p>
<ul class="quiz-options">
  <li class="quiz-option"><span class="quiz-option-marker">A</span> <code>6</code></li>
  <li class="quiz-option"><span class="quiz-option-marker">B</span> <code>5</code></li>
  <li class="quiz-option"><span class="quiz-option-marker">C</span> <code>0</code></li>
  <li class="quiz-option"><span class="quiz-option-marker">D</span> Erreur de compilation</li>
</ul>
<button class="quiz-check" disabled>Vérifier</button>
<div class="quiz-feedback quiz-feedback-correct" hidden>✅ Correct ! <code>ft_increment</code> reçoit une <strong>copie</strong> de <code>n</code>. Modifier cette copie n'affecte pas le <code>n</code> de <code>main</code>. Le <code>n</code> de <code>main</code> vaut toujours <strong>5</strong>. Pour modifier la variable originale, il faudrait passer son adresse avec un pointeur (Support 09).</div>
<div class="quiz-feedback quiz-feedback-incorrect" hidden>❌ Pas tout à fait. La bonne réponse est <strong>B — <code>5</code></strong>. En C, les arguments sont passés <strong>par valeur</strong> : <code>ft_increment</code> ne reçoit qu'une copie de <code>n</code>, pas la variable elle-même. La modification reste locale à la fonction.</div>
</div>

<div class="quiz-question" data-correct="1">
<p class="quiz-number">Question 1.6</p>
<p class="quiz-prompt">Quelle est la valeur numérique de <code>result</code> à la fin ?<br><br><code>c = 'C'; result = c + 1;</code> (<code>result</code> est un <code>int</code>)</p>
<ul class="quiz-options">
  <li class="quiz-option"><span class="quiz-option-marker">A</span> <code>'D'</code></li>
  <li class="quiz-option"><span class="quiz-option-marker">B</span> <code>68</code></li>
  <li class="quiz-option"><span class="quiz-option-marker">C</span> <code>1</code></li>
  <li class="quiz-option"><span class="quiz-option-marker">D</span> Erreur</li>
</ul>
<button class="quiz-check" disabled>Vérifier</button>
<div class="quiz-feedback quiz-feedback-correct" hidden>✅ Correct ! <code>'C'</code> = 67 en ASCII, + 1 = <strong>68</strong>. Stocké dans un <code>int</code>, c'est la valeur numérique 68. <code>ft_putchar(result)</code> afficherait <code>'D'</code>, mais la valeur dans <code>result</code> est bien l'entier 68.</div>
<div class="quiz-feedback quiz-feedback-incorrect" hidden>❌ Pas tout à fait. La bonne réponse est <strong>B — 68</strong>. <code>'C'</code> vaut 67 en ASCII. 67 + 1 = 68. Ce 68 est stocké comme entier dans <code>result</code>. <code>'D'</code> est juste la façon de l'interpréter comme caractère — ce n'est pas la valeur stockée dans le <code>int</code>.</div>
</div>

<p id="quiz-score" class="quiz-score"></p>

---

## Partie 2 — Exercices pratiques

### Exercice 2.1 — La lettre N

Écris un programme qui déclare une variable `int` nommée `position`, lui assigne la valeur `13`, puis affiche la lettre majuscule à cette position de l'alphabet (avec `'A'` = position 0).

Sortie attendue : `N\n` (car `'A' + 13 = 'N'`).

**Contraintes :**

- Une variable `int` et une variable `char`, déclarées aux normes 42 (alignées avec tabs).
- `norminette` OK.

??? success "Solution"
    ```c
    /* en-tête 42 ici */

    #include <unistd.h>

    void	ft_putchar(char c)
    {
    	write(1, &c, 1);
    }

    int	main(void)
    {
    	int		position;
    	char	lettre;

    	position = 13;
    	lettre = 'A' + position;
    	ft_putchar(lettre);
    	ft_putchar('\n');
    	return (0);
    }
    ```

### Exercice 2.2 — Trois variables

Écris un programme qui :

1. Déclare trois variables `int` nommées `a`, `b`, `c`.
2. Affecte respectivement `2`, `3`, `4`.
3. Calcule et affiche la somme `a + b + c` sous forme de caractère (sous l'hypothèse que la somme tient sur un chiffre).

Sortie attendue : `9\n`.

??? success "Solution"
    ```c
    /* en-tête 42 ici */

    #include <unistd.h>

    void	ft_putchar(char c)
    {
    	write(1, &c, 1);
    }

    int	main(void)
    {
    	int	a;
    	int	b;
    	int	c;

    	a = 2;
    	b = 3;
    	c = 4;
    	ft_putchar('0' + a + b + c);
    	ft_putchar('\n');
    	return (0);
    }
    ```

### Exercice 2.3 — Échange de valeurs

Écris un programme qui :

1. Déclare deux variables `char` nommées `a` et `b`.
2. Affecte `a = 'X'` et `b = 'Y'`.
3. **Échange** les valeurs (à la fin, `a` doit contenir `'Y'` et `b` doit contenir `'X'`).
4. Affiche `a` puis `b`.

Sortie attendue : `YX\n`.

**Indice :** tu auras besoin d'une **troisième variable temporaire**. Sans elle, l'affectation `a = b` perdrait la valeur initiale de `a`.

??? success "Solution"
    ```c
    /* en-tête 42 ici */

    #include <unistd.h>

    void	ft_putchar(char c)
    {
    	write(1, &c, 1);
    }

    int	main(void)
    {
    	char	a;
    	char	b;
    	char	tmp;

    	a = 'X';
    	b = 'Y';
    	tmp = a;
    	a = b;
    	b = tmp;
    	ft_putchar(a);
    	ft_putchar(b);
    	ft_putchar('\n');
    	return (0);
    }
    ```

    Cette technique d'échange via une variable temporaire est un classique absolu de la programmation. Tu la retrouveras partout (tri, manipulation de structures…).

### Exercice 2.4 — Démonstration de portée

Écris un programme qui :

1. Définit une fonction `ft_double(int x)` qui prend un `int`, le multiplie par 2, et l'affiche comme caractère (`'0' + x`).
2. Dans `main`, déclare `int n = 3` (en deux étapes — déclaration puis affectation, conformément à la Norm).
3. Appelle `ft_double(n)`.
4. Affiche `n` lui-même comme caractère.
5. Affiche un `\n`.

Sortie attendue : `63\n`. (Car `ft_double` affiche 6, puis `main` affiche `n` qui vaut toujours 3.)

??? success "Solution"
    ```c
    /* en-tête 42 ici */

    #include <unistd.h>

    void	ft_putchar(char c)
    {
    	write(1, &c, 1);
    }

    void	ft_double(int x)
    {
    	x = x * 2;
    	ft_putchar('0' + x);
    }

    int	main(void)
    {
    	int	n;

    	n = 3;
    	ft_double(n);
    	ft_putchar('0' + n);
    	ft_putchar('\n');
    	return (0);
    }
    ```

    La sortie `63` prouve que `ft_double` n'a pas modifié le `n` de `main` — il n'a modifié que sa copie locale `x`.

### Exercice 2.5 — Trouver l'erreur

Voici un programme qui ne passe **pas** la Norm 42. Trouve les **trois erreurs** sans le compiler.

```c
/* en-tête 42 ici */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	main(void)
{
	int x = 5, y;
	char c;

	y = x + 1;
	c = '0' + y;
	ft_putchar(c);
	ft_putchar('\n');
	return (0);
}
```

??? success "Réponse"
    Trois violations de la Norm 42 :

    1. **Initialisation à la déclaration** : `int x = 5` est interdit. Il faut séparer en `int x;` puis `x = 5;`.
    2. **Deux variables sur la même ligne** : `int x = 5, y;` viole la règle « une variable par ligne ».
    3. **Pas de ligne vide entre déclarations et code** : il manque une ligne vide après le bloc de déclarations.

    Bonus : il y a aussi un problème d'**alignement** entre `int x` et `char c` — `int` est suivi d'une seule tabulation, ce qui ne place pas `x` à la même colonne que `c`.

    Version corrigée :

    ```c
    int	main(void)
    {
    	int		x;
    	int		y;
    	char	c;

    	x = 5;
    	y = x + 1;
    	c = '0' + y;
    	ft_putchar(c);
    	ft_putchar('\n');
    	return (0);
    }
    ```

### Exercice 2.6 — Débordement

Écris un programme qui :

1. Déclare une variable `char` nommée `c`.
2. Lui assigne la valeur `127` (le maximum d'un `char` signé).
3. Lui ajoute `1`.
4. Affiche la valeur numérique de `c` sous forme de deux caractères : un signe (si négatif) puis les chiffres.

**Question :** quelle valeur observes-tu après l'ajout ? Que démontre-t-elle ?

!!! info "Aide"
    Sans loops ni `printf`, afficher un nombre négatif à plusieurs chiffres demande du travail manuel. Pour cet exercice, **observe avec un debugger** ou ajoute temporairement `printf` juste pour voir la valeur (puis retire-le pour la version finale).

??? success "Réponse"
    Si tu testes :

    ```c
    char	c;

    c = 127;
    c = c + 1;
    /* c vaut maintenant -128 */
    ```

    Le débordement (*overflow*) fait passer `c` de `127` directement à `-128`. C'est ce qu'on appelle un **wrap-around**.

    **Démonstration :** un `char` signé ne peut contenir que des valeurs entre -128 et +127. Quand on dépasse, on « boucle » à l'autre extrémité.

    Ce comportement n'est **pas** un crash, c'est juste une valeur incorrecte. C'est ce qui rend le débordement particulièrement vicieux : ton programme continue, mais avec des données fausses.

---

## Partie 3 — Bonus

### Exercice 3.1 — Avant et après

Écris un programme qui affiche, sur une seule ligne, la lettre précédente et la lettre suivante de `'M'` dans l'alphabet, séparées par un tiret.

Sortie attendue : `L-N\n`.

**Contraintes :**

- Utilise une variable `char` initialisée à `'M'`.
- Calcule les autres à partir d'elle (pas de littéraux `'L'` ou `'N'` directs).

??? success "Solution"
    ```c
    /* en-tête 42 ici */

    #include <unistd.h>

    void	ft_putchar(char c)
    {
    	write(1, &c, 1);
    }

    int	main(void)
    {
    	char	lettre;

    	lettre = 'M';
    	ft_putchar(lettre - 1);
    	ft_putchar('-');
    	ft_putchar(lettre + 1);
    	ft_putchar('\n');
    	return (0);
    }
    ```

### Exercice 3.2 — Trace mentale

Sans compiler, donne la sortie de ce programme :

```c
void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_etrange(int n)
{
	n = n - 1;
	ft_putchar('0' + n);
	n = n + 3;
	ft_putchar('0' + n);
}

int	main(void)
{
	int	n;

	n = 4;
	ft_etrange(n);
	ft_putchar('0' + n);
	n = n + 1;
	ft_putchar('0' + n);
	ft_putchar('\n');
	return (0);
}
```

??? success "Réponse"
    Décortiquons :

    - `main` : `n = 4`.
    - Appel `ft_etrange(4)` : copie locale `n = 4`.
      - `n = n - 1` → 3, affiche `'3'`.
      - `n = n + 3` → 6, affiche `'6'`.
    - Retour dans `main` : le `n` local de `main` vaut **toujours 4**.
      - Affiche `'0' + 4` = `'4'`.
      - `n = n + 1` → 5.
      - Affiche `'0' + 5` = `'5'`.
    - `'\n'`.

    Sortie : **`3645`** suivi d'un saut de ligne.

    Cet exercice combine arithmétique, portée et appel de fonction. Si tu l'as réussi sans hésiter, tu maîtrises les bases de ce support.

---

## Validation finale

Avant de passer au Support 04, assure-toi de savoir faire **sans hésiter** :

- [ ] Déclarer plusieurs variables aux normes 42 (alignement, ordre, une par ligne).
- [ ] Citer la taille en octets de `char` et `int`.
- [ ] Donner la plage de valeurs d'un `int` signé.
- [ ] Affecter une valeur à une variable existante.
- [ ] Comprendre pourquoi `x = x + 1` n'est pas absurde en C.
- [ ] Expliquer ce qu'est la portée d'une variable.
- [ ] Prédire l'effet d'un débordement.

Si tu butes sur l'un de ces points, relis la section concernée et refais l'exercice associé.

---

➡️ **Retour au cours :** [Support 03 — Variables et types](./cours.md)
➡️ **Support suivant :** Support 04 — Opérateurs *(à venir)*
