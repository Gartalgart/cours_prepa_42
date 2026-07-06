# Support 06 — Exercices

> **Objectif :** Maîtriser la boucle `while` pour résoudre des problèmes répétitifs, utiliser des boucles imbriquées, et appliquer `break`/`continue`.

Compile chaque exercice avec `cc -Wall -Wextra -Werror`, valide avec `norminette`, vérifie la sortie.

---

## Partie 1 — Quiz

<div class="quiz-question" data-correct="0">
<p class="quiz-number">Question 1.1</p>
<p class="quiz-prompt">Quelle est l'unique structure de boucle autorisée à 42 ?</p>
<ul class="quiz-options">
  <li class="quiz-option"><span class="quiz-option-marker">A</span> <code>while</code></li>
  <li class="quiz-option"><span class="quiz-option-marker">B</span> <code>for</code></li>
  <li class="quiz-option"><span class="quiz-option-marker">C</span> <code>do…while</code></li>
  <li class="quiz-option"><span class="quiz-option-marker">D</span> Les trois</li>
</ul>
<button class="quiz-check" disabled>Vérifier</button>
<div class="quiz-feedback quiz-feedback-correct" hidden>✅ Correct ! <strong><code>while</code></strong> uniquement. <code>for</code> et <code>do…while</code> font échouer <code>norminette</code>.</div>
<div class="quiz-feedback quiz-feedback-incorrect" hidden>❌ Pas tout à fait. La bonne réponse est <strong>A — <code>while</code></strong>. À 42, <code>for</code> et <code>do…while</code> sont interdits par la Norm.</div>
</div>

<div class="quiz-question" data-correct="1">
<p class="quiz-number">Question 1.2</p>
<p class="quiz-prompt">Que va afficher ce programme ?<br><br><code>i = 0;<br>while (i &lt; 5)<br>{<br>&nbsp;&nbsp;&nbsp;&nbsp;ft_putchar('0' + i);<br>&nbsp;&nbsp;&nbsp;&nbsp;i++;<br>}</code></p>
<ul class="quiz-options">
  <li class="quiz-option"><span class="quiz-option-marker">A</span> <code>12345</code></li>
  <li class="quiz-option"><span class="quiz-option-marker">B</span> <code>01234</code></li>
  <li class="quiz-option"><span class="quiz-option-marker">C</span> <code>0123</code></li>
  <li class="quiz-option"><span class="quiz-option-marker">D</span> <code>1234</code></li>
</ul>
<button class="quiz-check" disabled>Vérifier</button>
<div class="quiz-feedback quiz-feedback-correct" hidden>✅ Correct ! <code>01234</code>. Le compteur démarre à <code>0</code> et s'arrête dès que <code>i</code> atteint <code>5</code> (exclu) : cinq itérations, <code>0, 1, 2, 3, 4</code>.</div>
<div class="quiz-feedback quiz-feedback-incorrect" hidden>❌ Pas tout à fait. La bonne réponse est <strong>B — <code>01234</code></strong>. On affiche <code>i</code> avant de l'incrémenter, en partant de 0 et en s'arrêtant à 4 (5 exclu).</div>
</div>

<div class="quiz-question" data-correct="1">
<p class="quiz-number">Question 1.3</p>
<p class="quiz-prompt">Que va afficher ce code ?<br><br><code>i = 5;<br>while (i &gt; 0)<br>{<br>&nbsp;&nbsp;&nbsp;&nbsp;ft_putchar('0' + i);<br>&nbsp;&nbsp;&nbsp;&nbsp;i--;<br>}</code></p>
<ul class="quiz-options">
  <li class="quiz-option"><span class="quiz-option-marker">A</span> <code>12345</code></li>
  <li class="quiz-option"><span class="quiz-option-marker">B</span> <code>54321</code></li>
  <li class="quiz-option"><span class="quiz-option-marker">C</span> <code>5432</code></li>
  <li class="quiz-option"><span class="quiz-option-marker">D</span> Boucle infinie</li>
</ul>
<button class="quiz-check" disabled>Vérifier</button>
<div class="quiz-feedback quiz-feedback-correct" hidden>✅ Correct ! <code>54321</code>. On compte à rebours de 5 à 1, puis on s'arrête (la condition <code>i &gt; 0</code> devient fausse quand <code>i</code> vaut <code>0</code>).</div>
<div class="quiz-feedback quiz-feedback-incorrect" hidden>❌ Pas tout à fait. La bonne réponse est <strong>B — <code>54321</code></strong>. On affiche puis on décrémente, de 5 jusqu'à 1 inclus (0 exclu).</div>
</div>

<div class="quiz-question" data-correct="2">
<p class="quiz-number">Question 1.4</p>
<p class="quiz-prompt">Combien de fois ce bloc s'exécute-t-il ?<br><br><code>i = 0;<br>while (i &lt;= 100)<br>{<br>&nbsp;&nbsp;&nbsp;&nbsp;/* ... */<br>&nbsp;&nbsp;&nbsp;&nbsp;i++;<br>}</code></p>
<ul class="quiz-options">
  <li class="quiz-option"><span class="quiz-option-marker">A</span> 99</li>
  <li class="quiz-option"><span class="quiz-option-marker">B</span> 100</li>
  <li class="quiz-option"><span class="quiz-option-marker">C</span> 101</li>
  <li class="quiz-option"><span class="quiz-option-marker">D</span> 102</li>
</ul>
<button class="quiz-check" disabled>Vérifier</button>
<div class="quiz-feedback quiz-feedback-correct" hidden>✅ Correct ! <strong>101</strong> fois : <code>i</code> prend les valeurs <code>0, 1, 2, ..., 100</code>, soit 101 valeurs. C'est un cas typique d'<strong>off-by-one</strong> : pour 100 itérations, il fallait <code>i &lt; 100</code>.</div>
<div class="quiz-feedback quiz-feedback-incorrect" hidden>❌ Pas tout à fait. La bonne réponse est <strong>C — 101</strong>. Avec <code>&lt;=</code>, <code>i</code> va de 0 à 100 inclus : 101 valeurs.</div>
</div>

<div class="quiz-question" data-correct="1">
<p class="quiz-number">Question 1.5</p>
<p class="quiz-prompt">Quel est l'effet de <code>break</code> dans une boucle ?</p>
<ul class="quiz-options">
  <li class="quiz-option"><span class="quiz-option-marker">A</span> Saute l'itération en cours, passe à la suivante.</li>
  <li class="quiz-option"><span class="quiz-option-marker">B</span> Sort immédiatement de la boucle.</li>
  <li class="quiz-option"><span class="quiz-option-marker">C</span> Met la boucle en pause.</li>
  <li class="quiz-option"><span class="quiz-option-marker">D</span> Réinitialise le compteur à zéro.</li>
</ul>
<button class="quiz-check" disabled>Vérifier</button>
<div class="quiz-feedback quiz-feedback-correct" hidden>✅ Correct ! <code>break</code> <strong>sort immédiatement</strong> de la boucle. Le code reprend juste après le <code>}</code> final du <code>while</code>.</div>
<div class="quiz-feedback quiz-feedback-incorrect" hidden>❌ Pas tout à fait. La bonne réponse est <strong>B</strong>. <code>break</code> sort immédiatement de la boucle (à ne pas confondre avec <code>continue</code>, qui saute juste l'itération).</div>
</div>

<div class="quiz-question" data-correct="0">
<p class="quiz-number">Question 1.6</p>
<p class="quiz-prompt">Quel est l'effet de <code>continue</code> dans une boucle ?</p>
<ul class="quiz-options">
  <li class="quiz-option"><span class="quiz-option-marker">A</span> Saute le reste de l'itération en cours, passe à la suivante.</li>
  <li class="quiz-option"><span class="quiz-option-marker">B</span> Sort de la boucle.</li>
  <li class="quiz-option"><span class="quiz-option-marker">C</span> Annule la boucle entière.</li>
  <li class="quiz-option"><span class="quiz-option-marker">D</span> N'a aucun effet.</li>
</ul>
<button class="quiz-check" disabled>Vérifier</button>
<div class="quiz-feedback quiz-feedback-correct" hidden>✅ Correct ! <code>continue</code> saute le reste du bloc et revient à l'évaluation de la condition. <strong>Attention</strong> : si la variable de boucle n'a pas été incrémentée avant le <code>continue</code>, c'est la boucle infinie garantie.</div>
<div class="quiz-feedback quiz-feedback-incorrect" hidden>❌ Pas tout à fait. La bonne réponse est <strong>A</strong>. <code>continue</code> saute le reste de l'itération courante et repart à la condition (contrairement à <code>break</code> qui sort de la boucle).</div>
</div>

<div class="quiz-question" data-correct="1">
<p class="quiz-number">Question 1.7</p>
<p class="quiz-prompt">Repère le bug dans ce code :<br><br><code>i = 0;<br>while (i &lt; 3)<br>{<br>&nbsp;&nbsp;&nbsp;&nbsp;while (j &lt; 3)<br>&nbsp;&nbsp;&nbsp;&nbsp;{<br>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;ft_putchar('X'); j++;<br>&nbsp;&nbsp;&nbsp;&nbsp;}<br>&nbsp;&nbsp;&nbsp;&nbsp;ft_putchar('\n'); i++;<br>}</code></p>
<ul class="quiz-options">
  <li class="quiz-option"><span class="quiz-option-marker">A</span> Boucle infinie sur <code>i</code>.</li>
  <li class="quiz-option"><span class="quiz-option-marker">B</span> La boucle interne ne se réinitialise pas : la 1re ligne aura 3 X et les suivantes 0.</li>
  <li class="quiz-option"><span class="quiz-option-marker">C</span> <code>ft_putchar('\n')</code> est mal placé.</li>
  <li class="quiz-option"><span class="quiz-option-marker">D</span> Pas de bug.</li>
</ul>
<button class="quiz-check" disabled>Vérifier</button>
<div class="quiz-feedback quiz-feedback-correct" hidden>✅ Correct ! <code>j</code> n'est <strong>jamais remis à 0</strong> avant la boucle interne. Après la première itération, <code>j</code> vaut 3 et la boucle interne ne tourne plus. Il faut ajouter <code>j = 0;</code> au début de la boucle externe.</div>
<div class="quiz-feedback quiz-feedback-incorrect" hidden>❌ Pas tout à fait. La bonne réponse est <strong>B</strong>. <code>j</code> n'est jamais réinitialisé : il faut <code>j = 0;</code> au début de chaque itération externe.</div>
</div>

<p id="quiz-score" class="quiz-score"></p>

---

## Partie 2 — Exercices pratiques

### Exercice 2.1 — Compter à rebours

Écris un programme qui affiche les chiffres de `9` à `0` (inclus), suivi d'un saut de ligne.

Sortie attendue : `9876543210\n`.

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
    	int	i;

    	i = 9;
    	while (i >= 0)
    	{
    		ft_putchar('0' + i);
    		i--;
    	}
    	ft_putchar('\n');
    	return (0);
    }
    ```

### Exercice 2.2 — Alphabet majuscule à l'envers

Écris un programme qui affiche les lettres majuscules de `'Z'` à `'A'`, suivies d'un saut de ligne.

Sortie attendue : `ZYXWVUTSRQPONMLKJIHGFEDCBA\n`.

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

    	c = 'Z';
    	while (c >= 'A')
    	{
    		ft_putchar(c);
    		c--;
    	}
    	ft_putchar('\n');
    	return (0);
    }
    ```

### Exercice 2.3 — Chiffres pairs seulement

Écris un programme qui affiche les chiffres pairs de `0` à `8` (`0, 2, 4, 6, 8`) sur une seule ligne.

Sortie attendue : `02468\n`.

**Contrainte :** utilise `continue` pour sauter les impairs.

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
    	int	i;

    	i = 0;
    	while (i <= 8)
    	{
    		if (i % 2 != 0)
    		{
    			i++;
    			continue ;
    		}
    		ft_putchar('0' + i);
    		i++;
    	}
    	ft_putchar('\n');
    	return (0);
    }
    ```

    **Note** : il existe une version plus simple sans `continue` (incrémenter `i` de 2 à chaque fois), mais l'objectif ici est de pratiquer `continue`.

### Exercice 2.4 — Carré plein

Écris un programme qui affiche un carré plein de `5` lignes de `5` caractères `#`.

Sortie attendue :

```
#####
#####
#####
#####
#####
```

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
    	int	i;
    	int	j;

    	i = 0;
    	while (i < 5)
    	{
    		j = 0;
    		while (j < 5)
    		{
    			ft_putchar('#');
    			j++;
    		}
    		ft_putchar('\n');
    		i++;
    	}
    	return (0);
    }
    ```

### Exercice 2.5 — Carré creux

Écris un programme qui affiche un carré **creux** de `5` lignes de `5` caractères :

```
#####
#   #
#   #
#   #
#####
```

(Les caractères intérieurs sont des espaces.)

**Indice :** dans la boucle interne, utilise un `if` pour différencier le bord du milieu.

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
    	int	i;
    	int	j;

    	i = 0;
    	while (i < 5)
    	{
    		j = 0;
    		while (j < 5)
    		{
    			if (i == 0 || i == 4 || j == 0 || j == 4)
    			{
    				ft_putchar('#');
    			}
    			else
    			{
    				ft_putchar(' ');
    			}
    			j++;
    		}
    		ft_putchar('\n');
    		i++;
    	}
    	return (0);
    }
    ```

    La condition `i == 0 || i == 4 || j == 0 || j == 4` détecte le **bord** du carré (première ligne, dernière ligne, première colonne, dernière colonne).

### Exercice 2.6 — Cherche et arrête

Écris un programme qui parcourt les nombres de `0` à `100` et s'arrête (avec `break`) dès qu'il trouve un nombre **divisible à la fois par 7 et par 11**. Affiche-le sous forme de deux chiffres.

Sortie attendue : `77\n` (car `77 = 7 × 11`).

**Indice :** pour afficher un nombre à 2 chiffres avec `ft_putchar`, utilise `n / 10` pour les dizaines et `n % 10` pour les unités.

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
    	int	i;

    	i = 1;
    	while (i <= 100)
    	{
    		if (i % 7 == 0 && i % 11 == 0)
    		{
    			ft_putchar('0' + i / 10);
    			ft_putchar('0' + i % 10);
    			ft_putchar('\n');
    			break ;
    		}
    		i++;
    	}
    	return (0);
    }
    ```

    On démarre à `1` parce que `0` est divisible par tout, ce qui rendrait l'exercice trivial.

---

## Partie 3 — Bonus

### Exercice 3.1 — Triangle rectangle

Affiche un triangle rectangle de hauteur 5 :

```
#
##
###
####
#####
```

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
    	int	i;
    	int	j;

    	i = 0;
    	while (i < 5)
    	{
    		j = 0;
    		while (j <= i)
    		{
    			ft_putchar('#');
    			j++;
    		}
    		ft_putchar('\n');
    		i++;
    	}
    	return (0);
    }
    ```

    La clé : la boucle interne va de `0` à `i` inclus (donc `i + 1` `#` à la ligne `i`).

### Exercice 3.2 — Table de multiplication d'un chiffre

Écris un programme qui affiche la table de multiplication de `3` de la forme :

```
3 x 1 = 3
3 x 2 = 6
3 x 3 = 9
```

(Et ainsi de suite jusqu'à `3 x 9 = 27`.)

**Indice :** pour les résultats à deux chiffres (`12`, `15`, `18`, `21`, `24`, `27`), tu devras gérer le cas.

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
    	int	i;
    	int	resultat;

    	i = 1;
    	while (i <= 9)
    	{
    		resultat = 3 * i;
    		ft_putchar('3');
    		ft_putchar(' ');
    		ft_putchar('x');
    		ft_putchar(' ');
    		ft_putchar('0' + i);
    		ft_putchar(' ');
    		ft_putchar('=');
    		ft_putchar(' ');
    		if (resultat >= 10)
    		{
    			ft_putchar('0' + resultat / 10);
    		}
    		ft_putchar('0' + resultat % 10);
    		ft_putchar('\n');
    		i++;
    	}
    	return (0);
    }
    ```

    La gestion des deux chiffres : si `resultat >= 10`, on affiche les dizaines puis les unités. Sinon, seulement les unités. Au Support 07, on enverra cette logique dans une fonction `ft_putnbr`.

### Exercice 3.3 — Sapin de Noël

Affiche un sapin de hauteur 5 (5 lignes), centré sur 9 colonnes :

```
    #
   ###
  #####
 #######
#########
```

**Indice :** pour chaque ligne `i` (de 0 à 4), il faut afficher `4 - i` espaces, puis `2 * i + 1` `#`.

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
    	int	i;
    	int	j;

    	i = 0;
    	while (i < 5)
    	{
    		j = 0;
    		while (j < 4 - i)
    		{
    			ft_putchar(' ');
    			j++;
    		}
    		j = 0;
    		while (j < 2 * i + 1)
    		{
    			ft_putchar('#');
    			j++;
    		}
    		ft_putchar('\n');
    		i++;
    	}
    	return (0);
    }
    ```

    Cet exercice combine deux boucles internes consécutives (pas imbriquées) : la première gère les espaces, la seconde les `#`. Note la **réinitialisation explicite** de `j = 0` entre les deux.

---

## Validation finale

Avant de passer au Support 07, assure-toi de savoir faire **sans hésiter** :

- [ ] Écrire une boucle `while` aux normes 42 avec ses trois ingrédients (init, condition, mise à jour).
- [ ] Parcourir une plage de nombres ou de caractères.
- [ ] Compter à rebours.
- [ ] Imbriquer deux boucles pour parcourir une grille.
- [ ] Utiliser `break` et `continue` à bon escient.
- [ ] Reconnaître une `for` ou une `do…while` dans du code, et savoir qu'elles sont **interdites à 42**.
- [ ] Détecter une boucle infinie potentielle dans un code.
- [ ] Afficher un nombre à 2 chiffres avec `n / 10` et `n % 10`.

Si tu butes, refais l'exercice 3.3 (sapin) — il combine boucles, conditions, et compteurs croisés, c'est le test ultime pour ce support.

---

➡️ **Retour au cours :** [Support 06 — Boucles](./cours.md)
➡️ **Support suivant :** [Support 07 — Fonctions](../support-07/cours.md)
