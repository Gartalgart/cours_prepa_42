# ============================================================================ #
#                                                                              #
#   Support 05 - Conditions                                                    #
#   Compile les exemples avec les flags 42 standards.                          #
#                                                                              #
# ============================================================================ #

CC      = cc
CFLAGS  = -Wall -Wextra -Werror

SRCS    = ex01_if_simple.c \
          ex02_if_else.c \
          ex03_else_if.c \
          ex04_conditions_composees.c

BINS    = ex01 ex02 ex03 ex04

all: $(BINS)

ex01: ex01_if_simple.c
	$(CC) $(CFLAGS) $< -o $@

ex02: ex02_if_else.c
	$(CC) $(CFLAGS) $< -o $@

ex03: ex03_else_if.c
	$(CC) $(CFLAGS) $< -o $@

ex04: ex04_conditions_composees.c
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm -f $(BINS)

re: clean all

.PHONY: all clean re
