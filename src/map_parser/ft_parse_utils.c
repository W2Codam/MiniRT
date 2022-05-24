/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_parse_utils.c                                   :+:      :+:    :+:   */
/*                                                     +:+                    */
/*   By: lde-la-h <lde-la-h@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/12 13:17:16 by lde-la-h      #+#    #+#                 */
/*   Updated: 2022/05/24 10:22:33 by dvan-der         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Parser.h"

static bool	ft_in_range(t_FVec3 vec, float min, float max)
{
	if (vec.x > max || vec.x < min)
		return (false);
	else if (vec.y > max || vec.y < min)
		return (false);
	else if (vec.z > max || vec.z < min)
		return (false);
	return (true);
}

float	ft_init_number(char *line, int32_t row, size_t *i, int32_t atof)
{
	float	nbr;

	while (ft_isspace(line[*i]))
		(*i)++;
	if (atof)
		nbr = minirt_atof(line, row, i);
	else
		nbr = minirt_atoi(line, row, i);
	return (nbr);
}

t_FVec3	ft_init_coordinates(char *line, int32_t row, size_t *i, int32_t check)
{
	float	x;
	float	y;
	float	z;
	t_FVec3	xyz;

	while (ft_isspace(line[*i]))
		(*i)++;
	x = minirt_atof(line, row, i);
	if (line[(*i)++] != ',')
		ft_exit_parser("Incorrect format", row, *i, "init_coordinates");
	y = minirt_atof(line, row, i);
	if (line[(*i)++] != ',')
		ft_exit_parser("Incorrect format", row, *i, "init_coordinates");
	z = minirt_atof(line, row, i);
	xyz = ft_new_fvec3(x, y, z);
	if (check && !ft_in_range(xyz, -1, 1))
		ft_exit_parser("Surpassed range", row, *i, "init_coordinates");
	return (xyz);
}

t_FVec3	ft_init_color(char *line, int32_t row, size_t *i)
{
	int32_t		r;
	int32_t		g;
	int32_t		b;
	t_FVec3		color;

	while (ft_isspace(line[*i]))
		(*i)++;
	if (!ft_isdigit(line[*i]))
		ft_exit_parser("Incorrect format", row, *i, "init_color");
	r = minirt_atoi(line, row, i);
	if (line[(*i)++] != ',')
		ft_exit_parser("Incorrect format", row, *i, "init_color");
	g = minirt_atoi(line, row, i);
	if (line[(*i)++] != ',')
		ft_exit_parser("Incorrect format", row, *i, "init_color");
	b = minirt_atoi(line, row, i);
	color = ft_new_fvec3(r, g, b);
	if (!ft_in_range(color, 0, 255))
		ft_exit_parser("Surpassed range", row, *i, "init_color");
	return (color);
}
