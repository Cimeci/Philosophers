/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 10:01:40 by inowak--          #+#    #+#             */
/*   Updated: 2025/02/06 17:47:30 by marvin           ###   ########.fr       */
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

int main(int argc, char **argv)
{
    t_args *args;

    if (argc < 5 || argc > 6)
        ft_puterror("./philosophers nb nb nb nb [nb]\n", 1);
    check_input(argv);
    args = ft_init_args(argc, argv);
    check_int(args);
    process(args);
    free(args);
}