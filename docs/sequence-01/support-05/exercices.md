# Support 05 — Exercices

> **Objectif :** Utiliser `if`, `else`, `else if` aux normes 42 pour résoudre des problèmes concrets de décision.

Compile chaque exercice avec `cc -Wall -Wextra -Werror`, valide avec `norminette`, vérifie la sortie.

---

## Partie 1 — Quiz

<div class="quiz-question" data-correct="0">
<p class="quiz-number">Question 1.1</p>
<p class="quiz-prompt">En C, qu'est-ce qui est considéré comme <strong>faux</strong> dans une condition <code>if</code> ?</p>
<ul class="quiz-options">
  <li class="quiz-option"><span class="quiz-option-marker">A</span> La valeur <code>0</code></li>
  <li class="quiz-option"><span class="quiz-option-marker">B</span> La valeur <code>1</code></li>
  <li class="quiz-option"><span class="quiz-option-marker">C</span> La valeur <code>-1</code></li>
  <li class="quiz-option"><span class="quiz-option-marker">D</span> Toute valeur négative</li>
</ul>
<button class="quiz-check" disabled>Vérifier</button>
<div class="quiz-feedback quiz-feedback-correct" hidden>✅ Correct ! Seule la valeur <strong><code>0</code></strong> est considérée comme fausse. Tout le reste (<code>1</code>, <code>-1</code>, <code>42</code>, <code>-100</code>…) est vrai.</div>
<div class="quiz-feedback quiz-feedback-incorrect" hidden>❌ Pas tout à fait. La bonne réponse est <strong>A — <code>0</code></strong>. En C, seule la valeur 0 est fausse ; toute autre valeur, positive ou négative, est vraie.</div>
</div>

<div class="quiz-question" data-correct="1">
<p class="quiz-number">Question 1.2</p>
<p class="quiz-prompt">Quel est le style d'accolade accepté par la Norm 42 pour un <code>if</code> ?</p>
<ul class="quiz-options">
  <li class="quiz-option"><span class="quiz-option-marker">A</span> <code>if (x &gt; 0) {<br>&nbsp;&nbsp;&nbsp;&nbsp;...<br>}</code></li>
  <li class="quiz-option"><span class="quiz-option-marker">B</span> <code>if (x &gt; 0)<br>{<br>&nbsp;&nbsp;&nbsp;&nbsp;...<br>}</code></li>
  <li class="quiz-option"><span class="quiz-option-marker">C</span> Les deux sont équivalents.</li>
</ul>
<button class="quiz-check" disabled>Vérifier</button>
<div class="quiz-feedback quiz-feedback-correct" hidden>✅ Correct ! Seul le <strong>style Allman</strong> (accolade ouvrante sur sa propre ligne) est accepté. Le style K&amp;R fait échouer <code>norminette</code>.</div>
<div class="quiz-feedback quiz-feedback-incorrect" hidden>❌ Pas tout à fait. La bonne réponse est <strong>B</strong> — le style Allman, avec l'accolade ouvrante seule sur sa propre ligne. Le style K&amp;R fait échouer <code>norminette</code>.</div>
</div>

<div class="quiz-question" data-correct="1">
<p class="quiz-number">Question 1.3</p>
<p class="quiz-prompt">Que va afficher ce programme ?<br><br><code>n = 0;<br>if (n)<br>{<br>&nbsp;&nbsp;&nbsp;&nbsp;ft_putchar('A');<br>}<br>else<br>{<br>&nbsp;&nbsp;&nbsp;&nbsp;ft_putchar('B');<br>}</code></p>
<ul class="quiz-options">
  <li class="quiz-option"><span class="quiz-option-marker">A</span> <code>A</code></li>
  <li class="quiz-option"><span class="quiz-option-marker">B</span> <code>B</code></li>
  <li class="quiz-option"><span class="quiz-option-marker">C</span> Erreur de compilation</li>
  <li class="quiz-option"><span class="quiz-option-marker">D</span> Rien</li>
</ul>
<button class="quiz-check" disabled>Vérifier</button>
<div class="quiz-feedback quiz-feedback-correct" hidden>✅ Correct ! <code>B</code>. La condition <code>if (n)</code> teste si <code>n</code> est différent de zéro. Comme <code>n</code> vaut <code>0</code>, la condition est fausse, et c'est le <code>else</code> qui s'exécute.</div>
<div class="quiz-feedback quiz-feedback-incorrect" hidden>❌ Pas tout à fait. La bonne réponse est <strong>B — <code>B</code></strong>. <code>if (n)</code> est faux quand <code>n</code> vaut 0, donc le bloc <code>else</code> s'exécute.</div>
</div>

<div class="quiz-question" data-correct="1">
<p class="quiz-number">Question 1.4</p>
<p class="quiz-prompt">Que va afficher ce programme ?<br><br><code>n = 5;<br>if (n &gt; 0) { ft_putchar('A'); }<br>if (n &gt; 3) { ft_putchar('B'); }<br>if (n &gt; 10) { ft_putchar('C'); }</code></p>
<ul class="quiz-options">
  <li class="quiz-option"><span class="quiz-option-marker">A</span> <code>A</code></li>
  <li class="quiz-option"><span class="quiz-option-marker">B</span> <code>AB</code></li>
  <li class="quiz-option"><span class="quiz-option-marker">C</span> <code>ABC</code></li>
  <li class="quiz-option"><span class="quiz-option-marker">D</span> <code>B</code></li>
</ul>
<button class="quiz-check" disabled>Vérifier</button>
<div class="quiz-feedback quiz-feedback-correct" hidden>✅ Correct ! <code>AB</code>. Les trois <code>if</code> sont <strong>indépendants</strong> : <code>5 &gt; 0</code> (vrai → A), <code>5 &gt; 3</code> (vrai → B), <code>5 &gt; 10</code> (faux). Avec des <code>else if</code>, seul <code>A</code> serait affiché.</div>
<div class="quiz-feedback quiz-feedback-incorrect" hidden>❌ Pas tout à fait. La bonne réponse est <strong>B — <code>AB</code></strong>. Les trois <code>if</code> sont indépendants : <code>5 &gt; 0</code> et <code>5 &gt; 3</code> sont vrais (A et B), <code>5 &gt; 10</code> est faux.</div>
</div>

<div class="quiz-question" data-correct="1">
<p class="quiz-number">Question 1.5</p>
<p class="quiz-prompt">Quel est le résultat de ce code avec <code>n = -7</code> ?<br><br><code>if (n &gt; 0) { ft_putchar('+'); }<br>else if (n &lt; 0) { ft_putchar('-'); }<br>else { ft_putchar('0'); }</code></p>
<ul class="quiz-options">
  <li class="quiz-option"><span class="quiz-option-marker">A</span> <code>+</code></li>
  <li class="quiz-option"><span class="quiz-option-marker">B</span> <code>-</code></li>
  <li class="quiz-option"><span class="quiz-option-marker">C</span> <code>0</code></li>
  <li class="quiz-option"><span class="quiz-option-marker">D</span> Aucun affichage</li>
</ul>
<button class="quiz-check" disabled>Vérifier</button>
<div class="quiz-feedback quiz-feedback-correct" hidden>✅ Correct ! <code>-</code>. La première condition (<code>n &gt; 0</code>) est fausse, la deuxième (<code>n &lt; 0</code>) est vraie : on affiche <code>-</code> et le <code>else</code> final est sauté.</div>
<div class="quiz-feedback quiz-feedback-incorrect" hidden>❌ Pas tout à fait. La bonne réponse est <strong>B — <code>-</code></strong>. <code>n</code> vaut -7 : <code>n &gt; 0</code> est faux, <code>n &lt; 0</code> est vrai → on affiche <code>-</code>.</div>
</div>

<div class="quiz-question" data-correct="0">
<p class="quiz-number">Question 1.6</p>
<p class="quiz-prompt">Le code suivant est-il accepté par la Norm 42 ?<br><br><code>if (n &gt; 0)<br>&nbsp;&nbsp;&nbsp;&nbsp;ft_putchar('+');<br>else<br>&nbsp;&nbsp;&nbsp;&nbsp;ft_putchar('-');</code></p>
<ul class="quiz-options">
  <li class="quiz-option"><span class="quiz-option-marker">A</span> Oui (mais peu recommandé).</li>
  <li class="quiz-option"><span class="quiz-option-marker">B</span> Non, il manque les accolades.</li>
  <li class="quiz-option"><span class="quiz-option-marker">C</span> Non, le style est K&amp;R.</li>
</ul>
<button class="quiz-check" disabled>Vérifier</button>
<div class="quiz-feedback quiz-feedback-correct" hidden>✅ Correct ! La Norm 42 accepte les <code>if</code>/<code>else</code> sans accolades quand une seule instruction suit (sur la ligne suivante, indentée). Par sécurité, <strong>mets toujours les accolades</strong> : tu n'oublieras pas le jour où tu ajouteras une seconde instruction.</div>
<div class="quiz-feedback quiz-feedback-incorrect" hidden>❌ Pas tout à fait. La bonne réponse est <strong>A — Oui</strong>. La Norm tolère l'absence d'accolades pour une instruction unique, mais par convention pédagogique mets-les toujours.</div>
</div>

<div class="quiz-question" data-correct="2">
<p class="quiz-number">Question 1.7</p>
<p class="quiz-prompt">Pourquoi l'opérateur ternaire (<code>? :</code>) ne doit-il jamais apparaître dans ton code à 42 ?</p>
<ul class="quiz-options">
  <li class="quiz-option"><span class="quiz-option-marker">A</span> Il ne fonctionne pas correctement.</li>
  <li class="quiz-option"><span class="quiz-option-marker">B</span> Il est très lent.</li>
  <li class="quiz-option"><span class="quiz-option-marker">C</span> La Norm 42 l'interdit (erreur <code>TERNARY_FBIDDEN</code>).</li>
  <li class="quiz-option"><span class="quiz-option-marker">D</span> Il n'existe pas en C.</li>
</ul>
<button class="quiz-check" disabled>Vérifier</button>
<div class="quiz-feedback quiz-feedback-correct" hidden>✅ Correct ! L'opérateur ternaire existe en C et fonctionne très bien, mais la <strong>Norm 42 l'interdit</strong> explicitement (<code>TERNARY_FBIDDEN</code>). <code>norminette</code> rejette tout fichier qui en contient.</div>
<div class="quiz-feedback quiz-feedback-incorrect" hidden>❌ Pas tout à fait. La bonne réponse est <strong>C</strong>. Le ternaire fonctionne parfaitement en C standard, mais la Norm 42 l'interdit (<code>TERNARY_FBIDDEN</code>).</div>
</div>

<p id="quiz-score" class="quiz-score"></p>

---

## Partie 2 — Exercices pratiques

### Exercice 2.1 — Signe d'un nombre

Écris un programme qui affiche `+`, `-` ou `0` selon le signe d'un `int n`. Teste avec `n = 42`.

Sortie attendue : `+\n`.

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

    	n = 42;
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
    	ft_putchar('\n');
    	return (0);
    }
    ```

### Exercice 2.2 — Chiffre, lettre ou autre ?

Écris un programme qui prend une variable `char c` et affiche :

- `D` si `c` est un chiffre (`'0'` à `'9'`).
- `L` si `c` est une lettre (minuscule ou majuscule).
- `?` sinon.

Teste avec `c = 'k'`.

Sortie attendue : `L\n`.

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
    	char	c;

    	c = 'k';
    	if (c >= '0' && c <= '9')
    	{
    		ft_putchar('D');
    	}
    	else if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
    	{
    		ft_putchar('L');
    	}
    	else
    	{
    		ft_putchar('?');
    	}
    	ft_putchar('\n');
    	return (0);
    }
    ```

    Note l'usage de **parenthèses** autour des deux plages de lettres : on combine deux conditions avec `||`, donc on parenthèse pour la clarté.

### Exercice 2.3 — Maximum de deux nombres

Écris un programme qui affiche le plus grand de deux `int` `a` et `b` (qui tiennent sur un chiffre).

Teste avec `a = 4`, `b = 7`.

Sortie attendue : `7\n`.

**Contrainte :** pas d'opérateur ternaire (rappel : interdit).

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
    	int	max;

    	a = 4;
    	b = 7;
    	if (a > b)
    	{
    		max = a;
    	}
    	else
    	{
    		max = b;
    	}
    	ft_putchar('0' + max);
    	ft_putchar('\n');
    	return (0);
    }
    ```

### Exercice 2.4 — Division sécurisée

Écris un programme qui calcule `100 / diviseur` et affiche le dernier chiffre du résultat, **sauf** si `diviseur == 0`, auquel cas il affiche `E` (pour « erreur »).

Teste avec `diviseur = 7` (sortie : `2\n` car `100 / 7 = 14`, dernier chiffre `4`… ah non, `100 / 7 = 14`, dont le dernier chiffre est `4`).

Recalcul : `100 / 7 = 14`. Donc le dernier chiffre est `4`. Sortie attendue : `4\n`.

Ensuite teste avec `diviseur = 0`. Sortie attendue : `E\n`.

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
    	int	diviseur;
    	int	resultat;

    	diviseur = 7;
    	if (diviseur == 0)
    	{
    		ft_putchar('E');
    	}
    	else
    	{
    		resultat = 100 / diviseur;
    		ft_putchar('0' + resultat % 10);
    	}
    	ft_putchar('\n');
    	return (0);
    }
    ```

    Si tu changes `diviseur = 7` en `diviseur = 0`, tu obtiens `E`. La division par zéro n'est jamais tentée grâce au `if`.

### Exercice 2.5 — Voyelle ou consonne ?

Écris un programme qui prend une `char c` (suppose qu'elle est entre `'a'` et `'z'`) et affiche `V` si c'est une voyelle, `C` sinon.

Les voyelles en français de base : `a`, `e`, `i`, `o`, `u`, `y`.

Teste avec `c = 'e'`.

Sortie attendue : `V\n`.

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
    	char	c;

    	c = 'e';
    	if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || c == 'y')
    	{
    		ft_putchar('V');
    	}
    	else
    	{
    		ft_putchar('C');
    	}
    	ft_putchar('\n');
    	return (0);
    }
    ```

    Note : on aurait pu utiliser un `switch`, mais comme on ne l'a pas encore vu (et que les contraintes 42 le rendent verbeux), la chaîne de `||` est OK ici.

### Exercice 2.6 — Trouver l'erreur

Ce programme essaie d'afficher `'P'` si `n` est positif et `'N'` sinon. Trouve les **deux erreurs**.

```c
int	n;

n = 5;
if (n = 5)
{
	ft_putchar('P');
}
else
	ft_putchar('N')
ft_putchar('\n');
```

??? success "Réponse"
    Deux erreurs :

    1. **`if (n = 5)`** : c'est une **affectation**, pas une comparaison. Norm 42 l'interdit en plus. Il fallait `if (n == 5)` (ou `if (n > 0)` selon l'intention).
    2. **Point-virgule manquant** après `ft_putchar('N')`. Toute instruction doit se terminer par `;`.

    Bonus : l'absence d'accolades autour de l'`else` est tolérée par Norm, mais déconseillée pour la cohérence.

    Version corrigée :

    ```c
    if (n > 0)
    {
    	ft_putchar('P');
    }
    else
    {
    	ft_putchar('N');
    }
    ft_putchar('\n');
    ```

---

## Partie 3 — Bonus

### Exercice 3.1 — Mention au bac

Écris un programme qui prend une `int note` entre `0` et `20` et affiche une lettre selon la mention :

| Note | Lettre |
|---|---|
| ≥ 16 | `T` (Très Bien) |
| ≥ 14 | `B` (Bien) |
| ≥ 12 | `A` (Assez Bien) |
| ≥ 10 | `P` (Passable) |
| < 10 | `R` (Recalé) |

Teste avec `note = 13`.

Sortie attendue : `A\n`.

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
    	int	note;

    	note = 13;
    	if (note >= 16)
    	{
    		ft_putchar('T');
    	}
    	else if (note >= 14)
    	{
    		ft_putchar('B');
    	}
    	else if (note >= 12)
    	{
    		ft_putchar('A');
    	}
    	else if (note >= 10)
    	{
    		ft_putchar('P');
    	}
    	else
    	{
    		ft_putchar('R');
    	}
    	ft_putchar('\n');
    	return (0);
    }
    ```

    L'ordre des tests est crucial : on teste les seuils du plus haut au plus bas. Si on testait `>= 10` en premier, tout le monde aurait `P`.

### Exercice 3.2 — Année bissextile

Une année est bissextile si elle est divisible par 4, **sauf** si elle est divisible par 100 — **sauf** si elle est divisible par 400.

Exemples :
- 2024 → bissextile (divisible par 4, pas par 100).
- 1900 → pas bissextile (divisible par 4 et 100, pas par 400).
- 2000 → bissextile (divisible par 400).

Écris un programme qui affiche `B` si l'année est bissextile, `N` sinon. Teste avec `annee = 2000`.

Sortie attendue : `B\n`.

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
    	int	annee;

    	annee = 2000;
    	if (annee % 400 == 0)
    	{
    		ft_putchar('B');
    	}
    	else if (annee % 100 == 0)
    	{
    		ft_putchar('N');
    	}
    	else if (annee % 4 == 0)
    	{
    		ft_putchar('B');
    	}
    	else
    	{
    		ft_putchar('N');
    	}
    	ft_putchar('\n');
    	return (0);
    }
    ```

    L'ordre des tests reflète l'imbrication des règles :

    1. Si `% 400 == 0` → bissextile (cas le plus spécifique).
    2. Sinon, si `% 100 == 0` → pas bissextile (exception à la règle des 4 ans).
    3. Sinon, si `% 4 == 0` → bissextile (règle de base).
    4. Sinon → pas bissextile.

    Une version équivalente avec une seule condition composée :

    ```c
    if ((annee % 4 == 0 && annee % 100 != 0) || annee % 400 == 0)
    ```

    Les deux sont valides. La première est plus pédagogique, la seconde plus condensée.

### Exercice 3.3 — Trace mentale

Sans compiler, donne la sortie de ce programme :

```c
int	n;

n = 15;
if (n > 0 && n < 10)
{
	ft_putchar('A');
}
else if (n >= 10 && n <= 20)
{
	ft_putchar('B');
}
else if (n > 20)
{
	ft_putchar('C');
}
ft_putchar('\n');
```

??? success "Réponse"
    - `n > 0 && n < 10` : `15 > 0` vrai, `15 < 10` faux → l'ensemble est faux.
    - `n >= 10 && n <= 20` : `15 >= 10` vrai, `15 <= 20` vrai → l'ensemble est vrai. On affiche `B` et on sort de la chaîne `else if`.
    - `n > 20` : pas évalué.

    Sortie : **`B\n`**.

---

## Validation finale

Avant de passer au Support 06, assure-toi de savoir faire **sans hésiter** :

- [ ] Écrire un `if` aux normes 42 (style Allman, accolades).
- [ ] Écrire un `if`/`else`.
- [ ] Enchaîner plusieurs cas avec `else if`.
- [ ] Combiner des conditions avec `&&`, `||`, `!`.
- [ ] Tester si un caractère est dans une plage.
- [ ] Reconnaître l'opérateur ternaire dans du code et savoir qu'il est interdit à 42.
- [ ] Éviter `if (n = 5)` et autres pièges classiques.

Si tu butes, refais l'exercice 3.2 (année bissextile) — c'est un classique des tests techniques d'embauche, et savoir le faire au quart de tour montre que tu maîtrises les conditions.

---

➡️ **Retour au cours :** [Support 05 — Conditions](./cours.md)
➡️ **Support suivant :** [Support 06 — Boucles](../support-06/cours.md)
