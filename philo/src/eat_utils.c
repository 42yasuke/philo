/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eat_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jose <jose@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 16:40:17 by jose              #+#    #+#             */
/*   Updated: 2023/05/03 16:45:24 by jose             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_your_t(t_philo *philo)
{
	t_philo	*tmp;

	tmp = ft_first_philo(philo);
	while (tmp)
	{
		if (tmp->time_last_meal < philo->time_last_meal)
			return (false);
		tmp = tmp->next;
	}
	return (true);
}