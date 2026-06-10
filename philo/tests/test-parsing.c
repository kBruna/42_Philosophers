#include "tests.h"
#include "../philo.h"

int	parsing_invalid_paramn_qtt_more(void)
{
	char	*list[7] = {"1", "1", "1", "2147483647", "1", "1", NULL};
	long	*nbr = parsing(7, list);

	ASSERT_NULL(nbr);
	return(EXIT_SUCCESS);
}

int	parsing_valid_paramn_qtt_optional(void)
{
	char	*list[6] = {"2147483647", "1","1", "1", "1", NULL};
	long	number[5] = {2147483647, 1, 1, 1, 1};
	long	*nbr = parsing(6, list);

	//ASSERT_NOT_NULL(nbr);
	ASSERT_EQ(nbr[0], number[0]);
	ASSERT_EQ(nbr[1], number[1]);
	ASSERT_EQ(nbr[2], number[2]);
	ASSERT_EQ(nbr[3], number[3]);
	ASSERT_EQ(nbr[4], number[4]);
	return(EXIT_SUCCESS);
}

int	parsing_invalid_paramn_qtt_less(void)
{
	char	*list[4] = {"2147483647", "-1", "1", NULL};
	long	*nbr = parsing(4, list);

	ASSERT_NULL(nbr);
	return(EXIT_SUCCESS);
}

int	parsing_invalid_input_char_plus(void)
{
	char	*list[5] = {"2147483647", "-1", "1", "1", NULL};
	long	*nbr = parsing(5, list);

	ASSERT_NULL(nbr);
	return(EXIT_SUCCESS);
}

int	parsing_invalid_input_char_minus(void)
{
	char	*list[5] = {"2147483647", "-1", "1", "1", NULL};
	long	*nbr = parsing(5, list);

	ASSERT_NULL(nbr);
	return(EXIT_SUCCESS);
}

int	parsing_invalid_input_int_max(void)
{
	char	*list[5] = {"2147483648", "1", "1", "1", NULL};
	long	*nbr = parsing(5, list);

	ASSERT_NULL(nbr);
	return(EXIT_SUCCESS);
}

int	parsing_valid_input_int_max(void)
{
	char	*list[5] = {"2147483647", "1", "1", "1", NULL};
	long	number[4] = {2147483647, 1, 1, 1};
	long	*nbr = parsing(5, list);

	//ASSERT_NOT_NULL(nbr);
	ASSERT_EQ(nbr[0], number[0]);
	ASSERT_EQ(nbr[1], number[1]);
	ASSERT_EQ(nbr[2], number[2]);
	ASSERT_EQ(nbr[3], number[3]);
	return(EXIT_SUCCESS);
}

int	main(void)
{
//	RUN_TEST(parsing_valid_input_int_max);
	//RUN_TEST(parsing_valid_paramn_qtt_optional);
	//RUN_TEST(parsing_invalid_input_int_max);
	RUN_TEST(parsing_invalid_input_char_minus);
	RUN_TEST(parsing_invalid_input_char_plus);
	RUN_TEST(parsing_invalid_paramn_qtt_less);
	RUN_TEST(parsing_invalid_paramn_qtt_more);

	return (0);
}
