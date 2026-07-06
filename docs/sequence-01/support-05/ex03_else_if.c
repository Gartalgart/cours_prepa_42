/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex03_else_if.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdenimal <rdenimal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/08 16:00:00 by rdenimal          #+#    #+#             */
/*   Updated: 2026/06/08 16:00:00 by rdenimal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	main(void)
{
	int	n;

	n = -3;
	if (n > 0)
	{
		ft_putchar('+');
	}
	else if (n < 0)
	{
		ft_putchar('-');
	}
	else
	{
		ft_putchar('0');
	}
	ft_putchar('\n');
	return (0);
}
