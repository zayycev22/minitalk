/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthexbase.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larobbie <larobbie@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/31 03:51:15 by larobbie          #+#    #+#             */
/*   Updated: 2021/11/11 19:28:59 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "includes/ft_printf.h"

static void	print_hex(char *s)
{
	int	i;
	int	len;

	len = (int)ft_strlen(s);
	i = len - 1;
	while (i >= 0)
	{
		ft_putchar_fd(s[i], 1);
		i--;
	}
}

static	char	*new_s(char *old, char c)
{
	char	con[2];
	char	*new;

	con[0] = c;
	con[1] = '\0';
	new = ft_strjoin(old, con);
	free(old);
	return (new);
}

static void	ft_putnbr_fd_six(unsigned int n, char *base, int *cnt)
{
	int		tmp;
	char	*t;

	tmp = *cnt;
	t = ft_strdup("");
	while (n > 0)
	{
		t = new_s(t, base[n % 16]);
		*cnt = *cnt + 1;
		n /= 16;
	}
	if (tmp == *cnt)
	{
		t = new_s(t, base[n % 16]);
		*cnt = *cnt + 1;
	}
	print_hex(t);
	free(t);
}

int	puthex(char desc, unsigned int num)
{
	char	*all;
	int		cnt;

	cnt = 0;
	if (desc == 'x')
		all = ft_strdup("0123456789abcdef");
	else
		all = ft_strdup("0123456789ABCDEF");
	ft_putnbr_fd_six(num, all, &cnt);
	free(all);
	return (cnt);
}
