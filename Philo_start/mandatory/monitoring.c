/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitoring.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inowak-- <inowak--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 10:08:01 by inowak--          #+#    #+#             */
/*   Updated: 2025/02/12 16:26:46 by inowak--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <unistd.h>

long long	get_time_in_ms(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return (tv.tv_sec * 1000 + tv.tv_usec / 1000);
}

void	ft_eat(t_philo *philo, long long current_time)
{
	pthread_mutex_lock(&philo->left_fork);
	pthread_mutex_lock(&philo->args->write_lock);
	printf("%lld %d has taken a fork 🍴\n", get_time_in_ms()
		- philo->args->start_time, philo->id);
	pthread_mutex_unlock(&philo->args->write_lock);
	pthread_mutex_lock(&philo->right_fork);
	pthread_mutex_lock(&philo->args->write_lock);
	printf("%lld %d has taken a fork 🍴\n", get_time_in_ms()
		- philo->args->start_time, philo->id);
	pthread_mutex_unlock(&philo->args->write_lock);
	current_time = get_time_in_ms();
	pthread_mutex_lock(&philo->args->write_lock);
	printf("%lld %d is eating ​🍩\n", current_time - philo->args->start_time,
		philo->id);
	pthread_mutex_unlock(&philo->args->write_lock);
	philo->last_meal = current_time;
	usleep(philo->args->t_eat * 1000);
	pthread_mutex_unlock(&philo->right_fork);
	pthread_mutex_unlock(&philo->left_fork);
}

void	ft_sleep(t_philo *philo, long long current_time)
{
	current_time = get_time_in_ms();
	pthread_mutex_lock(&philo->args->write_lock);
	printf("%lld %d is sleeping 🛌\n", current_time - philo->args->start_time,
		philo->id);
	pthread_mutex_unlock(&philo->args->write_lock);
	usleep(philo->args->t_sleep * 1000);
}

void	ft_think(t_philo *philo, long long current_time)
{
	current_time = get_time_in_ms();
	pthread_mutex_lock(&philo->args->write_lock);
	printf("%lld %d is thinking 💭​\n", current_time - philo->args->start_time,
		philo->id);
	pthread_mutex_unlock(&philo->args->write_lock);
}

void	ft_die(t_philo *philo, long long current_time)
{
	if (current_time - philo->last_meal > philo->args->t_die)
		{
			pthread_join(philo->thread, NULL);
			pthread_mutex_lock(&philo->args->write_lock);
			printf("%lld %d died 💀\n", get_time_in_ms() - philo->args->start_time,
				philo->id);
			pthread_mutex_unlock(&philo->args->write_lock);
			exit(0);
		}
}

void	*routine(void *arg)
{
	t_philo		*philo;
	long long	current_time;

	philo = (t_philo *)arg;
	philo->last_meal = get_time_in_ms();
	if (philo->id % 2 == 0)
		usleep(15000);
	while (1)
	{
		current_time = get_time_in_ms();
		if (current_time - philo->last_meal > philo->args->t_die)
		ft_die(philo, current_time);
		ft_eat(philo, current_time);
		ft_sleep(philo, current_time);
		ft_think(philo, current_time);
		
	}
	return (NULL);
}
