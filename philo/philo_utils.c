#include "philo.h"

int	return_error(char *msg, char *msg2)
{
	write(STDERR_FILENO, &"Error: ", 7);
	write(STDERR_FILENO, msg, ft_strlen(msg));
	write(STDERR_FILENO, &"\n", 1);
	if (msg2)
	{
		write(STDERR_FILENO, msg2, ft_strlen(msg2));
		write(STDERR_FILENO, &"\n", 1);
	}
	return (1);
}
