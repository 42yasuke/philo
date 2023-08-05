/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dead.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jose <jose@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 10:57:46 by jose              #+#    #+#             */
/*   Updated: 2023/08/05 08:25:38 by jose             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_print_death(t_philo *philo)
{
	char	*str;
	char	*str2;
	t_ull	elapsed_ms;

	elapsed_ms = timestamp_in_ms();
	str = ft_itoa(elapsed_ms);
	write (STDOUT_FILENO, str, ft_strlen(str));
	write (STDOUT_FILENO, " ", 1);
	str2 = ft_itoa(philo->id + 1);
	write (STDOUT_FILENO, str2, ft_strlen(str2));
	write (STDOUT_FILENO, " died\n", 7);
	(free(str), free(str2));
}
