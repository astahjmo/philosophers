/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initial.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johmatos <johmatos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 14:03:44 by johmatos          #+#    #+#             */
/*   Updated: 2023/08/28 18:10:41 by johmatos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <pthread.h>
#include <stdio.h>

static void	*lonely_philo(void *args)
{
	t_philo	*philo;

	philo = (t_philo *)args;
	take_forks(philo);
	pthread_mutex_lock(&getter_table()->channel);
	printf("%d died\n", philo->id);
	pthread_mutex_unlock(&getter_table()->channel);
	return (NULL);
}

static void	*state_handler(void *args)
{
	t_philo	*philo;

	philo = (t_philo *)args;
	if (philo->id % 2 == 1)
		thinking(philo);
	while (!is_end() && philo->times_to_eat != 0)
	{
		take_forks(philo);
		eating(philo);
		drop_forks(philo);
		sleeping(philo);
		thinking(philo);
	}
	getter_table()->finishes++;
	philo->last_eaten = -1;
	return (NULL);
}

static void	init_philo(t_philo *philo, size_t count, t_table *table)
{
	philo[count].id = count;
	philo[count].times_to_eat = getter_rules()[TIMES_TO_EAT];
	philo[count].lifetime = getter_rules()[LIFETIME];
	philo[count].sleep_time = getter_rules()[SLEEP_TIME];
	philo[count].lunch_time = getter_rules()[LUNCHTIME];
	philo[count].last_eaten = get_time();
	if (getter_rules()[PHILO_QT] == 1)
		philo[count].left_fork = NULL;
	else if (count == 0 && getter_rules()[PHILO_QT] > 1)
		philo[count].left_fork = &philo[getter_rules()[PHILO_QT] - 1]
			.rigth_fork;
	else
		philo[count].left_fork = &philo[count - 1].rigth_fork;
	philo[count].table = table;
	if (philo[count].left_fork)
		pthread_mutex_init(philo[count].left_fork, NULL);
	pthread_mutex_init(&philo[count].rigth_fork, NULL);
}

static void	run(t_philo *philo)
{
	int	count;

	count = 0;
	if (getter_rules()[PHILO_QT] == 1)
	{
		pthread_create(&philo[count].thread_id, NULL,
			lonely_philo, &philo[count]);
		return ;
	}
	count = -1;
	while (++count < (int)getter_rules()[PHILO_QT])
		pthread_create(&philo[count].thread_id,
			NULL, state_handler, &philo[count]);
}

void	initial(void)
{
	t_philo			philo[MAX_PHILO];
	t_table			*table;
	size_t			count;

	count = -1;
	table = getter_table();
	getter_table()->finishes = 0;
	pthread_mutex_init(&table->channel, NULL);
	while (++count < getter_rules()[PHILO_QT])
		init_philo(philo, count, table);
	getter_table()->philo = philo;
	getter_table()->start = get_time();
	run(philo);
	usleep(50);
	god();
}
