/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inowak-- <inowak--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 10:08:01 by inowak--          #+#    #+#             */
/*   Updated: 2025/03/05 10:49:06 by inowak--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

void	ft_sleep(t_philo *philo)
{
	if (ft_check_die(philo))
		return ;
	write_msg(philo, "is sleeping 🛌​​");
	sleep_check(philo, philo->times->t_sleep);
	// usleep(philo->times->t_sleep * 1000);
}

void	ft_think(t_philo *philo, bool print)
{
	time_t	t_think;

	pthread_mutex_lock(&philo->eat);
	t_think = (philo->times->t_die - (get_time_in_ms() - philo->last_meal)
			- philo->times->t_eat) / 2;
	pthread_mutex_unlock(&philo->eat);
	if (t_think < 0)
		t_think = 0;
	if (t_think == 0 && print == false)
		t_think = 1;
	if (t_think > 600)
		t_think = 200;
	if (ft_check_die(philo))
		return ;
	if (print == true)
		write_msg(philo, "is thinking 🤔​");
	sleep_check(philo, t_think);
}

void	*routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	delay(philo);
	while (philo->nb_eat != philo->times->nb_must_eat)
	{
		if (philo->run->simulation_running == false)
			break ;
		if (philo->id % 2 != 0)
			ft_think(philo, false);
		ft_eat(philo);
		pthread_mutex_lock(&philo->eat);
		if (philo->nb_eat == philo->times->nb_must_eat)
		{
			pthread_mutex_unlock(&philo->eat);
			break ;
		}
		pthread_mutex_unlock(&philo->eat);
		ft_sleep(philo);
		ft_think(philo, true);
	}
	return (NULL);
}
