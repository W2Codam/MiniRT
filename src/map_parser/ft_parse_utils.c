#include "MiniRT.h"

int	check_range(t_FVec3 vec, float min, float max)
{
	if (vec.x > max || vec.x < min)
		return (EXIT_FAILURE);
	else if (vec.y > max || vec.y < min)
		return (EXIT_FAILURE);
	else if (vec.z > max || vec.z < min)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

float	init_number(char *line, int row, size_t *i, int atof)
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

t_FVec3	init_coordinates(char *line, int row, size_t *i, int check)
{
	float	x;
	float	y;
	float	z;
	t_FVec3	xyz;

	while (ft_isspace(line[*i]))
		(*i)++;
	x = minirt_atof(line, row, i);
	if (line[(*i)++] != ',')
		exit_parser("Incorrect format", row, *i, "init_coordinates");
	y = minirt_atof(line, row, i);
	if (line[(*i)++] != ',')
		exit_parser("Incorrect format", row, *i, "init_coordinates");
	z = minirt_atof(line, row, i);
	xyz = new_fvec3(x, y, z);
	if (check && check_range(xyz, -1, 1))
		exit_parser("Surpassed range", row, *i, "init_coordinates");
	return (xyz);
}

t_FVec3	init_color(char *line, int row, size_t *i)
{
	int		r;
	int		g;
	int		b;
	t_FVec3	color;

	while (ft_isspace(line[*i]))
		(*i)++;
	r = minirt_atoi(line, row, i);
	if (line[(*i)++] != ',')
		exit_parser("Incorrect format", row, *i, "init_color");
	g = minirt_atoi(line, row, i);
	if (line[(*i)++] != ',')
		exit_parser("Incorrect format", row, *i, "init_color");
	b = minirt_atoi(line, row, i);
	color = new_fvec3(r, g, b);
	if (check_range(color, 0, 255))
		exit_parser("Surpassed range", row, *i, "init_color");
	return (color);
}
