/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jose <jose@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 20:24:36 by jose              #+#    #+#             */
/*   Updated: 2023/04/29 03:23:45 by jose             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_error(int err, char *msg_err)
{
	if (err == BAD_NUM_PARAMETERS)
		write(STDOUT_FILENO, msg_err, ft_strlen(msg_err));
	if (err == BAD_PARAMETERS)
		write(STDOUT_FILENO, msg_err, ft_strlen(msg_err));
}