/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larobbie <larobbie@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/31 03:50:57 by larobbie          #+#    #+#             */
/*   Updated: 2021/11/09 00:22:14 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft/libft.h"
#include "includes/ft_printf.h"

int	parse(char arg, va_list ap)
{
	int		sum;

	sum = 0;
	if (arg == 'd' || arg == 'i' || arg == 'u')
		sum += printnb(arg, ap);
	else if (arg == 'c')
		sum += ft_char(va_arg(ap, int));
	else if (arg == 's')
		sum += ft_string(va_arg(ap, char *));
	else if (arg == 'x' || arg == 'X')
		sum += puthex(arg, (unsigned int)va_arg(ap, unsigned int));
	else if (arg == 'p')
		sum += ft_pointer((unsigned long)va_arg(ap, unsigned long));
	else if (arg == '%')
	{
		ft_putchar_fd('%', 1);
		sum++;
	}
	return (sum);
}

int	ft_printf(const char *arg, ...)
{
	va_list	ap;
	size_t	i;
	int		count;

	va_start(ap, arg);
	i = 0;
	count = 0;
	while (arg[i])
	{
		if (arg[i] == '%' && i != ft_strlen(arg) - 1)
		{
			count += parse(arg[i + 1], ap);
			i++;
		}
		else
		{
			ft_putchar_fd(arg[i], 1);
			count++;
		}
		i++;
	}
	return (count);
}
