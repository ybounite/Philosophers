/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybounite <ybounite@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 19:54:58 by ybounite          #+#    #+#             */
/*   Updated: 2025/05/29 16:00:51 by ybounite         ###   ########.fr       */
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
# include <sys/time.h>
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
	pthread_mutex_t		*left_fork;
	pthread_mutex_t		*right_fork;
	pthread_mutex_t		meals_lock;
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
	pthread_mutex_t		*forks;
	t_philosopher		*philos;
	pthread_mutex_t		write_lock;
	pthread_mutex_t		meal_lock;
	pthread_mutex_t		death_lock;
}						t_data_philo;

typedef struct s_mutex_
{
	pthread_mutex_t		st_mutex_;
	pthread_mutex_t		write_lock;
	pthread_mutex_t		meal_lock;
	pthread_mutex_t		death_lock;
}	t_mutex_;

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

/* ------------------------------------------------------------------------- */
/*                            manager_thread.c                               */
/* ------------------------------------------------------------------------- */
bool					ft_joind_pthread(t_data_philo *data, pthread_t monitor);
void					destroy_simulation_data(t_data_philo *data);
bool					ft_create_pthread(t_data_philo *t_data,
							pthread_t *monitor);

/* ------------------------------------------------------------------------- */
/*                            philo_routine.c                                */
/* ------------------------------------------------------------------------- */
void					*philo_routine(void *arg);
void					print_action(t_philosopher *philo, const char *action);
void					*monitor_death(void	*arg);

/* ------------------------------------------------------------------------- */
/*                            monitor_death.c                                */
/* ------------------------------------------------------------------------- */
void					*monitor_death(void	*arg);
void					print_new_time_to_died(t_data_philo *data);
void					handle_philosopher_death(t_data_philo *data);

/* ------------------------------------------------------------------------- */
/*                            init_data.c                                    */
/* ------------------------------------------------------------------------- */
bool					init_forks(t_data_philo *data);
bool					init_data_philo(t_data_philo *data);
bool					init_philosophers(t_data_philo *data);
bool					init_mutex(t_data_philo *data);
t_mutex_				*ft_mutex_(void);
/* ------------------------------------------------------------------------- */
/*                            eating_process.c                               */
/* ------------------------------------------------------------------------- */
void					eat_philo(t_philosopher	*philo);
bool					check_death(t_philosopher *philo);
void					manager_eating(t_philosopher *philo);

#endif