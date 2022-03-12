/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larobbie <larobbie@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 19:59:01 by larobbie          #+#    #+#             */
/*   Updated: 2022/03/12 19:59:01 by larobbie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
		number *= 2;
		pw--;
	}
	return (number);
}

static	char	translate(const char *c)
{
	int	number;
	int	i;

	number = 0;
	i = 0;
	while (c[i])
	{
		if (c[i] == '1')
			number += pow(i);
		i++;
	}
	return ((char)number);
}

static void	get_data(int sig)
{
	static t_word	*t;
	static char		*c;

	if (sig == SIGUSR1)
	{
		c = ft_strjoin(c, "1");
	}
	else if (sig == SIGUSR2)
	{
		c = ft_strjoin(c, "0");
	}
	if (ft_strlen(c) >= 8)
	{
		ft_printf("%c", translate(c));
		free(c);
		c = NULL;
	}
}

int	main(void)
{
	ft_printf("PID: %d\n", getpid());
	signal(SIGUSR1, get_data);
	signal(SIGUSR2, get_data);
	while (1)
		pause();
}
