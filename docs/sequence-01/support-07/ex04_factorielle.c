/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex04_factorielle.c                                 :+:      :+:    :+:   */
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

void	ft_putnbr(int n)
{
	if (n < 0)
	{
		ft_putchar('-');
		n = -n;
	}
	if (n >= 10)
	{
		ft_putnbr(n / 10);
	}
	ft_putchar('0' + n % 10);
}

int	ft_factorielle(int n)
{
	if (n <= 1)
	{
		return (1);
	}
	return (n * ft_factorielle(n - 1));
}

int	main(void)
{
	ft_putnbr(ft_factorielle(5));
	ft_putchar('\n');
	return (0);
}
