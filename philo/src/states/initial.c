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
#include <pthread.h>
#include <stdio.h>

void	take_forks(t_philo *philo)
{
	if (philo->id & 1)
	{
		pthread_mutex_lock(philo->left_fork);
		pthread_mutex_lock(&philo->rigth_fork);
		return ;
	}
	pthread_mutex_lock(&philo->rigth_fork);
	pthread_mutex_lock(&philo->table->channel);
	printf("%d %d has taken fork\n", get_time_from_start(philo), philo->id);
	pthread_mutex_lock(philo->left_fork);
	printf("%d %d has taken fork\n", get_time_from_start(philo), philo->id);
	pthread_mutex_unlock(&philo->table->channel);
}

void	drop_forks(t_philo *philo)
{
	pthread_mutex_lock(&philo->table->channel);
	printf("%d %d drop a fork\n", get_time_from_start(philo), philo->id);
	pthread_mutex_unlock(&philo->table->channel);
	pthread_mutex_unlock(philo->left_fork);
	pthread_mutex_unlock(&philo->rigth_fork);
}

static void	*state_handler(void *args)
{
	t_philo	*philo;

	philo = (t_philo *)args;
	if ((philo->id & 1) == 1)
		thinking(philo);
	take_forks(philo);
	eating(philo);
	drop_forks(philo);
	sleeping(philo);
	thinking(philo);
	return (NULL);
}

static void	init_philo(t_philo *philo, size_t count)
{
	philo[count].id = count;
	philo[count].times_to_eat = getter_rules()[TIMES_TO_EAT];
	philo[count].lifetime = getter_rules()[LIFETIME];
	philo[count].sleep_time = getter_rules()[SLEEP_TIME];
	philo[count].lunch_time = getter_rules()[LUNCHTIME];
	if (count == 0 && getter_rules()[PHILO_QT] > 1)
		philo[count].left_fork = &philo[3].rigth_fork;
	else
		philo[count].left_fork = &philo[count - 1].rigth_fork;
	philo[count].table = getter_table();
	pthread_mutex_init(philo[count].left_fork, NULL);
	pthread_mutex_init(&philo[count].rigth_fork, NULL);
}

static void	init_mutex(void)
{
	pthread_mutex_init(&getter_table()->channel, NULL);
}

void	initial(void)
{
	t_philo	philo[MAX_PHILO];
	size_t	count;

	init_mutex();
	count = -1;
	while (++count < getter_rules()[PHILO_QT])
		init_philo(philo, count);
	count = -1;
	getter_table()->start = get_time();
	while (++count < getter_rules()[PHILO_QT])
			pthread_create(&philo[count].thread_id, NULL, state_handler, &philo[count]);
	while (1)
		;
}
