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
#include <unistd.h>

static void	*print_count(void *arg)
{
	t_philo	*philo;

	philo = arg;
	(void)philo;
	pthread_mutex_lock(&getter_table()->channel);
	printf("%d teste\n", philo->id);
	pthread_mutex_unlock(&getter_table()->channel);
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
	philo->last_eaten = get_time();
	if (pthread_create(&philo->thread_id, NULL, print_count, philo) != 0)
		printf("after\n");
}

static void	init_table(void)
{
	t_table	*table;

	table = getter_table();
	pthread_mutex_init(&table->channel, 0);
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
	while (1)
		;
}
