/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inowak-- <inowak--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 10:14:42 by inowak--          #+#    #+#             */
/*   Updated: 2024/12/20 13:34:28 by inowak--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

t_args  *ft_init_args(int argc, char **argv)
{
    t_args  *args;

    args = malloc(sizeof(t_args));
    
    args->nb_philos = ft_atoi(argv[1]);
    args->t_die = ft_atoi(argv[2]);
    args->t_eat = ft_atoi(argv[3]);
    args->t_sleep = ft_atoi(argv[4]);
    if (argc == 6)
    {
        args->nb_must_eat = ft_atoi(argv[5]);
        if (args->nb_must_eat == -1)
            ft_puterror("Error : Overflow int max\n", 1);
    }
    if (args->nb_philos == -1 || args->t_die == -1 ||
        args->t_eat == -1 || args->t_sleep == -1)
        ft_puterror("Error : Overflow int max\n", 1);
    return (args);
}

