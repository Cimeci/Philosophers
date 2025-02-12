/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inowak-- <inowak--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 10:01:40 by inowak--          #+#    #+#             */
/*   Updated: 2025/02/12 11:01:41 by inowak--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	main(int argc, char **argv)
{
	t_args  *args;
	t_philo *philo;

	if (argc < 5 || argc > 6)
		ft_puterror("./philosophers nb nb nb nb [nb]\n", 1);
	check_input(argv);
	args = ft_init_args(argc, argv);
	philo = ft_init_philo(args);
	check_int(args);
	clean_all(philo, args);
}