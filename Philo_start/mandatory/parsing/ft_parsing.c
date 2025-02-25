/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inowak-- <inowak--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 10:55:01 by inowak--          #+#    #+#             */
/*   Updated: 2025/02/25 16:53:57 by inowak--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

void	check_input(char **argv)
{
	int	i;
	int	j;

	i = 0;
	j = 1;
	while (argv[j])
	{
		i = 0;
		while (argv[j][i])
		{
			while ((argv[j][i] > 6 && argv[j][i] < 14) || argv[j][i] == ' ')
				i++;
			if (argv[j][i] == '+')
				i++;
			if (argv[j][i] == '-')
				ft_puterror("Error : value is negative\n", 1);
			if (argv[j][i] < '0' || argv[j][i] > '9')
				ft_puterror("Error : not a digit\n", 1);
			i++;
		}
		j++;
	}
}

void	check_int(t_times times)
{
	if (times.nb_philos > 200)
		ft_puterror("Error : nb_philos is upper 200\n", 1);
}
