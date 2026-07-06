# ============================================================================ #
#                                                                              #
#   Bilan de la Séquence 1 - Mini-projet de synthèse                           #
#   Compile les programmes du bilan avec les flags 42 standards.               #
#                                                                              #
# ============================================================================ #

CC      = cc
CFLAGS  = -Wall -Wextra -Werror

BINS    = ft_atoi tri_tableau

all: $(BINS)

ft_atoi: ft_atoi.c
	$(CC) $(CFLAGS) $< -o $@

tri_tableau: tri_tableau.c
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm -f $(BINS)

re: clean all

.PHONY: all clean re
