/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manager_thread.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybounite <ybounite@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 15:09:00 by ybounite          #+#    #+#             */
/*   Updated: 2025/05/30 15:04:16 by ybounite         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

bool	ft_create_pthread(t_data_philo *t_data, pthread_t *monitor)
{
	int	i;

	i = 0;
	while (i < t_data->num_philo)
	{
		if (pthread_create(&t_data->philos[i].thread,
				NULL, &philo_routine, &t_data->philos[i]) != 0)
		{
			free(t_data->forks);
			free(t_data->philos);
			printf("FILED TO CREATE IN THREAD\n");
			return (false);
		}
		i++;
	}
	if (pthread_create(monitor, NULL, monitor_death, t_data) != 0)
		return (printf("FAILED TO CREATE MONITOR THREAD\n"), false);
	return (true);
}

bool	ft_joind_pthread(t_data_philo *data, pthread_t monitor)
{
	int	i;

	i = 0;
	if (pthread_join(monitor, NULL) != 0)
		return (printf("FILED TO JOIND MONITOR\n"), false);
	while (i < data->num_philo)
	{
		if (pthread_join(data->philos[i].thread, NULL) != 0)
		{
			free(data->forks);
			free(data->philos);
			printf("FILED TO JOIND THREAD\n");
			return (false);
		}
		i++;
	}
	return (true);
}

void	destroy_simulation_data(t_data_philo *data)
{
	short	i;

	i = 0;
	while (i < data->num_philo)
		pthread_mutex_destroy(&data->forks[i++]);
	free(data->forks);
	free(data->philos);
}
