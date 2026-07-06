/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex02_plusieurs_parametres.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdenimal <rdenimal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/08 18:00:00 by rdenimal          #+#    #+#             */
/*   Updated: 2026/06/08 18:00:00 by rdenimal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	ft_max(int a, int b)
{
	if (a > b)
	{
		return (a);
	}
	return (b);
}

int	ft_max3(int a, int b, int c)
{
	int	plus_grand;

	plus_grand = ft_max(a, b);
	plus_grand = ft_max(plus_grand, c);
	return (plus_grand);
}

int	main(void)
{
	int	resultat;

	resultat = ft_max3(3, 7, 5);
	ft_putchar('0' + resultat);
	ft_putchar('\n');
	return (0);
}
