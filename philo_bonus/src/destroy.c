/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybounite <ybounite@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 13:31:38 by ybounite          #+#    #+#             */
/*   Updated: 2025/06/02 14:45:24 by ybounite         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/philo_bonus.h"

void	ft_sem_unlink(void)
{
	sem_unlink("sem_forks");
	sem_unlink("sem_print");
	sem_unlink("sem_meals");
	sem_unlink("sem_dead");
	sem_unlink("if_dead");
	sem_unlink("sm_meals_eat");
}

void	destroy_close_(t_data_ *data)
{
	if (data->sm_forks)
		sem_close(data->sm_forks);
	if (data->sm_dead)
		sem_close(data->sm_dead);
	if (data->sm_meals)
		sem_close(data->sm_meals);
	if (data->sm_print)
		sem_close(data->sm_print);
	ft_sem_unlink();
	ft_malloc(CLEAR, CLEAR);
}
