/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sleep_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inowak-- <inowak--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 09:49:06 by inowak--          #+#    #+#             */
/*   Updated: 2025/02/28 14:02:51 by inowak--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

bool    sleep_check(t_philo *philo, time_t sleep_time)
{
    time_t  current_time;
    time_t  start_sleep;

    
    current_time = get_time_in_ms() - philo->start_time;
    start_sleep = get_time_in_ms() - philo->start_time;
    while(current_time - start_sleep < sleep_time)
	{
        pthread_mutex_lock(&philo->die->die);
		if (philo->times->simulation_running == false)
            return (false);
        pthread_mutex_unlock(&philo->die->die);
        usleep(1);
        current_time = get_time_in_ms() - philo->start_time;
	}
    return (true);
}   