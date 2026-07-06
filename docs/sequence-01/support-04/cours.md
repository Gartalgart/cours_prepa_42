# Support 04 — Opérateurs

> **Prérequis :** [Support 03 — Variables et types](../support-03/cours.md)
> **Objectif :** À la fin de ce support, tu sauras utiliser les opérateurs arithmétiques (`+ - * / %`), de comparaison (`< > == != <= >=`) et logiques (`&& || !`), et tu comprendras la **priorité** des opérateurs pour éviter les pièges classiques.

---

## A. Opérateurs arithmétiques

### 1. Les quatre opérations + le modulo

| Opérateur | Nom | Exemple | Résultat |
|---|---|---|---|
| `+` | Addition | `3 + 2` | `5` |
| `-` | Soustraction | `3 - 2` | `1` |
| `*` | Multiplication | `3 * 2` | `6` |
| `/` | Division | `7 / 2` | `3` |
| `%` | Modulo (reste de la division) | `7 % 2` | `1` |

Tu connais les quatre premiers depuis l'école. Le **modulo** est plus rare dans la vie quotidienne mais omniprésent en programmation.

### 2. La division entière

Voici le piège n° 1 de la division en C :

```c
int	resultat;

resultat = 7 / 2;       /* resultat = 3, PAS 3.5 */
```

Quand tu divises deux `int`, le résultat est un `int` : la partie décimale est **tronquée** (jetée). `7 / 2` donne `3`, pas `3.5`.

Pour obtenir une division réelle, il faudrait des **flottants** (`float`, `double`), ce qu'on verra hors séquence 1. Pour l'instant, retiens : **division d'`int` = division entière**.

### 3. Le modulo : trouver le reste

`%` te donne le **reste** d'une division entière :

```c
17 / 5  ->  3   (quotient)
17 % 5  ->  2   (reste, car 17 = 5 * 3 + 2)
```

Le modulo est extraordinairement utile :

- **Tester la parité** : `n % 2 == 0` veut dire que `n` est pair.
- **Découper un nombre en chiffres** : `n % 10` donne le chiffre des unités, `n / 10` retire ce chiffre.
- **Cycler** : pour passer à travers des valeurs 0, 1, 2, 0, 1, 2…, on fait `i % 3`.

!!! warning "Division par zéro"
    `n / 0` et `n % 0` provoquent une **erreur fatale** : *floating point exception* (le programme crashe). Avant de diviser, tu dois t'assurer que le diviseur n'est pas nul. On verra comment faire au Support 05 (conditions).

### 4. Opérateurs raccourcis

Quand tu modifies une variable par rapport à elle-même, tu peux utiliser une **forme raccourcie** :

| Forme complète | Forme raccourcie |
|---|---|
| `x = x + 5;` | `x += 5;` |
| `x = x - 1;` | `x -= 1;` |
| `x = x * 2;` | `x *= 2;` |
| `x = x / 4;` | `x /= 4;` |
| `x = x % 3;` | `x %= 3;` |

!!! note "À retenir"
    Ces formes raccourcies sont **autorisées par la Norm 42** et fréquemment utilisées en piscine. Elles rendent le code plus lisible quand l'opération est triviale.

### 5. Opérateurs unaires `++` et `--`

`++` et `--` incrémentent ou décrémentent une variable de `1` :

```c
i++;        /* équivalent à i = i + 1; */
i--;        /* équivalent à i = i - 1; */
```

Tu en verras partout dans les boucles à partir du Support 06.

!!! warning "Préfixe vs postfixe — un piège"
    Il existe deux formes : **préfixe** (`++i`) et **postfixe** (`i++`).

    - `i++` (postfixe) : « utilise la valeur de `i`, **puis** l'incrémente ».
    - `++i` (préfixe) : « incrémente `i`, **puis** utilise la nouvelle valeur ».

    ```c
    int	i;
    int	j;

    i = 5;
    j = i++;        /* j = 5, i = 6  (j prend la valeur AVANT incrément) */

    i = 5;
    j = ++i;        /* j = 6, i = 6  (j prend la valeur APRÈS incrément) */
    ```

    À la Norm 42, **utilise `++` et `--` sur une ligne séparée**, jamais à l'intérieur d'une expression complexe. C'est plus lisible et plus sûr.

---

## B. Opérateurs de comparaison

### 1. La liste

| Opérateur | Signification |
|---|---|
| `==` | Égal à |
| `!=` | Différent de |
| `<` | Strictement inférieur |
| `>` | Strictement supérieur |
| `<=` | Inférieur ou égal |
| `>=` | Supérieur ou égal |

### 2. Le résultat est un `int` : `0` ou `1`

Une comparaison renvoie un **entier** : `0` si la comparaison est **fausse**, `1` si elle est **vraie**.

```c
int	resultat;

resultat = 5 > 3;       /* resultat = 1 */
resultat = 5 < 3;       /* resultat = 0 */
resultat = 5 == 5;      /* resultat = 1 */
resultat = 5 != 5;      /* resultat = 0 */
```

C'est ce qu'on appelle un **booléen** : une valeur qui ne peut être que « vrai » ou « faux ». Tu utiliseras ces résultats dans les `if` du Support 05.

### 3. Le piège n° 2 : `=` vs `==`

C'est l'erreur la plus fréquente chez les débutants. Compare :

```c
x = 5;          /* AFFECTATION : x reçoit 5 */
x == 5;         /* COMPARAISON : est-ce que x vaut 5 ? */
```

Si tu écris `if (x = 5)` (avec un seul `=`), tu **affectes** `5` à `x` au lieu de tester. Le compilateur ne te le dira pas toujours, et le résultat est imprévisible.

!!! warning "À la Norm 42"
    **Une affectation à l'intérieur d'une condition est interdite.** Cette règle existe précisément pour t'empêcher de confondre `=` et `==`.

---

## C. Opérateurs logiques

### 1. La logique booléenne en C

En C, il n'y a pas de type `bool` natif (avant le standard C99). À la place :

- **Zéro = faux.**
- **Tout sauf zéro = vrai.**

C'est crucial. Un `int` qui vaut `42` est considéré comme « vrai » dans un test logique. Seul `0` est faux.

### 2. Les trois opérateurs

| Opérateur | Nom | Résultat |
|---|---|---|
| `&&` | ET logique | Vrai si **les deux** opérandes sont vrais |
| `\|\|` | OU logique | Vrai si **au moins un** opérande est vrai |
| `!` | NON logique (négation) | Inverse la valeur (vrai ↔ faux) |

Exemples :

```c
int	a;
int	b;
int	resultat;

a = 1;
b = 0;
resultat = a && b;      /* 0 (faux : a et b ne sont pas tous deux vrais) */
resultat = a || b;      /* 1 (vrai : au moins l'un est vrai) */
resultat = !a;          /* 0 (a était vrai, !a est faux) */
resultat = !b;          /* 1 (b était faux, !b est vrai) */
```

### 3. L'évaluation court-circuit

Les opérateurs `&&` et `||` évaluent leurs opérandes **de gauche à droite**, et **s'arrêtent dès qu'ils peuvent conclure** :

- `&&` s'arrête au premier opérande **faux** (le résultat sera faux quoi qu'il arrive).
- `||` s'arrête au premier opérande **vrai** (le résultat sera vrai quoi qu'il arrive).

```c
if (n != 0 && 10 / n > 2)
{
    /* ... */
}
```

Si `n` vaut 0, le premier opérande est faux, et le second (`10 / n`) **n'est jamais évalué**. C'est ce qui évite la division par zéro. **Mémorise cette technique**, elle est fondamentale.

---

## D. Priorité et associativité

Quand plusieurs opérateurs apparaissent dans une expression, le C suit des règles de **priorité** (qui est évalué en premier) et d'**associativité** (de gauche à droite, ou de droite à gauche).

### 1. Tableau de priorité (les principales)

De la **plus haute** (évaluée en premier) à la **plus basse** :

| Rang | Opérateurs | Associativité |
|---|---|---|
| 1 (haute) | `!` (non logique), `++` `--` (préfixe), `-` unaire | de droite à gauche |
| 2 | `*` `/` `%` | de gauche à droite |
| 3 | `+` `-` (binaires) | de gauche à droite |
| 4 | `<` `<=` `>` `>=` | de gauche à droite |
| 5 | `==` `!=` | de gauche à droite |
| 6 | `&&` | de gauche à droite |
| 7 | `\|\|` | de gauche à droite |
| 8 (basse) | `=` `+=` `-=` `*=` `/=` `%=` | de droite à gauche |

### 2. Exemples concrets

```c
int	x;

x = 2 + 3 * 4;          /* x = 14 (priorité * sur +) */
x = (2 + 3) * 4;        /* x = 20 (parenthèses forcent l'ordre) */
x = 1 + 2 == 3;         /* x = 1  (1+2 d'abord, puis == 3) */
x = 1 && 0 || 1;        /* x = 1  (1 && 0 = 0, puis 0 || 1 = 1) */
```

### 3. Ma règle d'or : **utilise des parenthèses**

Personne ne se souvient parfaitement de toute la table de priorité. Et même si c'est ton cas, les autres qui liront ton code ne s'en souviennent pas non plus.

❌ **Ambigu pour le lecteur** :
```c
x = a + b * c > d && e;
```

✅ **Clair** :
```c
x = ((a + (b * c)) > d) && e;
```

Tu paies quelques caractères de plus, tu gagnes en clarté et en sécurité. Ne te prive jamais de parenthèses quand l'expression a plus de deux opérateurs.

!!! tip "Astuce piscine"
    Les évaluateurs 42 sont sensibles à la **lisibilité**. Un code avec des parenthèses explicites passe mieux qu'un code « malin » qui s'appuie sur la priorité.

---

## Bilan

À la fin de ce support, tu sais :

- Utiliser les cinq opérateurs arithmétiques : `+ - * / %`.
- Comprendre que `/` entre deux `int` est une **division entière** (le reste est jeté).
- Utiliser `%` pour obtenir le reste, tester la parité, ou « cycler ».
- Citer les six opérateurs de comparaison : `== != < > <= >=`.
- Savoir qu'une comparaison renvoie `0` ou `1`.
- Ne **plus jamais** confondre `=` (affectation) et `==` (comparaison).
- Utiliser les trois opérateurs logiques : `&& || !`.
- Savoir qu'en C, `0` est faux et **tout le reste** est vrai.
- Utiliser l'**évaluation court-circuit** pour éviter des erreurs (comme la division par zéro).
- Ajouter des parenthèses pour clarifier la **priorité** dans une expression.

## Pour aller plus loin

- Tableau complet de priorité des opérateurs C : [cppreference.com — Operator precedence](https://en.cppreference.com/w/c/language/operator_precedence).
- Article sur les pièges du modulo avec des nombres négatifs (le standard C ne fixait pas le comportement avant C99).

---

➡️ **Exercices du support :** [voir la page exercices](./exercices.md)
➡️ **Support suivant :** [Support 05 — Conditions](../support-05/cours.md)
