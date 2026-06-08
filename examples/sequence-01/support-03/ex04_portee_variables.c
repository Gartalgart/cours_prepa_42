/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex04_portee_variables.c                            :+:      :+:    :+:   */
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

void	ft_modifier(int x)
{
	x = x + 5;
	ft_putchar('0' + x);
}

int	main(void)
{
	int	x;

	x = 1;
	ft_modifier(x);
	ft_putchar('0' + x);
	ft_putchar('\n');
	return (0);
}
