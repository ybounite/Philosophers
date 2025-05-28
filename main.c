/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybounite <ybounite@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/18 15:59:33 by ybounite          #+#    #+#             */
/*   Updated: 2025/05/28 15:18:37 by ybounite         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

bool	ft_create_pthread(t_data_philo *t_data)
{
	int	i;

	i = 0;
	while (i < t_data->number_of_philos)
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
	return (true);
}

bool	ft_joind_pthread(t_data_philo *data)
{
	int	i;

	i = 0;
	while (i < data->number_of_philos)
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

void	ft_destroy(t_data_philo *data)
{
	short	i;

	i = 0;
	while (i < data->number_of_philos)
		pthread_mutex_destroy(&data->forks[i++]);
	// pthread_mutex_destroy(&data->write_lock);
	free(data->forks);
	free(data->philos);
}

bool	init_mutex(t_data_philo *data, pthread_t *monitor)
{
	pthread_mutex_init(&data->write_lock, NULL);
	pthread_mutex_init(&data->time, NULL);
	pthread_mutex_init(&data->death_mutex, NULL);
	pthread_mutex_init(&data->times_eaten_mutex, NULL);
	if (pthread_create(monitor, NULL, monitor_death, &data) != 0)
		return (printf("FAILED TO CREATE MONITOR THREAD\n"), true);
}

int	main(int arc, char **arv)
{
	t_data_philo	data;
	pthread_t		monitor;

	memset(&data, false, sizeof(data));
	if (arc != 5 && arc != 6)
		return (syntax_error(1), EXIT_FAILURE);
	parsing(&data, arc, arv);
	if (data.is_error)
		return (EXIT_FAILURE);
	if (data.num_of_must_eat == 0)
		return (printf(PHILO_DONE_MSG), EXIT_SUCCESS);
	if (init_data_philo(&data))
		return (EXIT_FAILURE);
	// init_mutex(&data, &monitor);
	if (!ft_create_pthread(&data))
		return (EXIT_FAILURE);
	if (pthread_join(monitor, NULL) != 0)
		return (printf("FILED TO JOIND MONITOR\n"), EXIT_FAILURE);
	if (!ft_joind_pthread(&data))
		return (EXIT_FAILURE);
	ft_destroy(&data);
	return (EXIT_SUCCESS);
}
