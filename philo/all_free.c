# include "philo.h"

void	free_dinner(t_table *table)
{
	long	index;

	index = 0;
	while(index < table->philo)
	{
		pthread_mutex_destroy(table->philos[index].left_fork);
		free(table->philos[index].left_fork);
		table->philos[index].left_fork = NULL;
		index++;
	}
	free(table->philos);
	free(table);
}
