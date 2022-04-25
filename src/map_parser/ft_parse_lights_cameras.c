/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_parse_lights_cameras.c                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: lde-la-h <lde-la-h@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/12 13:15:42 by lde-la-h      #+#    #+#                 */
/*   Updated: 2022/04/25 19:14:21 by lde-la-h      ########   odam.nl         */
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
/*
void	ft_lookat(t_FVec3 out[3] ,t_FVec3 origin, t_FVec3 look_at)
{
	t_FVec3		check;
	t_FVec3		up_tmp;
	t_FVec3		forward;
	t_FVec3		right;
	t_FVec3		up;

	check = vec3_unit(look_at);
	if (check.x == 0.0 && fabs(check.y) == 1.0 && check.z == 0.0)
	{
		forward = vec3_unit(vec3_mult_s(vec3_sub(origin, look_at), -1));
		right = vec3_id(ID_X);
	}
	else
	{
		up_tmp = vec3_id(ID_Y);
		forward = vec3_unit(vec3_mult_s(vec3_sub(origin, look_at), -1));
		right = vec3_cross(up_tmp, forward);
	}
	up = vec3_cross(forward, right);
	return (mat4(origin, forward, right, up));
}
*/

void	ft_add_camera(t_RT *rt, char *line, int32_t row)
{
	size_t			i;
	t_FVec3			dir;
	t_Camera *const	camera = &rt->world.cameras[rt->world.camera_count];

	i = 0;
	camera->position = ft_init_coordinates(line, row, &i, 0);
	dir = ft_init_coordinates(line, row, &i, 1);
	camera->direction = dir;
	cam->world = mat4_lookat(cam->origin, vec3_add(cam->origin, cam->normal));
	camera->rotation_matrix[2] = ft_new_fvec3(dir.x, dir.y, dir.z);
	camera->rotation_matrix[0] = ft_cross_fvec3(ft_new_fvec3(0.577,0.577,0.577), camera->rotation_matrix[2]);
	camera->rotation_matrix[1] = ft_cross_fvec3(camera->rotation_matrix[0], camera->rotation_matrix[2]);
	//ft_dir_to_mat(dir, ft_new_fvec3(0.577,0.577,0.577), &camera->rotation_matrix);
	camera->fov = ft_init_number(line, row, &i, 0);
	if (camera->fov > 180 || camera->fov < 0)
		ft_exit_parser("Surpassed range", row, i, "init_camera");
	if (line[i] != '\n')
		ft_exit_parser("Missing immediate newline", row, i, "init_camera");
	rt->world.camera_count++;
}
