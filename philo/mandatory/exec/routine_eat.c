/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine_eat.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inowak-- <inowak--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 14:29:57 by inowak--          #+#    #+#             */
/*   Updated: 2025/03/04 18:29:46 by inowak--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

int	ft_eat_pair(t_philo *philo)
{
	pthread_mutex_lock(&philo->fork);
	if (ft_check_die(philo))
	{
		pthread_mutex_unlock(&philo->fork);
		return (1);
	}
	write_msg(philo, "has taken a fork 🍴​");
	pthread_mutex_lock(&philo->prev->fork);
	if (ft_check_die(philo))
	{
		pthread_mutex_unlock(&philo->prev->fork);
		pthread_mutex_unlock(&philo->fork);
		return (1);
	}
	write_msg(philo, "has taken a fork 🍴​");
	return (0);
}

int	ft_eat_impair(t_philo *philo)
{
	pthread_mutex_lock(&philo->prev->fork);
	if (ft_check_die(philo))
	{
		pthread_mutex_unlock(&philo->prev->fork);
		return (1);
	}
	write_msg(philo, "has taken a fork 🍴​");
	pthread_mutex_lock(&philo->fork);
	if (ft_check_die(philo))
	{
		pthread_mutex_unlock(&philo->fork);
		pthread_mutex_unlock(&philo->prev->fork);
		return (1);
	}
	write_msg(philo, "has taken a fork 🍴​");
	return (0);
}

void	ft_eat(t_philo *philo)
{
	int	save;

	save = 0;
	if (philo->id % 2 == 0)
		save = ft_eat_pair(philo);
	else
		save = ft_eat_impair(philo);
	if (save)
		return ;
	pthread_mutex_lock(&philo->eat);
	philo->last_meal = get_time_in_ms() - philo->times->start_time;
	philo->nb_eat++;
	pthread_mutex_unlock(&philo->eat);
	if (ft_check_die(philo))
	{
		pthread_mutex_unlock(&philo->prev->fork);
		pthread_mutex_unlock(&philo->fork);
		return ;
	}
	write_msg(philo, "is eating 🍜​​​");
	sleep_check(philo, philo->times->t_eat);
	pthread_mutex_unlock(&philo->prev->fork);
	pthread_mutex_unlock(&philo->fork);
}
