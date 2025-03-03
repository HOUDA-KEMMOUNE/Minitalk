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
# define _POSIX_C_SOURCE 200809L

# include <signal.h>
# include <unistd.h>
# include <stdio.h>
# include <limits.h>
# include <stdlib.h>

int		ft_atoi(const char *str);
// unsigned int	ft_atoi(const char *str);
void	print_error(void);

#endif
