/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inowak-- <inowak--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 11:13:46 by inowak--          #+#    #+#             */
/*   Updated: 2025/03/04 14:29:05 by inowak--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TOOLS_H
# define TOOLS_H

# include "../philosophers.h"
# include <unistd.h>

int		ft_strlen(char *str);
size_t	ft_atoi(char *str);
int		check_max_min(long long nb, char *str, int inf);

#endif