/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkemmoun <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/02 23:25:39 by hkemmoun          #+#    #+#             */
/*   Updated: 2025/03/02 23:25:41 by hkemmoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	print_bits(char c, pid_t server_pid)
{
	int	i;
	int	shift;
	int	error;
	static int	bit;

	i = 7;
	error = 0;
	while (i >= 0)
	{
		shift = 1 << i;
		bit = shift & c;
		if (bit == 0)
			error = kill(server_pid, SIGUSR1); //SIGUSR1 ghatakhod 0
		else
			error = kill(server_pid, SIGUSR2); //SIGUSR2 ghatakhod 1
		sleep(1);
		i--;
	}
	if (error == -1)
		print_error();
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
}

int main(int ac, char **av)
{
	pid_t	server_pid;
	char	*message;

	if (ac == 3)
	{
		// check_if_nbr(av[1]);
		server_pid = ft_atoi(av[1]);
		if (server_pid <= 0 || server_pid > 2147483647)
		{
			ft_putstr("Invalid PID\n");
			exit (1);
		}
		message = av[2];
		printf("The PID of the server (%u) and the message (%s) has been catched succesfully !\n", server_pid, message);
		send_char_by_char(message, server_pid);
	}
	else
		printf("ERROR: Usage --> %s <PID> <message>\n", av[0]);
}
