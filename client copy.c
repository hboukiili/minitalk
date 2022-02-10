/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hboukili <hboukili@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 03:38:19 by hboukili          #+#    #+#             */
/*   Updated: 2022/02/10 17:06:37 by hboukili         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <signal.h>

int	ft_atoi(char *str)
{
	int	i;
	int	res;

	i = 0;
	res = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		res = res * 10 + (str[i] - '0');
		i++;
	}
	return (res);
}

void	convert_tobinary(int pid, char c)
{
	int	a;
	int	b;

	a = 7;
	while (a >= 0)
	{
		b = ((c >> a) & 1);
		if (b == 1)
		{
			kill(pid, SIGUSR1);
			usleep(1200);
		}
		else
		{
			kill (pid, SIGUSR2);
			usleep (1200);
		}
		a--;
	}
}

int	main(int ac, char **av)
{
	int	i;
	int	pid;

	i = 0;
	if (ac == 3)
	{
		pid = ft_atoi(av[1]);
		if (pid <= 0)
			return (0);
		while (av[2][i])
		{
			convert_tobinary(pid, av[2][i]);
			i++;
		}
	}
}
