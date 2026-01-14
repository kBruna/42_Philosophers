#include <stdio.h>
#include <pthread.h>

#define	ERROR_PARAMETERS "Recommended Use: >$ ./philosophers <number_of_philosophers>
		<time_to_die> <time_to_eat> <time_to_sleep>
		[number_of_times_each_philosopher_must_eat];

void	return_error(char *msg, char *msg2)
{
	fprintf(2, "Error: %s", msg);
	if (msg2)
		fprintf(2, msg);
	exit(1);
}

void	parsing(int argc, char ** argv)
{
	int	idx;

	if (argc < 5 || argc > 6)
		return_error("Wrong Number of Parameters", ERROR_PARAMETERS);
	idx = 1;
	while (idx < argc){
		if (argv[idx][0] == '\0')
			return_error("Null Parameters");
		while (argv[idx])
		idx++;
	}
}

int	ft_atoi(char *str)
{
	int	nbr;

}

int	main(int argc, char **argv)
{
	parsing(argc, argv);
			

	return (0);
}
