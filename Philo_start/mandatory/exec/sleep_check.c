/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sleep_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inowak-- <inowak--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 09:49:06 by inowak--          #+#    #+#             */
/*   Updated: 2025/03/01 13:56:59 by inowak--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

int sleep_check(t_philo *philo, time_t sleep_time)
{
    time_t start_sleep = get_time_in_ms();
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