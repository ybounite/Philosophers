/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_time.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybounite <ybounite@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 13:04:25 by ybounite          #+#    #+#             */
/*   Updated: 2025/05/29 15:39:15 by ybounite         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long long	get_time(void)
{
	struct timeval	tv;	

	gettimeofday(&tv, NULL);
	return ((tv.tv_sec * 1000) + (tv.tv_usec / 1000));
}

void	safe_usleep(t_philosopher *philo, long long time)
{
	long long	start_time;

	start_time = get_time();
	while (!check_death(philo) && (get_time() - start_time) < time)
	{
		if (check_death(philo))
			return ;
		usleep(50);
	}
}
