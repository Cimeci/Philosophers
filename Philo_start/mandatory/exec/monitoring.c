/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitoring.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inowak-- <inowak--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 17:16:17 by inowak--          #+#    #+#             */
/*   Updated: 2025/03/01 17:27:14 by inowak--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

void	monitoring(t_philo *philo)
{
	time_t	current_time;
	t_philo	*cur;

	printf("\033[1;34m-----MONITORING-----\033[0m\n");
	cur = philo;
	while (cur)
	{
		current_time = get_time_in_ms() - cur->start_time;
		pthread_mutex_lock(&cur->eat);
		if (current_time - cur->last_meal >= cur->times->t_die)
		{
			pthread_mutex_lock(&cur->run->die);
			cur->run->simulation_running = false;
			pthread_mutex_unlock(&cur->run->die);
			write_msg(cur, "\033[1;31mdied1 ⚰️\033[0m​");
			pthread_mutex_unlock(&cur->eat);
			return ;
		}
		pthread_mutex_unlock(&cur->eat);
		cur = cur->next;
	}
}

void	monitoring_limit(t_philo *philo)
{
	time_t	current_time;
	time_t	eat;
	t_philo	*cur;
	int		i;

	eat = philo->times->nb_must_eat * philo->times->nb_philos;
	printf("\033[1;34m-----MONITORING_LIMIT-----\033[0m\n");
	i = 0;
	cur = philo;
	while (cur && i < eat)
	{
		current_time = get_time_in_ms() - cur->start_time;
		// printf("\033[1;35time : %ld\033[0m\n", get_time_in_ms());
		// printf("\033[1;35mstart_time : %ld\033[0m\n", cur->start_time);
		// printf("\033[1;35mcurrent_time : %ld\033[0m\n", current_time);
		// printf("\033[1;35mlast_meal : %ld\033[0m\n", cur->last_meal);
		// printf("\033[1;35mt_die : %ld\033[0m\n", cur->times->t_die);
		pthread_mutex_lock(&cur->eat);
		if (current_time - cur->last_meal >= cur->times->t_die)
		{
			pthread_mutex_lock(&cur->run->die);
			cur->run->simulation_running = false;
			pthread_mutex_unlock(&cur->run->die);
			write_msg(cur, "\033[1;31mdied2 ⚰️\033[0m​");
			pthread_mutex_unlock(&cur->eat);
			return ;
		}
		pthread_mutex_unlock(&cur->eat);
		i++;
		cur = cur->next;
	}
}
