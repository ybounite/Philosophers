/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_routine.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybounite <ybounite@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/01 18:47:49 by ybounite          #+#    #+#             */
/*   Updated: 2025/06/02 15:58:24 by ybounite         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo_bonus.h"

void	philo_think(t_philosopher *philo)
{
	print_action(philo, "is thinking");
}

void	philo_sleep(t_philosopher *philo)
{
	print_action(philo, "is sleeping");
	safe_usleep(philo, philo->data->time_to_sleep);
}

void	routine_philosopher(t_philosopher *philo)
{
	pthread_t	monitor;

	sem_wait(philo->data->sm_meals);
	philo->last_meal = get_time();
	sem_post(philo->data->sm_meals);
	pthread_create(&monitor, NULL, monitor_death, philo);
	while (true)
	{
		if (!check_death(philo))
			exit(EXIT_FAILURE);
		philo_think(philo);
		if (!check_death(philo))
			exit(EXIT_FAILURE);
		philo_eat(philo);
		if (philo->data->num_philo == 1)
			break ;
		if (!check_death(philo))
			exit(EXIT_FAILURE);
		if (philo->meals_eaten == philo->data->num_of_must_eat)
		{
			printf(GREEN"phile id %d meals eaten : %d and exit%s\n", philo->id, philo->meals_eaten, NC);
			exit(EXIT_SUCCESS);
		}
		philo_sleep(philo);
		usleep(500);
	}
	pthread_join(monitor, NULL);
}
