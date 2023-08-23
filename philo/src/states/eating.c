/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johmatos <johmatos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 14:03:44 by johmatos          #+#    #+#             */
/*   Updated: 2023/08/10 18:24:44 by johmatos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	eating(t_philo *philo)
{
	philo->last_eaten = get_time();
	pthread_mutex_lock(&getter_table()->channel);
	printf("%d %d is eating\n", get_time_from_start(philo), philo->id);
	pthread_mutex_unlock(&getter_table()->channel);
	if (philo->times_to_eat > 0)
		philo->times_to_eat--; 
	usleep(philo->lunch_time * 1000);
}
