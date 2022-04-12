#include "MiniRT.h"
#include <float.h>

static float	make_decimal(const char *str, int row, size_t *i)
{
	int		dec_point;
	float	nbr;

	dec_point = 0;
	nbr = 0;
	if (!ft_isdigit(str[*i]))
		exit_parser("Incorrect format", row, *i, "make_decimal");
	while (ft_isdigit(str[*i]))
	{
		nbr = (nbr * 10) + (str[(*i)] - '0');
		(*i)++;
		dec_point++;
	}
	return (nbr / (float)powf(10, dec_point));
}

static float	make_float(const char *str, int row, size_t *i) 
{
	double	nbr;

	nbr = 0;
	while (ft_isdigit(str[*i]))
	{
		nbr = (nbr * 10) + (str[(*i)] - '0');
		(*i)++;
	}
	//printf("nbr: %f\nfltmax: %f, fltmin: %f\n\n", nbr, FLT_MAX, -FLT_MAX);
	if (nbr > FLT_MAX)
		exit_parser("Too large input number", row, *i, "make_float");
	else if (nbr < -FLT_MAX)
		exit_parser("Too small input number", row, *i, "make_float");
	if (str[*i] == '.')
	{
		(*i)++;
		nbr += make_decimal(str, row, i);
	}
	return (nbr);
}

float	minirt_atof(const char *str, int row, size_t *i)
{
	int		pos_neg;
	float	nbr;

	pos_neg = 1;
	if (str[*i] == '-' || str[*i] == '+')
	{
		if (str[*i] == '-')
			pos_neg = -1;
		(*i)++;
	}
	if (!ft_isdigit(str[*i]))
		exit_parser("Incorrect format", row, *i, "minirt_atof");
	nbr = make_float(str, row, i);
	return (nbr * pos_neg);
}

int	minirt_atoi(const char *str, int row, size_t *i)
{
	long long	nbr;
	int			p_n;

	p_n = 1;
	nbr = 0;
	if (str[*i] == '-')
	{
		p_n = -1;
		(*i)++;
	}
	while (ft_isdigit(str[*i]))
	{
		nbr = (nbr * 10) + (str[*i] - '0');
		(*i)++;
	}
	nbr *= p_n;
	if (nbr > 2147483647 || nbr < -2147483648)
		exit_parser("Too large input number", row, *i, "minirt_atoi");
	return (nbr);
}
