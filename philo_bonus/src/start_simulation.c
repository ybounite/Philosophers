/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_simulation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybounite <ybounite@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 14:36:48 by ybounite          #+#    #+#             */
/*   Updated: 2025/06/02 15:20:48 by ybounite         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo_bonus.h"

bool	wait_child_process(pid_t *pids, t_data_ *data)
{
	int (status), (count), (i);
	i = 0;
	count = 0;
	while (i < data->num_philo)
	{
		if (waitpid(pids[i], &status, 0) == -1)
		{
			ft_putstre(RED"Error waitpid\n"NC);
			destroy_close_(data);
			exit(EXIT_FAILURE);
		}
		if (WEXITSTATUS(status) == 0)
			count++;
		i++;
	}
	if (count == data->num_philo)
		printf("%sAll philosophers must eat all their meals\n"NC, GREEN);
	return (true);
}

bool	start_simulation(t_data_ *data)
{
	int		i;
	pid_t	*pids;

	i = 0;
	pids = ft_malloc(sizeof(pid_t) * data->num_philo, ALLOC);
	data->start_time = get_time();
	while (i < data->num_philo)
	{
		pids[i] = fork();
		if (pids[i] == -1)
			return (ft_putstre(GREEN"Error: fork failed\n"), false);
		if (pids[i] == 0)
		{
			routine_philosopher(&data->philos[i]);
			destroy_close_(data);
			exit(EXIT_SUCCESS);
		}
		i++;
	}
	wait_child_process(pids, data);
	return (true);
}
