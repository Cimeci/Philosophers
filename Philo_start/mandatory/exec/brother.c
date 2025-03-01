/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   brother.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inowak-- <inowak--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 13:27:46 by inowak--          #+#    #+#             */
/*   Updated: 2025/02/27 13:51:13 by inowak--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

void	brother(t_philo *philo)
{
    t_philo *cur;

    cur = philo;
	while (cur)
	{
		if (pthread_join(cur->thread, NULL))
			return ;
        cur = cur->next;
        if (cur == philo)
            break;
	}
}