/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybounite <ybounite@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 15:20:15 by ybounite          #+#    #+#             */
/*   Updated: 2025/05/31 14:35:31 by ybounite         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/philo_bonus.h"

void	philo_eat(t_philosopher *philo)
{
	sem_wait(philo->forks);
	sem_wait(philo->forks);

	sem_wait(philo->print);
	printf("%lld %d has taken a fork\n", get_time() - philo->data->start_time, philo->id);
	printf("%lld %d has taken a fork\n", get_time() - philo->data->start_time, philo->id);
	printf("%lld %d is eating\n", get_time() - philo->data->start_time, philo->id);
	sem_post(philo->print);

	philo->last_meal = get_time();
	philo->meals_eaten++;
	usleep(philo->data->time_to_eat * 1000);

	sem_post(philo->forks);
	sem_post(philo->forks);
}

void	philo_think(t_philosopher *philo)
{
	sem_wait(philo->print);
	printf("%lld %d is thinking\n", get_time() - philo->data->start_time, philo->id);
	sem_post(philo->print);
}

void	philo_sleep(t_philosopher *philo)
{
	sem_wait(philo->print);
	printf("%lld %d is sleeping\n", get_time() - philo->data->start_time, philo->id);
	sem_post(philo->print);
	usleep(philo->data->time_to_sleep * 1000);
}

void	philosopher_routine(t_philosopher *philo)
{
	while (!philo->data->someone_died)
	{
		philo_think(philo);
		philo_eat(philo);
		philo_sleep(philo);
	}
}

bool philo(t_data_philo *data, pid_t *pids)
{
	int	i = 0;
	while (i < data->num_philo)
	{
		pids[i] = fork();
		if (pids[i] == -1)
			return (ft_putstre("Error: fork failed\n"), false);
		if (pids[i] == 0)
		{
			philosopher_routine(&data->philos[i]); // Call philosopher routine
			exit(EXIT_SUCCESS);
		}
		i++;
	}
	i = 0;
	while (!(waitpid(pids[i], NULL, 0)))
		i++;
	return (true);
}

int	main(int arc, char **arv)
{
	t_data_philo	data;
	pid_t			*pids;

	memset(&data, false, sizeof(t_data_philo));
	if (arc != 5 && arc != 6)
		return (syntax_error(1), EXIT_FAILURE);
	parsing(&data, arc, arv);
	if (data.is_error)
		return (EXIT_FAILURE);
	if (data.num_of_must_eat == false)
		return (printf(PHILO_DONE_MSG), EXIT_SUCCESS);
	pids = ft_malloc(sizeof(pid_t) * data.num_philo, true);
	if (!pids)
		return (ft_putstre("FILAD MALLOC"), EXIT_FAILURE);	
	if (init_data_philo(&data))
		return (EXIT_FAILURE);
	if (!philo(&data, pids))
		return (EXIT_FAILURE);
	ft_malloc(false, false);
	return (EXIT_SUCCESS);
}
