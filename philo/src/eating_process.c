/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eating_process.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybounite <ybounite@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 15:43:52 by ybounite          #+#    #+#             */
/*   Updated: 2025/06/02 16:00:17 by ybounite         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

bool	check_death(t_philosopher *philo)
{
	pthread_mutex_lock(&philo->data->death_lock);
	if (philo->data->someone_died)
	{
		pthread_mutex_unlock(&philo->data->death_lock);
		return (true);
	}
	pthread_mutex_unlock(&philo->data->death_lock);
	return (false);
}

void	take_forks(t_philosopher *philo)
{
	if (philo->id % 2 == 0)
	{
		pthread_mutex_lock(philo->left_fork);
		pthread_mutex_lock(philo->right_fork);
		print_action(philo, "has taken a fork");
	}
	else
	{
		usleep(1000);
		pthread_mutex_lock(philo->right_fork);
		pthread_mutex_lock(philo->left_fork);
		print_action(philo, "has taken a fork");
	}
}

void	release_forks(t_philosopher *philo)
{
	if (philo->id % 2 == 0)
	{
		pthread_mutex_unlock(philo->left_fork);
		pthread_mutex_unlock(philo->right_fork);
	}
	else
	{
		pthread_mutex_unlock(philo->right_fork);
		pthread_mutex_unlock(philo->left_fork);
	}
}

void	eat_philo(t_philosopher	*philo)
{
	take_forks(philo);
	print_action(philo, "is eating");
	pthread_mutex_lock(&philo->data->meal_lock);
	philo->last_meal = get_time();
	pthread_mutex_unlock(&philo->data->meal_lock);
	pthread_mutex_lock(&ft_mutex_()->st_mutex_);
	philo->meals_eaten++;
	pthread_mutex_unlock(&ft_mutex_()->st_mutex_);
	safe_usleep(philo, philo->data->time_to_eat);
	release_forks(philo);
}

void	manager_eating(t_philosopher *philo)
{
	if (philo->data->num_philo == 1)
	{
		pthread_mutex_lock(philo->left_fork);
		print_action(philo, "has taken a fork");
		safe_usleep(philo, philo->data->time_to_die);
		pthread_mutex_lock(&philo->data->death_lock);
		philo->data->someone_died = true;
		pthread_mutex_unlock(&philo->data->death_lock);
		printf("%lld %d is died\n", get_time() - philo->data->start_time,
			philo->id);
		pthread_mutex_unlock(philo->left_fork);
	}
	else
		eat_philo(philo);
}
