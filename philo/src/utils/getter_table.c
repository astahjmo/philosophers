#include "philo.h"

t_table	*getter_table(void)
{
	static t_table	table;

	return (&table);
}
