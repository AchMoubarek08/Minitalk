#include <signal.h>
#include <unistd.h>
#include <strings.h>
#include <stdlib.h>
#include <stdio.h>

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
					exit(0);
			}
			else if (kill(pid, SIGUSR2) == -1)
				exit(0);
			*(argv + j) = *(argv + j) >> 1;
			i++;
			usleep(500);
		}
		j++;
		i = 0;
	}
}

int main(int argc, char **argv)
{
    int pid = atoi(*(argv + 1));
    printf("%d\n", pid);
    int i = 0;
    bit_sender(*(argv + 2), pid);
}
