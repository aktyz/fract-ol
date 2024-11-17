
#include "fractol.h"
#include <stdio.h>

int	main(int argc, char *argv[])
{
	if ((argc == 2 && !ft_strncmp(argv[1], "mandelbrot", 10))
		|| (argc == 4 && !ft_strncmp(argv[1], "julia", 5)))
			printf("Kicking in the application!\n\n");
	else
	{
		printf("%s", ERROR_MESSAGE);
		return (0);
	}
	return (0);
}
