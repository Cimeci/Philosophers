/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 11:09:07 by inowak--          #+#    #+#             */
/*   Updated: 2024/12/22 14:41:57 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tools.h"

#include <stdio.h>

int	ft_atoi(char *str)
{
	long nb;
	int res;
	int i;
	int j;

	nb = 0;
	i = 0;
	j = 0;
	while ((str[i] > 6 && str[i] < 14) || str[i] == ' ')
		i++;
	if (str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		nb = nb * 10 + (str[i] - '0');
		if (j > 10)
			return (-1);
		j++;
		i++;
	}
	res = nb;
	if (nb <= 2147483647)
		return (res);
	return (-1);
}
