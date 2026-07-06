/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex01_premier_pointeur.c                            :+:      :+:    :+:   */
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
	int	x;
	int	*p;

	x = 7;
	p = &x;
	ft_putchar('0' + *p);
	*p = 9;
	ft_putchar('0' + x);
	ft_putchar('\n');
	return (0);
}
