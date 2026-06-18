#include "tests.h"
#include "../philo.h"

int	philo_paramns_valid(void)
{
	t_philo	**philo = all_philos(5);
//	int	index = 0;

	ASSERT_NOT_NULL(philo);
//	while (index < 5) {
//		ASSERT_NOT_NULL(philo[index]);
//		ASSERT_EQ(philo[index]->index, index);
//		index++;
//	}
	free_dinner(&philo, 5);
	ASSERT_NULL(philo);
	return(EXIT_SUCCESS);
}

int	main(void)
{
	RUN_TEST(philo_paramns_valid);

	return (0);
}
