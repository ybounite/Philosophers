/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybounite <ybounite@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 15:18:22 by ybounite          #+#    #+#             */
/*   Updated: 2025/05/31 14:35:18 by ybounite         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_BONUS_H
# define PHILO_BONUS_H

# include <stdio.h>
# include <unistd.h>
# include <string.h>
# include <stdlib.h>
# include <stdbool.h>
# include <fcntl.h> 
# include <pthread.h>
# include <sys/types.h>
# include <sys/time.h>
# include <semaphore.h>
# include "../includes/allocation_manager.h"
# include <sys/wait.h>


# define NC "\e[0m"
# define YELLOW "\e[1;33m"
# define RED "\e[1;31m"
# define GREEN "\e[1;32m"
# define BLUE "\e[1;34m"
# define WHITE "\e[1;37m"
# define PHILO_DONE_MSG "All philoscd has taking there meals\n"

typedef struct s_data_philo		t_data_philo;
typedef struct s_philosopher	t_philosopher;

typedef struct s_philosopher
{
	int					id;
	pthread_t			thread;
	int					meals_eaten;
	long long			last_meal;
	sem_t				*forks;
	sem_t				*print;
	t_data_philo		*data;
}						t_philosopher;

typedef struct s_data_philo
{
	int					num_philo;
	int					time_to_die;
	int					time_to_eat;
	int					time_to_sleep;
	int					num_of_must_eat;
	bool				is_error;
	bool				someone_died;
	long long			start_time;
	sem_t				*is_died;
	sem_t				*forks;
	sem_t				*print;
	t_philosopher		*philos;
}						t_data_philo;

/* ------------------------------------------------------------------------- */
/*                            ft_utlis.c                                     */
/* ------------------------------------------------------------------------- */
bool					ft_isdigit(int c);
int						ft_atoi(char *str);
bool					ft_isemtystr(char *str);
/* ------------------------------------------------------------------------- */
/*                            parsing.c                                      */
/* ------------------------------------------------------------------------- */
bool					parsing(t_data_philo *t_data, int arc, char **arv);
void					data_init(t_data_philo *t_data, int arc, char **arv);

/* ------------------------------------------------------------------------- */
/*                           syntax_error.c                                  */
/* ------------------------------------------------------------------------- */
void					ft_putstre(char *str);
bool					check_isdigit(char *str);
void					syntax_error(short option);
bool					check_syntax_error(int arc, char **arv);
/* ------------------------------------------------------------------------- */
/*                            get_time.c                                     */
/* ------------------------------------------------------------------------- */
long long				get_time(void);
void					safe_usleep(t_philosopher *philo, long long time);

bool					init_data_philo(t_data_philo *data);

#endif