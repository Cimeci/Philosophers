/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitoring.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inowak-- <inowak--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 17:16:17 by inowak--          #+#    #+#             */
/*   Updated: 2025/02/25 16:54:25 by inowak--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

// void	monitoring(t_data *data)
// {
// 	time_t current_time;
// 	int i;

// 	i = 0;
// 	current_time = get_time_in_ms();
// 	while (1)
// 	{
// 		i = 0;
// 		while (i < data->nb_philos)
// 		{
// 			// printf("monitoring: %lld\n", current_time - data->philo->last_meal);
// 			if (current_time - data->philo[i].last_meal > data->t_die)
// 			{
// 				data->simulation_running = false;
// 				return ;
// 			}
// 			i++;
// 		}
// 	}
// 	usleep(1000);
// }