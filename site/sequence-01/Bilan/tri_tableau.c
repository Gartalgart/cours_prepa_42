/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tri_tableau.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdenimal <rdenimal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/08 21:00:00 by rdenimal          #+#    #+#             */
/*   Updated: 2026/06/08 21:00:00 by rdenimal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_swap(int *a, int *b)
{
	int	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

void	ft_tri_bulles(int *tab, int taille)
{
	int	i;
	int	j;

	i = 0;
	while (i < taille - 1)
	{
		j = 0;
		while (j < taille - 1 - i)
		{
			if (tab[j] > tab[j + 1])
			{
				ft_swap(&tab[j], &tab[j + 1]);
			}
			j++;
		}
		i++;
	}
}

void	ft_print_tab(int *tab, int taille)
{
	int	i;

	i = 0;
	while (i < taille)
	{
		ft_putchar('0' + tab[i]);
		i++;
	}
	ft_putchar('\n');
}

int	main(void)
{
	int	tab[7];

	tab[0] = 5;
	tab[1] = 2;
	tab[2] = 8;
	tab[3] = 1;
	tab[4] = 9;
	tab[5] = 3;
	tab[6] = 4;
	ft_print_tab(tab, 7);
	ft_tri_bulles(tab, 7);
	ft_print_tab(tab, 7);
	return (0);
}
