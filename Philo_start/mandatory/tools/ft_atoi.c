/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inowak-- <inowak--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 11:09:07 by inowak--          #+#    #+#             */
/*   Updated: 2025/02/25 11:18:20 by inowak--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tools.h"

#include <stdio.h>

size_t	ft_atoi(char *str)
{
	int			i;
	int			nb;
	int			inf;

	inf = 0;
	nb = 0;
	i = 0;
	printf("%s\n", str);
	if (str[i] == '+')
		i++;
	if (!(str[i] >= '0' && str[i] <= '9'))
		return (0);
	while (str[i] >= '0' && str[i] <= '9')
		nb = nb * 10 + (str[i++] - '0');
	if (nb <= 2147483647)
		return (nb);
	return (0);
}

