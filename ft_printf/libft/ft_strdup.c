/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  <>                                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/17 15:32:34 by                   #+#    #+#             */
/*   Updated: 2021/10/24 19:05:02 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strdup(const char *s1)
{
	size_t	len;
	char	*str_to_dup;

	len = ft_strlen(s1);
	str_to_dup = (char *)malloc((len + 1) * sizeof(char));
	if (str_to_dup == NULL)
	{
		return (NULL);
	}
	ft_strlcpy(str_to_dup, s1, len + 1);
	return (str_to_dup);
}
