/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramahrez <ramahrez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 22:20:28 by ramahrez          #+#    #+#             */
/*   Updated: 2024/11/18 16:33:21 by ramahrez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_lst;
	t_list	*nex_ele;
	void	*content;

	if (!lst || !f | !del)
		return (NULL);
	new_lst = NULL;
	while (lst)
	{
		content = f(lst->content);
		nex_ele = ft_lstnew(content);
		if (!nex_ele)
		{
			ft_lstclear(&new_lst, del);
			del(content);
			return (NULL);
		}
		ft_lstadd_back(&new_lst, nex_ele);
		lst = lst->next;
	}			
	return (new_lst);
}
/*
 int    main(void)
{
    t_list    *head;
    t_list    *second;
    t_list    *third;
    t_list    *explorer;
    t_list    *fourth;
    t_list    *map;

    //PREMIER MAILLON
    head = NULL;
    head = malloc(sizeof(t_list));
    if (head == NULL)
        return (1);
    head->content = ft_strdup("C'est le debut de la grande aventure");
    head->next = NULL;
    //SECOND MAILLON
    second = NULL;
    second = malloc(sizeof(t_list));
    if (second == NULL)
        return (2);
    second->content = ft_itoa(171096);
    second->next = NULL;
    head->next = second; // maillon 1 relie le 2
    //TROISIEME MAILLON
    third = NULL;
    third = malloc(sizeof(t_list));
    if (third == NULL)
        return (3);
    third->content = ft_itoa((int)strlen("Salut comment ca va ?"));
    third->next = NULL;
    second->next = third; // maillon 2 relie le 3
    //PARCOURIR LES MAILLONS
    int    i;
    i = 1;
    explorer = head;
    while(explorer != NULL)
        {
            printf("noeud num: %d -> %s\n", i, (char *)explorer ->content);
            i++;
            explorer = explorer->next;
        }
    fourth = NULL;
    fourth = malloc(sizeof(t_list));
    if (fourth == NULL)
        return (4);
    fourth->content = ft_strdup("ici mon pote");
    ft_lstadd_back(&head, fourth);
    map = ft_lstmap(head, )
}
*/