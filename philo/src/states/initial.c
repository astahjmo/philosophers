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
#include <stdlib.h>
#include <unistd.h>

static void	*state_handler(void *args)
{
	t_philo	*philo;

	philo = (t_philo *)args;
	if (philo->id % 2 == 1)
		thinking(philo);
	while (!is_end())
	{
		take_forks(philo);
		eating(philo);
		drop_forks(philo);
		sleeping(philo);
		thinking(philo);
	}
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
	if (count == 0 && getter_rules()[PHILO_QT] > 1)
		philo[count].left_fork = &philo[3].rigth_fork;
	else
		philo[count].left_fork = &philo[count - 1].rigth_fork;
	philo[count].table = table;
	pthread_mutex_init(philo[count].left_fork, NULL);
	pthread_mutex_init(&philo[count].rigth_fork, NULL);
	pthread_mutex_init(&philo[count].last_lunch, NULL);
}

void	initial(void)
{
	t_philo			philo[MAX_PHILO];
	t_table			*table;
	size_t			count;

	count = -1;
	table = getter_table();
	pthread_mutex_init(&table->channel, NULL);
	pthread_mutex_init(&table->end, NULL);
	while (++count < getter_rules()[PHILO_QT])
		init_philo(philo, count, table);
	table->start = get_time();
	getter_table()->start = get_time();
	getter_table()->philo = philo;
	count = -1;
	while (++count < getter_rules()[PHILO_QT])
			pthread_create(&philo[count].thread_id, NULL, state_handler, &philo[count]);
	usleep(600);
	god();
}
