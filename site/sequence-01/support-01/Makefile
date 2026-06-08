# ============================================================================ #
#                                                                              #
#   Support 01 - Premier programme                                             #
#   Compile les exemples avec les flags 42 standards.                          #
#                                                                              #
#   Usage :                                                                    #
#     make           Compile tous les exemples                                 #
#     make ex01      Compile uniquement le premier exemple                     #
#     make clean     Supprime les binaires produits                            #
#                                                                              #
# ============================================================================ #

CC      = cc
CFLAGS  = -Wall -Wextra -Werror

SRCS    = ex01_premier_programme.c ex02_plusieurs_lignes.c
BINS    = ex01 ex02

all: $(BINS)

ex01: ex01_premier_programme.c
	$(CC) $(CFLAGS) $< -o $@

ex02: ex02_plusieurs_lignes.c
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm -f $(BINS)

re: clean all

.PHONY: all clean re
