/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkemmoun <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/02 23:25:25 by hkemmoun          #+#    #+#             */
/*   Updated: 2025/03/09 03:10:01 by hkemmoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	send_character(int *len, char *letter)
{
	if (*letter == '\0')
	{
		write(1, "\0\n", 2);
		*len = 0;
		*letter = 0;
	}
	write(1, letter, 1);
	*len = 0;
	*letter = 0;
}

void	handler(int sig_nbr, siginfo_t *info, void *context)
{
	static char	letter;
	static int	bit;
	static int	len;
	static int	pid;

	(void)context;
	if (!pid)
		pid = info->si_pid;
	if (pid != info->si_pid)
	{
		pid = info->si_pid;
		len = 0;
		letter = 0;
	}
	if (sig_nbr == SIGUSR1)
		bit = 0;
	else
		bit = 1;
	letter = (letter << 1) | (bit & 1);
	len++;
	if (len == 8)
		send_character(&len, &letter);
}

int	main(void)
{
	int					id;
	struct sigaction	move;

	id = getpid();
	ft_putnbr(id);
	write(1, "\n", 1);
	move.sa_sigaction = handler;
	move.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &move, NULL);
	sigaction(SIGUSR2, &move, NULL);
	while (1)
		pause();
	return (0);
}
