/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkemmoun <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/02 23:25:39 by hkemmoun          #+#    #+#             */
/*   Updated: 2025/03/09 03:10:05 by hkemmoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	print_bits(char c, pid_t server_pid)
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
		usleep(500);
		i--;
	}
}

void	send_char_by_char(char *message, pid_t server_pid)
{
	int	i;

	i = 0;
	while (message[i])
	{
		print_bits(message[i], server_pid);
		i++;
	}
	print_bits('\0', server_pid);
}

int	main(int ac, char **av)
{
	pid_t	server_pid;
	char	*message;

	if (ac == 3)
	{
		server_pid = ft_atoi(av[1]);
		if (server_pid <= 0 || server_pid > 2147483647)
		{
			ft_putstr("Invalid PID\n");
			exit (1);
		}
		message = av[2];
		send_char_by_char(message, server_pid);
	}
	else
		printf("ERROR: Usage --> %s <PID> <message>\n", av[0]);
}
