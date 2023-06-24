/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sleep.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jose <jose@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 08:34:17 by jose              #+#    #+#             */
/*   Updated: 2023/06/24 11:19:28 by jose             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	ft_print_sleep(t_philo *philo)
{
	char	*str;
	char	*str2;

	pthread_mutex_lock(philo->conf->m);
	str = ft_itoa(timestamp_in_ms());
	if (philo->conf->stop_thread)
		return (pthread_mutex_unlock(philo->conf->m), free(str), true);
	write (STDOUT_FILENO, str, ft_strlen(str));
	write (STDOUT_FILENO, "ms ", 3);
	str2 = ft_itoa(philo->id + 1);
	write (STDOUT_FILENO, str2, ft_strlen(str2));
	write (STDOUT_FILENO, " is sleeping\n", 14);
	pthread_mutex_unlock(philo->conf->m);
	return (free(str), free(str2), false);
}

int	ft_sleep(t_philo *philo)
{
	if (ft_print_sleep(philo))
		return (true);
	usleep(philo->conf->t_sleep * 1000);
	return (false);
}
