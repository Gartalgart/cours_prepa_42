/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex04_break_continue.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdenimal <rdenimal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/08 17:00:00 by rdenimal          #+#    #+#             */
/*   Updated: 2026/06/08 17:00:00 by rdenimal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	main(void)
{
	int	i;

	i = 0;
	while (i < 10)
	{
		if (i == 7)
		{
			break ;
		}
		if (i == 3)
		{
			i++;
			continue ;
		}
		ft_putchar('0' + i);
		i++;
	}
	ft_putchar('\n');
	return (0);
}
