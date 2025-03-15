/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkemmoun <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 02:23:13 by hkemmoun          #+#    #+#             */
/*   Updated: 2025/03/10 02:23:15 by hkemmoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	send_character(int *len, char *letter)
{
	if (*len == 8)
	{
		if (*letter == '\0')
			ft_putstr("\n");
		write(1, letter, 1);
		*len = 0;
		*letter = 0;
	}
	else
		return ;
}

void	handler(int sig_nbr, siginfo_t *info, void *context)
{
	static char	letter;
	static int	bit;
	static int	len;
	static int	pid;
	int			error;

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
	send_character(&len, &letter);
	error = kill(pid, SIGUSR1);
	if (error == -1)
		print_error();
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
