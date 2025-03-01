/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inowak-- <inowak--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 10:30:06 by inowak--          #+#    #+#             */
/*   Updated: 2025/03/01 16:29:02 by inowak--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

void clean_all(t_philo *philo, t_run *run, t_times *times)
{
	t_philo *cur;
	t_philo *next;

	cur = philo;
	while (cur)
	{
		next = cur->next;
		pthread_mutex_destroy(&cur->write);
		pthread_mutex_destroy(&cur->fork);
		pthread_mutex_destroy(&cur->eat);
		free(cur);
		cur = next;
		if (cur == philo)
			break;
	}
	pthread_mutex_destroy(&run->die);
	free(run);
	free (times);
}