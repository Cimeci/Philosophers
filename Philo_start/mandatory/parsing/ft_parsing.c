/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inowak-- <inowak--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 10:55:01 by inowak--          #+#    #+#             */
/*   Updated: 2024/12/20 13:34:51 by inowak--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

void    check_input(char **argv)
{
    int i;
    int j;

    i = 0;
    j = 1;
    while (argv[j])
    {
        i = 0;
        while (argv[j][i])
        {
            while ((argv[j][i] > 6 && argv[j][i] < 14) ||
                argv[j][i] == ' ')
                i++;
            if (argv[j][i] == '+')
                i++;
            if (argv[j][i] < '0' || argv[j][i] > '9') 
                ft_puterror("Error : not a digit\n", 1);
            i++;
        }
        j++;
    }
}
