/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inowak-- <inowak--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 10:01:40 by inowak--          #+#    #+#             */
/*   Updated: 2024/12/20 13:40:00 by inowak--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void    process(t_args *args)
{
    printf("%d ", args->nb_philos);
    printf("\n");
    printf("%d ", args->t_die);
    printf("\n");
    printf("%d ", args->t_eat);
    printf("\n");
    printf("%d ", args->t_sleep);
    printf("\n");
    printf("%d ", args->nb_must_eat);
    printf("\n");

}

int main(int argc, char **argv)
{
    t_args *args;

    if (argc < 5 || argc > 6)
        ft_puterror("./philosophers nb nb nb nb [nb]\n", 1);
    check_input(argv);
    args = ft_init_args(argc, argv);
    process(args);
    free(args);
}