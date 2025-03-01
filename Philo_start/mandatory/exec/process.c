/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inowak-- <inowak--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 12:46:23 by inowak--          #+#    #+#             */
/*   Updated: 2025/03/01 17:12:10 by inowak--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

void	process(t_philo *philo, t_times *times)
{
	t_philo	*cur;

	cur = philo;
	if (times->nb_philos == 1)
	{
		unique_philo(philo);
		return ;
	}
	printf("\033[1;34m-----ROUTINE-----\033[0m\n");
	while (cur)
	{
		cur->start_time = get_time_in_ms();
		if (pthread_create(&cur->thread, NULL, routine, cur))
		{
			printf("Error create\n");
			return ;
		}
		cur = cur->next;
		if (cur == philo)
			break;
	}
	if (philo->times->nb_must_eat)
		monitoring_limit(philo);
	else 
		monitoring(philo);
	brother(philo);
}