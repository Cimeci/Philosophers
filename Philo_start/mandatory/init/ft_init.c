/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inowak-- <inowak--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 10:14:42 by inowak--          #+#    #+#             */
/*   Updated: 2025/02/25 16:58:31 by inowak--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

t_times	*ft_init_time(int argc, char **argv)
{
	t_times	*times;

	times = malloc(sizeof(t_times));
	if (!times)
		return (ft_puterror("Error: malloc failed\n", 1), NULL);
	times->nb_philos = ft_atoi(argv[1]);
	times->t_die = ft_atoi(argv[2]);
	times->t_eat = ft_atoi(argv[3]);
	times->t_sleep = ft_atoi(argv[4]);
	if (argc == 6)
	{
		times->nb_must_eat = ft_atoi(argv[5]);
		if (!times->nb_must_eat)
		{
			free(times);
			ft_puterror("Error1 : input false\n", 1);
		}
	}
	if (!times->nb_philos || !times->t_die || !times->t_eat || !times->t_sleep)
	{
		free(times);
		ft_puterror("Error2 : input false\n", 1);
	}
	times->start_time = get_time_in_ms();
	times->simulation_running = true;
	return (times);
}

// void	ft_init_philo(t_time *time)
// {
// 	t_philo		philosophers[200];
// 	pthread_t	threads[200];

// 	while ()
// 		create() monitor() while () join
// }
void	process(t_times times)
{
	int			i;
	int			j;
	t_philo		*philo;

	i = 0;
	j = 1;
	philo = malloc(sizeof(t_philo) * times.nb_philos);
	if (!philo)
		return ; // free en cas d'erreur
	if (times.nb_philos == 1)
	{
		unique_philo(philo);
		return ;
	}
	while (i < times.nb_philos)
	{
		
		philo[i].last_meal = get_time_in_ms();
		pthread_mutex_init(&philo[i].left_fork, NULL); // a check
		philo[i].id = i + 1;
		printf("left_fork: j: %d | i: %d\n", j, i);
		if (j == times.nb_philos)
		{
			philo[i].right_fork = philo[0].left_fork;
			printf("right_fork: j: %d | i: %d\n", 0, i);
		}
		else
		{
			philo[i].right_fork = philo[j].left_fork;
			printf("right_fork: j: %d | i: %d\n", j, i);
		}
		j++;
		printf("create thread\n");
		if (pthread_create(&philo[i].thread, NULL, routine, &philo[i]))
			return ;
		i++;
	}
}
