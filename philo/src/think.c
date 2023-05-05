/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   think.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jose <jose@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 16:46:44 by jose              #+#    #+#             */
/*   Updated: 2023/05/05 13:49:43 by jose             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_think(t_philo *philo, unsigned long long elapsed_ms)
{
	char	*str;
	char	*str2;

	str = ft_itoa(elapsed_ms);
	pthread_mutex_lock(philo->mutex);
	write (STDOUT_FILENO, str, ft_strlen(str));
	write (STDOUT_FILENO, "ms ", 3);
	str2 = ft_itoa(philo->philo_id + 1);
	write (STDOUT_FILENO, str2, ft_strlen(str2));
	write (STDOUT_FILENO, " is thinking\n", 14);
	pthread_mutex_unlock(philo->mutex);
	philo->is_thinking = true;
	(free(str), free(str2));
}
