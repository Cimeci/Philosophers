/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inowak-- <inowak--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 14:27:17 by inowak--          #+#    #+#             */
/*   Updated: 2025/03/04 18:23:50 by inowak--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

void	write_msg(t_philo *philo, char *msg)
{
	time_t	current_time;

	pthread_mutex_lock(&philo->run->write);
	current_time = get_time_in_ms() - philo->times->start_time;
	printf("%ld ms | %d %s\n", current_time, philo->id, msg);
	pthread_mutex_unlock(&philo->run->write);
}

int	ft_check_die(t_philo *philo)
{
	pthread_mutex_lock(&philo->run->die);
	if (philo->run->simulation_running == false)
	{
		pthread_mutex_unlock(&philo->run->die);
		return (1);
	}
	pthread_mutex_unlock(&philo->run->die);
	return (0);
}
