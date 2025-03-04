/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inowak-- <inowak--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 10:08:01 by inowak--          #+#    #+#             */
/*   Updated: 2025/03/04 18:22:58 by inowak--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

void	ft_sleep(t_philo *philo)
{
	if (ft_check_die(philo))
		return ;
	write_msg(philo, "is sleeping 🛌​​");
	sleep_check(philo, philo->times->t_sleep);
}

void	ft_think(t_philo *philo)
{
	if (ft_check_die(philo))
		return ;
	write_msg(philo, "is thinking 🤔​");
	usleep(1);
}

void	*routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	delay(philo);
	while (philo->nb_eat != philo->times->nb_must_eat)
	{
		pthread_mutex_lock(&philo->run->die);
		if (philo->run->simulation_running == false)
		{
			pthread_mutex_unlock(&philo->run->die);
			break ;
		}
		pthread_mutex_unlock(&philo->run->die);
		ft_eat(philo);
		pthread_mutex_lock(&philo->eat);
		if (philo->nb_eat == philo->times->nb_must_eat)
		{
			pthread_mutex_unlock(&philo->eat);
			break ;
		}
		pthread_mutex_unlock(&philo->eat);
		ft_sleep(philo);
		ft_think(philo);
	}
	return (NULL);
}
