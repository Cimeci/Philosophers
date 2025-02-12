/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inowak-- <inowak--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 09:57:37 by inowak--          #+#    #+#             */
/*   Updated: 2025/02/12 15:20:18 by inowak--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <pthread.h>
# include <pthread.h>
# include <stdbool.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/time.h>
# include <unistd.h>

typedef struct s_args
{
	int				nb_philos;
	int				t_die;
	int				t_eat;
	int				t_sleep;
	int				nb_must_eat;
	// bool			simulation_running;
	pthread_mutex_t	write_lock;
	long long		start_time;
}					t_args;

typedef struct s_philo
{
	int				id;
	long long		last_meal;
	int				meals_eaten;
	t_args			*args;
	pthread_mutex_t	left_fork;
	pthread_mutex_t	right_fork;
	pthread_t		thread;
	struct s_philo	*next;
}					t_philo;

# include "tools/tools.h"

// error //

void				ft_puterror(char *msg, int info);

// init //

t_args				*ft_init_args(int argc, char **argv);
t_philo				*ft_init_philo(t_args *args);
void				check_int(t_args *args);

// clean //

void				clean_all(t_philo *philo, t_args *args);

// parsing //

void				check_input(char **argv);

// monitoring //

long long			get_time_in_ms(void);
void				*routine(void *arg);

#endif