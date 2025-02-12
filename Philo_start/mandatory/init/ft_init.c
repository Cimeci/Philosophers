/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inowak-- <inowak--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 10:14:42 by inowak--          #+#    #+#             */
/*   Updated: 2025/02/12 15:51:20 by inowak--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

t_args	*ft_init_args(int argc, char **argv)
{
	t_args	*args;

	args = malloc(sizeof(t_args));
	if (!args)
		return (ft_puterror("Error: malloc failed\n", 1), NULL);
	args->nb_philos = ft_atoi(argv[1]);
	args->t_die = ft_atoi(argv[2]);
	args->t_eat = ft_atoi(argv[3]);
	args->t_sleep = ft_atoi(argv[4]);
	pthread_mutex_init(&args->write_lock, NULL);
	if (argc == 6)
	{
		args->nb_must_eat = ft_atoi(argv[5]);
		if (args->nb_must_eat == -1)
		{
			free(args);
			ft_puterror("Error : Overflow int max\n", 1);
		}
	}
	if (args->nb_philos == -1 || args->t_die == -1 || args->t_eat == -1
		|| args->t_sleep == -1)
	{
		free(args);
		ft_puterror("Error : Overflow int max\n", 1);
	}
	args->start_time = get_time_in_ms();
	return (args);
}

t_philo *ft_init_philo(t_args *args)
{
    t_philo *first;
    t_philo *previous;
    int     i;
    t_philo *new;
    t_philo *current;

    first = NULL;
    previous = NULL;
    i = 0;
    while (i < args->nb_philos)
    {
        new = ft_lstnew_generic(sizeof(t_philo));
        if (!new)
            return (NULL);
        new->id = i + 1;
        new->args = args;
        new->last_meal = get_time_in_ms();
        new->meals_eaten = 0;
        new->next = NULL;
        if (pthread_mutex_init(&new->left_fork, NULL) != 0)
        {
            free(new);
            return (NULL);
        }
        if (previous)
        {
            previous->next = new;
            new->right_fork = previous->left_fork;
        }
        else
            first = new;
        previous = new;
        i++;
    }
    if (previous)
    {
        previous->next = first;
        first->right_fork = previous->left_fork;
    }

    current = first;
    i = 0;
    while (i < args->nb_philos)
    {
        if (pthread_create(&current->thread, NULL, routine, current) != 0)
            return (NULL);
        current = current->next;
        i++;
    }
    return first;
}
