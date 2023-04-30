/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jose <jose@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 12:42:32 by jose              #+#    #+#             */
/*   Updated: 2023/04/30 02:03:27 by jose             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_free_lst_philo(t_lst_philo **lst)
{
	t_philo		*tmp;
	t_lst_philo	*tmp_lst;
	int	i;

	tmp_lst = *lst;
	i = 0;
	while (tmp_lst)
	{
		tmp = tmp_lst->philo;
		if (tmp)
		{
			if (i == 0)
			{
				free(tmp->forks);
				pthread_mutex_destroy(&tmp->mutex);
			}
			free(tmp);
		}
		tmp_lst = tmp_lst->next;
	}
	free(*lst);
	*lst = NULL;
}
