/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inowak-- <inowak--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 10:08:01 by inowak--          #+#    #+#             */
/*   Updated: 2025/02/28 15:07:17 by inowak--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

time_t	get_time_in_ms(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return (tv.tv_sec * 1000 + tv.tv_usec / 1000);
}

void	write_msg(t_philo *philo, char *msg)
{
	time_t	current_time;

	current_time = get_time_in_ms() - philo->start_time;
	pthread_mutex_lock(&philo->write);
	printf("%ld ms|%d : %s\n", current_time, philo->id, msg);
	pthread_mutex_unlock(&philo->write);
}

void	ft_eat(t_philo *philo)
{
	if (philo->id % 2 == 0)
	{
		pthread_mutex_lock(&philo->fork);
		if (ft_die(philo))
		{
			pthread_mutex_unlock(&philo->prev->fork);
			pthread_mutex_unlock(&philo->fork);
			return ;
		}
		write_msg(philo, "take a right_fork 🍴");
		pthread_mutex_lock(&philo->prev->fork);
		if (ft_die(philo))
		{
			pthread_mutex_unlock(&philo->prev->fork);
			pthread_mutex_unlock(&philo->fork);
			return ;
		}
		write_msg(philo, "take a left_fork 🍴");
	}
	else
	{
		pthread_mutex_lock(&philo->prev->fork);
		if (ft_die(philo))
		{
			pthread_mutex_unlock(&philo->prev->fork);
			pthread_mutex_unlock(&philo->fork);
			return ;
		}
		write_msg(philo, "take a left_fork 🍴​");
		pthread_mutex_lock(&philo->fork);
		if (ft_die(philo))
		{
			pthread_mutex_unlock(&philo->prev->fork);
			pthread_mutex_unlock(&philo->fork);
			return ;
		}
		write_msg(philo, "take a right_fork 🍴​");
	}
	pthread_mutex_lock(&philo->eat);
	philo->last_meal = get_time_in_ms();
	pthread_mutex_unlock(&philo->eat);
	if (ft_die(philo))
	{
		pthread_mutex_unlock(&philo->prev->fork);
		pthread_mutex_unlock(&philo->fork);
		return ;
	}
	write_msg(philo, "eat 🍜​​​");
	if (!sleep_check(philo, philo->times->t_eat))
	{
		pthread_mutex_unlock(&philo->prev->fork);
		pthread_mutex_unlock(&philo->fork);
		return ;
	}
	pthread_mutex_unlock(&philo->prev->fork);
	pthread_mutex_unlock(&philo->fork);
}

void	ft_sleep(t_philo *philo)
{
	if (ft_die(philo))
		return ;
	write_msg(philo, "sleep 🛌​​");
	if (!sleep_check(philo, philo->times->t_sleep))
		return ;
}

void	ft_think(t_philo *philo)
{
	if (ft_die(philo))
		return ;
	write_msg(philo, "think 🤔​");
	usleep(1);
}

int	ft_die(t_philo *philo)
{
	pthread_mutex_lock(&philo->die->die);
	if (philo->times->simulation_running == false)
	{
		write_msg(philo, "died ⚰️​");
		pthread_mutex_unlock(&philo->die->die);
		exit(0);
	}
	pthread_mutex_unlock(&philo->die->die);
	return (0);
}

void	*routine(void *arg)
{
	t_philo	*philo;
	time_t	current_time;

	current_time = 0;
	philo = (t_philo *)arg;
	philo->start_time = get_time_in_ms();
	// philo->last_meal = get_time_in_ms() - philo->start_time;
	while (1)
	{
		if (ft_die(philo))
			return (NULL);
		ft_eat(philo);
		if (ft_die(philo))
			return (NULL);
		ft_sleep(philo);
		if (ft_die(philo))
			return (NULL);
		ft_think(philo);
		if (ft_die(philo))
			return (NULL);
	}
	return (NULL);
}
