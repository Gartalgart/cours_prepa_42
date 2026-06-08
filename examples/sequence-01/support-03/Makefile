# ============================================================================ #
#                                                                              #
#   Support 03 - Variables et types                                            #
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

SRCS    = ex01_premiere_variable.c \
          ex02_arithmetique_variables.c \
          ex03_modification_variable.c \
          ex04_portee_variables.c

BINS    = ex01 ex02 ex03 ex04

all: $(BINS)

ex01: ex01_premiere_variable.c
	$(CC) $(CFLAGS) $< -o $@

ex02: ex02_arithmetique_variables.c
	$(CC) $(CFLAGS) $< -o $@

ex03: ex03_modification_variable.c
	$(CC) $(CFLAGS) $< -o $@

ex04: ex04_portee_variables.c
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm -f $(BINS)

re: clean all

.PHONY: all clean re
