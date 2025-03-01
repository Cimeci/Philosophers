/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inowak-- <inowak--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 10:14:42 by inowak--          #+#    #+#             */
/*   Updated: 2025/03/01 17:19:41 by inowak--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

t_times	*ft_init_time(t_times *times, int argc, char **argv)
{
	times->nb_philos = ft_atoi(argv[1]);
	times->t_die = ft_atoi(argv[2]);
	times->t_eat = ft_atoi(argv[3]);
	times->t_sleep = ft_atoi(argv[4]);
	times->nb_must_eat = 0;
	if (argc == 6)
	{
		times->nb_must_eat = ft_atoi(argv[5]);
		if (!times->nb_must_eat)
		{
			free(times);
			ft_puterror("Error1 : input false\n", 1);
			return (NULL);
		}
	}
	if (!times->nb_philos || !times->t_die || !times->t_eat || !times->t_sleep)
	{
		free(times);
		ft_puterror("Error2 : input false\n", 1);
		return (NULL);
	}
	printf("\033[1;32m-----INPUT-----\033[0m\n");
	printf("nb_philos :%zu\n", times->nb_philos);
	printf("t_die :%ld\n", times->t_die);
	printf("t_eat :%ld\n", times->t_eat);
	printf("t_sleep :%ld\n", times->t_sleep);
	printf("nb_must_eat :%zu\n", times->nb_must_eat);
	return (times);
}

t_run	*ft_init_run(void)
{
	t_run	*run;

	run = malloc(sizeof(t_run));
	if (!run)
		return (NULL);
	pthread_mutex_init(&run->die, NULL);
	run->simulation_running = true;
	return (run);
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
		new->times = times;
		new->last_meal = get_time_in_ms();
		new->id = i + 1;
		new->run = run;
		if (pthread_mutex_init(&new->write, NULL))
			return (NULL);
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
