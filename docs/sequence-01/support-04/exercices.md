# Support 04 — Exercices

> **Objectif :** Maîtriser les opérateurs arithmétiques, de comparaison et logiques, ainsi que la priorité.

Comme aux supports précédents : compile chaque exercice avec `cc -Wall -Wextra -Werror`, valide-le avec `norminette`, et vérifie la sortie.

---

## Partie 1 — Quiz

<div class="quiz-question" data-correct="1">
<p class="quiz-number">Question 1.1</p>
<p class="quiz-prompt">Que vaut <code>13 / 4</code> en C avec des <code>int</code> ?</p>
<ul class="quiz-options">
  <li class="quiz-option"><span class="quiz-option-marker">A</span> <code>3.25</code></li>
  <li class="quiz-option"><span class="quiz-option-marker">B</span> <code>3</code></li>
  <li class="quiz-option"><span class="quiz-option-marker">C</span> <code>4</code></li>
  <li class="quiz-option"><span class="quiz-option-marker">D</span> <code>1</code></li>
</ul>
<button class="quiz-check" disabled>Vérifier</button>
<div class="quiz-feedback quiz-feedback-correct" hidden>✅ Correct ! La division entière tronque toujours la partie décimale : 13 ÷ 4 = 3.25 en maths, mais <strong>3</strong> en C. Pour obtenir 3.25, il faudrait des <code>float</code> ou <code>double</code>.</div>
<div class="quiz-feedback quiz-feedback-incorrect" hidden>❌ Pas tout à fait. La bonne réponse est <strong>B — <code>3</code></strong>. En C, diviser deux <code>int</code> donne un <code>int</code> : la partie décimale est jetée. 13 / 4 = 3 (reste 1, que tu récupères avec <code>13 % 4</code>).</div>
</div>

<div class="quiz-question" data-correct="2">
<p class="quiz-number">Question 1.2</p>
<p class="quiz-prompt">Que vaut <code>13 % 4</code> ?</p>
<ul class="quiz-options">
  <li class="quiz-option"><span class="quiz-option-marker">A</span> <code>3</code></li>
  <li class="quiz-option"><span class="quiz-option-marker">B</span> <code>4</code></li>
  <li class="quiz-option"><span class="quiz-option-marker">C</span> <code>1</code></li>
  <li class="quiz-option"><span class="quiz-option-marker">D</span> <code>0</code></li>
</ul>
<button class="quiz-check" disabled>Vérifier</button>
<div class="quiz-feedback quiz-feedback-correct" hidden>✅ Correct ! <code>13 = 4 × 3 + 1</code>, donc le reste est <strong>1</strong>. Le modulo donne toujours ce qui « déborde » après la division entière.</div>
<div class="quiz-feedback quiz-feedback-incorrect" hidden>❌ Pas tout à fait. La bonne réponse est <strong>C — <code>1</code></strong>. Le modulo (<code>%</code>) donne le reste de la division entière. 13 = 4 × 3 + <strong>1</strong>, donc <code>13 % 4 = 1</code>.</div>
</div>

<div class="quiz-question" data-correct="1">
<p class="quiz-number">Question 1.3</p>
<p class="quiz-prompt">Quelle expression permet de vérifier qu'un <code>int n</code> est pair ?</p>
<ul class="quiz-options">
  <li class="quiz-option"><span class="quiz-option-marker">A</span> <code>n / 2 == 0</code></li>
  <li class="quiz-option"><span class="quiz-option-marker">B</span> <code>n % 2 == 0</code></li>
  <li class="quiz-option"><span class="quiz-option-marker">C</span> <code>n - 2 == 0</code></li>
  <li class="quiz-option"><span class="quiz-option-marker">D</span> <code>n + 2 == 0</code></li>
</ul>
<button class="quiz-check" disabled>Vérifier</button>
<div class="quiz-feedback quiz-feedback-correct" hidden>✅ Correct ! <code>n % 2 == 0</code> — un nombre est pair si son reste de division par 2 vaut 0. C'est un réflexe fondamental : tu l'utiliseras constamment en piscine.</div>
<div class="quiz-feedback quiz-feedback-incorrect" hidden>❌ Pas tout à fait. La bonne réponse est <strong>B — <code>n % 2 == 0</code></strong>. Le modulo donne le reste de la division par 2 : 0 si pair, 1 si impair. <code>n / 2 == 0</code> ne vaut 0 que pour <code>n = 0</code> ou <code>n = 1</code>.</div>
</div>

<div class="quiz-question" data-correct="2">
<p class="quiz-number">Question 1.4</p>
<p class="quiz-prompt">Que vaut l'expression <code>2 + 3 * 4 - 1</code> ?</p>
<ul class="quiz-options">
  <li class="quiz-option"><span class="quiz-option-marker">A</span> <code>19</code></li>
  <li class="quiz-option"><span class="quiz-option-marker">B</span> <code>9</code></li>
  <li class="quiz-option"><span class="quiz-option-marker">C</span> <code>13</code></li>
  <li class="quiz-option"><span class="quiz-option-marker">D</span> <code>24</code></li>
</ul>
<button class="quiz-check" disabled>Vérifier</button>
<div class="quiz-feedback quiz-feedback-correct" hidden>✅ Correct ! La priorité de <code>*</code> sur <code>+</code> et <code>-</code> s'applique : <code>3 * 4 = 12</code> d'abord, puis <code>2 + 12 − 1 = <strong>13</strong></code>. Même règle qu'en maths.</div>
<div class="quiz-feedback quiz-feedback-incorrect" hidden>❌ Pas tout à fait. La bonne réponse est <strong>C — <code>13</code></strong>. La multiplication a priorité : on évalue <code>3 * 4 = 12</code> d'abord, puis <code>2 + 12 - 1 = 13</code>. Pour forcer un autre ordre, utilise des parenthèses.</div>
</div>

<div class="quiz-question" data-correct="0">
<p class="quiz-number">Question 1.5</p>
<p class="quiz-prompt">Quel est le résultat de <code>5 == 5 &amp;&amp; 3 &gt; 4</code> ?</p>
<ul class="quiz-options">
  <li class="quiz-option"><span class="quiz-option-marker">A</span> <code>0</code></li>
  <li class="quiz-option"><span class="quiz-option-marker">B</span> <code>1</code></li>
  <li class="quiz-option"><span class="quiz-option-marker">C</span> <code>2</code></li>
  <li class="quiz-option"><span class="quiz-option-marker">D</span> <code>5</code></li>
</ul>
<button class="quiz-check" disabled>Vérifier</button>
<div class="quiz-feedback quiz-feedback-correct" hidden>✅ Correct ! <code>5 == 5</code> → 1 (vrai). <code>3 &gt; 4</code> → 0 (faux). <code>1 &amp;&amp; 0</code> → <strong>0</strong>. Le ET logique est faux dès qu'un seul opérande est faux.</div>
<div class="quiz-feedback quiz-feedback-incorrect" hidden>❌ Pas tout à fait. La bonne réponse est <strong>A — <code>0</code></strong>. <code>5 == 5</code> est vrai (1), mais <code>3 &gt; 4</code> est faux (0). <code>&amp;&amp;</code> renvoie 0 dès qu'un opérande est faux.</div>
</div>

<div class="quiz-question" data-correct="2">
<p class="quiz-number">Question 1.6</p>
<p class="quiz-prompt">Quel est le résultat de <code>!0 + !5</code> ?</p>
<ul class="quiz-options">
  <li class="quiz-option"><span class="quiz-option-marker">A</span> <code>5</code></li>
  <li class="quiz-option"><span class="quiz-option-marker">B</span> <code>0</code></li>
  <li class="quiz-option"><span class="quiz-option-marker">C</span> <code>1</code></li>
  <li class="quiz-option"><span class="quiz-option-marker">D</span> <code>6</code></li>
</ul>
<button class="quiz-check" disabled>Vérifier</button>
<div class="quiz-feedback quiz-feedback-correct" hidden>✅ Correct ! <code>!0</code> = 1 (la négation de faux est vrai). <code>!5</code> = 0 (tout non-zéro est vrai, donc sa négation est 0). Résultat : 1 + 0 = <strong>1</strong>.</div>
<div class="quiz-feedback quiz-feedback-incorrect" hidden>❌ Pas tout à fait. La bonne réponse est <strong>C — <code>1</code></strong>. En C, 0 est faux et tout le reste est vrai. Donc : <code>!0</code> = 1 et <code>!5</code> = 0. Addition : 1 + 0 = 1.</div>
</div>

<div class="quiz-question" data-correct="1">
<p class="quiz-number">Question 1.7</p>
<p class="quiz-prompt">Quelle est l'erreur dans ce code ?<br><br><code>n = 10;<br>if (n = 0) { ... }</code></p>
<ul class="quiz-options">
  <li class="quiz-option"><span class="quiz-option-marker">A</span> Il manque un <code>;</code>.</li>
  <li class="quiz-option"><span class="quiz-option-marker">B</span> <code>n = 0</code> est une affectation, pas une comparaison — il fallait <code>n == 0</code>.</li>
  <li class="quiz-option"><span class="quiz-option-marker">C</span> L'accolade est mal placée.</li>
  <li class="quiz-option"><span class="quiz-option-marker">D</span> Il n'y a pas d'erreur.</li>
</ul>
<button class="quiz-check" disabled>Vérifier</button>
<div class="quiz-feedback quiz-feedback-correct" hidden>✅ Correct ! <code>if (n = 0)</code> <strong>affecte</strong> 0 à <code>n</code> et teste si le résultat (0) est vrai — ce qui est toujours faux. La condition ne s'exécutera jamais et <code>n</code> aura perdu sa valeur. Il fallait <code>if (n == 0)</code>. La Norm 42 interdit l'affectation dans une condition précisément pour éviter ce piège.</div>
<div class="quiz-feedback quiz-feedback-incorrect" hidden>❌ Pas tout à fait. La bonne réponse est <strong>B</strong> : <code>n = 0</code> est une <em>affectation</em> (un seul <code>=</code>), pas une <em>comparaison</em>. Il faut écrire <code>n == 0</code> (deux <code>=</code>). C'est l'une des erreurs les plus fréquentes en C.</div>
</div>

<p id="quiz-score" class="quiz-score"></p>

---

## Partie 2 — Exercices pratiques

### Exercice 2.1 — Le reste de la division

Écris un programme qui :

1. Déclare deux `int` nommés `dividende` (valeur 23) et `diviseur` (valeur 7).
2. Calcule et affiche le quotient sur un caractère, puis un espace, puis le reste sur un caractère.

Sortie attendue : `3 2\n`.

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
    	int	dividende;
    	int	diviseur;

    	dividende = 23;
    	diviseur = 7;
    	ft_putchar('0' + dividende / diviseur);
    	ft_putchar(' ');
    	ft_putchar('0' + dividende % diviseur);
    	ft_putchar('\n');
    	return (0);
    }
    ```

    Vérification : `23 / 7 = 3` (reste `2`), donc `23 = 7 × 3 + 2`. ✓

### Exercice 2.2 — Trois comparaisons

Écris un programme qui :

1. Déclare deux `int` `a = 4` et `b = 9`.
2. Affiche, sur une seule ligne et sans espace, les résultats des trois comparaisons : `a == b`, `a < b`, `a >= b`.

Sortie attendue : `010\n` (faux, vrai, faux).

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

    	a = 4;
    	b = 9;
    	ft_putchar('0' + (a == b));
    	ft_putchar('0' + (a < b));
    	ft_putchar('0' + (a >= b));
    	ft_putchar('\n');
    	return (0);
    }
    ```

    Note l'usage de parenthèses autour des comparaisons : techniquement pas obligatoires ici (priorité de `+` plus basse que `==`/`<`/`>=`), mais elles rendent l'intention plus claire.

### Exercice 2.3 — Table de vérité

Écris un programme qui affiche, sur deux lignes, la **table de vérité** de l'opérateur `&&` pour deux variables qui valent chacune `0` ou `1`.

Sortie attendue :

```
0 0 0
0 1 0
1 0 0
1 1 1
```

(Format de chaque ligne : `a` espace `b` espace `a && b`.)

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
    	ft_putchar('0');
    	ft_putchar(' ');
    	ft_putchar('0');
    	ft_putchar(' ');
    	ft_putchar('0' + (0 && 0));
    	ft_putchar('\n');
    	ft_putchar('0');
    	ft_putchar(' ');
    	ft_putchar('1');
    	ft_putchar(' ');
    	ft_putchar('0' + (0 && 1));
    	ft_putchar('\n');
    	ft_putchar('1');
    	ft_putchar(' ');
    	ft_putchar('0');
    	ft_putchar(' ');
    	ft_putchar('0' + (1 && 0));
    	ft_putchar('\n');
    	ft_putchar('1');
    	ft_putchar(' ');
    	ft_putchar('1');
    	ft_putchar(' ');
    	ft_putchar('0' + (1 && 1));
    	ft_putchar('\n');
    	return (0);
    }
    ```

    !!! tip "Astuce"
        Dans cet exercice, on calcule explicitement `0 && 0`, `0 && 1`, etc. Le compilateur va même optimiser ça à la compilation, mais ça illustre bien le comportement.

### Exercice 2.4 — Trouve l'erreur de priorité

Voici un programme qui devrait afficher `1` (car `(5 + 3) / 2 = 4`, et `4 == 4` est vrai), mais qui affiche `0`. Pourquoi ?

```c
int	resultat;

resultat = 5 + 3 / 2 == 4;
ft_putchar('0' + resultat);
ft_putchar('\n');
```

??? success "Réponse"
    Le piège : la priorité.

    L'expression est interprétée comme : `5 + (3 / 2) == 4`.

    - `3 / 2 = 1` (division entière).
    - `5 + 1 = 6`.
    - `6 == 4` → `0` (faux).

    Sortie : `0`.

    Pour obtenir le comportement voulu, il faut **forcer les parenthèses** :

    ```c
    resultat = ((5 + 3) / 2) == 4;
    ```

    Cette correction donne bien `1`.

    C'est exactement le genre de bug que les parenthèses explicites évitent.

### Exercice 2.5 — Court-circuit

Écris un programme qui démontre l'évaluation court-circuit en évitant une division par zéro. Le programme doit :

1. Déclarer un `int n` qui vaut `0`.
2. Calculer `resultat = (n != 0) && (10 / n > 2)`.
3. Afficher `resultat`.

**Question :** que vaut la sortie ? Pourquoi le programme ne crashe-t-il pas ?

??? success "Solution + Réponse"
    ```c
    /* en-tête 42 ici */

    #include <unistd.h>

    void	ft_putchar(char c)
    {
    	write(1, &c, 1);
    }

    int	main(void)
    {
    	int	n;
    	int	resultat;

    	n = 0;
    	resultat = (n != 0) && (10 / n > 2);
    	ft_putchar('0' + resultat);
    	ft_putchar('\n');
    	return (0);
    }
    ```

    Sortie : `0`.

    Pas de crash, car l'évaluation court-circuit s'applique :

    - `n != 0` est faux (`0`).
    - `&&` voit que le premier opérande est faux, conclut immédiatement que le résultat est faux, et **n'évalue pas** la seconde partie.
    - `10 / n` n'est donc jamais calculé, et pas de division par zéro.

    **Si tu inversais l'ordre** (`(10 / n > 2) && (n != 0)`), le programme **crasherait** avec « floating point exception ». L'ordre des opérandes en `&&` n'est pas anodin.

---

## Partie 3 — Bonus

### Exercice 3.1 — Le dernier chiffre

Écris un programme qui, à partir d'un `int n = 247`, affiche son **dernier chiffre** (le chiffre des unités), suivi d'un saut de ligne.

Sortie attendue : `7\n`.

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
    	int	n;

    	n = 247;
    	ft_putchar('0' + n % 10);
    	ft_putchar('\n');
    	return (0);
    }
    ```

    `n % 10` extrait toujours le chiffre des unités. Cette technique est universelle : elle te servira à afficher des nombres entiers chiffre par chiffre dès que tu connaîtras les boucles.

### Exercice 3.2 — Le chiffre du milieu

Toujours avec `n = 247`, écris un programme qui affiche son **chiffre du milieu** (les dizaines), soit `4`.

**Indice :** combine `/` et `%`.

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
    	int	n;

    	n = 247;
    	ft_putchar('0' + (n / 10) % 10);
    	ft_putchar('\n');
    	return (0);
    }
    ```

    Décortiquons :

    - `n / 10` = `24` (on a « retiré » le chiffre des unités).
    - `24 % 10` = `4` (le nouveau chiffre des unités est l'ancien chiffre des dizaines).

    Sortie : `4`.

    Généralisation : pour extraire le N-ième chiffre en partant de la droite (0-indexé), tu fais `(n / 10^N) % 10`. Tu utiliseras cette technique constamment en piscine.

### Exercice 3.3 — Trace mentale

Sans compiler, donne la sortie de ce programme :

```c
int	a;
int	b;
int	c;

a = 3;
b = 5;
c = (a > 2) && (b < 10) && (a + b == 8);
ft_putchar('0' + c);
c = (a == b) || (a + b > 7);
ft_putchar('0' + c);
c = !(a == b) && !(a > b);
ft_putchar('0' + c);
ft_putchar('\n');
```

??? success "Réponse"
    Décortiquons :

    - 1er : `(3 > 2) && (5 < 10) && (3 + 5 == 8)` = `1 && 1 && 1` = **`1`**.
    - 2e : `(3 == 5) || (3 + 5 > 7)` = `0 || 1` = **`1`**.
    - 3e : `!(3 == 5) && !(3 > 5)` = `!0 && !0` = `1 && 1` = **`1`**.

    Sortie : `111\n`.

---

## Validation finale

Avant de passer au Support 05, assure-toi de savoir faire **sans hésiter** :

- [ ] Calculer mentalement le résultat d'une division entière (`13 / 4 = 3`).
- [ ] Calculer mentalement un modulo (`13 % 4 = 1`).
- [ ] Tester la parité d'un nombre avec `% 2`.
- [ ] Extraire le dernier chiffre d'un entier avec `% 10`.
- [ ] Distinguer `=` (affectation) de `==` (comparaison) au premier coup d'œil.
- [ ] Évaluer mentalement une expression avec `&&`, `||`, `!`.
- [ ] Comprendre pourquoi l'ordre dans un `&&` permet d'éviter des erreurs.
- [ ] Ajouter des parenthèses préventives quand une expression dépasse 2 opérateurs.

Si tu butes sur l'un de ces points, refais l'exercice 3.3 jusqu'à le faire de tête en moins d'une minute.

---

➡️ **Retour au cours :** [Support 04 — Opérateurs](./cours.md)
➡️ **Support suivant :** [Support 05 — Conditions](../support-05/cours.md)
