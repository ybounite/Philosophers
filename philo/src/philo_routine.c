/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_routine.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybounite <ybounite@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 13:02:44 by ybounite          #+#    #+#             */
/*   Updated: 2025/06/02 16:00:17 by ybounite         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	print_action(t_philosopher *philo, const char *action)
{
	pthread_mutex_lock(&philo->data->death_lock);
	if (!philo->data->someone_died)
	{
		printf("%lld %d %s\n", get_time() - philo->data->start_time,
			philo->id, action);
	}
	pthread_mutex_unlock(&philo->data->death_lock);
}

void	think_philo(t_philosopher *philo)
{
	print_action(philo, "is thinking");
}

void	sleep_philo(t_philosopher *philo)
{
	print_action(philo, "is sleeping");
	safe_usleep(philo, philo->data->time_to_sleep);
}

void	*philo_routine(void *arg)
{
	t_philosopher	*philo;

	philo = (t_philosopher *)arg;
	while (true)
	{
		if (check_death(philo))
			return (NULL);
		think_philo(philo);
		manager_eating(philo);
		if (check_death(philo))
			return (NULL);
		sleep_philo(philo);
	}
	return (NULL);
}
