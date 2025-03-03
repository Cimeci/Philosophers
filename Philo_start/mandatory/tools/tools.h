/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inowak-- <inowak--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 11:13:46 by inowak--          #+#    #+#             */
/*   Updated: 2025/02/28 09:18:34 by inowak--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TOOLS_H
# define TOOLS_H

# include "../philosophers.h"

int		ft_strlen(char *str);
size_t	ft_atoi(char *str);
int		check_max_min(long long nb, char *str, int inf);
void	ft_lstadd_back(t_philo **lst, t_philo *new);
void	*ft_lstnew_generic(size_t data_size);
void	ft_lstadd_front(t_philo **lst, t_philo *new);

#endif