/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inowak-- <inowak--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 10:14:42 by inowak--          #+#    #+#             */
/*   Updated: 2025/03/04 18:24:54 by inowak--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

t_times	*ft_init_time(t_times *times, int argc, char **argv)
{
	times->nb_philos = ft_atoi(argv[1]);
	times->t_die = ft_atoi(argv[2]);
	times->t_eat = ft_atoi(argv[3]);
	times->t_sleep = ft_atoi(argv[4]);
	times->nb_must_eat = -1;
	if (argc == 6)
	{
		times->nb_must_eat = ft_atoi(argv[5]);
		if (!times->nb_must_eat)
		{
			free(times);
			ft_puterror("Error1 : input false\n", 0);
			return (NULL);
		}
	}
	if (!times->nb_philos || !times->t_die || !times->t_eat || !times->t_sleep)
	{
		free(times);
		ft_puterror("Error : input false\n", 0);
		return (NULL);
	}
	times->time = get_time_in_ms() + times->nb_philos * 20;
	return (times);
}

t_run	*ft_init_run(void)
{
	t_run	*run;

	run = malloc(sizeof(t_run));
	if (!run)
		return (NULL);
	if (pthread_mutex_init(&run->die, NULL))
		return (NULL);
	if (pthread_mutex_init(&run->write, NULL))
		return (NULL);
	run->simulation_running = true;
	return (run);
}

void	init_new_philo(t_philo *new, t_times *times, t_run *run, size_t i)
{
	new->nb_eat = 0;
	new->times = times;
	new->run = run;
	new->last_meal = get_time_in_ms();
	new->id = i + 1;
}

t_philo	*ft_init_philo(t_philo *philo, t_times *times, t_run *run)
{
	t_philo	*cur;
	t_philo	*new;
	size_t	i;

	i = 0;
	philo = NULL;
	cur = philo;
	while (i < times->nb_philos)
	{
		new = (t_philo *)ft_lstnew_generic(sizeof(t_philo));
		if (!new)
			return (NULL);
		init_new_philo(new, times, run, i);
		if (pthread_mutex_init(&new->fork, NULL))
			return (NULL);
		if (pthread_mutex_init(&new->eat, NULL))
			return (NULL);
		ft_lstadd_back(&cur, new);
		i++;
	}
	new->next = cur;
	cur->prev = new;
	return (cur);
}
