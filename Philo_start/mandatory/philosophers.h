/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inowak-- <inowak--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 09:57:37 by inowak--          #+#    #+#             */
/*   Updated: 2024/12/20 13:34:24 by inowak--         ###   ########.fr       */
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
	int nb_philos;
	int t_die;
	int t_eat;
	int t_sleep;
	int	nb_must_eat;
}		t_args;


// error //

void    ft_puterror(char *msg, int info);

// init //

t_args  *ft_init_args(int argc, char **argv);

// parsing //

void    check_input(char **argv);

#endif