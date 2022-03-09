#include "minitalk.h"
#include "ft_printf/libft/libft.h"

static void	send_text(int pid, int message)
{
	int	i;

	i = 0;
	while (message)
	{
		if (message % 2 == 1)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		ft_printf("OK %d\n", message % 2);
		message /= 2;
		usleep(30);
		i++;
	}
	if (i < 8)
	{
		while (i <= 8)
		{
			kill(pid, SIGUSR2);
			i++;
		}
	}
	usleep(1600);
}

static void	send_text2(int pid)
{
	int	i;

	i = 0;
	while (i < 9)
	{
		kill(pid, SIGUSR2);
		i++;
	}
}

int	main(int argc, char **argv)
{
	int	pid;
	int	i;

	if (argc == 3)
	{
		pid = ft_atoi(argv[1]);
		i = 0;
		while (argv[2][i])
		{
			send_text(pid, argv[2][i]);
			ft_printf("\n");
			i++;
		}
		//send_text2(pid);
	}
	else
		exit(-1);
}
