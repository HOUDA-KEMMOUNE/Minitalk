/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkemmoun <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 14:38:57 by hkemmoun          #+#    #+#             */
/*   Updated: 2025/03/06 14:38:59 by hkemmoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

/*------------print_error--------------*/
void	print_error(void)
{
	write(1, "Error\n", 6);
	exit (1);
}

/*------------print_error--------------*/
void	wrong_pid_mess(void)
{
	ft_putstr("Wrong PID :/\n");
	exit(1);
}

/*------------ft_putstr--------------*/

void	ft_putstr(char *s)
{
	size_t	i;

	if (!s)
		return ;
	i = 0;
	while (s[i])
	{
		write(1, &s[i], 1);
		i++;
	}
}
/*------------check_if_nbr--------------*/

static void	neg_and_pos(char *str)
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
