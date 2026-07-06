/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex02_chaine_parcours.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdenimal <rdenimal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/08 19:00:00 by rdenimal          #+#    #+#             */
/*   Updated: 2026/06/08 19:00:00 by rdenimal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_print_inverse(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	i--;
	while (i >= 0)
	{
		ft_putchar(str[i]);
		i--;
	}
}

int	main(void)
{
	ft_print_inverse("Bonjour");
	ft_putchar('\n');
	return (0);
}
