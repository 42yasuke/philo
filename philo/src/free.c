/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jose <jose@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 12:42:32 by jose              #+#    #+#             */
/*   Updated: 2023/05/01 04:21:01 by jose             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_free_lst_philo(t_lst_philo *lst)
{
	t_philo		*tmp;
	t_lst_philo	*tmp_lst;
	int	i;

	tmp_lst = lst;
	i = 0;
	while (tmp_lst)
	{
		tmp = tmp_lst->philo;
		if (tmp)
		{
			if (i == 0)
			{
				if (tmp->mutex)
					pthread_mutex_destroy(tmp->mutex);
				(free(tmp->mutex), free(tmp->forks));
			}
			free(tmp->philo_thread);
			free(tmp);
		}
		tmp_lst = tmp_lst->next;
	}
	free(lst);
	lst = NULL;
}
