/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_digit.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  <>                                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 05:28:39 by                   #+#    #+#             */
/*   Updated: 2021/11/08 06:05:40 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft/libft.h"
#include "includes/ft_printf.h"

int	printnb(char desc, va_list ap)
{
	size_t		count;
	long		num;
	char		*tmp;

	count = 0;
	tmp = NULL;
	if (desc == 'd' || desc == 'i')
	{
		tmp = ft_itoa(va_arg(ap, int));
		count += ft_strlen(tmp);
		ft_putstr_fd(tmp, 1);
	}
	else if (desc == 'u')
	{
		num = (unsigned int)va_arg(ap, unsigned int);
		tmp = ft_itoa(num);
		count += ft_strlen(tmp);
		ft_putstr_fd(tmp, 1);
	}
	free(tmp);
	return ((int)count);
}
