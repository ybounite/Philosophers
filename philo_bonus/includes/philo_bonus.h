/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybounite <ybounite@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 15:18:22 by ybounite          #+#    #+#             */
/*   Updated: 2025/06/02 14:45:24 by ybounite         ###   ########.fr       */
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
# include <signal.h>

# define NC "\e[0m"
# define YELLOW "\e[1;33m"
# define RED "\e[1;31m"
# define GREEN "\e[1;32m"
# define BLUE "\e[1;34m"
# define WHITE "\e[1;37m"
# define PHILO_DONE_MSG "\e[1;32mAll philosophers has taking there meals\n"
# define ALLOC 1
# define CLEAR 0

typedef struct s_data_
{
	int					num_philo;
	int					time_to_die;
	int					time_to_eat;
	int					time_to_sleep;
	int					num_of_must_eat;
	bool				is_error;
	long long			start_time;
	sem_t				*sm_forks;
	sem_t				*sm_print;
	sem_t				*sm_meals;
	sem_t				*if_dead;
	sem_t				*sm_dead;
	struct s_philo		*philos;
}						t_data_;

typedef struct s_philo
{
	int					id;
	pid_t				pid;
	int					meals_eaten;
	long long			last_meal;
	bool				is_alive;
	sem_t				*sm_is_dead;
	t_data_				*data;
}						t_philosopher;

typedef struct st_mutex_
{
	sem_t	*sm_meals_eat;
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
t_data_					*parsing(int arc, char **arv);
void					data_init(t_data_ *t_data, int arc, char **arv);
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
/*                            init_data.c                                    */
/* ------------------------------------------------------------------------- */
bool					init_simulation_data(t_data_ *data);
bool					init_semaphores(t_data_ *data);
bool					init_philosophers(t_data_ *data);
t_mutex_				*ft_sem_(void);
/* ------------------------------------------------------------------------- */
/*                            start_simulation.c                             */
/* ------------------------------------------------------------------------- */
bool					start_simulation(t_data_ *data);
bool					wait_child_process(pid_t *pids, t_data_ *data);
/* ------------------------------------------------------------------------- */
/*                            philo_routine.c                                */
/* ------------------------------------------------------------------------- */
void					routine_philosopher(t_philosopher *philo);
void					philo_sleep(t_philosopher *philo);
void					philo_think(t_philosopher *philo);
/* ------------------------------------------------------------------------- */
/*                            monutor_death.c                                */
/* ------------------------------------------------------------------------- */
void					*monitor_death(void	*args);
int						check_death(t_philosopher *philo);
/* ------------------------------------------------------------------------- */
/*                            eating_process.c                               */
/* ------------------------------------------------------------------------- */
void					philo_eat(t_philosopher *philo);
void					print_action(t_philosopher *philo, char *messag);
/* ------------------------------------------------------------------------- */
/*                            destroy.c                                      */
/* ------------------------------------------------------------------------- */
void					destroy_close_(t_data_ *data);
void					ft_sem_unlink(void);

#endif