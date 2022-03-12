/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larobbie <larobbie@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 19:58:20 by larobbie          #+#    #+#             */
/*   Updated: 2022/03/12 19:58:22 by larobbie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
		message /= 2;
		usleep(30);
		i++;
	}
	if (i < 8)
	{
		while (i < 8)
		{
			kill(pid, SIGUSR2);
			usleep(30);
			i++;
		}
	}
	usleep(400);
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
			i++;
		}
	}
	else
		exit(-1);
}
