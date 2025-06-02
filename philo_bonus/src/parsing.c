/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybounite <ybounite@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 19:51:28 by ybounite          #+#    #+#             */
/*   Updated: 2025/06/02 11:19:51 by ybounite         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/philo_bonus.h"

void	data_init(t_data_ *t_data, int arc, char **arv)
{
	t_data->num_philo = ft_atoi(arv[1]);
	t_data->time_to_die = ft_atoi(arv[2]);
	t_data->time_to_eat = ft_atoi(arv[3]);
	t_data->time_to_sleep = ft_atoi(arv[4]);
	if (t_data->num_philo < 0 || t_data->time_to_die < 0
		|| t_data->time_to_eat < 0 || t_data->time_to_sleep < 0)
	{
		syntax_error(2);
		t_data->is_error = true;
		return ;
	}
	t_data->num_of_must_eat = -1;
	if (arc == 6)
	{
		t_data->num_of_must_eat = ft_atoi(arv[5]);
		if (t_data->num_of_must_eat < 0)
		{
			syntax_error(2);
			t_data->is_error = true;
		}
	}
}

t_data_	*parsing(int arc, char **arv)
{
	t_data_	*t_data;

	t_data = ft_malloc(sizeof(t_data_), ALLOC);
	memset(t_data, 0, sizeof(t_data_));
	if (check_syntax_error(arc, arv))
		return (t_data->is_error = true, t_data);
	data_init(t_data, arc, arv);
	if (t_data->num_philo == 0)
	{
		t_data->is_error = true;
		return (syntax_error(3), t_data);
	}
	if (t_data->time_to_die == 0 || t_data->time_to_eat == 0
		|| t_data->time_to_sleep == 0)
	{
		(t_data->is_error = true);
		ft_putstre(RED"0 : should be more than zero"NC);
	}
	return (t_data);
}
