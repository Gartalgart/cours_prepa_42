/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex04_conditions_composees.c                        :+:      :+:    :+:   */
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
	char	c;

	c = 'k';
	if (c >= 'a' && c <= 'z')
	{
		ft_putchar('m');
	}
	else if (c >= 'A' && c <= 'Z')
	{
		ft_putchar('M');
	}
	else
	{
		ft_putchar('?');
	}
	ft_putchar('\n');
	return (0);
}
