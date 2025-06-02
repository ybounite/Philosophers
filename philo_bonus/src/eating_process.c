/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eating_process.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybounite <ybounite@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/01 18:54:58 by ybounite          #+#    #+#             */
/*   Updated: 2025/06/02 15:19:44 by ybounite         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo_bonus.h"

void	print_action(t_philosopher *philo, char *messag)
{
	if (!check_death(philo))
		exit(1);
	sem_wait(philo->data->sm_print);
	if (!check_death(philo))
	{
		sem_post(philo->data->sm_print);
		exit(1);
	}
	printf("%lld %d %s\n", get_time() - philo->data->start_time,
		philo->id, messag);
	sem_post(philo->data->sm_print);
}

void	philo_eat(t_philosopher *philo)
{
	if (philo->id % 2 == 0)
		usleep(2000);
	sem_wait(philo->data->sm_forks);
	if (philo->data->num_philo == 1)
	{
		sem_post(philo->data->sm_forks);
		return ;
	}
	sem_wait(philo->data->sm_forks);
	print_action(philo, "has taken a fork");
	sem_wait(ft_sem_()->sm_meals_eat);
	philo->last_meal = get_time();
	sem_post(ft_sem_()->sm_meals_eat);
	sem_wait(philo->data->sm_meals);
	philo->meals_eaten++;
	sem_post(philo->data->sm_meals);
	print_action(philo, YELLOW"is eating"NC);
	safe_usleep(philo, philo->data->time_to_eat);
	sem_post(philo->data->sm_forks);
	sem_post(philo->data->sm_forks);
}
