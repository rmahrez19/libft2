/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramahrez <ramahrez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 03:33:05 by ramahrez          #+#    #+#             */
/*   Updated: 2024/11/16 22:21:38 by ramahrez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*new_lst;

	new_lst = malloc(sizeof(t_list));
	if (!new_lst)
		return (NULL);
	new_lst->content = content;
	new_lst -> next = NULL;
	return (new_lst);
}

// int main(void)
// {
// 	char *content = "hello word";
// 	t_list *manon = ft_lstnew(content);
// 	if(!manon)
// 	  if (manon == NULL)
//     {
//         printf("Erreur : la fonction ft_lstnew a retourné NULL\n");
//         return (1);
//     }
//     printf("Contenu du nœud : %s\n", (char *)manon->content);
//     if (manon->next == NULL)
//         printf("Le champ 'next' est correctement initialisé à NULL\n");
//     else
//         printf("Erreur : le champ 'next' n'est pas NULL\n")
//     // Libération de la mémoire allouée
//     free(manon);
// }