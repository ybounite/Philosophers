/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybounite <ybounite@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 19:51:28 by ybounite          #+#    #+#             */
/*   Updated: 2025/05/27 10:02:46 by ybounite         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	data_init(t_data_philo *t_data, int arc, char **arv)
{
	int	time_each_philo_eat;

	time_each_philo_eat = 0;
	t_data->number_of_philos = ft_atoi(arv[1]);
	t_data->time_to_die = ft_atoi(arv[2]);
	t_data->time_to_eat = ft_atoi(arv[3]);
	t_data->time_to_sleep = ft_atoi(arv[4]);
	t_data->num_of_must_eat = -1;
	if (arc == 6)
		time_each_philo_eat = ft_atoi(arv[5]);
	if (t_data->number_of_philos < 0 || t_data->time_to_die < 0
		|| t_data->time_to_eat < 0 || t_data->time_to_sleep < 0
		|| time_each_philo_eat < 0)
	{
		syntax_error(2);
		t_data->is_error = true;
	}
	t_data->num_of_must_eat = time_each_philo_eat;
}

bool	parsing(t_data_philo *t_data, int arc, char **arv)
{
	if (check_syntax_error(arc, arv))
		return (t_data->is_error = true, false);
	data_init(t_data, arc,arv);
	if (t_data->number_of_philos == 0)
	{
		t_data->is_error = true;
		syntax_error(3);
	}
	return (true);
}
