/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jose <jose@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 12:42:32 by jose              #+#    #+#             */
/*   Updated: 2023/05/04 09:49:35 by jose             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_free_lst_philo(t_philo *lst)
{
	t_philo		*tmp;
	int	i;

	i = 0;
	while (lst)
	{
		tmp = lst->next;
		if (!i++)
		{
			if (lst->mutex)
				pthread_mutex_destroy(lst->mutex);
			(free(lst->mutex), free(lst->forks));
		}
		(free(lst->philo_thread), free(lst));
		lst = tmp;
	}
}
