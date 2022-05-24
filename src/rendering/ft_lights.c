/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lights.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: lde-la-h <lde-la-h@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/14 15:10:46 by lde-la-h      #+#    #+#                 */
/*   Updated: 2022/05/17 13:46:02 by lde-la-h      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "MiniRT.h"

//= Private =//

static float	ft_max_float(float a, float b)
{
	return (a * (a >= b) + b * (b > a));
}

static t_FVec3	ft_calc_light(t_Light *light, t_Ray ray, t_FVec3 *normal)
{
	const t_FVec3	light_color = ft_from_rgba(light->color);
	const float		shade = ft_max_float(ft_dot_fvec3(*normal, ray.dir), 0.0f);

	return (ft_mul_fvec3f(ft_mul_fvec3f(light_color, shade), light->intensity));
}

// Correct for acnee
static t_FVec3	ft_correct_hit(t_FVec3 hit, t_FVec3 *normal)
{
	const t_FVec3	new = ft_new_fvec3(\
	hit.x + normal->x * 0.0001, \
	hit.y + normal->y * 0.0001, \
	hit.z + normal->z * 0.0001);

	return (new);
}

static bool	ft_shit(t_RT *rt, t_Ray *ray_light, t_Light *light, \
const t_FVec3 hit_pos)
{
	float			dist;
	const t_FVec3	delta = ft_sub_fvec3(light->position, hit_pos);

	*ray_light = ft_new_ray(hit_pos, ft_normalize_fvec3_2(delta));
	dist = ft_ray_intersect_any(rt, *ray_light, ft_len_fvec3(delta)).distance;
	if (dist <= 0 || dist > ft_len_fvec3(delta))
		return (true);
	return (false);
}

//= Public =//

/**
 * Calculates the lights onto the object color.
 * 
 * @param rt Intance
 * @param cur_ray The current ray that is being sent.
 * @param hit The hit result.
 * @param normal The hit normal
 * @return t_FVec3 The color to draw.
 */
t_FVec3	ft_apply_lights(t_RT *rt, t_Ray cur_ray, t_Hit *hit, t_FVec3 *normal)
{
	uint16_t		i;
	t_FVec3			color;
	t_Light			*light;
	t_Ray			ray_light;
	const t_FVec3	hit_pos = \
	ft_correct_hit(ft_ray_at(&cur_ray, hit->distance), normal);

	i = 0;
	color = ft_mul_fvec3(ft_from_rgba(hit->object->color), ft_mul_fvec3f(\
	ft_from_rgba(rt->world.ambient.color), rt->world.ambient.intensity));
	while (i < rt->world.light_count)
	{
		light = &rt->world.lights[i];
		if (ft_shit(rt, &ray_light, light, hit_pos))
			color = ft_add_fvec3(color, \
			ft_calc_light(light, ray_light, normal));
		i++;
	}
	return (ft_mul_fvec3(ft_from_rgba(hit->object->color), color));
}
