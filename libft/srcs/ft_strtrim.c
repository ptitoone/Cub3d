/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akotzky <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/18 09:46:30 by akotzky           #+#    #+#             */
/*   Updated: 2021/01/23 10:33:51 by akotzky          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_is_set(char const *s, char const c)
{
	unsigned int	i;

	i = 0;
	while (s[i] != 0)
	{
		if (s[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	unsigned int	i;
	unsigned int	j;
	char			*str;

	i = 0;
	if (!s1)
		return (NULL);
	while (ft_is_set(set, s1[i]))
		i++;
	if (i == ft_strlen(s1))
	{
		str = (char *)malloc(sizeof(char) * 1);
		if (str == NULL)
			return (NULL);
		str[0] = 0;
		return (str);
	}
	j = ft_strlen(s1) - 1;
	while (ft_is_set(set, s1[j]))
		j--;
	str = (char *)malloc(sizeof(char) * (j - i) + 2);
	if (str == NULL)
		return (NULL);
	ft_strlcpy(str, s1 + i, j - i + 2);
	return (str);
}
