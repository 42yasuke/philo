/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jose <jose@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 00:48:27 by jose              #+#    #+#             */
/*   Updated: 2023/08/03 20:23:58 by jose             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_all_alive(t_config *conf)
{
	t_philo	*philo;
	int		i;
	t_ull	death;

	philo = conf->philo;
	i = 0;
	while (i < conf->philo_num)
	{
		death = philo[i].t_last_meal + conf->t_die;
		if (death <= timestamp_in_ms())
		{
			conf->stop_thread = true;
			return (ft_print_death(&philo[i]), false);
		}
		i++;
	}
	return (true);
}

int	ft_all_eat(t_config *conf)
{
	t_philo	*philo;
	int		i;

	i = 0;
	philo = conf->philo;
	if (conf->times_to_eat == -1)
		return (false);
	else
	{
		while (i < conf->philo_num)
		{
			if (philo[i].eat_num < conf->times_to_eat)
				return (false);
			i++;
		}
	}
	conf->stop_thread = true;
	return (true);
}
