/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkemmoun <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 02:22:59 by hkemmoun          #+#    #+#             */
/*   Updated: 2025/03/10 02:23:00 by hkemmoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

// void	check_receive(int sig)
// {
// 	(void)sig;
// 	// printf("message wsal alm3alam\n");
// }

void	print_bits(char c, int server_pid)
{
	int	i;
	int	shifted;
	int	error;
	int	bit;

	i = 7;
	error = 0;
	while (i >= 0)
	{
		shifted = 1 << i;
		bit = c & shifted;
		if (bit == 0)
			error = kill(server_pid, SIGUSR1);
		else
			error = kill(server_pid, SIGUSR2);
		if (error == -1)
			print_error();
		usleep(20000);
		i--;
	}
}

void	send_char_by_char(char *message, pid_t server_pid)
{
	while (*message)
	{
		print_bits(*message, server_pid);
		message++;
	}
	print_bits('\0', server_pid);
}

void	check_receive(int sig)
{
	if (sig == SIGUSR1)
		printf("message wsal alm3alam\n");
}

int	main(int ac, char **av)
{
	int		server_pid;
	char	*message;

	if (ac == 3)
	{
		signal(SIGUSR2, check_receive);
		signal(SIGUSR1, check_receive);
		server_pid = ft_atoi(av[1]);
		message = av[2];
		if (server_pid <= 0 || server_pid > 2147483647)
		{
			ft_putstr("Invalid PID\n");
			exit (1);
		}
		send_char_by_char(message, server_pid);
	}
	else
		printf("ERROR: Usage --> %s <PID> <message>\n", av[0]);
}
