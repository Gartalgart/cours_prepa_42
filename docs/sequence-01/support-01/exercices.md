# Support 01 — Exercices

> **Objectif :** Mettre en pratique l'écriture, la compilation et l'exécution d'un programme C minimal aux normes 42.

Pour chaque exercice, écris le code dans ton éditeur, sauvegarde-le, **compile** avec `cc -Wall -Wextra -Werror`, lance le binaire, et valide avec `norminette` avant de passer au suivant.

---

## Partie 1 — Quiz

<div class="quiz-question" data-correct="2">
<p class="quiz-number">Question 1.1</p>
<p class="quiz-prompt">Parmi ces noms de fichiers, lequel est valide pour un projet 42 ?</p>
<ul class="quiz-options">
  <li class="quiz-option"><span class="quiz-option-marker">A</span> <code>Premier_Programme.C</code></li>
  <li class="quiz-option"><span class="quiz-option-marker">B</span> <code>ex1.txt</code></li>
  <li class="quiz-option"><span class="quiz-option-marker">C</span> <code>ex01_premier_programme.c</code></li>
  <li class="quiz-option"><span class="quiz-option-marker">D</span> <code>1er-programme.c</code></li>
</ul>
<button class="quiz-check" disabled>Vérifier</button>
<div class="quiz-feedback quiz-feedback-correct" hidden>✅ Correct ! <code>ex01_premier_programme.c</code> — l'extension doit être <code>.c</code> en minuscules, en <em>snake_case</em>, sans commencer par un chiffre.</div>
<div class="quiz-feedback quiz-feedback-incorrect" hidden>❌ Pas tout à fait. La bonne réponse est <strong>C</strong> : <code>ex01_premier_programme.c</code>. L'extension doit être <code>.c</code> en minuscules, en <em>snake_case</em>, sans commencer par un chiffre.</div>
</div>

<div class="quiz-question" data-correct="1">
<p class="quiz-number">Question 1.2</p>
<p class="quiz-prompt">Que fait l'instruction <code>#include &lt;unistd.h&gt;</code> ?</p>
<ul class="quiz-options">
  <li class="quiz-option"><span class="quiz-option-marker">A</span> Elle exécute la bibliothèque <code>unistd</code>.</li>
  <li class="quiz-option"><span class="quiz-option-marker">B</span> Elle importe les déclarations des fonctions de <code>unistd</code> (dont <code>write</code>).</li>
  <li class="quiz-option"><span class="quiz-option-marker">C</span> Elle copie le code source de <code>unistd</code> dans ton programme.</li>
  <li class="quiz-option"><span class="quiz-option-marker">D</span> Elle est optionnelle pour utiliser <code>write</code>.</li>
</ul>
<button class="quiz-check" disabled>Vérifier</button>
<div class="quiz-feedback quiz-feedback-correct" hidden>✅ Correct ! Elle importe les <strong>déclarations</strong> (prototypes) des fonctions, ce qui permet au compilateur de savoir comment appeler <code>write</code>. Sans ce <code>#include</code>, <code>-Werror</code> rejette ton code.</div>
<div class="quiz-feedback quiz-feedback-incorrect" hidden>❌ Pas tout à fait. La bonne réponse est <strong>B</strong> : elle importe les <strong>déclarations</strong> (prototypes). Sans ce <code>#include</code>, le compilateur émettra un warning, et <code>-Werror</code> rejettera ton code.</div>
</div>

<div class="quiz-question" data-correct="1">
<p class="quiz-number">Question 1.3</p>
<p class="quiz-prompt">À quoi sert le <code>\n</code> à la fin d'une chaîne ?</p>
<ul class="quiz-options">
  <li class="quiz-option"><span class="quiz-option-marker">A</span> À indiquer la fin de la chaîne au compilateur.</li>
  <li class="quiz-option"><span class="quiz-option-marker">B</span> À insérer un retour à la ligne dans la sortie.</li>
  <li class="quiz-option"><span class="quiz-option-marker">C</span> À effacer le terminal.</li>
  <li class="quiz-option"><span class="quiz-option-marker">D</span> À séparer deux mots.</li>
</ul>
<button class="quiz-check" disabled>Vérifier</button>
<div class="quiz-feedback quiz-feedback-correct" hidden>✅ Correct ! <code>\n</code> est un caractère d'échappement qui représente un retour à la ligne. Il compte pour <strong>un seul</strong> octet dans le décompte passé à <code>write</code>.</div>
<div class="quiz-feedback quiz-feedback-incorrect" hidden>❌ Pas tout à fait. La bonne réponse est <strong>B</strong> : <code>\n</code> insère un retour à la ligne. C'est un caractère unique qui compte pour <strong>un seul</strong> octet.</div>
</div>

<div class="quiz-question" data-correct="2">
<p class="quiz-number">Question 1.4</p>
<p class="quiz-prompt">Que fait le flag de compilation <code>-Werror</code> ?</p>
<ul class="quiz-options">
  <li class="quiz-option"><span class="quiz-option-marker">A</span> Il génère un fichier d'erreur.</li>
  <li class="quiz-option"><span class="quiz-option-marker">B</span> Il désactive les warnings.</li>
  <li class="quiz-option"><span class="quiz-option-marker">C</span> Il transforme chaque warning en erreur de compilation.</li>
  <li class="quiz-option"><span class="quiz-option-marker">D</span> Il efface les warnings du terminal.</li>
</ul>
<button class="quiz-check" disabled>Vérifier</button>
<div class="quiz-feedback quiz-feedback-correct" hidden>✅ Correct ! <code>-Werror</code> transforme chaque warning en erreur fatale. Combiné à <code>-Wall</code> et <code>-Wextra</code>, aucun code « presque correct » ne passe.</div>
<div class="quiz-feedback quiz-feedback-incorrect" hidden>❌ Pas tout à fait. La bonne réponse est <strong>C</strong> : <code>-Werror</code> transforme chaque warning en erreur. La compilation échoue au moindre avertissement.</div>
</div>

<div class="quiz-question" data-correct="1">
<p class="quiz-number">Question 1.5</p>
<p class="quiz-prompt">Combien d'octets faut-il passer à <code>write</code> pour afficher la chaîne <code>"42\n"</code> ?</p>
<ul class="quiz-options">
  <li class="quiz-option"><span class="quiz-option-marker">A</span> 2</li>
  <li class="quiz-option"><span class="quiz-option-marker">B</span> 3</li>
  <li class="quiz-option"><span class="quiz-option-marker">C</span> 4</li>
  <li class="quiz-option"><span class="quiz-option-marker">D</span> 5</li>
</ul>
<button class="quiz-check" disabled>Vérifier</button>
<div class="quiz-feedback quiz-feedback-correct" hidden>✅ Correct ! 3 octets : <code>'4'</code>, <code>'2'</code>, <code>'\n'</code>. Le <code>\n</code> compte pour <strong>un seul</strong> octet, et le <code>\0</code> de fin de chaîne n'est pas envoyé à <code>write</code>.</div>
<div class="quiz-feedback quiz-feedback-incorrect" hidden>❌ Pas tout à fait. La bonne réponse est <strong>B — 3</strong> : <code>'4'</code>, <code>'2'</code> et <code>'\n'</code> (un seul octet). Le <code>\0</code> de fin de chaîne n'est pas compté.</div>
</div>

<p id="quiz-score" class="quiz-score"></p>

---

## Partie 2 — Exercices pratiques

### Exercice 2.1 — Le minimum vital

Crée un fichier `ex01_minimal.c` qui affiche exactement :

```
Bonjour, le C !
```

(avec un retour à la ligne à la fin)

**Contraintes :**

- Inclure l'en-tête 42.
- Utiliser uniquement `write`.
- Passer `norminette` sans erreur.
- Compiler sans warning avec `-Wall -Wextra -Werror`.

??? success "Solution"
    ```c
    /* ************************************************************************** */
    /*                                                                            */
    /*                                                        :::      ::::::::   */
    /*   ex01_minimal.c                                     :+:      :+:    :+:   */
    /*                                                    +:+ +:+         +:+     */
    /*   By: rdenimal <rdenimal@student.42.fr>          +#+  +:+       +#+        */
    /*                                                +#+#+#+#+#+   +#+           */
    /*   Created: 2026/06/08 10:00:00 by rdenimal          #+#    #+#             */
    /*   Updated: 2026/06/08 10:00:00 by rdenimal         ###   ########.fr       */
    /*                                                                            */
    /* ************************************************************************** */

    #include <unistd.h>

    int	main(void)
    {
    	write(1, "Bonjour, le C !\n", 16);
    	return (0);
    }
    ```

    Le décompte : `B-o-n-j-o-u-r-,-espace-l-e-espace-C-espace-!-\n` = 16 caractères.

### Exercice 2.2 — Carte de visite

Écris un programme qui affiche **ton prénom**, **ton nom** et **ton login 42** (ou ton pseudo de promo) sur trois lignes séparées.

Sortie attendue (avec tes infos) :

```
Prenom : Rémy
Nom : Denimal
Login : rdenimal
```

**Contraintes :**

- Trois appels à `write` distincts.
- Chaque ligne se termine par `\n`.

??? success "Solution"
    ```c
    /* en-tête 42 ici */

    #include <unistd.h>

    int	main(void)
    {
    	write(1, "Prenom : Remy\n", 14);
    	write(1, "Nom : Denimal\n", 14);
    	write(1, "Login : rdenimal\n", 17);
    	return (0);
    }
    ```

    !!! tip "Astuce sur les accents"
        Pour éviter les soucis d'encodage en piscine, on évite souvent les accents dans les chaînes affichées au terminal. « Remy » sans accent est plus sûr que « Rémy » : un caractère accentué peut compter pour **2 octets** en UTF-8, ce qui fausse ton décompte pour `write`.

### Exercice 2.3 — Compter juste

Voici un programme qui contient une erreur de décompte d'octets. Identifie-la **sans le compiler**, puis corrige-la.

```c
#include <unistd.h>

int	main(void)
{
	write(1, "42 c'est la vie\n", 14);
	return (0);
}
```

??? success "Solution"
    La chaîne `"42 c'est la vie\n"` contient 16 caractères :

    `4-2-espace-c-'-e-s-t-espace-l-a-espace-v-i-e-\n` = 16

    Le programme passe `14`, donc il n'affichera que les 14 premiers caractères et coupera avant le `\n` (et même avant le `e` de `vie`).

    Version corrigée :

    ```c
    write(1, "42 c'est la vie\n", 16);
    ```

### Exercice 2.4 — ASCII art minimaliste

Écris un programme qui affiche cette figure dans le terminal :

```
  *
 ***
*****
 ***
  *
```

**Contraintes :**

- Un seul appel à `write` est autorisé. Réfléchis à comment construire la chaîne.
- N'oublie pas de compter exactement les octets.

??? success "Solution"
    ```c
    /* en-tête 42 ici */

    #include <unistd.h>

    int	main(void)
    {
    	write(1, "  *\n ***\n*****\n ***\n  *\n", 24);
    	return (0);
    }
    ```

    Décompte ligne par ligne :

    - `"  *\n"` → 4 caractères
    - `" ***\n"` → 5 caractères
    - `"*****\n"` → 6 caractères
    - `" ***\n"` → 5 caractères
    - `"  *\n"` → 4 caractères

    Total : 4+5+6+5+4 = **24** caractères.

### Exercice 2.5 — La valeur de retour

Modifie `ex01_premier_programme.c` pour qu'il retourne `42` à la place de `0`. Compile-le, lance-le, puis tape immédiatement après dans ton terminal :

```bash
echo $?
```

Qu'observes-tu ? Pourquoi ?

??? success "Réponse"
    `echo $?` affiche le **code de retour** du dernier programme exécuté. Tu verras `42`, exactement ce que tu as renvoyé depuis `main`.

    Cette valeur est la manière dont un programme communique son **statut** au shell ou au programme appelant. Par convention :

    - `0` = tout s'est bien passé.
    - Tout autre nombre = une erreur, dont le code spécifique dépend du programme.

    Tu utiliseras cette convention dans tous tes futurs projets piscine, notamment dans les Makefiles et les tests automatisés.

---

## Partie 3 — Pour aller plus loin (bonus)

### Exercice 3.1 — Sortie d'erreur

Le descripteur `2` correspond à la **sortie d'erreur standard** (`stderr`). Écris un programme qui :

1. Affiche `"Tout va bien\n"` sur la sortie standard.
2. Affiche `"Petit souci ici\n"` sur la sortie d'erreur.

Vérifie que tu peux séparer les deux sorties avec :

```bash
./ton_programme 2>/dev/null    # Cache stderr, n'affiche que stdout
./ton_programme 1>/dev/null    # Cache stdout, n'affiche que stderr
```

??? success "Solution"
    ```c
    /* en-tête 42 ici */

    #include <unistd.h>

    int	main(void)
    {
    	write(1, "Tout va bien\n", 13);
    	write(2, "Petit souci ici\n", 16);
    	return (0);
    }
    ```

    Cette distinction `stdout` / `stderr` est fondamentale en Unix : elle permet aux scripts qui appellent ton programme de séparer les vraies sorties des messages d'erreur.

---

## Validation finale

Avant de passer au Support 02, assure-toi que tu peux faire **sans hésiter** :

- [ ] Créer un fichier `.c` avec un en-tête 42.
- [ ] Écrire une fonction `main` qui retourne `0`.
- [ ] Afficher une chaîne avec `write(1, "...", N)`.
- [ ] Compter les octets correctement (y compris les `\n`).
- [ ] Compiler avec `cc -Wall -Wextra -Werror -o nom_binaire fichier.c`.
- [ ] Lancer le binaire avec `./nom_binaire`.
- [ ] Valider avec `norminette` sans aucune erreur.

Si l'un de ces points te demande encore de réfléchir, refais l'exercice 2.1 jusqu'à ce que ça devienne mécanique. Le but de la piscine, c'est la fluidité — ces gestes doivent être automatiques pour que tu puisses te concentrer sur les vraies difficultés à venir.

---

➡️ **Retour au cours :** [Support 01 — Premier programme](./cours.md)
➡️ **Support suivant :** Support 02 — Caractères et affichage *(à venir)*
