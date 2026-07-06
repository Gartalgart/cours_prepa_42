/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex02_ft_swap.c                                     :+:      :+:    :+:   */
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

void	ft_swap(int *a, int *b)
{
	int	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

int	main(void)
{
	int	x;
	int	y;

	x = 3;
	y = 7;
	ft_swap(&x, &y);
	ft_putchar('0' + x);
	ft_putchar('0' + y);
	ft_putchar('\n');
	return (0);
}
