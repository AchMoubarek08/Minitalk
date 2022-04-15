/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoubare <amoubare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 21:38:17 by amoubare          #+#    #+#             */
/*   Updated: 2022/04/15 04:19:53 by amoubare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <unistd.h>
#include <stdio.h>

void	hehe(int sig)
{
	static char	x;
	static int	i;
	static int	count;

	if (count == 0)
	{
		count = 0;
		x = '\0';
		i = 1;
	}
	if (sig == SIGUSR1)
		x = x | i;
	i = i << 1;
	count++;
	if (count == 8)
	{
		write(1, &x, 1);
		count = 0;
	}
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int n)
{
	if (n >= 0 && n <= 9)
	{
		ft_putchar(n + '0');
	}
	else
	{
		ft_putnbr(n / 10);
		ft_putnbr(n % 10);
	}
}

void	ft_putstr(char *s)
{
	int	i;

	i = 0;
	if (s)
	{
		while (s[i])
		{
			write(1, &s[i], 1);
			i++;
		}
	}
}

int	main(int argc, char **argv)
{
	int	pid;

	(void) argv;
	(void) argc;
	pid = getpid();
	ft_putstr("server PID : ");
	ft_putnbr(pid);
	ft_putstr("\n");
	signal(SIGUSR1, &hehe);
	signal(SIGUSR2, &hehe);
	while (1)
		pause();
}
