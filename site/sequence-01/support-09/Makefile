# ============================================================================ #
#                                                                              #
#   Support 09 - Pointeurs (initiation)                                        #
#   Compile les exemples avec les flags 42 standards.                          #
#                                                                              #
# ============================================================================ #

CC      = cc
CFLAGS  = -Wall -Wextra -Werror

SRCS    = ex01_premier_pointeur.c \
          ex02_ft_swap.c \
          ex03_pointeur_tableau.c \
          ex04_pointeur_chaine.c

BINS    = ex01 ex02 ex03 ex04

all: $(BINS)

ex01: ex01_premier_pointeur.c
	$(CC) $(CFLAGS) $< -o $@

ex02: ex02_ft_swap.c
	$(CC) $(CFLAGS) $< -o $@

ex03: ex03_pointeur_tableau.c
	$(CC) $(CFLAGS) $< -o $@

ex04: ex04_pointeur_chaine.c
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm -f $(BINS)

re: clean all

.PHONY: all clean re
