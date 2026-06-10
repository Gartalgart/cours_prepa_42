/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex01_quatre_operations.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdenimal <rdenimal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/08 15:00:00 by rdenimal          #+#    #+#             */
/*   Updated: 2026/06/08 15:00:00 by rdenimal         ###   ########.fr       */
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

	a = 3;
	b = 2;
	ft_putchar('0' + a + b);
	ft_putchar(' ');
	ft_putchar('0' + a - b);
	ft_putchar(' ');
	ft_putchar('0' + a * b);
	ft_putchar(' ');
	ft_putchar('0' + a / b);
	ft_putchar('\n');
	return (0);
}
