/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jose <jose@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 20:24:36 by jose              #+#    #+#             */
/*   Updated: 2023/04/29 18:48:07 by jose             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_error(int err)
{
	if (err == BAD_NUM_PARAMETERS)
		write(STDERR_FILENO, "Error: bad number of parameters\n", 33);
	else if (err == BAD_PARAMETERS)
		write(STDERR_FILENO, "Error: bad parameters\n", 23);
	else if (err == MUTEX_INIT)
		write(STDERR_FILENO, "Error: mutex init failed\n", 26);
}