/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 10:14:42 by inowak--          #+#    #+#             */
/*   Updated: 2025/02/06 19:29:48 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

t_args  *ft_init_args(int argc, char **argv)
{
	t_args  *args;

	args = malloc(sizeof(t_args));
	
	args->nb_philos = ft_atoi(argv[1]);
	args->t_die = ft_atoi(argv[2]);
	args->t_eat = ft_atoi(argv[3]);
	args->t_sleep = ft_atoi(argv[4]);
	if (argc == 6)
	{
		args->nb_must_eat = ft_atoi(argv[5]);
		if (args->nb_must_eat == -1)
		{
			free(args);
			ft_puterror("Error : Overflow int max\n", 1);
		}
	}
	if (args->nb_philos == -1 || args->t_die == -1 ||
		args->t_eat == -1 || args->t_sleep == -1)
	{
		free(args);
		ft_puterror("Error : Overflow int max\n", 1);
	}
	args->stop_simulation = 0;
	pthread_mutex_init(&args->stop_mutex, NULL);
	args->meal_count = 0;
	pthread_mutex_init(&args->meals_mutex, NULL);
	return (args);
}

