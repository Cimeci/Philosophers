/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inowak-- <inowak--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 10:30:06 by inowak--          #+#    #+#             */
/*   Updated: 2025/02/25 16:59:46 by inowak--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

// void    clean_all(t_philo *philo)
// {
//     int i;

//     i = 0;
//     while (i < philo->times->nb_philos)
//     {
//         pthread_mutex_destroy(&philo[i].left_fork);
//         i++;
//     }
//     free(philo);
// }