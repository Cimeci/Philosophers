/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inowak-- <inowak--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 10:01:40 by inowak--          #+#    #+#             */
/*   Updated: 2025/02/28 09:33:34 by inowak--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	main(int argc, char **argv)
{
	t_philo	*philo;
	t_times *times;

	times = NULL;
	philo = NULL;
	if (argc < 5 || argc > 6)
		ft_puterror("./philosophers nb nb nb nb [nb]\n", 1);
	times = malloc(sizeof(t_times));
	if (!times)
	{
		ft_puterror("Error: malloc failed\n", 1);
		return (0);
	}
	philo = malloc(sizeof(t_philo));
	if (!philo)
	{
		free(times);
		ft_puterror("Error: malloc failed\n", 1);
		return (0);
	}
	check_input(argv);
	times = ft_init_time(times, argc, argv);
	philo = ft_init_philo(philo, times);
	process(philo, times);
	clean_all(philo);
}