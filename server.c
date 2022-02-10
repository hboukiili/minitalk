/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hboukili <hboukili@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 03:38:14 by hboukili          #+#    #+#             */
/*   Updated: 2022/02/10 16:52:11 by hboukili         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <signal.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int nb)
{
	if (nb > 9)
	{
		ft_putnbr(nb / 10);
		ft_putchar(nb % 10 + 48);
	}
	if (nb < 10)
		ft_putchar (nb + 48);
}

void	signal_handler(int sig)
{
	static int	sam;
	static int	i;

	if (sig == SIGUSR1)
		sam += (1 << (7 - i));
	i++;
	if (i == 8)
	{
		ft_putchar(sam);
		i = 0;
		sam = 0;
	}
}

int	main(void)
{
	signal(SIGUSR1, signal_handler);
	signal(SIGUSR2, signal_handler);
	ft_putnbr(getpid());
	while (1)
		;
}
