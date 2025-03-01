/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inowak-- <inowak--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 10:30:06 by inowak--          #+#    #+#             */
/*   Updated: 2025/02/27 16:00:06 by inowak--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

void clean_all(t_philo *philo)
{
    t_philo *cur;
    t_philo *next;

    cur = philo;
    while (cur)
    {
        next = cur->next;
        pthread_mutex_destroy(&cur->die->die);
        pthread_mutex_destroy(&cur->write);
        pthread_mutex_destroy(&cur->fork);
        free(cur);
        cur = next;
        if (cur == philo) // Pour une liste circulaire
            break;
    }
}