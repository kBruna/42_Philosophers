#include "tests.h"
#include "../philo.h"

int	table_four_paramns_valid(void)
{
	char	*list[6] = {"", "200", "300", "400", "500", NULL};
	t_table	*table = init_table(5, list);

	ASSERT_NOT_NULL(table);
	ASSERT_EQ(table->philo, 200);
	ASSERT_EQ(table->to_die, 300);
	ASSERT_EQ(table->to_eat, 400);
	ASSERT_EQ(table->to_sleep, 500);
	ASSERT_EQ(table->max_meals, -1);
	free(table);
	return(EXIT_SUCCESS);
}

int	table_five_paramns_valid(void)
{
	char	*list[7] = {"", "200", "300", "400", "500", "100", NULL};
	t_table	*table = init_table(6, list);

	ASSERT_NOT_NULL(table);
	ASSERT_EQ(table->philo, 200);
	ASSERT_EQ(table->to_die, 300);
	ASSERT_EQ(table->to_eat, 400);
	ASSERT_EQ(table->to_sleep, 500);
	ASSERT_EQ(table->max_meals, 100);
	free(table);
	return(EXIT_SUCCESS);
}

int	table_four_paramns_empty_param(void)
{
	char	*list[6] = {"", "", "400", "500", "100", NULL};
	t_table	*table = init_table(6, list);

	ASSERT_NULL(table);
	return(EXIT_SUCCESS);
}

int	table_five_paramns_empty_param(void)
{
	char	*list[7] = {"", "", "300", "400", "500", "100", NULL};
	t_table	*table = init_table(7, list);

	ASSERT_NULL(table);
	return(EXIT_SUCCESS);
}

int	table_five_paramns_invalid_param(void)
{
	char	*list[7] = {"", "45738295743209823", "300", "400", "500", "100", NULL};
	t_table	*table = init_table(7, list);

	ASSERT_NULL(table);
	return(EXIT_SUCCESS);
}

int	main(void)
{
	RUN_TEST(table_five_paramns_valid);
	RUN_TEST(table_five_paramns_valid);
	RUN_TEST(table_four_paramns_empty_param);
	RUN_TEST(table_five_paramns_empty_param);
	RUN_TEST(table_five_paramns_invalid_param);

	return (0);
}
