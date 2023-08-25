/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sleep.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jose <jose@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 08:34:17 by jose              #+#    #+#             */
/*   Updated: 2023/08/25 13:25:29 by jose             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	ft_print_sleep(t_philo *philo)
{
	t_ull	elapsed_ms;

	pthread_mutex_lock(philo->conf->m);
	if (philo->conf->stop_thread)
		return (pthread_mutex_unlock(philo->conf->m), true);
	elapsed_ms = timestamp_in_ms();
	printf("%lld %d is sleeping\n", elapsed_ms, philo->id + 1);
	pthread_mutex_unlock(philo->conf->m);
	return (false);
}

int	ft_sleep(t_philo *philo)
{
	if (ft_print_sleep(philo))
		return (true);
	usleep(philo->conf->t_sleep * 1000);
	return (false);
}
