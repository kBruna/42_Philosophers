#include "philo.h"

void	init_fork_right(t_table *table)
{
	long	i;
	long	qtt;

	i = 0;
	qtt = table->philo;
	while (i < qtt)
	{
		table->philos[i].right_fork = table->philos[(i + 1) % qtt].left_fork;
		i++;
	}
}

int	init_fork_left(t_table *table)
{
	long	index;
	long	qtt;

	index = 0;
	qtt = table->philo;
	while (index < qtt)
	{
		table->philos[index].left_fork = malloc(sizeof(pthread_mutex_t));
		if (!table->philos[index].left_fork)
		{
			free_dinner(table);
			return (1);
		}
		if (pthread_mutex_init(table->philos[index].left_fork, NULL))
		{
			free_dinner(table);
			return (1);
		}
		index++;
	}
	return (0);
}
