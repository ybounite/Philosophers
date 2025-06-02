/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybounite <ybounite@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 14:41:51 by ybounite          #+#    #+#             */
/*   Updated: 2025/06/02 16:00:17 by ybounite         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

t_mutex_	*ft_mutex_(void)
{
	static t_mutex_	_mutex_ = {PTHREAD_MUTEX_INITIALIZER,
		PTHREAD_MUTEX_INITIALIZER,
		PTHREAD_MUTEX_INITIALIZER,
		PTHREAD_MUTEX_INITIALIZER};

	return (&_mutex_);
}

bool	init_forks(t_data_philo *data)
{
	int	i;

	i = 0;
	data->forks = malloc(sizeof(pthread_mutex_t) * data->num_philo);
	if (!data->forks)
		return (printf("FILED IN MALLOC\n"), true);
	while (i < data->num_philo)
	{
		if (pthread_mutex_init(&data->forks[i], NULL) != 0)
		{
			printf("FAILED TO INIT MUTEX at index %d\n", i);
			free(data->forks);
			return (true);
		}
		i++;
	}
	return (false);
}

bool	init_philosophers(t_data_philo *data)
{
	int	i;

	i = 0;
	data->philos = malloc(sizeof(t_philosopher) * data->num_philo);
	if (!data->philos)
	{
		free(data->forks);
		printf("FILED IN MALLOC\n");
		return (true);
	}
	data->start_time = get_time();
	while (i < data->num_philo)
	{
		data->philos[i].id = i + 1;
		data->philos[i].last_meal = data->start_time;
		data->philos[i].meals_eaten = 0;
		data->philos[i].left_fork = &data->forks[i];
		data->philos[i].right_fork = &data->forks[(i + 1) % data->num_philo];
		data->philos[i].data = data;
		i++;
	}
	return (false);
}

bool	init_mutex(t_data_philo *data)
{
	if (pthread_mutex_init(&data->write_lock, NULL) != 0)
		return (printf("FILED TO INIT MUTEX\n"), true);
	if (pthread_mutex_init(&data->meal_lock, NULL) != 0)
		return (printf("FILED TO INIT MUTEX\n"), true);
	if (pthread_mutex_init(&data->death_lock, NULL) != 0)
		return (printf("FILED TO INIT MUTEX\n"), true);
	return (false);
}

bool	init_data_philo(t_data_philo *data)
{
	if (init_forks(data))
		return (EXIT_FAILURE);
	if (init_philosophers(data))
		return (EXIT_FAILURE);
	if (init_mutex(data))
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
