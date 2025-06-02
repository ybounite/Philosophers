/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybounite <ybounite@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/31 11:38:23 by ybounite          #+#    #+#             */
/*   Updated: 2025/06/02 15:20:48 by ybounite         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo_bonus.h"

t_mutex_	*ft_sem_(void)
{
	static t_mutex_	_mutex_ = {0};

	return (&_mutex_);
}

bool	init_semaphores(t_data_ *data)
{
	ft_sem_unlink();
	data->sm_forks = sem_open("sem_forks", O_CREAT, 0644, data->num_philo);
	if (data->sm_forks == SEM_FAILED)
		return (ft_putstre("Error creating forks semaphore\n"), false);
	data->sm_print = sem_open("sem_print", O_CREAT, 0644, 1);
	if (data->sm_print == SEM_FAILED)
		return (ft_putstre("Error creating print semaphore\n"), false);
	data->sm_meals = sem_open("sem_meals", O_CREAT, 0644, 1);
	if (data->sm_meals == SEM_FAILED)
		return (ft_putstre("Error creating ms_meals\n"), false);
	data->sm_dead = sem_open("sem_dead", O_CREAT, 0644, 2);
	if (data->sm_dead == SEM_FAILED)
		return (ft_putstre("Error creating ms_dead\n"), false);
	data->if_dead = sem_open("if_dead", O_CREAT, 0644, 1);
	if (data->if_dead == SEM_FAILED)
		return (ft_putstre("Error creating print semaphore\n"), false);
	ft_sem_()->sm_meals_eat = sem_open("sm_meals_eat", O_CREAT, 0644, 1);
	if (ft_sem_()->sm_meals_eat == SEM_FAILED)
		return (ft_putstre(RED"Error sem meals eat\n"NC), false);
	return (true);
}

bool	init_philosophers(t_data_ *data)
{
	int (i);
	i = 0;
	data->philos = ft_malloc(sizeof(t_philosopher) * data->num_philo, ALLOC);
	while (i < data->num_philo)
	{
		data->philos[i].id = i + 1;
		data->philos[i].pid = 0;
		data->philos[i].last_meal = 0;
		data->philos[i].meals_eaten = 0;
		data->philos[i].data = data;
		i++;
	}
	return (false);
}

bool	init_simulation_data(t_data_ *data)
{
	if (init_philosophers(data))
		return (EXIT_FAILURE);
	if (!init_semaphores(data))
		return (destroy_close_(data), EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
