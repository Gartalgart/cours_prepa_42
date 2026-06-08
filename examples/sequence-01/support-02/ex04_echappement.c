/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex04_echappement.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdenimal <rdenimal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/08 11:00:00 by rdenimal          #+#    #+#             */
/*   Updated: 2026/06/08 11:00:00 by rdenimal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	main(void)
{
	ft_putchar('A');
	ft_putchar('\t');
	ft_putchar('B');
	ft_putchar('\t');
	ft_putchar('C');
	ft_putchar('\n');
	ft_putchar('\'');
	ft_putchar('\\');
	ft_putchar('\"');
	ft_putchar('\n');
	return (0);
}
