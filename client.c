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
	static int	bit;

	i = 7;
	while (i >= 0)
	{
		shift = 1 << i;
		bit = shift & c;
		if (bit == 0)
			kill(server_pid, SIGUSR1); //SIGUSR1 ghatakhod 0
		else
			kill(server_pid, SIGUSR2); //SIGUSR2 ghatakhod 1
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
}

int main(int ac, char **av)
{
	pid_t	server_pid;
	char	*message;

	if (ac == 3)
	{
		// if (ft_atoi(av[1]) > 4294967295) //the 4294967295 is the max of unsigned int
		// 	print_error();
		server_pid = ft_atoi(av[1]);
		message = av[2];
		printf("The PID of the server (%u) and the message (%s) has been catched succesfully !\n", server_pid, message);

	}
	else
		printf("ERROR: Usage --> %s <PID> <message>\n", av[0]);
}
