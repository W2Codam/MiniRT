/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_parse_lights_cameras.c                          :+:      :+:    :+:   */
/*                                                     +:+                    */
/*   By: lde-la-h <lde-la-h@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/12 13:15:42 by lde-la-h      #+#    #+#                 */
/*   Updated: 2022/04/26 11:33:17 by dvan-der         ###   ########.fr       */
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

void	ft_lookat(t_FVec3 out[3], t_FVec3 origin, t_FVec3 look_at)
{
	t_FVec3		check;
	t_FVec3		up_tmp;
	t_FVec3		forward;
	t_FVec3		right;
	t_FVec3		up;

	check = ft_normalize_fvec3_2(look_at);
	if (check.x == 0.0 && fabs(check.y) == 1.0 && check.z == 0.0)
	{
		forward = ft_normalize_fvec3_2(ft_mul_fvec3f(\
					ft_sub_fvec3(origin, look_at), -1));
		right = ft_new_fvec3(1, 0, 0);
	}
	else
	{
		up_tmp = ft_new_fvec3(0, 1, 0);
		forward = ft_normalize_fvec3_2(ft_mul_fvec3f(\
					ft_sub_fvec3(origin, look_at), -1));
		right = ft_cross_fvec3(up_tmp, forward);
	}
	up = ft_cross_fvec3(forward, right);
	out[0] = right;
	out[1] = up;
	out[2] = forward;
}

void	ft_add_camera(t_RT *rt, char *line, int32_t row)
{
	size_t			i;
	t_FVec3			dir;
	t_Camera *const	camera = &rt->world.cameras[rt->world.camera_count];

	i = 0;
	camera->position = ft_init_coordinates(line, row, &i, 0);
	dir = ft_init_coordinates(line, row, &i, 1);
	camera->direction = dir;
	ft_lookat(camera->rotation_matrix, camera->position,
		ft_add_fvec3(camera->position, camera->direction));
	camera->fov = ft_init_number(line, row, &i, 0);
	camera->fov = tanf((camera->fov * 0.5) * (M_PI / 180));
	if (camera->fov > 180 || camera->fov < 0)
		ft_exit_parser("Surpassed range", row, i, "init_camera");
	if (line[i] != '\n')
		ft_exit_parser("Missing immediate newline", row, i, "init_camera");
	rt->world.camera_count++;
}
