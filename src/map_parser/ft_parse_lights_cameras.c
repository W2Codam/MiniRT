/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_parse_lights_cameras.c                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: lde-la-h <lde-la-h@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/12 13:15:42 by lde-la-h      #+#    #+#                 */
/*   Updated: 2022/04/21 11:23:54 by lde-la-h      ########   odam.nl         */
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

void	ft_add_camera(t_RT *rt, char *line, int32_t row)
{
	size_t			i;
	t_Camera *const	camera = &rt->world.cameras[rt->world.camera_count];

	i = 0;
	camera->position = ft_init_coordinates(line, row, &i, 0);
	camera->rotation = ft_init_coordinates(line, row, &i, 1);
	camera->fov = ft_init_number(line, row, &i, 0);
	if (camera->fov > 180 || camera->fov < 0)
		ft_exit_parser("Surpassed range", row, i, "init_camera");
	if (line[i] != '\n')
		ft_exit_parser("Missing immediate newline", row, i, "init_camera");
	ft_new_camera(camera, camera->position, ft_new_fvec3(0, 0, 0), camera->fov);
	rt->world.camera_count++;
}
