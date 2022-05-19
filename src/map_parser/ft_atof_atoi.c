/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_atof_atoi.c                                     :+:      :+:    :+:   */
/*                                                     +:+                    */
/*   By: lde-la-h <lde-la-h@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/12 14:38:31 by lde-la-h      #+#    #+#                 */
/*   Updated: 2022/05/19 18:31:27 by dvan-der         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Parser.h"

static float	make_decimal(const char *str, int32_t row, size_t *i)
{
	int32_t	dec_point;
	float	nbr;

	dec_point = 0;
	nbr = 0;
	if (!ft_isdigit(str[*i]))
		ft_exit_parser("Incorrect format", row, *i, "make_decimal");
	while (ft_isdigit(str[*i]))
	{
		nbr = (nbr * 10) + (str[(*i)] - '0');
		(*i)++;
		dec_point++;
	}
	return (nbr / (float)powf(10, dec_point));
}

static float	make_float(const char *str, int32_t row, size_t *i)
{
	double	nbr;

	nbr = 0;
	while (ft_isdigit(str[*i]))
	{
		nbr = (nbr * 10) + (str[(*i)] - '0');
		(*i)++;
	}
	if (nbr > FLT_MAX || nbr < -FLT_MAX)
		ft_exit_parser("Incorrect input number range", row, *i, "make_float");
	if (str[*i] == '.')
	{
		(*i)++;
		nbr += make_decimal(str, row, i);
	}
	return (nbr);
}

float	minirt_atof(const char *str, int32_t row, size_t *i)
{
	int32_t	pos_neg;
	float	nbr;

	pos_neg = 1;
	if (str[*i] == '-' || str[*i] == '+')
	{
		if (str[*i] == '-')
			pos_neg = -1;
		(*i)++;
	}
	if (!ft_isdigit(str[*i]))
		ft_exit_parser("Incorrect format", row, *i, "minirt_atof");
	nbr = make_float(str, row, i);
	return (nbr * pos_neg);
}

int32_t	minirt_atoi(const char *str, int32_t row, size_t *i)
{
	long long	nbr;
	int32_t		p_n;

	p_n = 1;
	nbr = 0;
	if (str[*i] == '-')
	{
		p_n = -1;
		(*i)++;
	}
	if (!ft_isdigit(str[*i]))
		ft_exit_parser("Incorrect format", row, *i, "minirt_atoi");
	while (ft_isdigit(str[*i]))
	{
		nbr = (nbr * 10) + (str[*i] - '0');
		(*i)++;
	}
	nbr *= p_n;
	if (nbr > 2147483647 || nbr < -2147483648)
		ft_exit_parser("Too large input number", row, *i, "minirt_atoi");
	return (nbr);
}
