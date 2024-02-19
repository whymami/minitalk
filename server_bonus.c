/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muguveli <muguveli@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 15:20:45 by muguveli          #+#    #+#             */
/*   Updated: 2024/02/17 14:39:50 by muguveli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

static int	get_signal_client(char c)
{
	static char	pid[11];
	static int	pid_client = 0;
	static int	i = 0;

	pid[i++] = c;
	if (c == 1)
	{
		pid[i] = 0;
		pid_client = ft_atoi(pid);
		i = 0;
	}
	return (pid_client);
}

static void	read_byte(int *flag, char *c, int *bit)
{
	static int	client_pid;

	if (*flag % 2 != 0)
	{
		client_pid = get_signal_client(*c);
		if (*c == 1)
		{
			(*flag)++;
			kill(client_pid, SIGUSR1);
		}
		*c = 0;
		*bit = 128;
	}
	else
	{
		write(1, c, 1);
		if (*c == 1)
			(*flag)++;
		*c = 0;
		*bit = 128;
	}
}

static void	handle(int signo)
{
	static int	bit = 128;
	static char	c;
	static int	flag;

	if (signo == SIGUSR2)
		c += bit;
	bit >>= 1;
	if (bit == 0)
		read_byte(&flag, &c, &bit);
}

int	main(void)
{
	ft_printf("PID: %d\n", getpid());
	signal(SIGUSR1, &handle);
	signal(SIGUSR2, &handle);
	while (1)
		usleep(75);
	return (0);
}
