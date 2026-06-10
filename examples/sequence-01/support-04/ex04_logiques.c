/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex04_logiques.c                                    :+:      :+:    :+:   */
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
	int	result;

	a = 1;
	b = 0;
	result = a && b;
	ft_putchar('0' + result);
	result = a || b;
	ft_putchar('0' + result);
	result = !a;
	ft_putchar('0' + result);
	result = !b;
	ft_putchar('0' + result);
	ft_putchar('\n');
	return (0);
}
