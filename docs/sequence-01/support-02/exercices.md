# Support 02 — Exercices

> **Objectif :** Manipuler les caractères, comprendre la table ASCII, écrire et utiliser `ft_putchar`.

Comme au support précédent : pour chaque exercice de code, écris le fichier dans ton éditeur, **compile** avec `cc -Wall -Wextra -Werror`, lance le binaire, et valide avec `norminette` avant de passer au suivant.

---

## Partie 1 — Quiz

<div class="quiz-question" data-correct="1">
<p class="quiz-number">Question 1.1</p>
<p class="quiz-prompt">Lequel de ces extraits de code est valide en C ?</p>
<ul class="quiz-options">
  <li class="quiz-option"><span class="quiz-option-marker">A</span> <code>char c = "A";</code></li>
  <li class="quiz-option"><span class="quiz-option-marker">B</span> <code>char c = 'A';</code></li>
  <li class="quiz-option"><span class="quiz-option-marker">C</span> <code>char c = A;</code></li>
  <li class="quiz-option"><span class="quiz-option-marker">D</span> <code>char c = `A`;</code></li>
</ul>
<button class="quiz-check" disabled>Vérifier</button>
<div class="quiz-feedback quiz-feedback-correct" hidden>✅ Correct ! Seul <code>char c = 'A';</code> est du C valide. <code>"A"</code> est une chaîne (2 octets), pas un <code>char</code>. <code>A</code> sans délimiteur serait un identifiant inexistant. Les accents graves n'ont aucun sens en C.<br><br>⚠️ Attention : à la <strong>Norm 42</strong>, initialiser à la déclaration est <strong>interdit</strong>. La forme correcte est : <code>char c;</code> puis <code>c = 'A';</code> sur une ligne séparée.</div>
<div class="quiz-feedback quiz-feedback-incorrect" hidden>❌ Pas tout à fait. La bonne réponse est <strong>B</strong> : <code>char c = 'A';</code>. <code>"A"</code> est une chaîne (pas un <code>char</code>), <code>A</code> serait interprété comme un identifiant, et les accents graves n'ont aucun sens en C. Note : à la Norm 42, cette initialisation devrait quand même être séparée en deux lignes.</div>
</div>

<div class="quiz-question" data-correct="2">
<p class="quiz-number">Question 1.2</p>
<p class="quiz-prompt">Que vaut <code>'D' - 'A'</code> ?</p>
<ul class="quiz-options">
  <li class="quiz-option"><span class="quiz-option-marker">A</span> <code>'D'</code></li>
  <li class="quiz-option"><span class="quiz-option-marker">B</span> <code>0</code></li>
  <li class="quiz-option"><span class="quiz-option-marker">C</span> <code>3</code></li>
  <li class="quiz-option"><span class="quiz-option-marker">D</span> <code>68</code></li>
</ul>
<button class="quiz-check" disabled>Vérifier</button>
<div class="quiz-feedback quiz-feedback-correct" hidden>✅ Correct ! <code>'A'</code> vaut 65, <code>'D'</code> vaut 68 — donc <code>'D' - 'A'</code> = <strong>3</strong>. Cette opération donne la position d'une lettre dans l'alphabet (0-indexé). C'est très utilisé en piscine.</div>
<div class="quiz-feedback quiz-feedback-incorrect" hidden>❌ Pas tout à fait. La bonne réponse est <strong>C — 3</strong>. <code>'A'</code> = 65 et <code>'D'</code> = 68 en ASCII, donc la différence est 68 − 65 = 3. Les chars sont des entiers, les opérations arithmétiques s'appliquent directement.</div>
</div>

<div class="quiz-question" data-correct="2">
<p class="quiz-number">Question 1.3</p>
<p class="quiz-prompt">Combien d'octets en mémoire occupe la chaîne <code>"Hi"</code> ?</p>
<ul class="quiz-options">
  <li class="quiz-option"><span class="quiz-option-marker">A</span> 1</li>
  <li class="quiz-option"><span class="quiz-option-marker">B</span> 2</li>
  <li class="quiz-option"><span class="quiz-option-marker">C</span> 3</li>
  <li class="quiz-option"><span class="quiz-option-marker">D</span> 4</li>
</ul>
<button class="quiz-check" disabled>Vérifier</button>
<div class="quiz-feedback quiz-feedback-correct" hidden>✅ Correct ! <strong>3 octets</strong> : <code>'H'</code>, <code>'i'</code>, et le caractère nul <code>'\0'</code> de fin de chaîne ajouté automatiquement. C'est ce qui distingue <code>"A"</code> (2 octets) de <code>'A'</code> (1 octet).</div>
<div class="quiz-feedback quiz-feedback-incorrect" hidden>❌ Pas tout à fait. La bonne réponse est <strong>C — 3</strong> : <code>'H'</code>, <code>'i'</code>, et le <code>'\0'</code> de fin de chaîne que le compilateur ajoute automatiquement après tout littéral entre guillemets.</div>
</div>

<div class="quiz-question" data-correct="1">
<p class="quiz-number">Question 1.4</p>
<p class="quiz-prompt">Que va afficher ce programme ?<br><br><code>c = 'A' + 32;<br>write(1, &amp;c, 1);</code></p>
<ul class="quiz-options">
  <li class="quiz-option"><span class="quiz-option-marker">A</span> <code>A</code></li>
  <li class="quiz-option"><span class="quiz-option-marker">B</span> <code>a</code></li>
  <li class="quiz-option"><span class="quiz-option-marker">C</span> <code>33</code></li>
  <li class="quiz-option"><span class="quiz-option-marker">D</span> <code>Aa</code></li>
</ul>
<button class="quiz-check" disabled>Vérifier</button>
<div class="quiz-feedback quiz-feedback-correct" hidden>✅ Correct ! <code>'A'</code> = 65, + 32 = 97 = <code>'a'</code>. L'écart de 32 entre une majuscule et sa minuscule est un réflexe à avoir : c'est utilisé dans des dizaines d'exercices de piscine.</div>
<div class="quiz-feedback quiz-feedback-incorrect" hidden>❌ Pas tout à fait. La bonne réponse est <strong>B — <code>a</code></strong>. <code>'A'</code> vaut 65 en ASCII. 65 + 32 = 97, qui est le code de <code>'a'</code>. L'écart entre toute majuscule et sa minuscule est toujours 32.</div>
</div>

<div class="quiz-question" data-correct="2">
<p class="quiz-number">Question 1.5</p>
<p class="quiz-prompt">Combien de caractères représente <code>"a\\b\nc"</code> en mémoire (sans le <code>\0</code> final) ?</p>
<ul class="quiz-options">
  <li class="quiz-option"><span class="quiz-option-marker">A</span> 7</li>
  <li class="quiz-option"><span class="quiz-option-marker">B</span> 6</li>
  <li class="quiz-option"><span class="quiz-option-marker">C</span> 5</li>
  <li class="quiz-option"><span class="quiz-option-marker">D</span> 4</li>
</ul>
<button class="quiz-check" disabled>Vérifier</button>
<div class="quiz-feedback quiz-feedback-correct" hidden>✅ Correct ! <strong>5 caractères</strong> : <code>'a'</code>, <code>'\\'</code> (un seul antislash), <code>'b'</code>, <code>'\n'</code> (un seul saut de ligne), <code>'c'</code>. Chaque séquence d'échappement compte pour <strong>un seul</strong> octet en mémoire.</div>
<div class="quiz-feedback quiz-feedback-incorrect" hidden>❌ Pas tout à fait. La bonne réponse est <strong>C — 5</strong>. La chaîne contient : <code>'a'</code>, <code>'\\'</code> (1 antislash = 1 octet), <code>'b'</code>, <code>'\n'</code> (1 saut de ligne = 1 octet), <code>'c'</code>. Les séquences d'échappement s'écrivent en 2 chars dans le source mais ne comptent que pour 1 octet en mémoire.</div>
</div>

<div class="quiz-question" data-correct="2">
<p class="quiz-number">Question 1.6</p>
<p class="quiz-prompt">Quelle est la différence entre <code>putchar</code> (bibliothèque standard) et <code>ft_putchar</code> (la tienne) ?</p>
<ul class="quiz-options">
  <li class="quiz-option"><span class="quiz-option-marker">A</span> Aucune, c'est juste un préfixe esthétique.</li>
  <li class="quiz-option"><span class="quiz-option-marker">B</span> <code>ft_putchar</code> est plus rapide.</li>
  <li class="quiz-option"><span class="quiz-option-marker">C</span> <code>ft_putchar</code> est ta propre implémentation avec <code>write</code> ; <code>putchar</code> est fournie par la libc et utilise des tampons.</li>
  <li class="quiz-option"><span class="quiz-option-marker">D</span> <code>putchar</code> ne fonctionne pas à 42.</li>
</ul>
<button class="quiz-check" disabled>Vérifier</button>
<div class="quiz-feedback quiz-feedback-correct" hidden>✅ Correct ! <code>ft_putchar</code> appelle directement <code>write</code> — pas de tampon, pas de formatage. <code>putchar</code> (de <code>&lt;stdio.h&gt;</code>) passe par des mécanismes de bufferisation plus complexes. À 42 en piscine, tu n'utilises pas <code>putchar</code> : tu écris tes propres versions pour comprendre le fonctionnement sous-jacent.</div>
<div class="quiz-feedback quiz-feedback-incorrect" hidden>❌ Pas tout à fait. La bonne réponse est <strong>C</strong> : <code>ft_putchar</code> est ta version maison qui appelle <code>write</code> directement, sans tampon. <code>putchar</code> (de <code>&lt;stdio.h&gt;</code>) fait globalement la même chose, mais avec de la bufferisation. À 42, on code nos propres versions pour comprendre les couches basses.</div>
</div>

<p id="quiz-score" class="quiz-score"></p>

---

## Partie 2 — Exercices pratiques

### Exercice 2.1 — Écrire `ft_putchar`

Crée un fichier `ft_putchar.c` qui :

1. Contient l'en-tête 42.
2. Définit la fonction `ft_putchar` qui prend un `char` et l'affiche.
3. Dans `main`, l'utilise pour afficher ton initiale (la première lettre de ton prénom) suivie d'un saut de ligne.

**Contraintes :**

- Aucun `#include` autre que `<unistd.h>`.
- `norminette` OK, compile avec `-Wall -Wextra -Werror`.

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
    	ft_putchar('R');
    	ft_putchar('\n');
    	return (0);
    }
    ```

### Exercice 2.2 — Le mot « 42 »

Écris un programme qui affiche `42\n` en utilisant **uniquement** `ft_putchar` et des **codes ASCII numériques** (pas de littéraux `'4'` ou `'2'`).

Indice : le code ASCII de `'0'` est `48`.

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
    	ft_putchar(52);   /* '4' = 48 + 4 */
    	ft_putchar(50);   /* '2' = 48 + 2 */
    	ft_putchar(10);   /* '\n' */
    	return (0);
    }
    ```

    L'astuce mentale : `'0'` vaut 48, donc `'N'` (un chiffre) vaut `48 + N`. C'est utilisé partout en piscine pour convertir des nombres en caractères affichables.

### Exercice 2.3 — Conversion majuscule

Écris un programme qui affiche la lettre `g` **en majuscule**, en partant du caractère `'g'`. Tu dois utiliser le fait que `'a' - 'A' == 32`.

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

    	c = 'g';
    	c = c - 32;
    	ft_putchar(c);
    	ft_putchar('\n');
    	return (0);
    }
    ```

    Sortie : `G`.

### Exercice 2.4 — Trois colonnes alignées

Écris un programme qui affiche cette sortie, en utilisant exclusivement `ft_putchar` :

```
A	B	C
1	2	3
```

(Les espaces entre les colonnes sont des **tabulations** `\t`, pas des espaces.)

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
    	ft_putchar('A');
    	ft_putchar('\t');
    	ft_putchar('B');
    	ft_putchar('\t');
    	ft_putchar('C');
    	ft_putchar('\n');
    	ft_putchar('1');
    	ft_putchar('\t');
    	ft_putchar('2');
    	ft_putchar('\t');
    	ft_putchar('3');
    	ft_putchar('\n');
    	return (0);
    }
    ```

### Exercice 2.5 — Caractères piégeux

Écris un programme qui affiche cette ligne **exacte** :

```
Il a dit : "C'est l'été !"
```

(suivie d'un saut de ligne)

**Contrainte :** utilise `ft_putchar` uniquement (pas de `write` direct avec une chaîne).

!!! warning "Attention aux accents"
    Le caractère `é` n'est pas dans la table ASCII de base. En UTF-8, il occupe **2 octets**. Pour cet exercice, remplace `été` par `ete` (sans accent). On reverra l'UTF-8 plus tard.

??? success "Solution"
    Une fois `été` remplacé par `ete`, la phrase devient `Il a dit : "C'est l'ete !"`.

    ```c
    /* en-tête 42 ici */

    #include <unistd.h>

    void	ft_putchar(char c)
    {
    	write(1, &c, 1);
    }

    int	main(void)
    {
    	ft_putchar('I');
    	ft_putchar('l');
    	ft_putchar(' ');
    	ft_putchar('a');
    	ft_putchar(' ');
    	ft_putchar('d');
    	ft_putchar('i');
    	ft_putchar('t');
    	ft_putchar(' ');
    	ft_putchar(':');
    	ft_putchar(' ');
    	ft_putchar('"');
    	ft_putchar('C');
    	ft_putchar('\'');
    	ft_putchar('e');
    	ft_putchar('s');
    	ft_putchar('t');
    	ft_putchar(' ');
    	ft_putchar('l');
    	ft_putchar('\'');
    	ft_putchar('e');
    	ft_putchar('t');
    	ft_putchar('e');
    	ft_putchar(' ');
    	ft_putchar('!');
    	ft_putchar('"');
    	ft_putchar('\n');
    	return (0);
    }
    ```

    Note l'usage de `'\''` pour les apostrophes dans le texte, et de `'"'` pour les guillemets (qui n'ont pas besoin d'être échappés dans un caractère).

### Exercice 2.6 — Lecture de code

Sans compiler, dis ce que ce programme va afficher (puis vérifie en compilant) :

```c
#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	main(void)
{
	char	c;

	c = '0' + 7;
	ft_putchar(c);
	c = 'Z' - 25;
	ft_putchar(c);
	c = 'a' + ('Z' - 'A');
	ft_putchar(c);
	ft_putchar('\n');
	return (0);
}
```

??? success "Réponse"
    Décomposons :

    - `'0' + 7` = 48 + 7 = 55 = `'7'`
    - `'Z' - 25` = 90 - 25 = 65 = `'A'`
    - `'a' + ('Z' - 'A')` = 97 + 25 = 122 = `'z'`

    Sortie : `7Az`

    Cet exercice est typique de ce que tu verras à la piscine : la lecture mentale du code ASCII devient un automatisme.

---

## Partie 3 — Bonus

### Exercice 3.1 — Affichage formaté

Écris un programme qui affiche cette « carte d'identité » dans le terminal :

```
+-----------------+
| Nom    : Doe    |
| Prenom : John   |
+-----------------+
```

**Contraintes :**

- Tu peux utiliser soit `write` avec des chaînes, soit `ft_putchar` répété — au choix.
- Les barres verticales `|` et les tirets `-` sont des caractères ASCII standard.
- Compte bien tes octets si tu utilises `write` avec des chaînes.

??? success "Solution (avec `write`)"
    ```c
    /* en-tête 42 ici */

    #include <unistd.h>

    int	main(void)
    {
    	write(1, "+-----------------+\n", 20);
    	write(1, "| Nom    : Doe    |\n", 20);
    	write(1, "| Prenom : John   |\n", 20);
    	write(1, "+-----------------+\n", 20);
    	return (0);
    }
    ```

    Chaque ligne fait exactement 19 caractères visibles + 1 `\n` = **20 octets**. Vérifie en comptant à la main.

### Exercice 3.2 — Code mystère

Lis ce code et **devine la sortie** :

```c
char	c;

c = 'A';
ft_putchar(c);
ft_putchar(c + 1);
ft_putchar(c + 2);
ft_putchar('\\');
ft_putchar(c + 1);
ft_putchar(c);
ft_putchar('\n');
```

??? success "Réponse"
    - `c` = `'A'` (65) → `A`
    - `c + 1` = 66 → `B`
    - `c + 2` = 67 → `C`
    - `'\\'` → un antislash : `\`
    - `c + 1` → `B`
    - `c` → `A`

    Sortie : `ABC\BA`

---

## Validation finale

Avant de passer au Support 03, assure-toi de savoir faire **sans hésiter** :

- [ ] Déclarer une variable `char` et lui assigner une valeur.
- [ ] Distinguer `'A'` (char) et `"A"` (chaîne).
- [ ] Citer les codes ASCII de `'0'`, `'A'` et `'a'`.
- [ ] Convertir une majuscule en minuscule (et inverse) avec `± 32`.
- [ ] Écrire `ft_putchar` de mémoire.
- [ ] Échapper un antislash, une apostrophe et un guillemet selon le contexte.
- [ ] Compter le nombre d'octets d'une chaîne contenant des séquences d'échappement.

Si l'un de ces points te demande encore de réfléchir, refais l'exercice 2.6 jusqu'à ce que la lecture des codes ASCII te vienne naturellement.

---

➡️ **Retour au cours :** [Support 02 — Caractères et affichage](./cours.md)
➡️ **Support suivant :** Support 03 — Variables et types *(à venir)*
