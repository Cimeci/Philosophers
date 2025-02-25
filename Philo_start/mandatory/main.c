/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inowak-- <inowak--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 10:01:40 by inowak--          #+#    #+#             */
/*   Updated: 2025/02/25 17:01:57 by inowak--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	main(int argc, char **argv)
{

	t_times times;

	if (argc < 5 || argc > 6)
		ft_puterror("./philosophers nb nb nb nb [nb]\n", 1);
	check_input(argv);
	times = *ft_init_time(argc, argv);
	check_int(times);
	process(times);
	// brother(philo);
	// monitoring(philo);
	// clean_all(philo);
}