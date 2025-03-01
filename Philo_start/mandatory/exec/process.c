/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inowak-- <inowak--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 12:46:23 by inowak--          #+#    #+#             */
/*   Updated: 2025/02/28 14:05:24 by inowak--         ###   ########.fr       */
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
	printf("create\n");
	while (cur)
	{
		if (pthread_create(&cur->thread, NULL, routine, cur))
		{
			printf("Error create\n");
			return ;
		}
		cur = cur->next;
		if (cur == philo)
			break;
	}
	monitoring(philo);
	brother(philo);
}