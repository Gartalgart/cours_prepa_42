# Compilation

> Comment transformer un fichier `.c` en programme exécutable.

## La commande de base

```bash
cc -Wall -Wextra -Werror fichier.c -o mon_programme
```

| Option | Signification |
|---|---|
| `-Wall` | Active tous les warnings courants |
| `-Wextra` | Active des warnings supplémentaires |
| `-Werror` | Traite tous les warnings comme des erreurs |
| `-o nom` | Spécifie le nom du fichier de sortie |

!!! warning "Attention"
    À l'École 42, un programme qui ne compile pas avec `-Wall -Wextra -Werror` est
    systématiquement noté 0. Compile toujours avec ces flags dès le début.

## Exécuter le programme

```bash
./mon_programme
```

## Voir ce que fait le compilateur (étapes intermédiaires)

```bash
cc -E fichier.c   # Préprocesseur uniquement (expand les #include et #define)
cc -S fichier.c   # Génère le code assembleur (fichier.s)
cc -c fichier.c   # Compilation uniquement, génère un objet (fichier.o)
```

## Messages d'erreur courants

| Message | Cause probable |
|---|---|
| `implicit declaration of function` | Prototype manquant ou header non inclus |
| `undeclared identifier` | Variable non déclarée |
| `unused variable` | Variable déclarée mais jamais utilisée |
| `control reaches end of non-void function` | `return` manquant |
