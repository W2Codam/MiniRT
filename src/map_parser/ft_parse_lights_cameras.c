/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_parse_lights_cameras.c                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: lde-la-h <lde-la-h@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/12 13:15:42 by lde-la-h      #+#    #+#                 */
/*   Updated: 2022/04/21 16:59:19 by lde-la-h      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Parser.h"

void	ft_add_light(t_RT *rt, char *line, int32_t row)
{
	size_t			i;
	t_Light *const	light = &rt->world.lights[rt->world.light_count];

	i = 0;
	light->is_ambient = false;
	light->position = ft_init_coordinates(line, row, &i, 0);
	light->intensity = ft_init_number(line, row, &i, 1);
	if (light->intensity < 0 || light->intensity > 1)
		ft_exit_parser("Surpassed range", row, i, "init_ambient");
	light->color = ft_init_color(line, row, &i);
	if (line[i] != '\n')
		ft_exit_parser("Missing immediate newline", row, i, "init_light");
	rt->world.light_count++;
}

void	ft_add_ambient(t_RT *rt, char *line, int32_t row)
{
	size_t			i;
	t_Light *const	light = &rt->world.ambient;

	i = 0;
	if (rt->has_ambient)
		ft_exit_parser("Multiple ambient lighting", row, i, "init_ambient");
	light->is_ambient = true;
	light->position = ft_new_fvec3(0, 0, 0);
	light->intensity = ft_init_number(line, row, &i, 1);
	if (light->intensity < 0 || light->intensity > 1)
		ft_exit_parser("Surpassed range", row, i, "init_ambient");
	light->color = ft_init_color(line, row, &i);
	if (line[i] != '\n')
		ft_exit_parser("Missing immediate newline", row, i, "init_ambient");
	rt->has_ambient = true;
}

// void coordSystem(vec3 n, out vec3 r, out vec3 u)
// {
// 	if (abs(n.x) > abs(n.y))
// 		u = vec3(n.z, 0, -n.x) / sqrt(n.x * n.x + n.z * n.z);
// 	else
// 		u = vec3(0, -n.z, n.y) / sqrt(n.y * n.y + n.z * n.z);
// 	r = cross(n, u);
// }

static void	ft_dir_to_mat(t_FVec3 normal, t_FVec3 arb, t_FVec3 *matrix_out[3])
{
	(*matrix_out)[2] = ft_new_fvec3(normal.x, normal.y, normal.z);
	(*matrix_out)[0] = ft_cross_fvec3(arb, (*matrix_out)[2]);
	(*matrix_out)[1] = ft_cross_fvec3((*matrix_out)[0], (*matrix_out)[2]);
}

//	transpose

void	ft_add_camera(t_RT *rt, char *line, int32_t row)
{
	size_t			i;
	t_FVec3			dir;
	t_Camera *const	camera = &rt->world.cameras[rt->world.camera_count];

	i = 0;
	camera->position = ft_init_coordinates(line, row, &i, 0);
	dir = ft_init_coordinates(line, row, &i, 1);
	ft_dir_to_mat(dir, ft_new_fvec3(0.577,0.577,0.577), &camera->rotation_matrix);
	camera->fov = ft_init_number(line, row, &i, 0);
	if (camera->fov > 180 || camera->fov < 0)
		ft_exit_parser("Surpassed range", row, i, "init_camera");
	if (line[i] != '\n')
		ft_exit_parser("Missing immediate newline", row, i, "init_camera");
	rt->world.camera_count++;
}
