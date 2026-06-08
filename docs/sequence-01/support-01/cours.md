# Support 01 — Premier programme

> **Prérequis :** aucun
> **Objectif :** À la fin de ce support, tu sauras écrire, compiler et exécuter ton premier programme en C, conforme aux normes de l'École 42.

---

## A. La structure d'un fichier C

### 1. L'extension `.c`

Tout fichier de code source en C porte l'extension `.c`. C'est une convention universelle : ton compilateur, ton éditeur et tes camarades de piscine s'attendent à la voir.

Pour ce support, tu vas créer un fichier nommé `ex01_premier_programme.c`. Le nom n'a pas d'importance technique, mais il doit être **explicite** : on doit deviner ce que fait le fichier rien qu'en lisant son nom.

!!! tip "Astuce"
    À 42, on évite les noms vagues comme `test.c` ou `truc.c`. Préfère `parser_csv.c`, `ft_atoi.c`, `print_grid.c`. Un bon nom de fichier, c'est de la doc gratuite.

### 2. L'en-tête 42

Tout fichier `.c` rendu à l'École 42 commence obligatoirement par un **en-tête 42** : un bloc de 11 lignes de commentaires qui identifie l'auteur, la date de création et la date de dernière modification.

```c
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex01_premier_programme.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdenimal <rdenimal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/08 10:00:00 by rdenimal          #+#    #+#             */
/*   Updated: 2026/06/08 10:00:00 by rdenimal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
```

Tu n'écris jamais cet en-tête à la main : il est généré automatiquement par une extension de ton éditeur (souvent appelée « 42header »). À 42, le raccourci standard est `Ctrl+Alt+H` sous VS Code avec l'extension officielle.

!!! warning "Attention"
    Pas d'en-tête = `norminette` refuse le fichier. Pas de fichier valide = pas de soumission. Active l'extension dès le premier jour.

### 3. Les `#include`

En dessous de l'en-tête, tu déclares les **bibliothèques** dont ton programme a besoin. Une bibliothèque, c'est un ensemble de fonctions déjà écrites que tu peux utiliser sans les recoder.

Pour ce premier programme, tu vas afficher du texte avec la fonction `write`. Cette fonction est définie dans la bibliothèque `unistd.h`. Tu l'importes avec :

```c
#include <unistd.h>
```

Les chevrons (`< >`) indiquent que c'est une bibliothèque **système**, fournie par ton environnement Unix/Linux.

### 4. La fonction `main`

Tout programme C commence son exécution par une fonction unique, obligatoire et nommée précisément : **`main`**.

```c
int	main(void)
{
	/* Ton code ici */
	return (0);
}
```

Décomposons :

- `int` est le **type de retour** : `main` renvoie un nombre entier au système d'exploitation à la fin de son exécution.
- `void` entre parenthèses signifie que `main` ne reçoit aucun paramètre (pour l'instant — on verra `argc` et `argv` plus tard).
- Les accolades `{` et `}` délimitent le **corps** de la fonction. Toutes les instructions entre ces accolades seront exécutées dans l'ordre.
- `return (0);` indique au système que tout s'est bien passé. Une valeur de retour différente de zéro signifie une erreur.

!!! note "À retenir"
    À la Norm 42, les parenthèses autour de la valeur de retour sont **obligatoires** : on écrit `return (0);` et jamais `return 0;`.

---

## B. Afficher avec `write`

### 1. Pourquoi pas `printf` ?

Si tu as déjà fait du C ailleurs, tu connais peut-être `printf`. À 42, et particulièrement au début de la piscine, `printf` est **interdit**. La raison : on veut que tu comprennes ce qui se passe vraiment quand un programme écrit dans le terminal. `printf` cache beaucoup de complexité (formatage, conversion, tampons). `write` est l'appel système brut, en dessous duquel il n'y a plus rien.

Tu reverras `printf` plus tard, et tu le réécriras toi-même dans un projet appelé `ft_printf`. D'ici là, on travaille avec `write`.

### 2. Anatomie d'un appel à `write`

```c
write(1, "Salut, piscine !\n", 17);
```

Trois arguments, séparés par des virgules :

| Position | Rôle | Exemple |
|---|---|---|
| 1er argument | Le **descripteur de fichier** | `1` = sortie standard (le terminal) |
| 2e argument | La **chaîne** à afficher | `"Salut, piscine !\n"` |
| 3e argument | Le **nombre d'octets** à écrire | `17` (compte les caractères de la chaîne) |

Le descripteur `1` correspond à la **sortie standard** (`stdout`) — c'est l'endroit où ton terminal lit ce qu'il doit afficher. On verra `0` (entrée standard) et `2` (sortie d'erreur) plus tard.

!!! warning "Compter les caractères"
    Le troisième argument est piégeux : tu dois compter **chaque caractère** de la chaîne, y compris les espaces, la ponctuation et le `\n`. Si tu mets un nombre trop petit, une partie du message ne s'affiche pas. Trop grand, et tu lis de la mémoire à côté (comportement indéfini, parfois plantage).

    Pour `"Salut, piscine !\n"` : `S-a-l-u-t-,-espace-p-i-s-c-i-n-e-espace-!-\n` → 17 caractères.

### 3. Le caractère `\n`

`\n` n'est pas deux caractères : c'est un **caractère unique** qui signifie « passer à la ligne suivante ». On l'appelle un caractère d'**échappement** parce qu'on l'écrit avec un antislash suivi d'une lettre.

Sans `\n` à la fin, ton prochain prompt shell apparaîtrait collé à ta sortie, ce qui est moche.

---

## C. Compiler et exécuter

Un fichier `.c` n'est pas exécutable. Il faut le transformer en un **binaire** (un programme que la machine peut lancer) à l'aide d'un **compilateur**.

### 1. Le compilateur `cc`

À 42, le compilateur de référence est `cc` (qui, sur la plupart des systèmes, est un alias pour `clang` ou `gcc`). La commande minimale pour compiler ton fichier :

```bash
cc ex01_premier_programme.c
```

Par défaut, cette commande produit un binaire nommé `a.out` dans le dossier courant. Pour donner un nom explicite à ton binaire, utilise l'option `-o` :

```bash
cc ex01_premier_programme.c -o ex01
```

### 2. Les flags 42 obligatoires

Compiler sans options, c'est demander à `cc` d'être gentil avec toi : il ferme les yeux sur beaucoup de problèmes. À 42, on exige **trois flags** systématiques :

```bash
cc -Wall -Wextra -Werror ex01_premier_programme.c -o ex01
```

| Flag | Effet |
|---|---|
| `-Wall` | Active **toutes les warnings** courantes (variables non utilisées, comparaisons douteuses…) |
| `-Wextra` | Active des warnings **supplémentaires** plus stricts |
| `-Werror` | Transforme chaque warning en **erreur** : la compilation échoue au moindre avertissement |

L'idée : si ton code passe ces trois flags, il est **propre**. Aucune ambiguïté, aucun comportement douteux toléré.

!!! tip "Astuce"
    Quand tu compileras des projets plus gros, tu utiliseras un fichier `Makefile` pour automatiser la commande. Pour aujourd'hui, tape la commande à la main : c'est utile de la connaître par cœur.

### 3. Lancer le programme

Une fois compilé, lance le binaire en préfixant son nom par `./` (qui veut dire « dans le dossier courant ») :

```bash
./ex01
```

Sortie attendue :

```
Salut, piscine !
```

Si tu vois ça, **bravo** : tu viens d'écrire, compiler et exécuter ton premier programme en C aux normes 42.

---

## D. Valider avec `norminette`

### 1. Qu'est-ce que la Norm ?

La **Norm 42** est un ensemble de règles strictes sur la mise en forme du code C : indentation, nommage, taille des fonctions, structure des fichiers… Tout code rendu à 42 doit passer la Norm, sinon le projet est noté **0**.

Pour vérifier qu'un fichier respecte la Norm, on utilise un outil officiel : **`norminette`**.

### 2. Installation et utilisation

```bash
pip install norminette
norminette ex01_premier_programme.c
```

Si tout va bien, tu verras :

```
ex01_premier_programme.c: OK!
```

Si quelque chose cloche, `norminette` te donnera une liste d'erreurs avec le numéro de ligne. À toi de les corriger.

### 3. Quelques règles déjà visibles dans ce fichier

Tu n'as pas besoin d'apprendre la Norm par cœur dès maintenant — on l'introduira par petits bouts. Mais en observant `ex01_premier_programme.c`, tu peux déjà repérer :

- **Indentation par tabulations** (pas par espaces).
- **Accolade `{` de la fonction sur une nouvelle ligne** (style Allman).
- **Un seul espace** ou une **tabulation** entre `int` et `main`.
- **Parenthèses obligatoires** autour de la valeur de retour : `return (0);`.

---

## Bilan

À la fin de ce support, tu sais :

- Créer un fichier `.c` avec un nom explicite.
- Reconnaître l'en-tête 42 et savoir qu'il est obligatoire (généré automatiquement par ton éditeur).
- Inclure une bibliothèque système avec `#include <...>`.
- Écrire une fonction `main` minimale qui retourne `0`.
- Afficher du texte avec `write(1, "...", N)`.
- Comprendre le rôle du caractère `\n`.
- Compiler avec `cc -Wall -Wextra -Werror` et exécuter avec `./binaire`.
- Valider ton code avec `norminette`.

## Pour aller plus loin

- Page de manuel de `write` : `man 2 write` dans ton terminal.
- Repo officiel `norminette` : [github.com/42School/norminette](https://github.com/42School/norminette).
- Documentation `clang` : [clang.llvm.org/docs](https://clang.llvm.org/docs/).

---

➡️ **Exercices du support :** [voir la page exercices](./exercices.md)
➡️ **Support suivant :** Support 02 — Caractères et affichage *(à venir)*
