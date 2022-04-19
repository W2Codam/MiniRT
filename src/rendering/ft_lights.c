/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lights.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: lde-la-h <lde-la-h@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/14 15:10:46 by lde-la-h      #+#    #+#                 */
/*   Updated: 2022/04/19 10:50:48 by lde-la-h      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "MiniRT.h"

static float ft_max_float(float a, float b)
{
	return (a * (a >= b) + b * (b > a));
}

static t_FVec3 ft_mult_float(t_FVec3 color, float a)
{
	return (ft_new_fvec3(color.x * a, color.y * a, color.z * a));
}

//= Public =//

t_FVec3	ft_apply_lights(t_RT *rt, t_Ray cur_ray, t_Hit *hit, t_FVec3 *normal)
{
	uint16_t		i;
	t_Light			*light;
	t_Ray			ray_light;
	t_FVec3			diffuse;
	const t_FVec3	obj_pos = ft_ray_at(&cur_ray, hit->distance);

	i = 0;
	ft_bzero(&diffuse, sizeof(t_FVec3));
	//out_color = hit->object->color;
	while (i < rt->world.light_count)
	{
		light = &rt->world.lights[i];
		ray_light = ft_new_ray(obj_pos, ft_sub_fvec3(light->position, obj_pos));

		// TODO: Norme
		const t_Hit hit = ft_ray_intersect_any(rt, ray_light);
		if (hit.distance > 0)
		{
			// Divison is for distance! Keep it or leave it if you want
			float shade = ft_max_float(ft_dot_fvec3(*normal, ray_light.dir), 0.0f) / (ft_distance(obj_pos, light->position) * (ft_distance(obj_pos, light->position)));
			t_FVec3 color_l = ft_mult_float(light->color, shade);
			diffuse = ft_add_fvec3(diffuse, color_l);
		}
		i++;
	}

	return (ft_muls_color(ft_add_fvec3(rt->world.ambient.color, diffuse), hit->object->color, rt->world.ambient.intensity));
}
