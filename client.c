/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muguveli <muguveli@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 18:37:05 by muguveli          #+#    #+#             */
/*   Updated: 2024/02/11 15:18:05 by muguveli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	ft_atoi(const char *str)
{
	int	i;
	int	sign;
	int	tmp;

	i = 0;
	sign = 1;
	tmp = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if ((str[i] == 43 || str[i] == 45))
		if (str[i++] == 45)
			sign *= -1;
	while (str[i])
	{
		if (str[i] >= 48 && str[i] <= 57)
			tmp = (tmp * 10) + (str[i++] - 48);
		else
			return (-1);
	}
	if (i > 10)
		return (-1);
	return (tmp * sign);
}

int	main(int ac, char **av)
{
	int	pid;
	int	i;
	int	j;

	i = 0;
	if (ac < 3)
		return (0);
	pid = ft_atoi(av[1]);
	if (pid < 0)
		return (0);
	while (av[2][i])
	{
		j = 6;
		while (j >= 0)
		{
			if ((av[2][i] >> j) & 1)
				kill(pid, SIGUSR2);
			else
				kill(pid, SIGUSR1);
			j--;
			usleep(100);
		}
		i++;
	}
	return (0);
}
