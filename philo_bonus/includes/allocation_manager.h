/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   allocation_manager.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybounite <ybounite@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 13:32:08 by ybounite          #+#    #+#             */
/*   Updated: 2025/05/31 10:56:28 by ybounite         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ALLOCATION_MANAGER_H
# define ALLOCATION_MANAGER_H

# include "../includes/philo_bonus.h"

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;
/* -------------------------------------------------------------------------- */
/*                               allocate_data.c                              */
/* -------------------------------------------------------------------------- */
void						*ft_malloc(size_t size, short option);
void						memory_released(t_list **head);
t_list						*ft_lstnew(void *content);
void						ft_lstadd_back(t_list **lst, t_list *new);
void						ft_lstclear(t_list **lst, void (*del)(void *));

#endif