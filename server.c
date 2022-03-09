#include "minitalk.h"
#include "ft_printf/includes/ft_printf.h"

static int	pow(int pw)
{
	int	number;

	if (!pw)
		return (1);
	number = 2;
	while (pw > 1)
	{
		//ft_printf("number = %d, pw = %d\n", number, pw);
		number *= 2;
		pw--;
	}
	return (number);
}

static int	improve_data(t_word	*t, int size)
{
	int	*mass;
	int	i;
	int	ans;

	mass = (int *) malloc(sizeof(int) * size);
	i = 0;
	ans = 0;
	while (i < size && t->next != NULL)
	{
		mass[i] = t->sig;
		//ft_printf("sig %d\n", t->sig);
		i++;
		t = (t_word *) t->next;
	}
	i = 0;
	while (i < size)
	{
		if (mass[i])
		{
			//ft_printf("index = %d\n", i);
			//ft_printf("pow = %d\n", pow(i));
			ans += pow(i);
		}
		i++;
	}
	free(mass);
	ft_printf("answer = %d\n", ans);
	return (ans);
}

static void	get_data(int sig)
{
	static t_word	*t;

	if (sig == SIGUSR1)
	{
		pb(&t, 1);
		//ft_printf("OK1\n");
	}
	else if (sig == SIGUSR2)
	{
		pb(&t, 0);
		//ft_printf("OK2\n");
	}
	//ft_printf("tmp lst size = %d\n", ft_size(t));
	if (ft_size(t) == 8)
	{
		//ft_printf("OK\n");
		//ft_printf("size of list %d\n", ft_size(t));
		get_d(t);
		ft_printf("%c", improve_data(t, ft_size(t)));
		ft_cls_stack(&t);
		//ft_printf("size after clean %d\n", ft_size(t));
	}
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
		pause();
}
