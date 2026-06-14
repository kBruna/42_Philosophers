# include "philo.h"

void	free_dinner(t_philo ***dinner, long qtt)
{
	long	philo;

	philo = 0;
	while(*dinner && philo < qtt)
	{
		if (*dinner[philo])
		{
			free(*dinner[philo]);
			*dinner[philo] = NULL;
		}
		philo++;
	}
	free(*dinner);
	*dinner = NULL;
}
