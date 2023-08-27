/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_time.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johmatos <johmatos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 23:27:14 by johmatos          #+#    #+#             */
/*   Updated: 2023/08/27 23:27:15 by johmatos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	update_time(t_philo *philo)
{
	pthread_mutex_lock(&philo->last_lunch);
	philo->last_eaten = get_time();
	pthread_mutex_unlock(&philo->last_lunch);
}
