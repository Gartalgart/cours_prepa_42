/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex03_pointeur_tableau.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdenimal <rdenimal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/08 20:00:00 by rdenimal          #+#    #+#             */
/*   Updated: 2026/06/08 20:00:00 by rdenimal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	main(void)
{
	int	tab[3];
	int	*p;

	tab[0] = 1;
	tab[1] = 2;
	tab[2] = 3;
	p = tab;
	ft_putchar('0' + *p);
	ft_putchar('0' + *(p + 1));
	ft_putchar('0' + *(p + 2));
	ft_putchar('\n');
	return (0);
}
