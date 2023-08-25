/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dead.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jose <jose@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 10:57:46 by jose              #+#    #+#             */
/*   Updated: 2023/08/24 19:53:28 by jose             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_print_death(t_philo *philo)
{
	t_ull	elapsed_ms;

	elapsed_ms = timestamp_in_ms();
	printf("%lld %d died\n", elapsed_ms, philo->id + 1);
}
