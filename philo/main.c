/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybounite <ybounite@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/18 15:59:33 by ybounite          #+#    #+#             */
/*   Updated: 2025/05/31 11:06:25 by ybounite         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int arc, char **arv)
{
	t_data_philo	data;
	pthread_t		monitor;

	memset(&data, false, sizeof(t_data_philo));
	if (arc != 5 && arc != 6)
		return (syntax_error(1), EXIT_FAILURE);
	parsing(&data, arc, arv);
	if (data.is_error)
		return (EXIT_FAILURE);
	if (data.num_of_must_eat == false)
		return (printf(PHILO_DONE_MSG), EXIT_SUCCESS);
	if (init_data_philo(&data))
		return (EXIT_FAILURE);
	if (!ft_create_pthread(&data, &monitor))
		return (EXIT_FAILURE);
	if (!ft_joind_pthread(&data, monitor))
		return (EXIT_FAILURE);
	destroy_simulation_data(&data);
	return (EXIT_SUCCESS);
}
