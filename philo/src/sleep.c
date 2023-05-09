/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sleep.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jose <jose@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 08:34:17 by jose              #+#    #+#             */
/*   Updated: 2023/05/10 01:40:38 by jose             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	ft_print_sleep(t_philo *philo)
{
	char	*str;
	char	*str2;

	str = ft_itoa(timestamp_in_ms());
	pthread_mutex_lock(philo->conf->m);
	write (STDOUT_FILENO, str, ft_strlen(str));
	write (STDOUT_FILENO, "ms ", 3);
	str2 = ft_itoa(philo->id + 1);
	write (STDOUT_FILENO, str2, ft_strlen(str2));
	write (STDOUT_FILENO, " is sleeping\n", 14);
	pthread_mutex_unlock(philo->conf->m);
	(free(str), free(str2));
}

void	ft_sleep(t_philo *philo)
{
	ft_print_sleep(philo);
	usleep(philo->conf->t_sleep * 1000);
}
