/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor_death.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybounite <ybounite@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/01 14:47:40 by ybounite          #+#    #+#             */
/*   Updated: 2025/06/02 15:20:48 by ybounite         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo_bonus.h"

int	check_death(t_philosopher *philo)
{
	int	is_dead;

	sem_wait(philo->data->if_dead);
	is_dead = philo->data->sm_dead->__align;
	sem_post(philo->data->if_dead);
	return (is_dead);
}

void	*monitor_death(void	*args)
{
	t_philosopher	*philo;

	philo = (t_philosopher *)args;
	while (true)
	{
		sem_wait(ft_sem_()->sm_meals_eat);
		if (get_time() - philo->last_meal > philo->data->time_to_die)
		{
			print_action(philo, "is died");
			sem_wait(philo->data->if_dead);
			philo->data->sm_dead->__align = 0;
			sem_post(philo->data->if_dead);
			exit(EXIT_FAILURE);
		}
		sem_post(ft_sem_()->sm_meals_eat);
		usleep(100);
	}
	return (NULL);
}
