/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pointer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  <>                                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 00:36:46 by                   #+#    #+#             */
/*   Updated: 2021/11/09 18:42:50 by                  ###   ########.fr       */
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

static void	get_p(unsigned long n, char *base, int *cnt)
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

int	ft_pointer(unsigned long num)
{
	int		cnt;
	char	*all;

	cnt = 0;
	all = ft_strdup("0123456789abcdef");
	if (num == 0)
		cnt += ft_putstr_fd("0x0", 1);
	else
	{
		cnt += ft_putstr_fd("0x", 1);
		get_p(num, all, &cnt);
	}
	free(all);
	return (cnt);
}
