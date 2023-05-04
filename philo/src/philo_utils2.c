/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jose <jose@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 00:48:27 by jose              #+#    #+#             */
/*   Updated: 2023/05/04 10:10:03 by jose             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_philo	*ft_first_philo(t_philo *philo)
{
	t_philo	*tmp;

	tmp = philo;
	while (tmp->prec)
		tmp = tmp->prec;
	return (tmp);
}

int	ft_all_alive(t_philo *philo)
{
	t_philo	*tmp;

	tmp = ft_first_philo(philo);
	while (tmp)
	{
		if (tmp->is_dead)
			return (false);
		tmp = tmp->next;
	}
	return (true);
}

int	ft_all_eat(t_philo *philo)
{
	t_philo	*tmp;

	if (philo->num_of_time_epm_eat == -1)
		return (false);
	tmp = ft_first_philo(philo);
	while (tmp)
	{
		if (tmp->num_meal < tmp->num_of_time_epm_eat)
			return (false);
		tmp = tmp->next;
	}
	return (true);
}
