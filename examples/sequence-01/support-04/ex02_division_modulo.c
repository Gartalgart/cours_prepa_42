/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex02_division_modulo.c                             :+:      :+:    :+:   */
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
	int	dividende;
	int	diviseur;
	int	quotient;
	int	reste;

	dividende = 17;
	diviseur = 5;
	quotient = dividende / diviseur;
	reste = dividende % diviseur;
	ft_putchar('0' + quotient);
	ft_putchar(' ');
	ft_putchar('0' + reste);
	ft_putchar('\n');
	return (0);
}
