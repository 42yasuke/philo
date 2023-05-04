/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jose <jose@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 20:24:36 by jose              #+#    #+#             */
/*   Updated: 2023/05/02 10:50:59 by jose             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_error(int err)
{
	if (err == BAD_NUM_PARAMETERS)
		write(STDERR_FILENO, "Error: bad number of parameters\n", 32);
	else if (err == BAD_PARAMETERS)
		write(STDERR_FILENO, "Error: bad parameters\n", 22);
	else if (err == MUTEX_INIT)
		write(STDERR_FILENO, "Error: mutex init failed\n", 25);
	else if (err == THREAD_CREATE)
		write(STDERR_FILENO, "Error: thread create failed\n", 28);
	else if (err == THREAD_JOIN)
		write(STDERR_FILENO, "Error: thread join failed\n", 26);
}