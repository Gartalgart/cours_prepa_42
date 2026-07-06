/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex01_tableau_int.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdenimal <rdenimal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/08 19:00:00 by rdenimal          #+#    #+#             */
/*   Updated: 2026/06/08 19:00:00 by rdenimal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	main(void)
{
	int	tab[5];
	int	i;
	int	somme;

	tab[0] = 10;
	tab[1] = 20;
	tab[2] = 30;
	tab[3] = 40;
	tab[4] = 50;
	i = 0;
	somme = 0;
	while (i < 5)
	{
		somme = somme + tab[i];
		i++;
	}
	ft_putchar('0' + somme / 100);
	ft_putchar('0' + (somme / 10) % 10);
	ft_putchar('0' + somme % 10);
	ft_putchar('\n');
	return (0);
}
