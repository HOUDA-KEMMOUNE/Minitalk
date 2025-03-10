/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkemmoun <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 02:15:42 by hkemmoun          #+#    #+#             */
/*   Updated: 2025/03/10 02:15:44 by hkemmoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	check_if_nbr(char *str)
{
	neg_and_pos(str);
	return (0);
}

void	neg_and_pos(char *str)
{
	int	j;

	j = 0;
	if ((str[0] == '-' || str[0] == '+')
		&& (str[1] == ' ' || str[1] == '\0'))
		print_error();
	if (str[0] == '-' || str[0] == '+')
		j++;
	while (str[j])
	{
		if ((str[j] == '-' || str[j] == '+') && (str[j - 1] == ' '))
			j++;
		if ((str[j] >= '0' && str[j] <= '9') || str[j] == ' ')
			j++;
		else
			print_error();
		j++;
	}
}

void	ft_putnbr(int n)
{
	char	c;

	if (n <= 0)
		wrong_pid_mess();
	else if (n >= 10)
	{
		ft_putnbr(n / 10);
		c = (n % 10) + '0';
		write(1, &c, 1);
	}
	else
	{
		c = n + '0';
		write(1, &c, 1);
	}
}
