/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramahrez <ramahrez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 17:51:45 by ramahrez          #+#    #+#             */
/*   Updated: 2024/11/16 22:22:31 by ramahrez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t len)
{
	size_t		i;
	const char	*s1;

	i = 0;
	s1 = (const char *)s;
	while (i < len)
	{
		if (s1[i] == (char)c)
			return ((void *)&s1[i]);
		i++;
	}
	return ((void *)0);
}
