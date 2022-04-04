/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_entities.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvan-der <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 11:20:34 by dvan-der          #+#    #+#             */
/*   Updated: 2022/04/04 14:43:54 by dvan-der         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MiniRT"

create_entity(t_rt *rt, char *line, int (*f)(t_rt *, char *))
{
	:wq

}

init_line(t_rt *rt, char *line)
{
	int	result;
	if (line[0] == 'A' && ft_isspace(line[1]))
		result = create_entity(rt, line, ambient_light);
	else if (line[
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

