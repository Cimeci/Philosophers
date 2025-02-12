/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inowak-- <inowak--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 10:30:06 by inowak--          #+#    #+#             */
/*   Updated: 2025/02/12 14:08:01 by inowak--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

void    clean_all(t_philo *philo, t_args *args)
{
    while (philo)
    {
        pthread_mutex_destroy(&philo->right_fork);
        pthread_mutex_destroy(&philo->left_fork);
        philo = philo->next;
    }
    free(philo);
    free(args);
}