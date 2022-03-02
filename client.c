#include "minitalk.h"
#include "ft_printf/libft/libft.h"

static void	send_text(int pid, int message)
{
	while (message)
	{
		if (message % 2)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		message /= 2;
		ft_printf("OK %d\n", message % 2);
	}
	usleep(600);
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
			i++;
		}
		return (0);
	}
	else
		exit(-1);
}
