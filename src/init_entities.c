/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_entities.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvan-der <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 11:20:34 by dvan-der          #+#    #+#             */
/*   Updated: 2022/04/04 17:58:55 by dvan-der         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MiniRT"


init_ambient(t_rt *rt, char *line)
{
	size_t	i;

	i = 0;
	rt->Ambient->intensity = ft_atof(line, &i);
	if (!ft_isspace(line[i++]))
		return (EXIT_FAILURE);

}

init_line(t_rt *rt, char *line)
{
	int	result;
	
	result = EXIT_FAILURE;
	if (line[0] == 'A' && ft_isspace(line[1]))
		result = init_ambient(rt, &line[1]);
	else if (line[0] == 'C' && ft_isspace(line[1]))
		result = init_camera(rt, line);
	else if (line[0] == 'L' && ft_isspace(line[1]))
		result = init_light(rt, line);
	else if (line[0] == 's' && line[1] == 'p' && ft_isspace(line[2]))
		result = init_sphere(rt, line);
	else if (line[0] == 'p' && line[1] == 'l' && ft_isspace(line[2]))
		result = init_plane(rt, line);
	else if (line[0] == 'c' && line[1] == 'y' && ft_isspace(line[2]))
		result = init_cylinder(rt, line);
	else if (line[0] == 't' && line[1] == 'r' && ft_isspace(line[2]))
		result = init_triangle(rt, line);
	return (result);
}

init_entities(t_rt *rt, char *input)
{
	int		rt_file;
	char	*line;

	rt_file = open(input, O_RONLY);
	if (rt_file < 0 | rt_file > 1024)
		return (EXIT_FAILURE);
	rt->cameras_size = 0;
	rt->lights_size = 0;
	rt->objects_size = 0;
	while (true)
	{
		line = get_next_line(rt_file);
		if (!line)
			break ;
		init_line(rt, line);
		
}

