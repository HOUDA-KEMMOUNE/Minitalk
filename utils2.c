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
