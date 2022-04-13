/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_parser.c                                        :+:      :+:    :+:   */
/*                                                     +:+                    */
/*   By: lde-la-h <lde-la-h@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/12 13:17:18 by lde-la-h      #+#    #+#                 */
/*   Updated: 2022/04/12 16:14:36 by lde-la-h      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Parser.h"

void	ft_exit_parser(char *error_line, int32_t row, size_t column, char *func)
{
	printf("Error: %s in %s\nRow: %i, collumn; %zu\n", error_line, func, row, \
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
	{.id = "tr", .func = &ft_add_triangle},
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
}

bool	ft_read_map(t_RT *rt, char *file)
{
	char			*line;
	int32_t			row;
	const int32_t	rt_file = open(file, O_RDONLY);

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
	}
	return (true);
}
