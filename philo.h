/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybounite <ybounite@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 19:54:58 by ybounite          #+#    #+#             */
/*   Updated: 2025/05/27 10:02:46 by ybounite         ###   ########.fr       */
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
#include <sys/time.h>
# include <sys/wait.h>


# define NC "\e[0m"
# define YELLOW "\e[1;33m"
# define RED "\e[1;31m"
# define GREEN "\e[1;32m"
# define BLUE "\e[1;34m"
# define WHITE "\e[1;37m"

typedef struct s_data_philo t_data_philo;
typedef struct s_philosopher t_philosopher;
typedef struct	s_philosopher
{
	int					id;
	pthread_t			thread;
	int					times_eaten;
	long long			last_meal;
	pthread_mutex_t		*left_fork;
	pthread_mutex_t		*right_fork;
	t_data_philo		*data;
}						t_philosopher;

typedef struct	s_data_philo
{
	int					number_of_philos;
	int					time_to_die;
	int					time_to_eat;
	int					time_to_sleep;
	int					num_of_must_eat;
	bool				is_error;

	long long			start_time;
	pthread_mutex_t		*forks;
	t_philosopher		*philos;
	pthread_mutex_t		write_lock;
	int					someone_died;
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
/*                            timestamp.c                                    */
/* ------------------------------------------------------------------------- */
long long				get_time(void);
void					print_action(t_philosopher *philo, const char *action);

#endif