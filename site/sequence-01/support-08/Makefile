# ============================================================================ #
#                                                                              #
#   Support 08 - Tableaux et chaînes                                           #
#   Compile les exemples avec les flags 42 standards.                          #
#                                                                              #
# ============================================================================ #

CC      = cc
CFLAGS  = -Wall -Wextra -Werror

SRCS    = ex01_tableau_int.c \
          ex02_chaine_parcours.c \
          ex03_ft_strlen.c \
          ex04_ft_putstr.c

BINS    = ex01 ex02 ex03 ex04

all: $(BINS)

ex01: ex01_tableau_int.c
	$(CC) $(CFLAGS) $< -o $@

ex02: ex02_chaine_parcours.c
	$(CC) $(CFLAGS) $< -o $@

ex03: ex03_ft_strlen.c
	$(CC) $(CFLAGS) $< -o $@

ex04: ex04_ft_putstr.c
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm -f $(BINS)

re: clean all

.PHONY: all clean re
