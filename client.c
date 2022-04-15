/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoubare <amoubare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 21:37:52 by amoubare          #+#    #+#             */
/*   Updated: 2022/04/15 04:15:01 by amoubare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <unistd.h>
#include <strings.h>
#include <stdlib.h>
#include <stdio.h>

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

void	ft_error(void)
{
	ft_putstr("Error");
	exit(0);
}

void	bit_sender(char *argv, int pid)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (*(argv + j))
	{
		while (i < 8)
		{
			if (*(argv + j) & 1)
			{
				if (kill(pid, SIGUSR1) == -1)
					ft_error();
			}
			else if (kill(pid, SIGUSR2) == -1)
				ft_error();
			*(argv + j) = *(argv + j) >> 1;
			i++;
			usleep(500);
		}
		j++;
		i = 0;
	}
}

int	main(int argc, char **argv)
{
	int	pid;

	if (argc != 3)
		ft_error();
	pid = atoi(*(argv + 1));
	bit_sender(*(argv + 2), pid);
}
