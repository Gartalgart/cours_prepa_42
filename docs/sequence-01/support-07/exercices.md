# Support 07 — Exercices

> **Objectif :** Écrire et utiliser des fonctions avec paramètres et valeur de retour, maîtriser la récursivité, implémenter `ft_putnbr`.

Pour chaque exercice : compile avec `cc -Wall -Wextra -Werror`, valide avec `norminette`, vérifie la sortie.

---

## Partie 1 — Quiz

<div class="quiz-question" data-correct="2">
<p class="quiz-number">Question 1.1</p>
<p class="quiz-prompt">Combien de paramètres une fonction peut-elle avoir au maximum à la Norm 42 ?</p>
<ul class="quiz-options">
  <li class="quiz-option"><span class="quiz-option-marker">A</span> 2</li>
  <li class="quiz-option"><span class="quiz-option-marker">B</span> 3</li>
  <li class="quiz-option"><span class="quiz-option-marker">C</span> 4</li>
  <li class="quiz-option"><span class="quiz-option-marker">D</span> Aucune limite</li>
</ul>
<button class="quiz-check" disabled>Vérifier</button>
<div class="quiz-feedback quiz-feedback-correct" hidden>✅ Correct ! <strong>4</strong> paramètres maximum. Si tu en as besoin de plus, c'est généralement signe que ta fonction fait trop de choses — découpe-la.</div>
<div class="quiz-feedback quiz-feedback-incorrect" hidden>❌ Pas tout à fait. La bonne réponse est <strong>C — 4</strong>. La Norm 42 limite chaque fonction à 4 paramètres maximum.</div>
</div>

<div class="quiz-question" data-correct="1">
<p class="quiz-number">Question 1.2</p>
<p class="quiz-prompt">Quel est l'effet de <code>return (5);</code> dans une fonction ?</p>
<ul class="quiz-options">
  <li class="quiz-option"><span class="quiz-option-marker">A</span> Affiche <code>5</code> à l'écran.</li>
  <li class="quiz-option"><span class="quiz-option-marker">B</span> Termine la fonction et renvoie la valeur <code>5</code> à l'appelant.</li>
  <li class="quiz-option"><span class="quiz-option-marker">C</span> Affecte <code>5</code> à une variable globale.</li>
  <li class="quiz-option"><span class="quiz-option-marker">D</span> Ne fait rien.</li>
</ul>
<button class="quiz-check" disabled>Vérifier</button>
<div class="quiz-feedback quiz-feedback-correct" hidden>✅ Correct ! <code>return</code> <strong>termine immédiatement la fonction</strong> et renvoie la valeur (ici <code>5</code>) à l'appelant. Le code après le <code>return</code> dans cette branche n'est jamais exécuté.</div>
<div class="quiz-feedback quiz-feedback-incorrect" hidden>❌ Pas tout à fait. La bonne réponse est <strong>B</strong>. <code>return</code> n'affiche rien : il met fin à la fonction et renvoie la valeur à l'appelant.</div>
</div>

<div class="quiz-question" data-correct="2">
<p class="quiz-number">Question 1.3</p>
<p class="quiz-prompt">Que va afficher ce programme ?<br><br><code>int ft_test(int n)<br>{<br>&nbsp;&nbsp;&nbsp;&nbsp;if (n &gt; 5) { return (1); }<br>&nbsp;&nbsp;&nbsp;&nbsp;return (0);<br>}<br>// main :<br>ft_putchar('0' + ft_test(7));<br>ft_putchar('0' + ft_test(3));</code></p>
<ul class="quiz-options">
  <li class="quiz-option"><span class="quiz-option-marker">A</span> <code>00</code></li>
  <li class="quiz-option"><span class="quiz-option-marker">B</span> <code>11</code></li>
  <li class="quiz-option"><span class="quiz-option-marker">C</span> <code>10</code></li>
  <li class="quiz-option"><span class="quiz-option-marker">D</span> <code>01</code></li>
</ul>
<button class="quiz-check" disabled>Vérifier</button>
<div class="quiz-feedback quiz-feedback-correct" hidden>✅ Correct ! <code>10</code>. <code>ft_test(7)</code> renvoie <code>1</code> (car <code>7 &gt; 5</code>), <code>ft_test(3)</code> renvoie <code>0</code> (car <code>3 &lt;= 5</code>).</div>
<div class="quiz-feedback quiz-feedback-incorrect" hidden>❌ Pas tout à fait. La bonne réponse est <strong>C — <code>10</code></strong>. <code>ft_test(7)</code> → 1, <code>ft_test(3)</code> → 0.</div>
</div>

<div class="quiz-question" data-correct="1">
<p class="quiz-number">Question 1.4</p>
<p class="quiz-prompt">Le code suivant compile-t-il avec <code>-Wall -Wextra -Werror</code> ?<br><br><code>int main(void)<br>{<br>&nbsp;&nbsp;&nbsp;&nbsp;int x;<br>&nbsp;&nbsp;&nbsp;&nbsp;x = ft_double(5);<br>&nbsp;&nbsp;&nbsp;&nbsp;return (0);<br>}<br>int ft_double(int n) { return (n * 2); }</code></p>
<ul class="quiz-options">
  <li class="quiz-option"><span class="quiz-option-marker">A</span> Oui, sans warning.</li>
  <li class="quiz-option"><span class="quiz-option-marker">B</span> Non, il manque un prototype de <code>ft_double</code> avant <code>main</code>.</li>
  <li class="quiz-option"><span class="quiz-option-marker">C</span> Oui, mais avec un warning.</li>
</ul>
<button class="quiz-check" disabled>Vérifier</button>
<div class="quiz-feedback quiz-feedback-correct" hidden>✅ Correct ! Avec <code>-Wall -Wextra -Werror</code>, le compilateur refuse parce que <code>ft_double</code> est utilisée avant d'être connue. Il faut soit la définir avant <code>main</code>, soit ajouter un <strong>prototype</strong> : <code>int ft_double(int n);</code>.</div>
<div class="quiz-feedback quiz-feedback-incorrect" hidden>❌ Pas tout à fait. La bonne réponse est <strong>B</strong>. <code>ft_double</code> est appelée avant d'être déclarée : avec <code>-Werror</code>, c'est une erreur. Il faut un prototype.</div>
</div>

<div class="quiz-question" data-correct="1">
<p class="quiz-number">Question 1.5</p>
<p class="quiz-prompt">Que fait cette fonction récursive ?<br><br><code>int ft_mystere(int n)<br>{<br>&nbsp;&nbsp;&nbsp;&nbsp;if (n == 0) { return (0); }<br>&nbsp;&nbsp;&nbsp;&nbsp;return (n + ft_mystere(n - 1));<br>}</code></p>
<ul class="quiz-options">
  <li class="quiz-option"><span class="quiz-option-marker">A</span> Renvoie <code>n</code> multiplié par 2.</li>
  <li class="quiz-option"><span class="quiz-option-marker">B</span> Renvoie la somme des entiers de 1 à n.</li>
  <li class="quiz-option"><span class="quiz-option-marker">C</span> Renvoie la factorielle de n.</li>
  <li class="quiz-option"><span class="quiz-option-marker">D</span> Boucle infinie.</li>
</ul>
<button class="quiz-check" disabled>Vérifier</button>
<div class="quiz-feedback quiz-feedback-correct" hidden>✅ Correct ! Elle renvoie <strong>la somme <code>1 + 2 + ... + n</code></strong>. Par exemple <code>ft_mystere(3)</code> = <code>3 + 2 + 1</code> = 6.</div>
<div class="quiz-feedback quiz-feedback-incorrect" hidden>❌ Pas tout à fait. La bonne réponse est <strong>B</strong>. À chaque appel on ajoute <code>n</code> au résultat de <code>ft_mystere(n - 1)</code> : c'est la somme de 1 à n.</div>
</div>

<div class="quiz-question" data-correct="1">
<p class="quiz-number">Question 1.6</p>
<p class="quiz-prompt">Pourquoi <code>ft_putnbr</code> doit-elle traiter <code>-2147483648</code> à part ?</p>
<ul class="quiz-options">
  <li class="quiz-option"><span class="quiz-option-marker">A</span> Parce que <code>printf</code> ne sait pas l'afficher.</li>
  <li class="quiz-option"><span class="quiz-option-marker">B</span> Parce que <code>-(-2147483648)</code> provoque un débordement d'entier.</li>
  <li class="quiz-option"><span class="quiz-option-marker">C</span> Parce que la Norm 42 l'exige.</li>
  <li class="quiz-option"><span class="quiz-option-marker">D</span> Parce que c'est plus rapide ainsi.</li>
</ul>
<button class="quiz-check" disabled>Vérifier</button>
<div class="quiz-feedback quiz-feedback-correct" hidden>✅ Correct ! <code>-2147483648</code> est <code>INT_MIN</code>. Calculer <code>-n</code> quand <code>n</code> vaut <code>INT_MIN</code> donne <code>+2147483648</code>, qui dépasse <code>INT_MAX</code> (<code>+2147483647</code>) : comportement indéfini. On écrit donc ce cas directement.</div>
<div class="quiz-feedback quiz-feedback-incorrect" hidden>❌ Pas tout à fait. La bonne réponse est <strong>B</strong>. Nier <code>INT_MIN</code> dépasse <code>INT_MAX</code> : il faut traiter ce cas séparément.</div>
</div>

<p id="quiz-score" class="quiz-score"></p>

---

## Partie 2 — Exercices pratiques

### Exercice 2.1 — `ft_min`

Écris une fonction `ft_min(int a, int b)` qui renvoie le plus petit des deux entiers. Teste avec `ft_min(7, 3)`, affiche le résultat.

Sortie attendue : `3\n`.

??? success "Solution"
    ```c
    /* en-tête 42 ici */

    #include <unistd.h>

    void	ft_putchar(char c)
    {
    	write(1, &c, 1);
    }

    int	ft_min(int a, int b)
    {
    	if (a < b)
    	{
    		return (a);
    	}
    	return (b);
    }

    int	main(void)
    {
    	ft_putchar('0' + ft_min(7, 3));
    	ft_putchar('\n');
    	return (0);
    }
    ```

### Exercice 2.2 — `ft_est_pair`

Écris une fonction `ft_est_pair(int n)` qui renvoie `1` si `n` est pair, `0` sinon.

Démontre-la dans `main` en affichant `ft_est_pair(4)` puis `ft_est_pair(7)` sur la même ligne.

Sortie attendue : `10\n`.

??? success "Solution"
    ```c
    /* en-tête 42 ici */

    #include <unistd.h>

    void	ft_putchar(char c)
    {
    	write(1, &c, 1);
    }

    int	ft_est_pair(int n)
    {
    	if (n % 2 == 0)
    	{
    		return (1);
    	}
    	return (0);
    }

    int	main(void)
    {
    	ft_putchar('0' + ft_est_pair(4));
    	ft_putchar('0' + ft_est_pair(7));
    	ft_putchar('\n');
    	return (0);
    }
    ```

### Exercice 2.3 — Réutilise `ft_putnbr`

En partant du code de `ft_putnbr` du cours, écris un `main` qui affiche les nombres `-100`, `0`, `42`, `2147483647`, chacun sur sa propre ligne.

Sortie attendue :

```
-100
0
42
2147483647
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
    	if (n == -2147483648)
    	{
    		write(1, "-2147483648", 11);
    		return ;
    	}
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

    int	main(void)
    {
    	ft_putnbr(-100);
    	ft_putchar('\n');
    	ft_putnbr(0);
    	ft_putchar('\n');
    	ft_putnbr(42);
    	ft_putchar('\n');
    	ft_putnbr(2147483647);
    	ft_putchar('\n');
    	return (0);
    }
    ```

### Exercice 2.4 — Somme de 1 à N (récursif)

Écris une fonction récursive `ft_somme(int n)` qui renvoie `1 + 2 + ... + n`. Teste avec `ft_somme(10)` (doit renvoyer `55`). Affiche le résultat avec `ft_putnbr`.

Sortie attendue : `55\n`.

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

    int	ft_somme(int n)
    {
    	if (n <= 0)
    	{
    		return (0);
    	}
    	return (n + ft_somme(n - 1));
    }

    int	main(void)
    {
    	ft_putnbr(ft_somme(10));
    	ft_putchar('\n');
    	return (0);
    }
    ```

    Vérification : `1+2+3+4+5+6+7+8+9+10 = 55`. ✓

### Exercice 2.5 — `ft_puissance` (récursif)

Écris une fonction récursive `ft_puissance(int base, int exposant)` qui calcule `base` à la puissance `exposant`. Suppose que `exposant >= 0`.

Teste avec `ft_puissance(2, 10)` (doit renvoyer `1024`). Affiche avec `ft_putnbr`.

Sortie attendue : `1024\n`.

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

    int	ft_puissance(int base, int exposant)
    {
    	if (exposant == 0)
    	{
    		return (1);
    	}
    	return (base * ft_puissance(base, exposant - 1));
    }

    int	main(void)
    {
    	ft_putnbr(ft_puissance(2, 10));
    	ft_putchar('\n');
    	return (0);
    }
    ```

    Décortiquons :

    - `ft_puissance(2, 10)` = `2 * ft_puissance(2, 9)` = `2 * 2 * ft_puissance(2, 8)` = ... = `2^10` = `1024`.

### Exercice 2.6 — Fibonacci (récursif)

La suite de Fibonacci est définie par `F(0) = 0`, `F(1) = 1`, et `F(n) = F(n-1) + F(n-2)` pour `n >= 2`.

Écris une fonction récursive `ft_fibo(int n)` qui renvoie le N-ième terme. Teste avec `ft_fibo(10)` (doit renvoyer `55`).

Sortie attendue : `55\n`.

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

    int	ft_fibo(int n)
    {
    	if (n <= 1)
    	{
    		return (n);
    	}
    	return (ft_fibo(n - 1) + ft_fibo(n - 2));
    }

    int	main(void)
    {
    	ft_putnbr(ft_fibo(10));
    	ft_putchar('\n');
    	return (0);
    }
    ```

    Vérification : `0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55`. Le 10e terme (en partant de 0) est bien `55`.

    !!! warning "Performance"
        Cette implémentation recalcule plein de valeurs. `ft_fibo(40)` prend déjà plusieurs secondes. Il existe des techniques pour éviter ça (boucle, mémoïsation), mais on les verra plus tard.

---

## Partie 3 — Bonus

### Exercice 3.1 — `ft_pgcd` (PGCD)

Le plus grand commun diviseur (PGCD) de deux nombres peut se calculer avec l'**algorithme d'Euclide** :

- `pgcd(a, 0) = a`.
- `pgcd(a, b) = pgcd(b, a % b)` si `b != 0`.

Écris une fonction récursive `ft_pgcd(int a, int b)`. Teste avec `ft_pgcd(48, 18)` (doit renvoyer `6`).

Sortie attendue : `6\n`.

??? success "Solution"
    ```c
    /* en-tête 42 ici */

    #include <unistd.h>

    void	ft_putchar(char c)
    {
    	write(1, &c, 1);
    }

    int	ft_pgcd(int a, int b)
    {
    	if (b == 0)
    	{
    		return (a);
    	}
    	return (ft_pgcd(b, a % b));
    }

    int	main(void)
    {
    	ft_putchar('0' + ft_pgcd(48, 18));
    	ft_putchar('\n');
    	return (0);
    }
    ```

    Trace :

    - `ft_pgcd(48, 18)` = `ft_pgcd(18, 48 % 18)` = `ft_pgcd(18, 12)`.
    - `ft_pgcd(18, 12)` = `ft_pgcd(12, 18 % 12)` = `ft_pgcd(12, 6)`.
    - `ft_pgcd(12, 6)` = `ft_pgcd(6, 12 % 6)` = `ft_pgcd(6, 0)`.
    - `ft_pgcd(6, 0)` = `6`.

### Exercice 3.2 — Version itérative de `ft_somme`

Réécris `ft_somme(int n)` de l'exercice 2.4 sans utiliser la récursivité — en utilisant une boucle `while`. Compare la longueur avec la version récursive.

??? success "Solution"
    ```c
    int	ft_somme(int n)
    {
    	int	i;
    	int	total;

    	i = 1;
    	total = 0;
    	while (i <= n)
    	{
    		total = total + i;
    		i++;
    	}
    	return (total);
    }
    ```

    Comparaison :

    | Aspect | Récursive | Itérative |
    |---|---|---|
    | Lignes de code | 4 (très concis) | 10 (plus verbeux) |
    | Variables locales | 0 | 2 |
    | Pile d'appel | Profondeur N | Plate |
    | Risque de stack overflow | Oui pour N grand | Non |
    | Lisibilité (pour débutants) | Élégante mais déroutante | Plus directe |

    Aucune des deux n'est « la bonne » — choisis selon le problème.

### Exercice 3.3 — Lecture de code

Sans compiler, donne la sortie de ce programme :

```c
void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	ft_truc(int n)
{
	if (n <= 0)
	{
		return (0);
	}
	ft_putchar('0' + n % 10);
	ft_truc(n / 10);
	return (1);
}

int	main(void)
{
	ft_truc(123);
	ft_putchar('\n');
	return (0);
}
```

??? success "Réponse"
    Décortiquons `ft_truc(123)` :

    1. `n = 123` → on affiche `'0' + 123 % 10` = `'3'`. Puis on appelle `ft_truc(12)`.
    2. `n = 12` → on affiche `'2'`. Puis on appelle `ft_truc(1)`.
    3. `n = 1` → on affiche `'1'`. Puis on appelle `ft_truc(0)`.
    4. `n = 0` → on sort directement (`return (0)`).

    Sortie : **`321\n`**.

    Cette fonction affiche les chiffres **à l'envers**. À comparer avec `ft_putnbr` qui les affiche dans l'ordre — la différence est l'**ordre** entre l'appel récursif et l'affichage.

---

## Validation finale

Avant de passer au Support 08, assure-toi de savoir faire **sans hésiter** :

- [ ] Définir une fonction avec type de retour, paramètres, corps, et `return`.
- [ ] Écrire un prototype en haut d'un fichier.
- [ ] Appeler une fonction comme valeur dans une expression.
- [ ] Identifier les deux ingrédients d'une fonction récursive (cas de base, appel convergent).
- [ ] Écrire `ft_putnbr` de mémoire (gestion `INT_MIN` incluse).
- [ ] Comprendre pourquoi `-INT_MIN` est un piège.
- [ ] Compter les lignes de tes fonctions pour respecter la limite des 25.
- [ ] Choisir entre boucle et récursivité selon le problème.

Si tu butes, refais l'exercice 2.3 (`ft_putnbr`) en l'écrivant **sans regarder** la solution. C'est l'exercice de référence du support — il faut le maîtriser à fond.

---

➡️ **Retour au cours :** [Support 07 — Fonctions](./cours.md)
➡️ **Support suivant :** [Support 08 — Tableaux et chaînes](../support-08/cours.md)
