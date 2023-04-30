/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jose <jose@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 10:39:40 by jose              #+#    #+#             */
/*   Updated: 2023/04/29 22:42:47 by jose             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_philo_manager(int ac, char **av)
{
	t_lst_philo	*lst;

	lst = malloc(sizeof(*lst));
	if (!lst)
		return (ft_error(MALLOC_FAILED));
	ft_init_all(ac, av, &lst);
	if (!lst)
		return ;
	
}