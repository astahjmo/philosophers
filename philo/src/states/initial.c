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
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

static void	*state_handler(void *arg)
{
	t_philo	*philo;

	philo = arg;
	while (1)
	{
		try_to_eat(philo);
		sleeping(philo);
		thinking(philo);
	}
	pthread_detach(philo->thread_id);
	free(philo);
	return (NULL);
}

static void	init_threads(size_t count)
{
	t_philo	*philo;

	philo = malloc(sizeof(t_philo) * 1);
	if (count == 0 && getter_rules()[0] > 1)
		philo->left_fork = getter_rules()[0] - 1;
	else
		philo->left_fork = count - 1;
	philo->right_fork = count;
	philo->id = count;
	philo->times_to_eat = getter_rules()[5];
	getter_table()->start = get_time();
	getter_table()->philo[count] = philo;
	pthread_create(&philo->thread_id, NULL, state_handler, philo);
}

static void	init_table(void)
{
	t_table	*table;
	size_t	count;

	count = 0;
	table = getter_table();
	table->philo = malloc(sizeof(t_philo *) * getter_rules()[PHILO_QT]);
	pthread_mutex_init(&table->channel, 0);
	table->forks = malloc(getter_rules()[PHILO_QT] * sizeof(pthread_mutex_t));
	while (count < getter_rules()[PHILO_QT])
		pthread_mutex_init(&table->forks[count++], NULL);
}

void	initial(void)
{
	size_t		count;

	init_table();
	count = 0;
	while (count < getter_rules()[0])
	{
		init_threads(count);
		count++;
	}
}
