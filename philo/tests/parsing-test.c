#include "tests.h"
#include "../philo.h"

int	parsing_valid_input_int_max(void)
{
	char	*list[5] = {"2147483647", "1", "1", "1", NULL};
	long	number[4] = {2147483647, 1, 1, 1};
	long	*nbr = parsing(5, list);

	ASSERT_NOT_NULL(nbr);
	ASSERT_EQ(nbr[0], number[0]);
	ASSERT_EQ(nbr[1], number[1]);
	ASSERT_EQ(nbr[2], number[2]);
	ASSERT_EQ(nbr[3], number[3]);
	ASSERT_EQ(nbr[4], number[4]);
	return(EXIT_SUCCESS);
}

int	main(void)
{
	RUN_TEST(parsing_valid_input_int_max);

	return (0);
}
