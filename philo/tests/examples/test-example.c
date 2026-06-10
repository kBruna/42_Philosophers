/* ************************************************************************** */
/* Example test file — also works as an out-of-the-box smoke test:            */
/*                                                                            */
/*     cp examples/test-example.c .                                           */
/*     make test                                                              */
/*                                                                            */
/* In real usage the functions under test come from your project (listed in   */
/* config.mk's PROJECT_SRCS); here they are defined locally so the example    */
/* compiles with an empty config.                                             */
/* ************************************************************************** */

#include "tests.h"

static int	square(int n)
{
	return (n * n);
}

static void	greet(void)
{
	printf("hello, tester!\n");
}

/* Plain style: just return EXIT_SUCCESS / EXIT_FAILURE */
int	square_of_4_must_be_16_plain_style(void)
{
	if (square(4) != 16)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

/* Assert style: on failure the report shows expected vs. got + file:line */
int	square_of_4_must_be_16_assert_style(void)
{
	ASSERT_EQ(square(4), 16);
	return (EXIT_SUCCESS);
}

/* Capturing stdout of the function under test */
int	greet_must_print_hello(void)
{
	int		saved;
	char	*out;

	saved = start_capture();
	ASSERT_TRUE(saved != -1);
	greet();
	out = end_capture(saved);
	ASSERT_NOT_NULL(out);
	if (strcmp(out, "hello, tester!\n") != 0)
	{
		free(out);
		TEST_FAILF("unexpected greeting output");
	}
	free(out);
	return (EXIT_SUCCESS);
}

int	main(void)
{
	RUN_TEST(square_of_4_must_be_16_plain_style);
	RUN_TEST(square_of_4_must_be_16_assert_style);
	RUN_TEST(greet_must_print_hello);
	return (0);
}
