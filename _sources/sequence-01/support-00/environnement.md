# Préparer son environnement de travail

> **Prérequis :** aucun
> **Objectif :** Avoir un environnement de développement Linux fonctionnel, avec tous les outils nécessaires pour écrire, compiler, valider et soumettre du code aux normes de l'École 42.

Avant d'écrire la moindre ligne de C, tu dois te mettre dans les bonnes conditions. À 42, l'environnement de travail n'est pas un détail : c'est ce qui fait la différence entre une piscine fluide et une piscine où tu galères sur des problèmes d'outils au lieu de problèmes de code.

Ce support est volontairement long et détaillé. Tu ne le liras qu'une fois. Prends ton temps, suis chaque étape, et garde-le sous la main pour y revenir.

---

## A. Choisir son système d'exploitation

### 1. Pourquoi pas Windows directement ?

Windows n'est pas un mauvais OS, mais il pose plusieurs problèmes pour faire du C aux normes 42 :

- Le compilateur de référence à 42 est `cc` (alias de `clang`), pas le compilateur Microsoft. Les comportements diffèrent parfois.
- Beaucoup d'outils Unix (`man`, `make`, `grep`, les permissions de fichiers, les liens symboliques…) sont absents ou se comportent différemment.
- `norminette` tourne sur Windows mais les conventions de fin de ligne (`CRLF` vs `LF`) sont une source d'ennuis permanente.
- En piscine, tu seras sur des Mac. Plus ton environnement personnel ressemble à un système Unix, moins tu auras de surprises.

**Conclusion :** travaille dans un environnement de type Unix. Trois options s'offrent à toi.

### 2. Les trois options possibles

| Option | Public idéal | Difficulté setup | Performance |
|---|---|---|---|
| **WSL2** (Windows Subsystem for Linux) | Tu es sous Windows et tu veux le minimum de bazar | ⭐ Très facile | ⭐⭐⭐ Excellent |
| **VM Linux** (VirtualBox, VMware) | Tu es sous Windows ou Mac et tu veux un Linux complet, isolé | ⭐⭐ Moyen | ⭐⭐ Bon |
| **Linux natif** (dual boot ou machine dédiée) | Tu es prêt à t'investir dans Linux pour de bon | ⭐⭐⭐ Plus exigeant | ⭐⭐⭐⭐ Parfait |

!!! tip "Recommandation pour préparer la piscine"
    Si tu es **sous Windows** : commence par **WSL2**. C'est l'option la plus rapide pour avoir un environnement Linux exploitable, et tu peux toujours basculer plus tard si tu veux.

    Si tu es **sous macOS** : tu peux faire toute ta prépa directement sur macOS (les outils sont quasi identiques à Linux), ou utiliser une VM Linux (UTM si tu es sur Apple Silicon, VirtualBox sur Intel).

### 3. Quelle distribution Linux choisir ?

Trois distributions sont des choix sûrs pour ton apprentissage :

- **Ubuntu LTS** (version « Long Term Support », ex : 24.04). Le défaut absolu, immense communauté, doc partout. **C'est ce que je recommande pour démarrer.**
- **Debian stable**. Plus dépouillée qu'Ubuntu, très stable. Excellent choix si tu veux comprendre ce que tu installes.
- **Linux Mint**. Très accessible visuellement, basée sur Ubuntu.

Évite pour l'instant : Arch, Gentoo, NixOS. Ce sont d'excellentes distributions mais elles te feront perdre du temps en setup au lieu de te le faire gagner en C.

---

## B. Installer ton environnement Linux

### 1. Option A : WSL2 sur Windows (recommandé si tu es sous Windows)

**WSL2** (*Windows Subsystem for Linux*) te donne un vrai noyau Linux qui tourne directement sous Windows, sans VM lourde.

#### Installation

1. Ouvre **PowerShell en mode administrateur** (clic droit sur le menu Démarrer → « Terminal (Administrateur) »).
2. Tape la commande :

    ```powershell
    wsl --install
    ```

    Cette commande installe WSL2 et Ubuntu par défaut.

3. **Redémarre** ta machine.

4. Au redémarrage, une fenêtre Ubuntu s'ouvre automatiquement. Crée ton utilisateur Linux (nom et mot de passe — celui-ci ne s'affichera pas en le tapant, c'est normal).

5. Tu es maintenant dans un shell Ubuntu. Tape :

    ```bash
    uname -a
    ```

    Si tu vois quelque chose comme `Linux ... GNU/Linux`, tu es prêt.

#### Bonus : accéder à tes fichiers

- Tes fichiers Windows sont accessibles depuis WSL via `/mnt/c/Users/ton_nom/...`.
- Tes fichiers WSL sont accessibles depuis Windows via `\\wsl$\Ubuntu\home\ton_nom_linux\...`.
- **Bonne pratique :** garde tes projets de code **dans le système de fichiers Linux** (`~/projets/`), pas sous `/mnt/c/`. Les performances sont nettement meilleures.

### 2. Option B : VM Linux avec VirtualBox

Si tu préfères une VM complète (utile si tu veux un environnement totalement isolé, ou si tu veux apprendre la virtualisation pour ton BTS) :

#### Installation

1. Télécharge **VirtualBox** depuis [virtualbox.org](https://www.virtualbox.org/) (gratuit, Oracle).
2. Télécharge une **ISO Ubuntu LTS** depuis [ubuntu.com/download/desktop](https://ubuntu.com/download/desktop).
3. Lance VirtualBox → **Nouvelle** → donne un nom (ex : `Ubuntu-42-prep`), sélectionne l'ISO téléchargée.
4. Configure les ressources :

    | Ressource | Minimum | Recommandé |
    |---|---|---|
    | RAM | 4 Go | 8 Go |
    | CPU | 2 cœurs | 4 cœurs |
    | Disque | 30 Go | 60 Go |

5. Démarre la VM. L'installeur Ubuntu te guide : choix de la langue, du clavier, création de l'utilisateur, mot de passe.

6. **Une fois Ubuntu installé**, installe les *Additions invité* (menu Périphériques → Insérer l'image CD des Additions invité…) pour bénéficier du copier-coller, du redimensionnement automatique, etc.

!!! warning "Mémoire et batterie"
    Une VM Linux consomme bien plus de RAM et de batterie qu'un WSL2. Si tu es sur portable, regarde la consommation après installation et adapte les ressources allouées.

### 3. Option C : Linux natif (dual boot)

Le dual boot est l'option la plus performante mais aussi la plus risquée si tu n'as jamais fait ça. **Avant toute manipulation : sauvegarde tes données importantes ailleurs.**

Tutoriel de référence : suis le guide officiel d'Ubuntu sur [ubuntu.com/tutorials/install-ubuntu-desktop](https://ubuntu.com/tutorials/install-ubuntu-desktop). Les étapes clés :

1. Réduire la partition Windows depuis la gestion des disques.
2. Créer une clé USB bootable avec l'ISO Ubuntu (outil **Rufus** sous Windows, **balenaEtcher** ailleurs).
3. Booter sur la clé USB depuis le BIOS/UEFI.
4. Pendant l'installation, choisir « Installer Ubuntu **à côté** de Windows ».

Le résultat : à chaque démarrage, tu choisis entre Windows et Ubuntu.

---

## C. Installer les outils de développement

À partir d'ici, je suppose que tu es dans un terminal Ubuntu (WSL, VM ou natif — peu importe). Les commandes sont identiques.

### 1. Mettre à jour le système

Premier réflexe **avant tout** :

```bash
sudo apt update && sudo apt upgrade -y
```

- `apt update` rafraîchit la liste des paquets disponibles.
- `apt upgrade` installe les mises à jour des paquets déjà présents.
- `sudo` exécute la commande en tant qu'administrateur (mot de passe demandé).
- `-y` répond automatiquement « oui » aux questions.

!!! info "À retenir"
    Refais cette commande **chaque semaine** sur ton système Linux. C'est l'équivalent de Windows Update.

### 2. Installer la chaîne de compilation C

```bash
sudo apt install -y build-essential
```

Ce paquet installe en une fois :

- `gcc` : le compilateur GNU C.
- `cc` : alias générique, qui pointera vers `gcc` par défaut sous Linux.
- `make` : l'outil pour exécuter des Makefiles.
- `libc6-dev` : les en-têtes de la bibliothèque standard C.

Vérifie l'installation :

```bash
cc --version
make --version
```

!!! tip "clang ou gcc ?"
    À 42, le compilateur officiel est `clang` (via l'alias `cc`). Sous Linux, par défaut, `cc` pointe vers `gcc`. **Cela n'a aucune importance pour ton apprentissage** : les deux compilateurs produisent un code conforme au standard C. Si tu veux vraiment installer clang pour être au plus près de l'environnement 42 :

    ```bash
    sudo apt install -y clang
    ```

### 3. Installer vim et git

```bash
sudo apt install -y vim git
```

Vérification :

```bash
vim --version | head -1
git --version
```

Configure git tout de suite (les commits sans identité refusent de partir) :

```bash
git config --global user.name "Prénom Nom"
git config --global user.email "ton.email@exemple.fr"
git config --global init.defaultBranch main
```

### 4. Installer Python et norminette

`norminette` est l'outil officiel qui valide tes fichiers C contre la Norm 42. Il est écrit en Python.

```bash
sudo apt install -y python3 python3-pip
pip install norminette --break-system-packages
```

!!! warning "Le flag `--break-system-packages`"
    Sur Ubuntu récent, `pip` refuse par défaut d'installer dans le Python système. `--break-system-packages` lève cette protection. C'est acceptable ici parce que `norminette` est un outil global. Pour des projets Python sérieux, tu apprendras à utiliser des **environnements virtuels** (`venv`), mais c'est hors sujet pour le moment.

Vérification :

```bash
norminette --version
```

Tu dois voir quelque chose comme `norminette 3.x.x, Python 3.x.x, Linux...`.

### 5. Installer un plugin 42header pour vim

L'**en-tête 42** (les 11 lignes de commentaires en haut de chaque `.c`) doit être générée automatiquement, pas tapée à la main. Plusieurs plugins existent pour vim.

Une option populaire : [`alexandregv/42header-vim`](https://github.com/alexandregv/42header-vim) sur GitHub.

Installation manuelle simple (sans gestionnaire de plugins) :

```bash
mkdir -p ~/.vim/plugin
curl -fLo ~/.vim/plugin/stdheader.vim \
    https://raw.githubusercontent.com/alexandregv/42header-vim/master/plugin/stdheader.vim
```

Configure ton identité 42 (à mettre dans ton `.bashrc` ou `.zshrc`) :

```bash
echo 'export USER42="rdenimal"' >> ~/.bashrc
echo 'export MAIL42="rdenimal@student.42.fr"' >> ~/.bashrc
source ~/.bashrc
```

Remplace `rdenimal` par ton vrai login (ou un pseudo provisoire si tu n'as pas encore ton login 42).

!!! info "Vérifie ce plugin avant utilisation"
    Plusieurs plugins 42header existent, et l'API de chacun diffère légèrement (nom de la commande, variables d'environnement attendues). Va sur la page GitHub du plugin que tu installes et lis son README. Celui suggéré ci-dessus utilise la commande `:Stdheader` et lit les variables `USER42` et `MAIL42`.

---

## D. Configurer vim pour le C

Sans configuration, vim est austère. Pour du C aux normes 42, la configuration **minimale** suivante est indispensable.

### 1. Créer ton `.vimrc`

Le fichier `~/.vimrc` est le fichier de configuration de vim. Crée-le :

```bash
vim ~/.vimrc
```

(Pour sortir de vim sans rien modifier : tape `:q!` puis Entrée. On verra la manipulation de vim à la section E.)

Voici une configuration de départ saine pour la piscine :

```vim
" === Indentation : OBLIGATOIRE pour la Norm 42 ===
set tabstop=4
set shiftwidth=4
set noexpandtab
set autoindent
set smartindent
set cinoptions=l1,t0

" === Affichage ===
syntax on
set number
set ruler
set showcmd
set cursorline
set colorcolumn=81

" === Recherche ===
set hlsearch
set incsearch
set ignorecase
set smartcase

" === Confort ===
set wildmenu
set autoread
set encoding=utf-8
set fileencoding=utf-8
set backspace=indent,eol,start
set mouse=a

" === Sauvegardes (évite les .swp partout) ===
set nobackup
set noswapfile

" === Reprise à la position précédente dans un fichier ===
autocmd BufReadPost *
    \ if line("'\"") > 1 && line("'\"") <= line("$") |
    \   exe "normal! g`\"" |
    \ endif

" === Raccourci 42header (F1) ===
nnoremap <F1> :Stdheader<CR>
```

### 2. Explication ligne par ligne

| Option | Effet |
|---|---|
| `set tabstop=4` | Une tabulation s'affiche comme 4 espaces. |
| `set shiftwidth=4` | L'indentation automatique utilise 4 caractères. |
| `set noexpandtab` | **CRITIQUE** : utilise des vraies tabulations, **pas** des espaces. La Norm 42 exige des tabs. |
| `set autoindent` | Hérite l'indentation de la ligne précédente. |
| `set smartindent` | Indente automatiquement après `{`, etc. |
| `set colorcolumn=81` | Colore la colonne 81 pour repérer le dépassement 80 col. |
| `set number` | Affiche les numéros de ligne. |
| `set hlsearch` | Surligne les résultats de recherche. |
| `set mouse=a` | Active la souris dans vim (clic = curseur, scroll = défilement). |

!!! warning "`expandtab` est le piège #1"
    Si tu actives accidentellement `set expandtab`, vim remplacera tes tabulations par des espaces. `norminette` rejettera **tous** tes fichiers. Si un jour `norminette` te dit « bad indentation » alors que tout te paraît bien aligné, c'est probablement ça.

### 3. Tester la config

Quitte vim (`:wq` pour sauvegarder et quitter), puis ouvre un fichier `.c` de test :

```bash
vim test.c
```

Tu dois voir : numéros de ligne à gauche, coloration syntaxique dès que tu tapes du C, et une colonne 81 colorée.

---

## E. Survivre dans vim

Vim a une réputation d'outil austère. C'est mérité. Mais en 20 minutes d'apprentissage, tu connaîtras assez de vim pour la piscine. Le reste s'apprend en route.

### 1. Les modes de vim

Vim est **modal** : la même touche fait des choses différentes selon le mode.

| Mode | Comment y entrer | Pour faire quoi |
|---|---|---|
| **Normal** | Touche `Esc` (depuis n'importe où) | Naviguer, supprimer, copier, coller |
| **Insertion** | Touche `i`, `a`, `o` (depuis Normal) | Taper du texte |
| **Visuel** | Touche `v` (depuis Normal) | Sélectionner du texte |
| **Commande** | Touche `:` (depuis Normal) | Sauvegarder, quitter, rechercher, etc. |

**Règle d'or :** quand tu es perdu, appuie sur **`Esc`**. Tu reviens en mode Normal, le mode par défaut.

### 2. Sauvegarder et quitter

En mode Normal, tape `:` puis une de ces commandes, puis Entrée :

| Commande | Effet |
|---|---|
| `:w` | Sauvegarder (write) |
| `:q` | Quitter |
| `:wq` ou `:x` | Sauvegarder puis quitter |
| `:q!` | Quitter **sans sauvegarder** (force) |
| `:w nom.c` | Sauvegarder sous un autre nom |

### 3. Naviguer dans le fichier

En mode Normal :

| Touche | Effet |
|---|---|
| `h` `j` `k` `l` | Gauche, bas, haut, droite (équivalent flèches) |
| `w` | Avancer d'un mot |
| `b` | Reculer d'un mot |
| `0` | Début de ligne |
| `$` | Fin de ligne |
| `gg` | Début du fichier |
| `G` | Fin du fichier |
| `:42` | Aller à la ligne 42 |
| `Ctrl-d` | Descendre d'une demi-page |
| `Ctrl-u` | Monter d'une demi-page |

!!! tip "Pourquoi `hjkl` ?"
    Sur les claviers historiques, ces touches étaient ergonomiques pour la main droite au repos. Aujourd'hui les flèches fonctionnent aussi, mais `hjkl` est tellement gravé dans vim que tu vas finir par les utiliser. Force-toi quelques jours, ça devient automatique.

### 4. Éditer

| Touche / Commande | Effet |
|---|---|
| `i` | Insérer **avant** le curseur |
| `a` | Insérer **après** le curseur |
| `o` | Nouvelle ligne en **dessous** + mode insertion |
| `O` | Nouvelle ligne **au-dessus** + mode insertion |
| `x` | Supprimer le caractère sous le curseur |
| `dd` | Supprimer la ligne entière |
| `yy` | Copier (yank) la ligne entière |
| `p` | Coller après la ligne courante |
| `P` | Coller avant la ligne courante |
| `u` | Annuler (undo) |
| `Ctrl-r` | Refaire (redo) |
| `.` | Répéter la dernière action |

### 5. Rechercher

En mode Normal :

| Commande | Effet |
|---|---|
| `/motif` | Chercher `motif` vers l'avant |
| `?motif` | Chercher `motif` vers l'arrière |
| `n` | Résultat suivant |
| `N` | Résultat précédent |
| `:noh` | Effacer le surlignage de recherche |

### 6. Sélection visuelle

| Touche | Effet |
|---|---|
| `v` | Mode visuel caractère par caractère |
| `V` | Mode visuel ligne par ligne |
| `Ctrl-v` | Mode visuel bloc (rectangulaire) |
| Une fois sélectionné : `d` (supprimer), `y` (copier), `>` (indenter), `<` (désindenter) | |

### 7. Le strict minimum à mémoriser pour démarrer

Si tu ne dois retenir que 12 commandes :

| # | Commande | Action |
|---|---|---|
| 1 | `Esc` | Revenir au mode Normal |
| 2 | `i` | Entrer en mode Insertion |
| 3 | `:w` | Sauvegarder |
| 4 | `:wq` | Sauvegarder et quitter |
| 5 | `:q!` | Quitter sans sauvegarder |
| 6 | `dd` | Supprimer une ligne |
| 7 | `yy` puis `p` | Dupliquer une ligne |
| 8 | `u` | Annuler |
| 9 | `/motif` | Chercher |
| 10 | `gg` / `G` | Début / fin de fichier |
| 11 | `:42` | Aller à la ligne 42 |
| 12 | `:Stdheader` | Insérer l'en-tête 42 (si plugin installé) |

---

## F. Atelier d'entraînement vim

Au lieu de t'apprendre vim « en théorie », fais ces exercices. Ils prennent 15 minutes et tu sauras vim assez pour la piscine.

### Exercice F.1 — Premier fichier

```bash
vim ex_vim_01.c
```

1. Appuie sur `i` pour entrer en mode Insertion.
2. Tape :

    ```c
    #include <unistd.h>
    int main(void)
    {
        write(1, "Vim\n", 4);
        return (0);
    }
    ```

3. Appuie sur `Esc` pour revenir au mode Normal.
4. Tape `:wq` puis Entrée. Le fichier est sauvegardé et vim quitte.
5. Vérifie : `cat ex_vim_01.c` doit afficher ce que tu as tapé.

### Exercice F.2 — Modifier un fichier existant

```bash
vim ex_vim_01.c
```

1. En mode Normal, va à la ligne 4 avec `:4`.
2. Sur la ligne `write(1, "Vim\n", 4);`, déplace-toi avec `l` jusqu'au `V` de `"Vim`.
3. Entre en mode Insertion avec `i` et remplace `Vim` par `Salut vim` (en ajustant le décompte d'octets : 10 au lieu de 4).
4. `Esc` puis `:wq`.
5. Compile et lance : `cc -Wall -Wextra -Werror ex_vim_01.c -o test && ./test`.

### Exercice F.3 — Manipulations rapides

Toujours dans `ex_vim_01.c` :

1. `gg` pour aller au début du fichier.
2. `yy` pour copier la ligne 1.
3. `p` pour la coller en dessous (tu as maintenant deux `#include`).
4. `u` pour annuler.
5. `dd` pour supprimer la ligne courante (`#include`). Oups.
6. `u` pour annuler à nouveau.
7. `:q!` pour quitter sans rien garder.

### Exercice F.4 — Recherche

1. Ouvre n'importe quel fichier C (le tien ou celui du Support 01).
2. Tape `/main` puis Entrée. Le mot `main` est surligné.
3. `n` pour aller au résultat suivant, `N` pour le précédent.
4. `:noh` pour effacer le surlignage.

### Exercice F.5 — Insertion d'en-tête 42

1. Crée un nouveau fichier : `vim test_header.c`.
2. En mode Normal, tape `:Stdheader` puis Entrée.
3. Si ton plugin et tes variables `USER42`/`MAIL42` sont bien configurés, l'en-tête apparaît automatiquement.
4. Si rien ne se passe : `:source ~/.vimrc` pour recharger, ou vérifie le README du plugin que tu as installé.

---

## G. Tester ton environnement complet

Une fois tout installé et configuré, fais ce test de bout en bout :

```bash
# 1. Créer un dossier de travail
mkdir -p ~/projets/test_env
cd ~/projets/test_env

# 2. Créer un fichier source avec vim
vim hello.c
```

Dans vim :

1. `:Stdheader` pour insérer l'en-tête 42 (Entrée).
2. `o` pour ajouter une ligne en dessous, puis `Esc`.
3. `i` puis tape :

    ```c
    #include <unistd.h>

    int	main(void)
    {
    	write(1, "Environnement OK\n", 17);
    	return (0);
    }
    ```

4. `Esc` puis `:wq`.

Puis dans le terminal :

```bash
# 3. Valider la Norm
norminette hello.c

# 4. Compiler avec les flags 42
cc -Wall -Wextra -Werror hello.c -o hello

# 5. Exécuter
./hello
```

**Tu dois voir :**

```
hello.c: OK!
Environnement OK
```

Si c'est le cas : **bravo**, ton environnement est prêt pour la piscine.

---

## Bilan

À la fin de ce support, tu as :

- [ ] Un environnement Linux fonctionnel (WSL2, VM ou natif).
- [ ] Le système à jour (`apt update && apt upgrade`).
- [ ] La chaîne de compilation installée (`build-essential` : `gcc`, `make`, `cc`).
- [ ] `vim` installé et configuré avec un `.vimrc` adapté à la Norm 42.
- [ ] `git` installé et configuré avec ton identité.
- [ ] `norminette` installé et fonctionnel.
- [ ] Un plugin 42header dans vim, avec tes variables `USER42` et `MAIL42`.
- [ ] Tu sais ouvrir, éditer, sauvegarder, quitter dans vim.
- [ ] Le test de bout en bout du §G passe sans erreur.

Tu peux maintenant attaquer le [Support 01 — Premier programme](../sequence-01/support-01/cours.md) sans frein technique.

## Pour aller plus loin

- `vimtutor` : un tutoriel interactif intégré à vim. Tape simplement `vimtutor` dans ton terminal, ça lance une session de 30 min qui couvre tout vim. **Fais-le au moins une fois.**
- Cheat sheet vim imprimable : [vim.rtorr.com](https://vim.rtorr.com/).
- Cours officiel WSL : [learn.microsoft.com/windows/wsl](https://learn.microsoft.com/en-us/windows/wsl/).
- Documentation Ubuntu : [help.ubuntu.com](https://help.ubuntu.com/).

---

➡️ **Support suivant :** [Support 01 — Premier programme](../sequence-01/support-01/cours.md)
