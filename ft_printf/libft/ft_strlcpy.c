/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  <>                                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/17 15:32:47 by                   #+#    #+#             */
/*   Updated: 2021/10/17 15:32:47 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	iter;
	size_t	exp_len;

	iter = 0;
	exp_len = ft_strlen(src);
	if (dstsize == 0)
		return (ft_strlen(src));
	while (iter < dstsize - 1 && src[iter] != '\0')
	{
		dst[iter] = src[iter];
		iter++;
	}
	dst[iter] = '\0';
	return (exp_len);
}
