/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor_death.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybounite <ybounite@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 13:05:57 by ybounite          #+#    #+#             */
/*   Updated: 2025/05/29 14:52:07 by ybounite         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	print_new_time_to_died(t_data_philo *data)
{
	printf("%lld  %d died\n", get_time() - data->start_time, data->philos->id);
}

void	handle_philosopher_death(t_data_philo *data)
{
	pthread_mutex_lock(&data->death_lock);
	if (!data->someone_died)
	{
		print_new_time_to_died(data);
		data->someone_died = true;
	}
	pthread_mutex_unlock(&data->meal_lock);
	pthread_mutex_unlock(&data->death_lock);
}

void	*monitor_death(void	*arg)
{
	t_data_philo	*data;
	int				i;

	data = (t_data_philo *)arg;
	printf("===> monitor number of ohilo %d <===\n", data->num_philo);
	while (!data->someone_died)
	{
		i = 0;
		while (i < data->num_philo)
		{
			pthread_mutex_lock(&data->meal_lock);
			if (get_time() - data->philos[i].last_meal > data->time_to_die)
			{
				handle_philosopher_death(data);
				return (NULL);
			}
			pthread_mutex_unlock(&data->meal_lock);
			i++;
		}
		usleep(1000);
	}
	return (NULL);
}
