# Support 00 — Préparer son environnement de travail

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

### 1. Option A — WSL2 sur Windows (recommandé si tu es sous Windows)

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

!!! warning "Attention aux performances"
    Garde tes projets de code **dans le système de fichiers Linux** (`~/projets/`), pas sous `/mnt/c/`. Les performances de compilation sont nettement meilleures côté Linux.

### 2. Option B — VM Linux avec VirtualBox

Si tu préfères une VM complète (utile si tu veux un environnement totalement isolé, ou si tu veux apprendre la virtualisation pour ton BTS) :

1. Télécharge **VirtualBox** (gratuit, Oracle).
2. Télécharge une **ISO Ubuntu LTS**.
3. Lance VirtualBox → **Nouvelle** → donne un nom, sélectionne l'ISO téléchargée.
4. Configure les ressources :

    | Ressource | Minimum | Recommandé |
    |---|---|---|
    | RAM | 4 Go | 8 Go |
    | CPU | 2 cœurs | 4 cœurs |
    | Disque | 30 Go | 60 Go |

5. Démarre la VM. L'installeur Ubuntu te guide : langue, clavier, création de l'utilisateur.
6. Installe les *Additions invité* (menu Périphériques → Insérer l'image CD des Additions invité…) pour le copier-coller et le redimensionnement.

!!! warning "Mémoire et batterie"
    Une VM consomme bien plus de RAM et de batterie que WSL2. Si tu es sur portable, adapte les ressources allouées.

### 3. Option C — Linux natif (dual boot)

Le dual boot est l'option la plus performante mais aussi la plus risquée si tu n'as jamais fait ça. **Avant toute manipulation : sauvegarde tes données importantes ailleurs.**

Suis le guide officiel Ubuntu. Les étapes clés :

1. Réduire la partition Windows depuis la gestion des disques.
2. Créer une clé USB bootable avec l'ISO Ubuntu (outil **Rufus** sous Windows, **balenaEtcher** ailleurs).
3. Booter sur la clé USB depuis le BIOS/UEFI.
4. Pendant l'installation, choisir « Installer Ubuntu **à côté** de Windows ».

---

## C. Installer les outils de développement

À partir d'ici, je suppose que tu es dans un terminal Ubuntu (WSL, VM ou natif — les commandes sont identiques).

### 1. Mettre à jour le système

Premier réflexe **avant tout** :

```bash
sudo apt update && sudo apt upgrade -y
```

!!! note "À retenir"
    Refais cette commande **chaque semaine** sur ton système Linux.

### 2. Installer la chaîne de compilation C

```bash
sudo apt install -y build-essential
```

Ce paquet installe en une fois `gcc`, `cc`, `make` et les en-têtes de la bibliothèque standard C.

Vérifie l'installation :

```bash
cc --version
make --version
```

!!! tip "clang ou gcc ?"
    À 42, le compilateur officiel est `clang` (via l'alias `cc`). Sous Linux, `cc` pointe par défaut vers `gcc`. **Cela n'a aucune importance pour ton apprentissage** : les deux sont conformes au standard C. Si tu veux installer clang pour être au plus près de l'environnement 42 :

    ```bash
    sudo apt install -y clang
    ```

### 3. Installer vim et git

```bash
sudo apt install -y vim git
```

Configure git immédiatement (les commits sans identité refusent de partir) :

```bash
git config --global user.name "Prénom Nom"
git config --global user.email "ton.email@exemple.fr"
git config --global init.defaultBranch main
```

### 4. Installer norminette

```bash
sudo apt install -y python3 python3-pip
pip install norminette --break-system-packages
```

!!! warning "Le flag `--break-system-packages`"
    Sur Ubuntu récent, `pip` refuse par défaut d'installer dans le Python système. Ce flag lève cette protection. C'est acceptable pour un outil global comme `norminette`. Pour des projets Python sérieux, utilise des environnements virtuels (`venv`).

Vérification :

```bash
norminette --version
```

Tu dois voir quelque chose comme `norminette 3.x.x, Python 3.x.x`.

### 5. Installer un plugin 42header pour vim

L'**en-tête 42** (les 11 lignes de commentaires en haut de chaque `.c`) est générée automatiquement par un plugin — pas écrite à la main.

Une option populaire : [`alexandregv/42header-vim`](https://github.com/alexandregv/42header-vim).

```bash
mkdir -p ~/.vim/plugin
curl -fLo ~/.vim/plugin/stdheader.vim \
    https://raw.githubusercontent.com/alexandregv/42header-vim/master/plugin/stdheader.vim
```

Configure ton identité 42 dans ton `.bashrc` :

```bash
echo 'export USER42="rdenimal"' >> ~/.bashrc
echo 'export MAIL42="rdenimal@student.42.fr"' >> ~/.bashrc
source ~/.bashrc
```

Remplace `rdenimal` par ton login (ou un pseudo provisoire si tu n'as pas encore ton login 42).

!!! info "Vérifie le README du plugin"
    Plusieurs plugins 42header existent avec des APIs différentes. Lis toujours le README de celui que tu installes. Celui suggéré ci-dessus utilise la commande `:Stdheader` et lit les variables `USER42` et `MAIL42`.

---

## D. Configurer vim pour la Norm 42

Sans configuration, vim est austère et **incompatible** avec la Norm 42 par défaut.

### 1. Créer ton `.vimrc`

```bash
vim ~/.vimrc
```

Colle cette configuration de départ :

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

### 2. Options clés

| Option | Effet |
|---|---|
| `set noexpandtab` | **CRITIQUE** : utilise des vraies tabulations. La Norm 42 exige des tabs, pas des espaces. |
| `set colorcolumn=81` | Colore la colonne 81 pour repérer les lignes trop longues (limite : 80 colonnes). |
| `set number` | Affiche les numéros de ligne. |
| `set mouse=a` | Active la souris dans vim. |

!!! warning "`expandtab` est le piège n°1"
    Si tu actives `set expandtab`, vim remplace tes tabulations par des espaces. `norminette` rejettera **tous** tes fichiers. Si un jour `norminette` affiche « bad indentation » sans raison apparente, c'est probablement ça.

---

## E. Survivre dans vim

Vim a une réputation d'outil austère. C'est mérité. Mais en 20 minutes, tu en sais assez pour la piscine. Le reste s'apprend en route.

### 1. Les modes de vim

Vim est **modal** : la même touche fait des choses différentes selon le mode actif.

| Mode | Comment y entrer | Pour faire quoi |
|---|---|---|
| **Normal** | `Esc` (depuis n'importe où) | Naviguer, supprimer, copier, coller |
| **Insertion** | `i`, `a`, `o` (depuis Normal) | Taper du texte |
| **Visuel** | `v` (depuis Normal) | Sélectionner du texte |
| **Commande** | `:` (depuis Normal) | Sauvegarder, quitter, rechercher |

**Règle d'or :** quand tu es perdu, appuie sur **`Esc`**. Tu reviens toujours en mode Normal.

### 2. Sauvegarder et quitter

| Commande | Effet |
|---|---|
| `:w` | Sauvegarder |
| `:q` | Quitter |
| `:wq` ou `:x` | Sauvegarder puis quitter |
| `:q!` | Quitter **sans sauvegarder** |

### 3. Naviguer dans le fichier

| Touche | Effet |
|---|---|
| `h` `j` `k` `l` | Gauche, bas, haut, droite |
| `w` / `b` | Avancer / reculer d'un mot |
| `0` / `$` | Début / fin de ligne |
| `gg` / `G` | Début / fin du fichier |
| `:42` | Aller à la ligne 42 |
| `Ctrl-d` / `Ctrl-u` | Descendre / monter d'une demi-page |

### 4. Éditer

| Touche | Effet |
|---|---|
| `i` / `a` | Insérer avant / après le curseur |
| `o` / `O` | Nouvelle ligne en dessous / au-dessus + insertion |
| `x` | Supprimer le caractère sous le curseur |
| `dd` | Supprimer la ligne entière |
| `yy` | Copier (yank) la ligne entière |
| `p` / `P` | Coller après / avant la ligne courante |
| `u` | Annuler (undo) |
| `Ctrl-r` | Refaire (redo) |

### 5. Le strict minimum à mémoriser

| # | Commande | Action |
|---|---|---|
| 1 | `Esc` | Revenir au mode Normal |
| 2 | `i` | Entrer en mode Insertion |
| 3 | `:wq` | Sauvegarder et quitter |
| 4 | `:q!` | Quitter sans sauvegarder |
| 5 | `dd` | Supprimer une ligne |
| 6 | `yy` puis `p` | Dupliquer une ligne |
| 7 | `u` | Annuler |
| 8 | `/motif` | Chercher |
| 9 | `gg` / `G` | Début / fin de fichier |
| 10 | `:Stdheader` | Insérer l'en-tête 42 |

---

## F. Tester ton environnement complet

Une fois tout installé, fais ce test de bout en bout :

```bash
mkdir -p ~/projets/test_env
cd ~/projets/test_env
vim hello.c
```

Dans vim :

1. `:Stdheader` + Entrée pour insérer l'en-tête 42.
2. `o` puis `Esc` pour ajouter une ligne vide en dessous.
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

Dans le terminal :

```bash
norminette hello.c
cc -Wall -Wextra -Werror hello.c -o hello
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

- Un environnement Linux fonctionnel (WSL2, VM ou natif).
- Le système à jour (`apt update && apt upgrade`).
- La chaîne de compilation installée (`build-essential` : `cc`, `make`).
- `vim` installé et configuré avec un `.vimrc` adapté à la Norm 42.
- `git` installé et configuré avec ton identité.
- `norminette` installé et fonctionnel.
- Un plugin 42header dans vim, avec tes variables `USER42` et `MAIL42`.
- Tu sais ouvrir, éditer, sauvegarder et quitter dans vim.
- Le test de bout en bout du §F passe sans erreur.

## Pour aller plus loin

- `vimtutor` — tutoriel interactif intégré à vim. Tape `vimtutor` dans ton terminal : une session de 30 min qui couvre tout vim. **Fais-le au moins une fois.**
- Cheat sheet vim : [vim.rtorr.com](https://vim.rtorr.com/)
- Documentation WSL : [learn.microsoft.com/windows/wsl](https://learn.microsoft.com/en-us/windows/wsl/)
- Documentation Ubuntu : [help.ubuntu.com](https://help.ubuntu.com/)

---

➡️ **Exercices du support :** [voir la page exercices](./exercices.md)
➡️ **Support suivant :** [Support 01 — Premier programme](../support-01/cours.md)
