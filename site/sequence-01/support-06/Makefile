# ============================================================================ #
#                                                                              #
#   Support 06 - Boucles                                                       #
#   Compile les exemples avec les flags 42 standards.                          #
#                                                                              #
# ============================================================================ #

CC      = cc
CFLAGS  = -Wall -Wextra -Werror

SRCS    = ex01_while_basique.c \
          ex02_alphabet.c \
          ex03_boucles_imbriquees.c \
          ex04_break_continue.c

BINS    = ex01 ex02 ex03 ex04

all: $(BINS)

ex01: ex01_while_basique.c
	$(CC) $(CFLAGS) $< -o $@

ex02: ex02_alphabet.c
	$(CC) $(CFLAGS) $< -o $@

ex03: ex03_boucles_imbriquees.c
	$(CC) $(CFLAGS) $< -o $@

ex04: ex04_break_continue.c
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm -f $(BINS)

re: clean all

.PHONY: all clean re
