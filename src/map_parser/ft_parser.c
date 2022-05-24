/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_parser.c                                        :+:      :+:    :+:   */
/*                                                     +:+                    */
/*   By: lde-la-h <lde-la-h@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/12 13:17:18 by lde-la-h      #+#    #+#                 */
/*   Updated: 2022/05/24 11:31:01 by dvan-der         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Parser.h"

void	ft_exit_parser(char *error_line, int32_t row, size_t column, char *func)
{
	printf("Error\n%s in %s\nRow: %i, collumn; %zu\n", error_line, func, row, \
	column);
	ft_putendl_fd("--------------------------------------------------------", \
	STDERR_FILENO);
	exit (EXIT_FAILURE);
}

static void	ft_parse_line(t_RT *rt, char *line, int32_t row)
{
	size_t					id_len;
	int32_t					i;
	static const t_JmpTable	table[] = {
	{.id = "A", .func = &ft_add_ambient},
	{.id = "C", .func = &ft_add_camera},
	{.id = "L", .func = &ft_add_light},
	{.id = "sp", .func = &ft_add_sphere},
	{.id = "pl", .func = &ft_add_plane},
	{.id = "cy", .func = &ft_add_cylinder},
	};

	if (ft_isempty(line))
		return ;
	i = -1;
	while (++i < (int32_t)(sizeof(table) / sizeof(t_JmpTable)))
	{
		id_len = ft_strlen(table[i].id);
		if (ft_strncmp(table[i].id, line, id_len) == 0)
		{
			table[i].func(rt, line + id_len, row);
			return ;
		}
	}
	if (line[0] != '\n')
		ft_exit_parser("Unrecognized symbols", row, 0, "file");
}

bool	ft_read_map(t_RT *rt, char *file)
{
	char			*line;
	int32_t			row;
	int32_t			rt_file;

	if (ft_strncmp(&file[ft_strlen(file) - 3], ".rt", 3))
	{
		ft_putstr_fd("Error\nIncorrect filename\n", 2);
		return (false);
	}
	rt_file = open(file, O_RDONLY);
	if (rt_file == -1)
		return (perror("MiniRT"), false);
	row = 0;
	ft_bzero(&rt->world, sizeof(t_World));
	while (true)
	{
		line = ft_get_next_line(rt_file);
		if (!line)
			break ;
		ft_parse_line(rt, line, ++row);
		free(line);
		if (rt->world.object_count == MAX_OBJECTS)
			return (false);
	}
	return (rt->world.camera_count != 0);
}
