/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   forks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johmatos <johmatos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 23:26:54 by johmatos          #+#    #+#             */
/*   Updated: 2023/08/28 17:00:46 by johmatos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	take_forks(t_philo *philo)
{
	if (is_end())
		return ;
	if (philo->id % 2 == 1 || (size_t)philo->id == getter_rules()[PHILO_QT])
	{
		pthread_mutex_lock(philo->left_fork);
		print_action("has taken a fork", philo);
		pthread_mutex_lock(&philo->rigth_fork);
		print_action("has taken a fork", philo);
		return ;
	}
	pthread_mutex_lock(&philo->rigth_fork);
	print_action("has taken a fork", philo);
	if (philo->left_fork == NULL)
		return ;
	pthread_mutex_lock(philo->left_fork);
	print_action("has taken a fork", philo);
}

void	drop_forks(t_philo *philo)
{
	if (philo->left_fork)
		pthread_mutex_unlock(philo->left_fork);
	pthread_mutex_unlock(&philo->rigth_fork);
}
