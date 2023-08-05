/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   think.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jose <jose@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 16:46:44 by jose              #+#    #+#             */
/*   Updated: 2023/08/05 08:33:41 by jose             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_think(t_philo *philo)
{
	char	*str;
	char	*str2;

	pthread_mutex_lock(philo->conf->m);
	if (philo->conf->stop_thread)
		return (pthread_mutex_unlock(philo->conf->m), true);
	str = ft_itoa(timestamp_in_ms());
	write (STDOUT_FILENO, str, ft_strlen(str));
	write (STDOUT_FILENO, " ", 1);
	str2 = ft_itoa(philo->id + 1);
	write (STDOUT_FILENO, str2, ft_strlen(str2));
	write (STDOUT_FILENO, " is thinking\n", 14);
	pthread_mutex_unlock(philo->conf->m);
	return (free(str), free(str2), false);
}
