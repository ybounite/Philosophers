/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybounite <ybounite@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 15:20:15 by ybounite          #+#    #+#             */
/*   Updated: 2025/06/02 15:20:48 by ybounite         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo_bonus.h"

int	main(int arc, char **arv)
{
	t_data_	*data;

	if (arc != 5 && arc != 6)
		return (syntax_error(1), EXIT_FAILURE);
	data = parsing(arc, arv);
	if (data->is_error)
		return (EXIT_FAILURE);
	if (data->num_of_must_eat == false)
		return (printf(PHILO_DONE_MSG), EXIT_SUCCESS);
	if (init_simulation_data(data))
		return (EXIT_FAILURE);
	if (!start_simulation(data))
		return (destroy_close_(data), EXIT_FAILURE);
	ft_malloc(false, false);
	return (EXIT_SUCCESS);
}
