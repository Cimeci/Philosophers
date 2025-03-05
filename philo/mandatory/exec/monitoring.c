/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitoring.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inowak-- <inowak--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 17:16:17 by inowak--          #+#    #+#             */
/*   Updated: 2025/03/05 10:51:13 by inowak--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

int	script_monitoringt(t_philo *cur)
{
	time_t	current_time;

	current_time = get_time_in_ms() - cur->times->start_time;
	pthread_mutex_lock(&cur->eat);
	usleep(1);
	if (current_time - cur->last_meal >= cur->times->t_die)
	{
		pthread_mutex_lock(&cur->run->die);
		cur->run->simulation_running = false;
		pthread_mutex_unlock(&cur->run->die);
		write_msg(cur, "\033[1;31mdied ⚰️\033[0m​");
		pthread_mutex_unlock(&cur->eat);
		return (1);
	}
	pthread_mutex_unlock(&cur->eat);
	return (0);
}

void	monitoring(t_philo *philo)
{
	t_philo	*cur;

	cur = philo;
	while (cur)
	{
		pthread_mutex_lock(&cur->eat);
		if (cur->nb_eat == cur->times->nb_must_eat)
		{
			pthread_mutex_unlock(&cur->eat);
			break ;
		}
		pthread_mutex_unlock(&cur->eat);
		if (script_monitoringt(cur))
			return ;
		cur = cur->next;
		if (cur == philo)
			usleep(1000);
	}
}

