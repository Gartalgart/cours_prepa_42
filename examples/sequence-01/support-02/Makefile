# ============================================================================ #
#                                                                              #
#   Support 02 - Caractères et affichage                                       #
#   Compile les exemples avec les flags 42 standards.                          #
#                                                                              #
#   Usage :                                                                    #
#     make           Compile tous les exemples                                 #
#     make exN       Compile uniquement l'exemple N (ex : make ex03)           #
#     make clean     Supprime les binaires produits                            #
#                                                                              #
# ============================================================================ #

CC      = cc
CFLAGS  = -Wall -Wextra -Werror

SRCS    = ex01_un_caractere.c \
          ex02_codes_ascii.c \
          ex03_ft_putchar.c \
          ex04_echappement.c

BINS    = ex01 ex02 ex03 ex04

all: $(BINS)

ex01: ex01_un_caractere.c
	$(CC) $(CFLAGS) $< -o $@

ex02: ex02_codes_ascii.c
	$(CC) $(CFLAGS) $< -o $@

ex03: ex03_ft_putchar.c
	$(CC) $(CFLAGS) $< -o $@

ex04: ex04_echappement.c
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm -f $(BINS)

re: clean all

.PHONY: all clean re
