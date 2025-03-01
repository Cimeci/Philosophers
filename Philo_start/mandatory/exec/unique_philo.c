/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unique_philo->c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inowak-- <inowak--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 13:04:52 by inowak--          #+#    #+#             */
/*   Updated: 2025/02/27 11:18:01 by inowak--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

void	unique_philo(t_philo *philo)
{
	philo->start_time = get_time_in_ms();
	printf("%ld ms : %d has taken a fork 🍴\n", get_time_in_ms()
		- philo->start_time, 1);
	usleep(philo->times->t_die * 1000);
	printf("%ld ms : %d died 💀\n", get_time_in_ms() - philo->start_time, 1);
}