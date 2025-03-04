/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inowak-- <inowak--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 10:01:40 by inowak--          #+#    #+#             */
/*   Updated: 2025/03/04 18:26:10 by inowak--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

t_times	*create_times_struct(int argc, char **argv)
{
	t_times	*times;

	times = malloc(sizeof(t_times));
	if (!times)
	{
		ft_puterror("Error: malloc failed\n", 1);
	}
	times = ft_init_time(times, argc, argv);
	if (!times)
		ft_puterror("", 1);
	return (times);
}

t_philo	*create_philo_struct(t_run *run, t_times *times)
{
	t_philo	*philo;
	t_philo	*cur;

	philo = malloc(sizeof(t_philo));
	if (!philo)
	{
		clean_all(philo, run, times);
		ft_puterror("Error: malloc failed\n", 1);
	}
	cur = ft_init_philo(philo, times, run);
	if (!cur)
	{
		clean_all(philo, run, times);
		ft_puterror("Error: init philo failed\n", 1);
	}
	free(philo);
	return (cur);
}

t_run	*create_run_struct(t_times *times)
{
	t_run	*run;

	run = ft_init_run();
	if (!run)
	{
		free(times);
		ft_puterror("Error: init run failed\n", 1);
	}
	return (run);
}

int	main(int argc, char **argv)
{
	t_philo	*cur;
	t_times	*times;
	t_run	*run;

	if (argc < 5 || argc > 6)
		ft_puterror("./philosophers nb nb nb nb [nb]\n", 1);
	check_input(argv);
	times = create_times_struct(argc, argv);
	run = create_run_struct(times);
	cur = create_philo_struct(run, times);
	process(cur, times);
	clean_all(cur, run, times);
}
