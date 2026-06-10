# ============================================================================ #
#                                                                              #
#   Support 04 - Opérateurs                                                    #
#   Compile les exemples avec les flags 42 standards.                          #
#                                                                              #
# ============================================================================ #

CC      = cc
CFLAGS  = -Wall -Wextra -Werror

SRCS    = ex01_quatre_operations.c \
          ex02_division_modulo.c \
          ex03_comparaison.c \
          ex04_logiques.c

BINS    = ex01 ex02 ex03 ex04

all: $(BINS)

ex01: ex01_quatre_operations.c
	$(CC) $(CFLAGS) $< -o $@

ex02: ex02_division_modulo.c
	$(CC) $(CFLAGS) $< -o $@

ex03: ex03_comparaison.c
	$(CC) $(CFLAGS) $< -o $@

ex04: ex04_logiques.c
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm -f $(BINS)

re: clean all

.PHONY: all clean re
