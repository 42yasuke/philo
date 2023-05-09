/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jose <jose@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 21:31:34 by jose              #+#    #+#             */
/*   Updated: 2023/05/09 20:32:16 by jose             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_ull	timestamp_in_ms(void)
{
	static t_ull	start = 0;

	if (!start)
		start = gettimeofday_ms();
	return (gettimeofday_ms() - start);
}

t_ull	gettimeofday_ms(void)
{
	struct timeval	end;

	gettimeofday(&end, NULL);
	return ((end.tv_sec * 1000) + (end.tv_usec / 1000));
}
