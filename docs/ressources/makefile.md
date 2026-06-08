# Makefiles

> Un Makefile automatise la compilation de ton projet. C'est indispensable à partir du moment où tu as plusieurs fichiers `.c`.

!!! info "Pour aller plus loin"
    Cette page sera complétée lors des séquences avancées. Pour la Séquence 1, la compilation
    fichier par fichier est suffisante.

## Structure minimale

```makefile
NAME    = mon_programme
CC      = cc
CFLAGS  = -Wall -Wextra -Werror
SRCS    = main.c
OBJS    = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
```

## Les règles obligatoires à la piscine 42

| Règle | Action |
|---|---|
| `all` | Compile le projet |
| `clean` | Supprime les fichiers objets (`.o`) |
| `fclean` | `clean` + supprime le binaire |
| `re` | `fclean` + `all` (recompile tout) |
| `.PHONY` | Déclare les cibles qui ne sont pas des fichiers |
