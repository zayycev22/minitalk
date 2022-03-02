/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  <>                                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/17 15:33:07 by                   #+#    #+#             */
/*   Updated: 2021/10/17 15:33:07 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*mapped;
	unsigned int	iter;
	size_t			len;

	mapped = NULL;
	if (s)
	{
		len = ft_strlen((const char *)s) + 1;
		mapped = (char *)malloc(sizeof(char) * len);
		if (!mapped)
			return (NULL);
		iter = 0;
		while (s[iter] != '\0')
		{
			mapped[iter] = f(iter, (char)s[iter]);
			iter++;
		}
		mapped[iter] = '\0';
	}
	return (mapped);
}
