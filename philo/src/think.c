/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   think.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jose <jose@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 16:46:44 by jose              #+#    #+#             */
/*   Updated: 2023/08/24 20:30:31 by jose             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_think(t_philo *philo)
{
	t_ull	elapsed_ms;

	pthread_mutex_lock(philo->conf->m);
	if (philo->conf->stop_thread)
		return (pthread_mutex_unlock(philo->conf->m), true);
	elapsed_ms = timestamp_in_ms();
	printf("%lld %d is thinking\n", elapsed_ms, philo->id + 1);
	pthread_mutex_unlock(philo->conf->m);
	return (false);
}
