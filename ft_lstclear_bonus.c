/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramahrez <ramahrez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 22:20:17 by ramahrez          #+#    #+#             */
/*   Updated: 2024/11/18 12:44:05 by ramahrez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*current;
	t_list	*next_lst;

	if (lst == NULL || *lst == NULL || !del)
		return ;
	current = *lst;
	while (current != NULL)
	{
		next_lst = current->next;
		del(current->content);
		free(current);
		current = next_lst;
	}
	*lst = NULL;
}
