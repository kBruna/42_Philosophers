# include "philo.h"

t_table	*init_table(int argc, char **argv)
{
	long	*nbr;
	t_table	*table;

	nbr = parsing(argc, argv);
	if (!nbr)
		return (NULL);
	table = ft_calloc(sizeof(t_table), 1);
	if (!table)
	{
		free(nbr);
		return (NULL);
	}
	table->simulation = 0;
	table->philo = nbr[0];
	table->to_die = nbr[1];
	table->to_eat = nbr[2];
	table->to_sleep = nbr[3];
	table->max_meals = -1;
	if (nbr[4])
		table->max_meals = nbr[4];
	free(nbr);
	return (table);
}

t_philo	*init_philo(long index)
{
	t_philo	*philo;

	philo = ft_calloc(sizeof(t_philo), 1);
	if (!philo)
		return (NULL);
	philo->index = index;
	philo->is_alive = 1;
	philo->last_meal = 0;
	philo->meals = 0;
	return (philo);
}

t_philo	**all_philos(long qtt_philo)
{
	t_philo	**array;
	long	index;

	array = ft_calloc(sizeof(t_philo *), qtt_philo);
	if (!array)
		return (NULL);
	index = 0;
	while (index < qtt_philo)
	{
		array[index] = init_philo(index);
		if (!array[index])
		{
			free_dinner(&array, qtt_philo);
			return (NULL);
		}
		index++;
	}
	return (array);
}
