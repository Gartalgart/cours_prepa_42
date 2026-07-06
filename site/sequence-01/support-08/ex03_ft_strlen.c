/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex03_ft_strlen.c                                   :+:      :+:    :+:   */
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

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

int	main(void)
{
	int	len;

	len = ft_strlen("Bonjour");
	ft_putchar('0' + len);
	ft_putchar('\n');
	len = ft_strlen("");
	ft_putchar('0' + len);
	ft_putchar('\n');
	return (0);
}
