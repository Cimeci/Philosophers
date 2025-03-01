/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitoring.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inowak-- <inowak--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 17:16:17 by inowak--          #+#    #+#             */
/*   Updated: 2025/02/28 14:49:58 by inowak--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

void	monitoring(t_philo *philo)
{
	time_t current_time;
	t_philo *cur;

	cur = philo;
	while (cur)
	{
		current_time = get_time_in_ms();
		if (current_time - philo->last_meal >= cur->times->t_die)
		{
			pthread_mutex_lock(&cur->die->die);
			cur->times->simulation_running = false;
			pthread_mutex_unlock(&cur->die->die);
			pthread_mutex_lock(&philo->write);
			// dprintf(2, "monitoring: %d : %ld | %ld | last_meal: %ld\n", cur->id, current_time - philo->last_meal, cur->times->t_die, philo->last_meal);
			pthread_mutex_unlock(&philo->write);
			return ;
		}
		cur = cur->next;
	}
}