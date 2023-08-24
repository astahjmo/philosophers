#include "philo.h"

void	print_action(char *msg , t_philo *philo)
{
	pthread_mutex_lock(&philo->table->channel);
	printf("%d %d %s\n", get_time_from_start(), philo->id, msg);
	pthread_mutex_unlock(&philo->table->channel);
}
