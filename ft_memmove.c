/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramahrez <ramahrez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 16:26:21 by ramahrez          #+#    #+#             */
/*   Updated: 2024/11/15 17:52:08 by ramahrez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{	
	char	*dstc;
	char	*srcc;

	dstc = (char *)dst;
	srcc = (char *)src;
	if (dstc > srcc && dstc < srcc + len)
	{
		dstc = dstc + len;
		srcc = srcc + len;
		while (len--)
			*--dstc = *--srcc;
	}
	else
		ft_memcpy(dstc, srcc, len);
	return (dst);
}
