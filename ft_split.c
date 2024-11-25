/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramahrez <ramahrez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 16:33:45 by ramahrez          #+#    #+#             */
/*   Updated: 2024/11/18 16:38:18 by ramahrez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	countwords(char const *s, char sep)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		while (s[i] == sep && s[i])
			i++;
		if (s[i] != '\0')
		{
			count++;
			i++;
		}
		while (s[i] != sep && s[i])
			i++;
	}
	return (count);
}

static void	ft_strcpyi(char *dest, const char *src, int index, int len)
{
	int	i;

	i = 0;
	while (i < len)
	{
		dest[i] = src[index + i];
		i++;
	}
	dest[i] = '\0';
}

static void	*ft_clear(char **res, int j)
{
	j--;
	while (j >= 0)
	{
		free(res[j]);
		j--;
	}
	free(res);
	return (NULL);
}

static char	**addwords(char **res, const char *s, char sep)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	j = 0;
	k = 0;
	while (j < countwords(s, sep))
	{
		while (s[i] == sep && s[i])
			i++;
		while (s[i] != sep && s[i])
		{
			i++;
			k++;
		}
		res[j] = malloc((k + 1) * sizeof(char));
		if (!res[j])
			return (ft_clear(res, j));
		ft_strcpyi(res[j], s, i - k, k);
		k = 0;
		j++;
	}
	res[j] = NULL;
	return (res);
}

char	**ft_split(char const *s, char sep)
{
	char	**res;

	res = malloc((countwords(s, sep) + 1) * sizeof(char *));
	if (!res)
		return (NULL);
	res = addwords(res, s, sep);
	return (res);
}
