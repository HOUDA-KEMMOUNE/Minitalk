/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkemmoun <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 00:22:53 by hkemmoun          #+#    #+#             */
/*   Updated: 2025/03/03 00:22:55 by hkemmoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <signal.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/types.h>
# include <sys/time.h>
# include <unistd.h>

int		ft_atoi(const char *str);
void	neg_and_pos(char *str);
void	print_error(void);
void	ft_putstr(char *s);
int		check_if_nbr(char *str);
void	ft_putnbr(int n);
void	wrong_pid_mess(void);

#endif
