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
#include <bits/pthreadtypes.h>
#include <pthread.h>
#include <stdio.h>
#include <unistd.h>

static void	unlock_forks(t_sint f_fork, t_sint s_fork);
static void	lock_forks(t_philo *philo, t_sint f_fork, t_sint s_fork);
static void	get_forks(t_philo *philo);
static void	eating(t_philo *philo);

static void	unlock_forks(t_sint f_fork, t_sint s_fork)
{
	t_table	*table;

	table = getter_table();
	pthread_mutex_unlock(&table->forks[f_fork]);
	pthread_mutex_unlock(&table->forks[s_fork]);
}

static void	lock_forks(t_philo *philo, t_sint f_fork, t_sint s_fork)
{
	t_table	*table;

	table = getter_table();
	pthread_mutex_lock(&getter_table()->channel);
	pthread_mutex_lock(&table->forks[f_fork]);
	printf("%d %d has taken a fork\n", get_time_from_start(), philo->id);
	pthread_mutex_lock(&table->forks[s_fork]);
	printf("%d %d has taken a fork\n", get_time_from_start(), philo->id);
	pthread_mutex_unlock(&getter_table()->channel);
}

static void	get_forks(t_philo *philo)
{
	if (philo->id & 1)
		lock_forks(philo, philo->left_fork, philo->right_fork);
	else
		lock_forks(philo, philo->right_fork, philo->left_fork);
}

void	try_to_eat(t_philo *philo)
{
	get_forks(philo);
	eating(philo);
	philo->last_eaten = get_time();
	unlock_forks(philo->left_fork, philo->right_fork);
}

static void	eating(t_philo *philo)
{
	pthread_mutex_lock(&getter_table()->channel);
	printf("%d %d is eating\n", get_time_from_start(), philo->id);
	pthread_mutex_unlock(&getter_table()->channel);
	if (philo->times_to_eat > 0)
		philo->times_to_eat--; 
	philo->last_eaten = get_time();
	usleep(getter_rules()[EAT_TIME] * 1000);
}
