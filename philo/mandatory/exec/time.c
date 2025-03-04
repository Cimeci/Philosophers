/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inowak-- <inowak--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 09:49:06 by inowak--          #+#    #+#             */
/*   Updated: 2025/03/04 14:26:29 by inowak--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

int	sleep_check(t_philo *philo, time_t sleep_time)
{
	time_t	start_sleep;

	start_sleep = get_time_in_ms();
	while (get_time_in_ms() - start_sleep < sleep_time)
	{
		pthread_mutex_lock(&philo->run->die);
		if (philo->run->simulation_running == false)
		{
			pthread_mutex_unlock(&philo->run->die);
			return (1);
		}
		pthread_mutex_unlock(&philo->run->die);
		usleep(1);
	}
	return (0);
}

time_t	get_time_in_ms(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return (tv.tv_sec * 1000 + tv.tv_usec / 1000);
}

void	delay(t_philo *philo)
{
	while (get_time_in_ms() < philo->times->start_time)
		continue ;
}
