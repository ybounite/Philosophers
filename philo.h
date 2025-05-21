/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybounite <ybounite@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 19:54:58 by ybounite          #+#    #+#             */
/*   Updated: 2025/05/21 16:31:36 by ybounite         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <unistd.h>
# include <string.h>
# include <stdlib.h>
# include <stdbool.h>
// for to create in thread
# include <pthread.h>
// for to create in child process 
# include <sys/types.h>
# include <sys/wait.h>
# include "allocation_manager.h"


# define NC "\e[0m"
# define YELLOW "\e[1;33m"
# define RED "\e[1;31m"
# define GREEN "\e[1;32m"
# define BLUE "\e[1;34m"
# define WHITE "\e[1;37m"

// typedef struct	s_list
// {
// 	void			*value;
// 	struct s_list	*next;
// }	t_list;

typedef struct	s_data_philo
{
	int		number_of_philos;
	int		time_to_die;
	int		time_to_eat;
	int		time_to_sleep;
	int		number_of_times_each_philos_must_eat;
	bool	is_error;
}			t_data_philo;

int			ft_atoi(char *str);
void		syntax_error(short option);


#endif