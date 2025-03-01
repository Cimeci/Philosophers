/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inowak-- <inowak--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 10:08:01 by inowak--          #+#    #+#             */
/*   Updated: 2025/03/01 17:07:01 by inowak--         ###   ########.fr       */
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
	printf("%ld ms | id :%d : %s\n", current_time, philo->id, msg);
	pthread_mutex_unlock(&philo->write);
}

void	ft_eat(t_philo *philo)
{
	if (philo->id % 2 == 0)
	{
		pthread_mutex_lock(&philo->fork);
		if (ft_check_die(philo))
		{
			pthread_mutex_unlock(&philo->fork);
			return ;
		}
		write_msg(philo, "take a right_fork 🍴");
		pthread_mutex_lock(&philo->prev->fork);
		if (ft_check_die(philo))
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
		if (ft_check_die(philo))
		{
			pthread_mutex_unlock(&philo->fork);
			return ;
		}
		write_msg(philo, "take a left_fork 🍴​");
		pthread_mutex_lock(&philo->fork);
		if (ft_check_die(philo))
		{
			pthread_mutex_unlock(&philo->prev->fork);
			pthread_mutex_unlock(&philo->fork);
			return ;
		}
		write_msg(philo, "take a right_fork 🍴​");
	}
	pthread_mutex_lock(&philo->eat);
	philo->last_meal = get_time_in_ms() - philo->start_time;
	pthread_mutex_unlock(&philo->eat);
	if (ft_check_die(philo))
	{
		pthread_mutex_unlock(&philo->prev->fork);
		pthread_mutex_unlock(&philo->fork);
		return ;
	}
	write_msg(philo, "\033[1;33meat 🍜​​\033[0m​");
	if (sleep_check(philo, philo->times->t_eat))
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
	if (ft_check_die(philo))
		return ;
	write_msg(philo, "sleep 🛌​​");
	if (sleep_check(philo, philo->times->t_sleep))
		return ;
}

void	ft_think(t_philo *philo)
{
	if (ft_check_die(philo))
		return ;
	write_msg(philo, "think 🤔​");
	usleep(1);
}

int	ft_check_die(t_philo *philo)
{
	pthread_mutex_lock(&philo->run->die);
	if (philo->run->simulation_running == false)
	{
		pthread_mutex_unlock(&philo->run->die);
		return (1);
	}
	pthread_mutex_unlock(&philo->run->die);
	return (0);
}

void	*routine(void *arg)
{
	t_philo	*philo;
	size_t		i;

	philo = (t_philo *)arg;
	i = philo->times->nb_must_eat;
	if (i > 0)
	{
		while (i > 0 && philo->run->simulation_running == true)
		{
			ft_eat(philo);
			ft_sleep(philo);
			ft_think(philo);
			i--;
		}
	}
	else
	{
		while (philo->run->simulation_running == true)
		{
			ft_eat(philo);
			ft_sleep(philo);
			ft_think(philo);
		}
	}
	return (NULL);
}
