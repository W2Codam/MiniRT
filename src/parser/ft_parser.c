#include "MiniRT.h"
#include <fcntl.h>

void	exit_parser(char *error_line, int row, size_t collumn, char *func)
{
	printf("Error: %s in %s\nRow: %i, collumn; %zu\n", error_line, func, row, collumn);
	printf("----------------------------------------------------------\n");
	printf("Required format:\n......");
	exit (1);
}

static void	init_line(t_rt *rt, char *line, int	row)
{
	int	i;

	i = 0;
	while (ft_isspace(line[i]))
		i++;
	if (line[i] == '\n')
		return ;
	else if (line[0] == 'A' && ft_isspace(line[1]))
		init_ambient(rt, &line[1], row);
	else if (line[0] == 'C' && ft_isspace(line[1]))
		init_camera(rt, &line[1], row);
	else if (line[0] == 'L' && ft_isspace(line[1]))
		init_light(rt, &line[1], row);
	else if (line[0] == 's' && line[1] == 'p' && ft_isspace(line[2]))
		init_sphere(rt, &line[2], row);
	else if (line[0] == 'p' && line[1] == 'l' && ft_isspace(line[2]))
		init_plane(rt, &line[2], row);
	else if (line[0] == 'c' && line[1] == 'y' && ft_isspace(line[2]))
		init_cylinder(rt, &line[2], row);
	else if (line[0] == 't' && line[1] == 'r' && ft_isspace(line[2]))
		init_triangle(rt, &line[2], row);
	else
		exit_parser("Incorrect format", row, i, "init_line");
	return ;
}

int	init_entities(t_rt *rt, char *input)
{
	int		rt_file;
	char	*line;
	int		row;

	rt_file = open(input, O_RDONLY);
	if (rt_file < 0 | rt_file > 1024)
		return (EXIT_FAILURE);
	rt->ambient.active = false;
	rt->cameras_size = 0;
	rt->lights_size = 0;
	rt->objects_size = 0;
	row = 0;
	while (true)
	{
		line = ft_get_next_line(rt_file);
		if (!line)
			break ;
		row++;
		init_line(rt, line, row);
	}
	return (EXIT_SUCCESS);
}

