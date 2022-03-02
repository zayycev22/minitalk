/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  <>                                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/17 15:32:38 by                   #+#    #+#             */
/*   Updated: 2021/10/26 20:08:48 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*cons;
	int		i;
	int		j;

	i = 0;
	j = 0;
	cons = (char *)malloc(sizeof(char) *(ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!cons)
		return (NULL);
	while (s1[j])
	{
		cons[i] = s1[j];
		i++;
		j++;
	}
	j = 0;
	while (s2[j])
	{
		cons[i] = s2[j];
		i++;
		j++;
	}
	cons[i] = '\0';
	return (cons);
}
