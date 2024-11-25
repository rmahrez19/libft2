/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramahrez <ramahrez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 16:42:56 by ramahrez          #+#    #+#             */
/*   Updated: 2024/11/16 22:35:56 by ramahrez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t n)
{
	size_t	i;
	size_t	y;
	size_t	len;

	i = 0;
	len = ft_strlen(needle);
	if (!haystack && n == 0)
		return (NULL);
	if (len == 0)
		return ((char *)haystack);
	while (haystack[i] && i < n)
	{
		y = 0;
		while (needle[y] == haystack[i + y] && (i + y) < n)
		{
			if (y == len - 1)
				return ((char *)haystack + i);
			y++;
		}
		i++;
	}
	return (NULL);
}
