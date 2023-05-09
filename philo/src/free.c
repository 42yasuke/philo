/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jose <jose@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 12:42:32 by jose              #+#    #+#             */
/*   Updated: 2023/05/09 18:19:38 by jose             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_free_all(t_config *conf)
{
	int	i;

	i = 0;
	if (conf->m)
		pthread_mutex_destroy(conf->m);
	while (i < conf->philo_num)
	{
		pthread_mutex_destroy(conf->forks + i);
		i++;
	}
	(free(conf->m), free(conf->forks), free(conf->philo));
	(free(conf->thrds), free(conf));
	conf = NULL;
}
