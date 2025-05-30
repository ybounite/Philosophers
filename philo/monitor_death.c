/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor_death.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybounite <ybounite@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 13:05:57 by ybounite          #+#    #+#             */
/*   Updated: 2025/05/30 09:56:06 by ybounite         ###   ########.fr       */
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
	pthread_mutex_unlock(&data->death_lock);
	pthread_mutex_unlock(&data->meal_lock);
}

bool	meals_checker(t_data_philo *data)
{
	int	i;

	i = 0;
	while (i < data->num_philo)
	{
		if (data->philos->meals_eaten == data->num_of_must_eat)
		{
			printf("all philo is eating \n");
			pthread_mutex_lock(&data->death_lock);
			data->someone_died = true;
			pthread_mutex_unlock(&data->death_lock);
			return (true);
		}
		i++;
	}
	return (false);
}

void	*monitor_death(void	*arg)
{
	t_data_philo (*data);
	int (i);
	data = (t_data_philo *)arg;
	while (true)
	{
		pthread_mutex_lock(&data->death_lock);
		if (data->someone_died)
			return (NULL);
		pthread_mutex_unlock(&data->death_lock);
		if (meals_checker(data))
			return (NULL);
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
