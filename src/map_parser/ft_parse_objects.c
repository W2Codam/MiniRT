/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_parse_objects.c                                 :+:      :+:    :+:   */
/*                                                     +:+                    */
/*   By: lde-la-h <lde-la-h@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/12 13:17:20 by lde-la-h      #+#    #+#                 */
/*   Updated: 2022/04/25 10:58:52 by dvan-der         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Parser.h"

void	ft_add_sphere(t_RT *rt, char *line, int32_t row)
{
	size_t			i;
	t_Object *const	sphere = &rt->world.objects[rt->world.object_count];

	i = 0;
	sphere->type = SPHERE;
	sphere->intersects = ft_intersect_sp;
	sphere->as_sphere.center = ft_init_coordinates(line, row, &i, 0);
	sphere->as_sphere.radius = ft_init_number(line, row, &i, 1) / 2;
	sphere->color = ft_init_color(line, row, &i);
	if (sphere->as_sphere.radius <= 0)
		ft_exit_parser("Must be positive value", row, i, "init_sphere");
	if (line[i] != '\n')
		ft_exit_parser("Missing immediate newline", row, i, "init_sphere");
	rt->world.object_count++;
}

void	ft_add_plane(t_RT *rt, char *line, int32_t row)
{
	size_t			i;
	t_Object *const	plane = &rt->world.objects[rt->world.object_count];

	i = 0;
	plane->type = PLANE;
	plane->intersects = ft_intersect_pl;
	plane->as_plane.center= ft_init_coordinates(line, row, &i, 0);
	plane->as_plane.dir = ft_init_coordinates(line, row, &i, 1);
	plane->color = ft_init_color(line, row, &i);
	if (line[i] != '\n')
		ft_exit_parser("Missing immediate newline", row, i, "init_plane");
	rt->world.object_count++;
}

void	ft_add_cylinder(t_RT *rt, char *line, int32_t row)
{
	size_t			i;
	t_Object *const	cylinder = &rt->world.objects[rt->world.object_count];

	i = 0;
	cylinder->type = CYLINDER;
	cylinder->intersects = ft_intersect_cl;
	cylinder->as_cylinder.center = ft_init_coordinates(line, row, &i, 0);
	cylinder->as_cylinder.dir = ft_init_coordinates(line, row, &i, 0);
	cylinder->as_cylinder.radius = ft_init_number(line, row, &i, 1) / 2;
	cylinder->as_cylinder.height = ft_init_number(line, row, &i, 1);
	cylinder->color = ft_init_color(line, row, &i);
	if (cylinder->as_cylinder.height <= 0 || \
		cylinder->as_cylinder.radius <= 0)
		ft_exit_parser("Must be positive value", row, i, "init_cylinder");
	if (line[i] != '\n')
		ft_exit_parser("Missing immediate newline", row, i, "init_cylinder");
	rt->world.object_count++;
}
