#include "MiniRT.h"

void	init_sphere(t_rt *rt, char *line, int row)
{
	size_t			i;
	t_SphereModel	sphere;

	i = 0;
	rt->objects[rt->objects_size].type = SPHERE;
	sphere = rt->objects[rt->objects_size].entity_sphere; 
	sphere.base.transform.pos = init_coordinates(line, row, &i, 0);
	sphere.diameter = init_number(line, row, &i, 1);
	if (sphere.diameter <= 0)
		exit_parser("Must be positive value", row, i, "init_sphere");
	sphere.base.color = init_color(line, row, &i);
	//rt->objects[objects_size].material;
	//rt->objects[objects_size].texture;
	sphere.intersect = intersect_sphere;
	if (line[i] != '\n')
		exit_parser("Missing immediate newline", row, i, "init_sphere");
	(rt->objects_size)++;
	return ;
}

void	init_plane(t_rt *rt, char *line, int row)
{
	size_t			i;
	t_PlaneModel	plane;

	i = 0;
	rt->objects[rt->objects_size].type = PLANE;
	plane = rt->objects[rt->objects_size].entity_plane; 
	plane.base.transform.pos = init_coordinates(line, row, &i, 0);
	plane.base.transform.rot = init_coordinates(line, row, &i, 1);
	plane.base.color = init_color(line, row, &i);
	//rt->objects[objects_size].material;
	//rt->objects[objects_size].texture;
	plane.intersect = intersect_plane;
	if (line[i] != '\n')
		exit_parser("Missing immediate newline", row, i, "init_plane");
	(rt->objects_size)++;
	return ;
}

void	init_cylinder(t_rt *rt, char *line, int row)
{
	size_t			i;
	t_CylinderModel	cylinder;
	
	i = 0;
	rt->objects[rt->objects_size].type = SPHERE;
	cylinder = rt->objects[rt->objects_size].entity_cylinder; 
	cylinder.base.transform.pos = init_coordinates(line, row, &i, 0);
	cylinder.base.transform.rot = init_coordinates(line, row, &i, 1);
	cylinder.height = init_number(line, row, &i, 1);
	cylinder.diameter = init_number(line, row, &i, 1);
	if (cylinder.height <= 0 || cylinder.diameter <= 0)
		exit_parser("Must be positive valur", row, i, "init_cylinder");
	cylinder.base.color = init_color(line, row, &i);
	//rt->objects[objects_size].material;
	//rt->objects[objects_size].texture;
	cylinder.intersect = intersect_cylinder;
	if (line[i] != '\n')
		exit_parser("Missing immediate newline", row, i, "init_cylinder");
	(rt->objects_size)++;
	return ;
}

void	init_triangle(t_rt *rt, char *line, int row)
{
	size_t			i;
	t_TriangleModel	triangle;
	
	i = 0;
	rt->objects[rt->objects_size].type = TRIANGLE;
	triangle = rt->objects[rt->objects_size].entity_triangle; 
	triangle.vertices[0] = init_coordinates(line, row, &i, 0);
	triangle.vertices[1] = init_coordinates(line, row, &i, 0);
	triangle.vertices[2] = init_coordinates(line, row, &i, 0);
	triangle.color = init_color(line, row, &i);
	//rt->objects[objects_size].material;
	//rt->objects[objects_size].texture;
	triangle.intersect = intersect_triangle;
	if (line[i] != '\n')
		exit_parser("Missing immediate newline", row, i, "init_triangle");
	(rt->objects_size)++;
	return ;
}
