/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdenimal <rdenimal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/08 21:00:00 by rdenimal          #+#    #+#             */
/*   Updated: 2026/06/08 21:00:00 by rdenimal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int n)
{
	if (n == -2147483648)
	{
		write(1, "-2147483648", 11);
		return ;
	}
	if (n < 0)
	{
		ft_putchar('-');
		n = -n;
	}
	if (n >= 10)
	{
		ft_putnbr(n / 10);
	}
	ft_putchar('0' + n % 10);
}

int	ft_atoi(char *str)
{
	int	i;
	int	signe;
	int	resultat;

	i = 0;
	signe = 1;
	resultat = 0;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n')
	{
		i++;
	}
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
		{
			signe = -1;
		}
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		resultat = resultat * 10 + (str[i] - '0');
		i++;
	}
	return (resultat * signe);
}

int	main(void)
{
	ft_putnbr(ft_atoi("42"));
	ft_putchar('\n');
	ft_putnbr(ft_atoi("-1234"));
	ft_putchar('\n');
	ft_putnbr(ft_atoi("   +99abc"));
	ft_putchar('\n');
	ft_putnbr(ft_atoi("0"));
	ft_putchar('\n');
	ft_putnbr(ft_atoi("bonjour"));
	ft_putchar('\n');
	return (0);
}
