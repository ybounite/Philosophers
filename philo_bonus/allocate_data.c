/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   allocate_data.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybounite <ybounite@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 13:07:38 by ybounite          #+#    #+#             */
/*   Updated: 2025/06/01 09:31:28 by ybounite         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/allocation_manager.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*new;

	new = malloc(sizeof(t_list));
	if (!new)
		return (NULL);
	new->content = content;
	new->next = NULL;
	return (new);
}

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*curr;

	if (lst == NULL || new == NULL)
		return ;
	if (*lst == NULL)
	{
		*lst = new;
		return ;
	}
	curr = *lst;
	while (curr->next)
		curr = curr->next;
	curr->next = new;
}

void	ft_lstclear(t_list **list, void (*del)(void *))
{
	t_list	*curr;

	if (!list || !*list || !del)
		return ;
	curr = *list;
	while (curr)
	{
		*list = curr;
		del((*list)->content);
		curr = curr->next;
		free(*list);
	}
	*list = NULL;
}

void	memory_released(t_list **head)
{
	ft_lstclear(head, free);
}

void	*ft_malloc(size_t size, short option)
{
	static t_list	*head;
	t_list			*new;
	void			*ptr;

	if (option == 1)
	{
		ptr = malloc(size);
		if (!ptr)
		{
			printf("allocation fail\n");
			return (memory_released(&head), exit(EXIT_FAILURE), NULL);
		}
		new = ft_lstnew(ptr);
		if (!new)
			return (memory_released(&head), exit(EXIT_FAILURE), NULL);
		ft_lstadd_back(&head, new);
		return (ptr);
	}
	if (option == 0)
		memory_released(&head);
	return (NULL);
}
