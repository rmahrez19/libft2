/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramahrez <ramahrez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 16:31:30 by ramahrez          #+#    #+#             */
/*   Updated: 2024/11/14 07:58:52 by ramahrez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int nb, int fd)
{
	long int	nbl;

	nbl = nb;
	if (nbl < 0)
	{
		ft_putchar_fd('-', fd);
		nbl = nbl * -1;
	}
	if (nbl < 10 && nbl >= 0)
		ft_putchar_fd(nbl + '0', fd);
	if (nbl >= 10)
	{
		ft_putnbr_fd(nbl / 10, fd);
		ft_putnbr_fd(nbl % 10, fd);
	}
}
