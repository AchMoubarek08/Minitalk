/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoubare <amoubare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 21:38:17 by amoubare          #+#    #+#             */
/*   Updated: 2022/04/15 03:58:31 by amoubare         ###   ########.fr       */
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

int	main(int argc, char **argv)
{
	int	pid;

	(void) argv;
	(void) argc;
	pid = getpid();
	printf("server PID : %d\n", pid);
	signal(SIGUSR1, &hehe);
	signal(SIGUSR2, &hehe);
	while (1)
		pause();
}
