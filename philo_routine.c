/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_routine.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybounite <ybounite@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 13:02:44 by ybounite          #+#    #+#             */
/*   Updated: 2025/05/28 15:21:00 by ybounite         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_death(t_philosopher *philo)
{
	pthread_mutex_lock(&philo->data->death_mutex);
	if (philo->data->someone_died)
	{
		pthread_mutex_unlock(&philo->data->death_mutex);
		return (1);
	}
	pthread_mutex_unlock(&philo->data->death_mutex);
	return (0);
}

void	print_action(t_philosopher *philo, const char *action)
{
	pthread_mutex_lock(&philo->data->write_lock);
	if (!philo->data->someone_died)
	{
		printf("%lld %d %s\n", get_time() - philo->data->start_time,
			philo->id, action);
	}
	pthread_mutex_unlock(&philo->data->write_lock);
}

void	*philo_routine(void *arg)
{
	t_philosopher	*philo;

	philo = (t_philosopher *)arg;
	while (1)
	{
		if (check_death(philo))
			break ;
		if (philo->id % 2 != 0) // if ID in odd usleep
		{
			printf("thread ID is usleep : %d\n", philo->id);
			usleep(1000);
		}
		if (check_death(philo))
			break ;
		pthread_mutex_lock(philo->left_fork);
		print_action(philo, "has taken a fork");
		pthread_mutex_lock(philo->right_fork);
		print_action(philo, "has taken a fork");
		print_action(philo, "is eating");
		pthread_mutex_lock(&philo->data->time);
		philo->last_meal = get_time(); // protect
		pthread_mutex_unlock(&philo->data->time);
		usleep(philo->data->time_to_eat * 1000); // protect
		pthread_mutex_lock(&philo->data->times_eaten_mutex);
		philo->times_eaten++;
		pthread_mutex_lock(&philo->data->times_eaten_mutex);
		pthread_mutex_unlock(philo->left_fork);
		pthread_mutex_unlock(philo->right_fork);
		if (check_death(philo))
			break ;
		print_action(philo, "is thinking");
		if (check_death(philo))
			break ;
		print_action(philo, "is sleeping");
		usleep(philo->data->time_to_sleep * 1000); // protect
	}
	return (NULL);
}
