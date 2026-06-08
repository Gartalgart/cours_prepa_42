/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex02_arithmetique_variables.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdenimal <rdenimal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/08 14:00:00 by rdenimal          #+#    #+#             */
/*   Updated: 2026/06/08 14:00:00 by rdenimal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	main(void)
{
	int	a;
	int	b;
	int	somme;

	a = 3;
	b = 5;
	somme = a + b;
	ft_putchar('0' + somme);
	ft_putchar('\n');
	return (0);
}
