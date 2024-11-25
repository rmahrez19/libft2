/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramahrez <ramahrez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 16:45:44 by ramahrez          #+#    #+#             */
/*   Updated: 2024/11/16 22:36:55 by ramahrez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_totrim(char c, char const *set)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (c == set[i])
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		min;
	int		max;
	int		len;
	char	*res;

	min = 0;
	while (s1[min] && ft_totrim(s1[min], set))
		min++;
	max = ft_strlen(s1);
	while (max > min && ft_totrim(s1[max - 1], set))
		max--;
	len = max - min;
	res = ft_substr(s1, min, len);
	if (!res)
		return (NULL);
	res[len] = '\0';
	return (res);
}
