/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybounite <ybounite@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/18 15:59:33 by ybounite          #+#    #+#             */
/*   Updated: 2025/05/21 17:00:14 by ybounite         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

bool	ft_isdigit(int c)
{
	return ('0' <= c && '9' >= c);
}

bool	check_isdigit(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (i == 0 && (str[0] == '+'|| str[0] == '-'))
			i++;
		if (!ft_isdigit(str[i]))
			return (syntax_error(2), true);
		i++;
	}
	if (i == false)
		return (syntax_error(2), true);
	return (false);
}

bool	ft_isemtystr(char *str)
{
	return (*str == '\0');
}

bool	check_syntax_error(int arc, char **arv)
{
	int	i;

	i = 1;
	while (i < arc)
	{
		if (check_isdigit(arv[i]) || ft_isemtystr(arv[i]))
			return (true);
		i++;	
	}
	return (false);
}

void	data_init(t_data_philo *t_data, int arc, char **arv)
{
	t_data->number_of_philos = ft_atoi(arv[1]);
	t_data->time_to_die = ft_atoi(arv[2]);
	t_data->time_to_eat = ft_atoi(arv[3]);
	t_data->time_to_sleep = ft_atoi(arv[4]);
	t_data->number_of_times_each_philos_must_eat = -1;
	if (arc == 6)
		t_data->number_of_times_each_philos_must_eat = ft_atoi(arv[5]);
	if (t_data->number_of_philos < 0 || t_data->time_to_die < 0
		|| t_data->time_to_eat < 0 || t_data->time_to_sleep < 0)
	{
		syntax_error(2);
		t_data->is_error = true;
	}
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

int	main(int arc, char **arv)
{
	t_data_philo	t_data;

	memset(&t_data, false, sizeof(t_data));
	if (arc != 5 && arc != 6)
		return (syntax_error(1), true);
	parsing(&t_data, arc, arv);
	printf("is error : %d\n", t_data.is_error);
	if (t_data.is_error)
		return (true);
	printf ("number of philosophers\t\t\t : %d\n", t_data.number_of_philos);
	printf("time to die\t\t\t\t : %d\n", t_data.time_to_die);
	printf("time to eat\t\t\t\t : %d\n", t_data.time_to_eat);
	printf("time to sleep\t\t\t\t : %d\n", t_data.time_to_sleep);
	printf("number of times each philosopher must eat: %d\n", t_data.number_of_times_each_philos_must_eat);
	return (false);
}
