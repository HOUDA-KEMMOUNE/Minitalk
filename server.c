/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkemmoun <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/02 23:25:25 by hkemmoun          #+#    #+#             */
/*   Updated: 2025/03/02 23:25:28 by hkemmoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	handler(int	sig_nbr)
{
	static char	letter;
	static int	bit;

	if (sig_nbr == SIGUSR1)
		letter = letter << 1;
	else
		letter = (letter << 1) | 1;
	bit++;
	if (bit == 8)
	{
		// if (letter == '\0')
		// 	exit(0);
		write(1, &letter, 1);
		bit = 0;
		letter = 0;
	}
}

int main()
{
	// printf("PID ---> %d\n", getpid());
	int	id;

	id = getpid();
	ft_putnbr(id);
	write(1, "\n", 1);
	signal(SIGUSR1, handler);
	signal(SIGUSR2, handler);
	while (1)
		pause();
	return (0);
}
