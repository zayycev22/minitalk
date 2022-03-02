#include "minitalk.h"

static void	get_data(int sig)
{
	static t_word	*t;

	if (sig == SIGUSR1)
		pb(&t, 1);
	else if (sig == SIGUSR2)
		pb(&t, 0);
	ft_printf("%d\n", ft_size(t));
}

static void	close_server(int sig)
{
	(void)sig;
	ft_printf("\nServer is closed\n");
	exit(0);
}

int	main(void)
{
	ft_printf("PID: %d\n", getpid());
	signal(SIGINT, close_server);
	signal(SIGKILL, close_server);
	signal(SIGUSR1, get_data);
	signal(SIGUSR2, get_data);
	while (1)
		usleep(500);
}
