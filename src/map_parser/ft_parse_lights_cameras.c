#include "MiniRT.h"

void	init_light(t_rt *rt, char *line, int row)
{
	size_t	i;
	t_Light	light;

	i = 0;
	light = rt->lights[rt->lights_size];
	light.transform.pos = init_coordinates(line, row, &i, 0);
	light.transform.rot = init_coordinates(line, row, &i, 1);
	light.intensity = init_number(line, row, &i, 1);
	if (light.intensity < 0 || light.intensity > 1)
		exit_parser("Surpassed range", row, i, "init_ambient");
	light.color = init_color(line, row, &i);
	if (line[i] != '\n')
		exit_parser("Missing immediate newline", row, i, "init_light");
	rt->lights[rt->lights_size] = light;
	(rt->lights_size)++;
	return ;
}

void	init_ambient(t_rt *rt, char *line, int row)
{
	size_t		i;
	t_Ambient	ambient;

	i = 0;
	if (rt->ambient.active)
		exit_parser("Found multiple ambient lighting", row, i, "init_ambient");
	ambient = rt->ambient;
	ambient.intensity = init_number(line, row, &i, 1);
	if (ambient.intensity < 0 || ambient.intensity > 1)
		exit_parser("Surpassed range", row, i, "init_ambient");
	ambient.color = init_color(line, row, &i);
	if (line[i] != '\n')
		exit_parser("Missing immediate newline", row, i, "init_ambient");
	ambient.active = true;
	rt->ambient = ambient;
	return ;
}

void	init_camera(t_rt *rt, char *line, int row)
{
	size_t		i;
	t_Camera	camera;

	i = 0;
	camera = rt->cameras[rt->cameras_size];
	camera.transform.pos = init_coordinates(line, row, &i, 0);
	camera.transform.rot = init_coordinates(line, row, &i, 1);
	camera.fov = init_number(line, row, &i, 0);
	if (camera.fov > 180 || camera.fov < 0)
		exit_parser("Surpassed range", row, i, "init_camera");
	if (line[i] != '\n')
		exit_parser("Missing immediate newline", row, i, "init_camera");
	rt->cameras[rt->cameras_size] = camera;
	(rt->cameras_size)++;
	return ;
}
