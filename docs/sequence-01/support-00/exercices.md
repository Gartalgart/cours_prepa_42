# Support 00 — Exercices

> **Objectif :** Maîtriser les commandes vim essentielles et vérifier que ton environnement est entièrement fonctionnel.

Pour chaque exercice pratique, lance réellement les commandes dans ton terminal avant de passer au suivant.

---

## Partie 1 — Quiz : vim et environnement

<div class="quiz-question" data-correct="1">
<p class="quiz-number">Question 1.1</p>
<p class="quiz-prompt">Tu viens de faire une erreur dans vim et tu es perdu. Quelle est la première touche à presser ?</p>
<ul class="quiz-options">
  <li class="quiz-option"><span class="quiz-option-marker">A</span> <code>Ctrl+Z</code></li>
  <li class="quiz-option"><span class="quiz-option-marker">B</span> <code>Esc</code></li>
  <li class="quiz-option"><span class="quiz-option-marker">C</span> <code>:q!</code></li>
  <li class="quiz-option"><span class="quiz-option-marker">D</span> <code>u</code></li>
</ul>
<button class="quiz-check" disabled>Vérifier</button>
<div class="quiz-feedback quiz-feedback-correct" hidden>✅ Correct ! <code>Esc</code> te ramène toujours en mode Normal — le mode par défaut de vim. C'est le réflexe n°1 à acquérir.</div>
<div class="quiz-feedback quiz-feedback-incorrect" hidden>❌ Pas tout à fait. La bonne réponse est <strong>B — <code>Esc</code></strong>. C'est le réflexe universel : peu importe dans quel mode ou quel état tu te trouves, <code>Esc</code> te ramène en mode Normal.</div>
</div>

<div class="quiz-question" data-correct="2">
<p class="quiz-number">Question 1.2</p>
<p class="quiz-prompt">Comment quitter vim <strong>sans sauvegarder</strong> les modifications ?</p>
<ul class="quiz-options">
  <li class="quiz-option"><span class="quiz-option-marker">A</span> <code>:wq</code></li>
  <li class="quiz-option"><span class="quiz-option-marker">B</span> <code>:w</code></li>
  <li class="quiz-option"><span class="quiz-option-marker">C</span> <code>:q!</code></li>
  <li class="quiz-option"><span class="quiz-option-marker">D</span> <code>Ctrl+C</code></li>
</ul>
<button class="quiz-check" disabled>Vérifier</button>
<div class="quiz-feedback quiz-feedback-correct" hidden>✅ Correct ! <code>:q!</code> force la fermeture sans sauvegarder. Le <code>!</code> signifie « force » — vim abandonne toutes les modifications non sauvegardées.</div>
<div class="quiz-feedback quiz-feedback-incorrect" hidden>❌ Pas tout à fait. La bonne réponse est <strong>C — <code>:q!</code></strong>. Le <code>!</code> force vim à quitter même s'il y a des modifications non sauvegardées. <code>:wq</code> sauvegarde avant de quitter, <code>:w</code> sauvegarde sans quitter.</div>
</div>

<div class="quiz-question" data-correct="0">
<p class="quiz-number">Question 1.3</p>
<p class="quiz-prompt">Quelle option du <code>.vimrc</code> est <strong>obligatoire</strong> pour respecter la Norm 42 ?</p>
<ul class="quiz-options">
  <li class="quiz-option"><span class="quiz-option-marker">A</span> <code>set noexpandtab</code></li>
  <li class="quiz-option"><span class="quiz-option-marker">B</span> <code>set number</code></li>
  <li class="quiz-option"><span class="quiz-option-marker">C</span> <code>set colorcolumn=81</code></li>
  <li class="quiz-option"><span class="quiz-option-marker">D</span> <code>set mouse=a</code></li>
</ul>
<button class="quiz-check" disabled>Vérifier</button>
<div class="quiz-feedback quiz-feedback-correct" hidden>✅ Correct ! <code>set noexpandtab</code> garantit que vim insère de vraies tabulations et non des espaces. La Norm 42 exige des tabulations — si vim insère des espaces, <code>norminette</code> rejette tous tes fichiers.</div>
<div class="quiz-feedback quiz-feedback-incorrect" hidden>❌ Pas tout à fait. La bonne réponse est <strong>A — <code>set noexpandtab</code></strong>. Sans cette option, vim peut remplacer les tabulations par des espaces, ce que <code>norminette</code> refuse systématiquement.</div>
</div>

<div class="quiz-question" data-correct="3">
<p class="quiz-number">Question 1.4</p>
<p class="quiz-prompt">Pourquoi est-il recommandé de garder ses projets <strong>dans le système de fichiers Linux</strong> plutôt que sous <code>/mnt/c/</code> avec WSL2 ?</p>
<ul class="quiz-options">
  <li class="quiz-option"><span class="quiz-option-marker">A</span> Pour éviter que Windows vole le code.</li>
  <li class="quiz-option"><span class="quiz-option-marker">B</span> Parce que <code>norminette</code> ne fonctionne pas sur <code>/mnt/c/</code>.</li>
  <li class="quiz-option"><span class="quiz-option-marker">C</span> Pour éviter les problèmes de majuscules dans les noms de fichiers.</li>
  <li class="quiz-option"><span class="quiz-option-marker">D</span> Les performances de compilation et d'I/O sont nettement meilleures côté Linux.</li>
</ul>
<button class="quiz-check" disabled>Vérifier</button>
<div class="quiz-feedback quiz-feedback-correct" hidden>✅ Correct ! Accéder à <code>/mnt/c/</code> depuis WSL2 passe par une couche de traduction entre les deux systèmes de fichiers. Pour la compilation et les accès fichiers intensifs, la différence de performance est très notable.</div>
<div class="quiz-feedback quiz-feedback-incorrect" hidden>❌ Pas tout à fait. La bonne réponse est <strong>D</strong> : les performances d'I/O sont nettement meilleures dans le système de fichiers Linux natif. La couche de traduction entre Windows et WSL2 introduit une latence significative pour les opérations fichiers intensives comme la compilation.</div>
</div>

<div class="quiz-question" data-correct="1">
<p class="quiz-number">Question 1.5</p>
<p class="quiz-prompt">Dans vim en mode Normal, quelle touche permet d'aller <strong>à la fin du fichier</strong> ?</p>
<ul class="quiz-options">
  <li class="quiz-option"><span class="quiz-option-marker">A</span> <code>gg</code></li>
  <li class="quiz-option"><span class="quiz-option-marker">B</span> <code>G</code></li>
  <li class="quiz-option"><span class="quiz-option-marker">C</span> <code>$</code></li>
  <li class="quiz-option"><span class="quiz-option-marker">D</span> <code>Ctrl-d</code></li>
</ul>
<button class="quiz-check" disabled>Vérifier</button>
<div class="quiz-feedback quiz-feedback-correct" hidden>✅ Correct ! <code>G</code> (majuscule) va à la dernière ligne du fichier. Son opposé, <code>gg</code>, va à la première ligne. <code>$</code> va à la fin de la <em>ligne courante</em>, et <code>Ctrl-d</code> descend d'une demi-page.</div>
<div class="quiz-feedback quiz-feedback-incorrect" hidden>❌ Pas tout à fait. La bonne réponse est <strong>B — <code>G</code></strong> (majuscule). <code>gg</code> va au <em>début</em> du fichier, <code>$</code> va à la fin de la <em>ligne</em> courante, et <code>Ctrl-d</code> descend d'une demi-page.</div>
</div>

<p id="quiz-score" class="quiz-score"></p>

---

## Partie 2 — Atelier vim (exercices pratiques)

### Exercice 2.1 — Premier fichier

```bash
vim ex_vim_01.c
```

1. Appuie sur `i` pour entrer en mode Insertion.
2. Tape :

    ```c
    #include <unistd.h>

    int	main(void)
    {
    	write(1, "Vim\n", 4);
    	return (0);
    }
    ```

3. Appuie sur `Esc`.
4. Tape `:wq` puis Entrée.
5. Vérifie : `cat ex_vim_01.c` doit afficher exactement ce que tu as tapé.

### Exercice 2.2 — Modifier un fichier existant

```bash
vim ex_vim_01.c
```

1. En mode Normal, va à la ligne du `write` avec `:5`.
2. Déplace-toi jusqu'à la chaîne `"Vim\n"`.
3. Entre en mode Insertion avec `i` et remplace `Vim` par `Salut vim`, en ajustant le décompte (10 au lieu de 4).
4. `Esc` puis `:wq`.
5. Compile et lance :

    ```bash
    cc -Wall -Wextra -Werror ex_vim_01.c -o test && ./test
    ```

    Tu dois voir `Salut vim` dans le terminal.

### Exercice 2.3 — Manipulations rapides

Toujours dans `ex_vim_01.c` :

1. `gg` pour aller au début du fichier.
2. `yy` pour copier la ligne 1 (`#include`).
3. `p` pour la coller en dessous — tu as maintenant deux `#include`.
4. `u` pour annuler.
5. `dd` pour supprimer la ligne courante.
6. `u` pour annuler à nouveau.
7. `:q!` pour quitter sans rien garder.

### Exercice 2.4 — Recherche dans un fichier

1. Ouvre n'importe quel fichier `.c`.
2. Tape `/main` puis Entrée. Le mot `main` est surligné.
3. `n` pour aller au résultat suivant, `N` pour le précédent.
4. `:noh` pour effacer le surlignage.

### Exercice 2.5 — En-tête 42

1. Crée un nouveau fichier : `vim test_header.c`.
2. En mode Normal, tape `:Stdheader` puis Entrée.
3. Si tes variables `USER42` et `MAIL42` sont bien configurées, l'en-tête apparaît automatiquement.
4. `:wq` pour sauvegarder.
5. Lance `norminette test_header.c` — il doit passer sans erreur, même sur un fichier vide (juste l'en-tête).

---

## Validation finale

Avant de passer au Support 01, assure-toi que tu peux faire **sans hésiter** :

- [ ] Lancer un terminal Linux (WSL, VM ou natif).
- [ ] Créer un fichier `.c` avec vim et y insérer l'en-tête 42 automatiquement.
- [ ] Sauvegarder et quitter vim (`:wq`).
- [ ] Naviguer dans vim avec `gg`, `G`, `:N`, `/motif`.
- [ ] Compiler un fichier C avec `cc -Wall -Wextra -Werror`.
- [ ] Lancer `norminette` et interpréter son résultat.
- [ ] Voir `Environnement OK` en lançant le test du §F du cours.

Si un point bloque encore, reviens à la section correspondante du [cours](./cours.md) et recommence l'installation depuis cette étape.

---

➡️ **Retour au cours :** [Support 00 — Préparer son environnement](./cours.md)
➡️ **Support suivant :** [Support 01 — Premier programme](../support-01/cours.md)
