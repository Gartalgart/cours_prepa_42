# ============================================================================ #
#                                                                              #
#   Support 07 - Fonctions                                                     #
#   Compile les exemples avec les flags 42 standards.                          #
#                                                                              #
# ============================================================================ #

CC      = cc
CFLAGS  = -Wall -Wextra -Werror

SRCS    = ex01_fonction_retour.c \
          ex02_plusieurs_parametres.c \
          ex03_ft_putnbr.c \
          ex04_factorielle.c

BINS    = ex01 ex02 ex03 ex04

all: $(BINS)

ex01: ex01_fonction_retour.c
	$(CC) $(CFLAGS) $< -o $@

ex02: ex02_plusieurs_parametres.c
	$(CC) $(CFLAGS) $< -o $@

ex03: ex03_ft_putnbr.c
	$(CC) $(CFLAGS) $< -o $@

ex04: ex04_factorielle.c
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm -f $(BINS)

re: clean all

.PHONY: all clean re
