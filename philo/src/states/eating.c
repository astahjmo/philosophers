/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eating.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johmatos <johmatos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 14:03:44 by johmatos          #+#    #+#             */
/*   Updated: 2023/08/28 17:10:43 by johmatos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <pthread.h>
#include <stdio.h>

void	eating(t_philo *philo)
{
	if (is_end() && philo->times_to_eat == 0)
		return ;
	print_action("is eating", philo);
	update_time(philo);
	if (philo->times_to_eat > 0)
		philo->times_to_eat--;
	usleep(philo->lunch_time * 1000);
}
