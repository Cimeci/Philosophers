/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inowak-- <inowak--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 09:57:37 by inowak--          #+#    #+#             */
/*   Updated: 2025/03/01 16:55:23 by inowak--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <pthread.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/time.h>
# include <unistd.h>

enum				e_msg
{
	FORK,
	EAT,
	DIE,
	SLEEP,
	THINK,
};

struct s_philo;

typedef struct s_run
{
	pthread_mutex_t	die;
	bool			simulation_running;
}					t_run;

typedef struct s_times
{
	size_t			nb_philos;
	size_t			nb_must_eat;
	time_t			t_die;
	time_t			t_eat;
	time_t			t_sleep;
}					t_times;

typedef struct s_philo
{
	t_times			*times;
	t_run			*run;

	time_t			start_time;
	time_t			last_meal;
	int				id;

	pthread_mutex_t	eat;
	pthread_mutex_t	write;
	pthread_mutex_t	fork;
	pthread_t		thread;

	struct s_philo	*next;
	struct s_philo	*prev;
}					t_philo;

# include "tools/tools.h"

// error //

void				ft_puterror(char *msg, int info);

// unique_philo //

void				unique_philo(t_philo *philo);

// init //

t_times				*ft_init_time(t_times *times, int argc, char **argv);
t_run				*ft_init_run(void);
t_philo				*ft_init_philo(t_philo *philo, t_times *times, t_run *run);

//	process //

void				process(t_philo *philo, t_times *times);

// clean //

void				clean_all(t_philo *philo, t_run *run, t_times *times);

// parsing //

void				check_int(t_times times);
void				check_input(char **argv);

// sleep_check //

int					sleep_check(t_philo *philo, time_t sleep_time);

// routine //

time_t				get_time_in_ms(void);
void				write_msg(t_philo *philo, char *msg);
void				ft_eat(t_philo *philo);
void				ft_sleep(t_philo *philo);
void				ft_think(t_philo *philo);
void				ft_die(t_philo *philo);
int					ft_check_die(t_philo *philo);
void				*routine(void *arg);

// brother //

void				brother(t_philo *philo);

// monitoring //

void				monitoring(t_philo *philo);
void				monitoring_limit(t_philo *philo);

#endif