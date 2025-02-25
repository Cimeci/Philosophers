/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inowak-- <inowak--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 09:57:37 by inowak--          #+#    #+#             */
/*   Updated: 2025/02/25 17:01:40 by inowak--         ###   ########.fr       */
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

struct s_philo;

typedef struct s_times
{
	int				nb_philos;
	int				nb_must_eat;
	time_t			t_die;
	time_t			t_eat;
	time_t			t_sleep;
	time_t			start_time;
	bool			simulation_running;
}					t_times;

typedef struct s_philo
{
	t_times			*times;
	time_t			last_meal;
	int				id;

	pthread_mutex_t	die;
	pthread_mutex_t	write;
	pthread_mutex_t	left_fork;
	pthread_mutex_t	right_fork;
	pthread_t		thread;
}					t_philo;

# include "tools/tools.h"

// error //

void				ft_puterror(char *msg, int info);

// unique_philo //

void				unique_philo(t_philo philo);

// init //

t_times				*ft_init_time(int argc, char **argv);
void				process(t_times times);
void				check_int(t_times times);

// clean //

// void				clean_all(t_philo );

// parsing //

void				check_input(char **argv);

// routine //

long long			get_time_in_ms(void);
void				*routine(void *arg);

// brother //

void				brother(t_times *times);

// monitoring //

void				monitoring(t_times *times);

#endif