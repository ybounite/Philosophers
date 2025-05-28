/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor_death.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybounite <ybounite@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 13:05:57 by ybounite          #+#    #+#             */
/*   Updated: 2025/05/28 15:04:49 by ybounite         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*monitor_death(void	*arg)
{
	t_data_philo	*data;
	int				i;

	data = (t_data_philo *)arg;
	while (!data->someone_died)
	{
		i = 0;
		while (i < data->number_of_philos)
		{
			if (get_time() - data->philos[i].last_meal > data->time_to_die)
			{
				pthread_mutex_lock(&data->death_mutex);
				if (!data->someone_died)
				{
					printf("%lld  %d died\n", get_time() - data->start_time, data->philos->id);
					data->someone_died = true;
				}
				pthread_mutex_unlock(&data->death_mutex);
				return (NULL);
			}
			i++;
		}
		usleep(1000);
	}
	return (NULL);
}
