/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inowak-- <inowak--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 10:08:01 by inowak--          #+#    #+#             */
/*   Updated: 2025/02/25 16:45:24 by inowak--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <unistd.h>

long long	get_time_in_ms(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return (tv.tv_sec * 1000 + tv.tv_usec / 1000);
}

// void	ft_eat(t_philo *philo, long long current_time)
// {

// }

// void	ft_sleep(t_philo *philo, long long current_time)
// {

// }

// void	ft_think(t_philo *philo, long long current_time)
// {

// }

// void	ft_die(t_philo *philo, long long current_time)
// {
// 	if (philo->data->simulation_running == true)
// 	{
		
// 	}
// }

void	*routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	if (philo->id % 2 == 0)
		usleep(15000);
	while (1)
	{
		printf("routine\n");
		pthread_mutex_lock(&philo->die);
		if (philo->times->simulation_running == false)
		{
			printf("%lld ms | %d died\n", get_time_in_ms(), philo->id);
			pthread_mutex_unlock(&philo->die);
			return (NULL);
		}
		pthread_mutex_unlock(&philo->die);
		usleep(1000);
	}
	return (NULL);
}
