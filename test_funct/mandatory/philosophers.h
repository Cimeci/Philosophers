/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 09:57:37 by inowak--          #+#    #+#             */
/*   Updated: 2025/02/06 19:29:31 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <string.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/time.h>
# include <pthread.h>

# include "tools/tools.h"

typedef struct s_args
{
    int                 nb_philos;
    int                 t_die;
    int                 t_eat;
    int                 t_sleep;
    int                 nb_must_eat;
    pthread_mutex_t     *forks;
    pthread_mutex_t     stop_mutex;
    pthread_mutex_t     meals_mutex;
    int                 stop_simulation;
    int                 meal_count;
}   t_args;


typedef struct s_philo
{
	int				id;
	int				meals_eaten;
	t_args			*args;
}	t_philo;



// error //

void    ft_puterror(char *msg, int info);

// init //

t_args  *ft_init_args(int argc, char **argv);
void    check_int(t_args *args);

// parsing //

void    check_input(char **argv);

#endif