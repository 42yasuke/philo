/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dead.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jose <jose@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 10:57:46 by jose              #+#    #+#             */
/*   Updated: 2023/05/03 16:11:38 by jose             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_print_death(t_philo *philo, unsigned long long elapsed_ms)
{
	char	*str;
	char	*str2;

	str = ft_itoa(elapsed_ms);
	write (STDOUT_FILENO, str, ft_strlen(str));
	write (STDOUT_FILENO, "ms ", 3);
	str2 = ft_itoa(philo->philo_id + 1);
	write (STDOUT_FILENO, str2, ft_strlen(str2));
	write (STDOUT_FILENO, " died\n", 7);
	(free(str), free(str2));
}