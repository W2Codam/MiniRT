#include "MiniRT.h"

t_FVec3	ft_normal_sphere(t_Ray ray, t_Hit hit)
{
	t_FVec3		normal;
	t_FVec3		point_at_t;
	t_Sphere	sphere;

	sphere = hit.object->as_sphere;
	point_at_t = ft_ray_at(&ray, hit.distance);
	normal = ft_normalize_fvec3_2(ft_sub_fvec3(point_at_t, sphere.center));
	return (normal);
}

t_FVec3 ft_normal_plane(t_Ray ray, t_Hit hit)
{
	float	side;
	t_Plane	plane;
	t_FVec3	normal;

	plane = hit.object->as_plane;
	side = ft_dot_fvec3(plane.dir, ray.dir);
	if (side > 0.)
		normal = (ft_sub_fvec3(ft_new_fvec3(0, 0, 0), \
					ft_normalize_fvec3_2(plane.dir)));
	else
		normal = ft_normalize_fvec3_2(plane.dir); 
	return (normal);
}

