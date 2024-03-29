/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muguveli <muguveli@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 14:44:32 by muguveli          #+#    #+#             */
/*   Updated: 2024/02/14 19:17:48 by muguveli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	handle(int signum)
{
	static char	c;
	static int	i = 64;

	if (signum == SIGUSR2)
		c += i;
	i >>= 1;
	if (i == 0)
	{
		write(1, &c, 1);
		c = 0;
		i = 64;
	}
}

int	main(void)
{
	ft_printf("PID: %d\n", getpid());
	signal(SIGUSR2, handle);
	signal(SIGUSR1, handle);
	while (1)
		usleep(100);
}
