/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex03_modification_variable.c                       :+:      :+:    :+:   */
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
	char	c;

	c = 'A';
	ft_putchar(c);
	c = c + 1;
	ft_putchar(c);
	c = c + 1;
	ft_putchar(c);
	ft_putchar('\n');
	return (0);
}
