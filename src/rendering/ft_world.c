#include "MiniRT.h"

static t_FVec3	hit_object(t_Ray ray, t_Hit hit)
{
	t_FVec3	normal;

	if (hit.object->type == SPHERE)
	{
		normal = ft_normal_sphere(ray, hit);
		return (hit.object->color);
	}
	else if (hit.object->type == PLANE)
	{
		normal = ft_normal_plane(ray, hit);
		return (hit.object->color);
	}
	else
		normal = ft_new_fvec3(0, 0, 0);
	//else if (hit.object.type == CYLINDER)
	//	normal = ft_normal_cylinder(ray, hit);
	return (ft_mul_fvec3f(ft_add_fvec3(normal, ft_new_fvec3(1, 1, 1)), 0.5f));
}

static t_FVec3	hit_nothing(t_Ray ray)
{
	//float		t;
	//t_FVec3		a;
	//t_FVec3		b;

	//ft_normalize_fvec3(&ray.dir);
	//t = 0.5f * (ray.dir.y + 1.0f);
	//a = ft_mul_fvec3f(ft_new_fvec3(1.0f, 1.0f, 1.0f), 1.0f - t);
	//b = ft_mul_fvec3f(ft_new_fvec3(0.5f, 0.7f, 1.0f), t);
	//return (ft_add_fvec3(a, b));
	(void)ray;
	return (ft_new_fvec3(0, 0, 0));
}

static t_Hit	ft_hittables(t_RT *rt, t_Ray ray)
{
	uint16_t	i;
	t_Hit		new_hit;
	t_Hit		closest_hit;
	bool		first_hit;

	i = 0;
	first_hit = true;
	closest_hit.distance = -1.0f;
	while (i < rt->world.object_count)
	{
		if (rt->world.objects[i].intersects(&rt->world.objects[i], &ray, &new_hit))
		{
			printf("hit_distance: %f\n", new_hit.distance);
			if (new_hit.distance > 0.0f)
			{
				if (first_hit)
				{
					closest_hit = new_hit;
					first_hit = false;
				}
				else if (new_hit.distance < closest_hit.distance)
					closest_hit = new_hit;
			}
		}
		i++;
	}
	return (closest_hit);
}

uint32_t	ray_to_world(t_RT *rt, t_Ray ray)
{
	t_Hit		hit;

	hit = ft_hittables(rt, ray);
	if (hit.distance > 0.0f)
		return (ft_to_rgba(hit_object(ray, hit)));
	else
		return (ft_to_rgba(hit_nothing(ray)));
}

