#include "libft.h"
#include <stdio.h>

int	main()
{
	int		i;
	float	nbr;

	i = 0;
	nbr = ft_atof("2.005", &i);
	printf("nbr: %f\ni: %i\n", nbr, i);
	i = 0;
	nbr = ft_atof(" 36.085.", &i);
	printf("nbr: %f\ni: %i\n", nbr, i);
	i = 0;
	nbr = ft_atof("  -2553..345", &i);
	printf("nbr: %f\ni: %i\n", nbr, i);
	i = 0;
	nbr = ft_atof("  -203,345", &i);
	printf("nbr: %f\ni: %i\n", nbr, i);
}
