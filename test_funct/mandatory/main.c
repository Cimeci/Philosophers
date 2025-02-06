/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 10:01:40 by inowak--          #+#    #+#             */
/*   Updated: 2025/02/06 19:30:46 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void    process(t_args *args)
{
    printf("%d\n", args->nb_philos);
    printf("%d\n", args->t_die);
    printf("%d\n", args->t_eat);
    printf("%d\n", args->t_sleep);
    printf("%d\n", args->nb_must_eat);
}

void take_forks(t_philo *philo, pthread_mutex_t *forks, int left_fork, int right_fork)
{
	if (philo->id % 2 == 0)
	{
		pthread_mutex_lock(&forks[left_fork]);
		pthread_mutex_lock(&forks[right_fork]);
	}
	else
	{
		pthread_mutex_lock(&forks[right_fork]);
		pthread_mutex_lock(&forks[left_fork]);
	}
}

void release_forks(pthread_mutex_t *forks, int left_fork, int right_fork)
{
	pthread_mutex_unlock(&forks[left_fork]);
	pthread_mutex_unlock(&forks[right_fork]);
}

long long current_time(void)
{
	struct timeval tv;
	gettimeofday(&tv, NULL);
	return ((tv.tv_sec * 1000) + (tv.tv_usec / 1000));
}

void *philosopher(void *arg)
{
    t_philo *philo = (t_philo *)arg;
    int left_fork = philo->id;
    int right_fork = (philo->id + 1) % philo->args->nb_philos;
    long long last_meal = current_time();
    philo->meals_eaten = 0;

    while (1)
    {
        pthread_mutex_lock(&philo->args->stop_mutex);
        if (philo->args->stop_simulation)
        {
            pthread_mutex_unlock(&philo->args->stop_mutex);
            break;
        }
        pthread_mutex_unlock(&philo->args->stop_mutex);

        printf("Philosopher %d is thinking...\n", philo->id);
        usleep(philo->args->t_sleep * 1000);

        if (current_time() - last_meal >= philo->args->t_die)
        {
            printf("Philosopher %d has died 💀\n", philo->id);
            pthread_mutex_lock(&philo->args->stop_mutex);
            philo->args->stop_simulation = 1;
            pthread_mutex_unlock(&philo->args->stop_mutex);
            return (NULL);
        }

        take_forks(philo, philo->args->forks, left_fork, right_fork);
        printf("Philosopher %d is eating...\n", philo->id);
        usleep(philo->args->t_eat * 1000);
        last_meal = current_time();
        philo->meals_eaten++;

        if (philo->args->nb_must_eat > 0 && philo->meals_eaten >= philo->args->nb_must_eat)
        {
            pthread_mutex_lock(&philo->args->meals_mutex);
            philo->args->meal_count++;
            if (philo->args->meal_count == philo->args->nb_philos)
            {
                pthread_mutex_lock(&philo->args->stop_mutex);
                philo->args->stop_simulation = 1;
                pthread_mutex_unlock(&philo->args->stop_mutex);
            }
            pthread_mutex_unlock(&philo->args->meals_mutex);
        }
        release_forks(philo->args->forks, left_fork, right_fork);
    }
    return (NULL);
}

void ft_funct(t_args *args)
{
    int i;
    pthread_t threads[args->nb_philos];
    t_philo philos[args->nb_philos];

    args->forks = malloc(sizeof(pthread_mutex_t) * args->nb_philos);
    if (!args->forks)
        return; // Gestion d'erreur

    pthread_mutex_init(&args->stop_mutex, NULL);
    
    i = 0;
    while (i < args->nb_philos)
        pthread_mutex_init(&args->forks[i++], NULL);

    i = 0;
    while (i < args->nb_philos)
    {
        philos[i].id = i;
        philos[i].args = args;
        pthread_create(&threads[i], NULL, philosopher, &philos[i]);
        i++;
    }

    // Boucle de surveillance
    while (1)
    {
        pthread_mutex_lock(&args->stop_mutex);
        if (args->stop_simulation)
        {
            pthread_mutex_unlock(&args->stop_mutex);
            break;
        }
        pthread_mutex_unlock(&args->stop_mutex);
        usleep(1000);
    }

    i = 0;
    while (i < args->nb_philos)
        pthread_join(threads[i++], NULL);

    i = 0;
    while (i < args->nb_philos)
        pthread_mutex_destroy(&args->forks[i++]);

    pthread_mutex_destroy(&args->stop_mutex);
    free(args->forks);
}


int main(int argc, char **argv)
{
    t_args *args;

    if (argc < 5 || argc > 6)
        ft_puterror("./philosophers nb nb nb nb [nb]\n", 1);
    check_input(argv);
    args = ft_init_args(argc, argv);
    check_int(args);
    // process(args);
    ft_funct(args);
    free(args);
}