/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  <>                                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/17 15:33:38 by                   #+#    #+#             */
/*   Updated: 2021/10/24 18:23:55 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*sub_str;
	unsigned int	iter;

	if (s)
	{
		if (start >= ft_strlen(s))
		{
			sub_str = (char *)malloc(sizeof(char));
			if (!sub_str)
				return (NULL);
			*sub_str = '\0';
			return (sub_str);
		}
		if (start + len > ft_strlen(s))
			len = ft_strlen(s) - start;
		sub_str = (char *)malloc(sizeof(char) * (len + 1));
		if (!sub_str)
			return (NULL);
		iter = 0;
		ft_strlcpy(sub_str, s + start, len + 1);
		return (sub_str);
	}
	return (NULL);
}
