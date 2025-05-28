/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybounite <ybounite@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 14:41:51 by ybounite          #+#    #+#             */
/*   Updated: 2025/05/28 15:31:19 by ybounite         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

bool	init_forks(t_data_philo *data)
{
	int	i;

	i = 0;
	data->forks = malloc(sizeof(t_data_philo) * data->num_philo);
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
	data->philos = malloc(sizeof(t_data_philo) * data->num_philo);
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
		data->philos[i].times_eaten = 0;
		data->philos[i].left_fork = &data->forks[i];
		data->philos[i].right_fork = &data->forks[(i + 1) % data->num_philo];
		data->philos[i].data = data;
		i++;
	}
	return (false);
}

bool	init_data_philo(t_data_philo *data)
{
	if (init_forks(data))
		return (EXIT_FAILURE);
	if (init_philosophers(data))
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
