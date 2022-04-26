/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lights.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: lde-la-h <lde-la-h@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/14 15:10:46 by lde-la-h      #+#    #+#                 */
<<<<<<< HEAD
/*   Updated: 2022/04/26 11:37:34 by dvan-der         ###   ########.fr       */
=======
/*   Updated: 2022/04/26 13:52:34 by lde-la-h      ########   odam.nl         */
>>>>>>> 85c1b7129a7ff0722896469396ff81dd2ec19e29
/*                                                                            */
/* ************************************************************************** */

#include "MiniRT.h"

//= Private =//

static float	ft_max_float(float a, float b)
{
	return (a * (a >= b) + b * (b > a));
}

<<<<<<< HEAD
=======
static t_FVec3	ft_calc_light(t_Light *light, t_Ray ray, t_FVec3 hit, \
t_FVec3 *normal)
{
	const t_FVec3	light_color = ft_from_rgba(light->color);
	const float		shade = ft_max_float(ft_dot_fvec3(*normal, ray.dir), 0.0f) \
	/ ft_distance(hit, light->position);

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
>>>>>>> 85c1b7129a7ff0722896469396ff81dd2ec19e29
t_FVec3	ft_apply_lights(t_RT *rt, t_Ray cur_ray, t_Hit *hit, t_FVec3 *normal)
{
	uint16_t		i;
	t_FVec3			color;
	t_Light			*light;
	t_Ray			ray_light;
<<<<<<< HEAD
	t_FVec3			output_color;
	const t_FVec3	hit_pos = ft_ray_at(&cur_ray, hit->distance);
	const t_FVec3	ambient_col = ft_mul_fvec3f(ft_from_rgba\
			(rt->world.ambient.color), rt->world.ambient.intensity);

	t_FVec3	new;
	new.x = hit_pos.x + normal->x * 0.0001;
	new.y = hit_pos.y + normal->y * 0.0001;
	new.z = hit_pos.z + normal->z * 0.0001;
=======
	const t_FVec3	hit_pos = \
	ft_correct_hit(ft_ray_at(&cur_ray, hit->distance), normal);
>>>>>>> 85c1b7129a7ff0722896469396ff81dd2ec19e29

	i = 0;
	color = ft_mul_fvec3(ft_from_rgba(hit->object->color), ft_mul_fvec3f(\
	ft_from_rgba(rt->world.ambient.color), rt->world.ambient.intensity));
	while (i < rt->world.light_count)
	{
		light = &rt->world.lights[i];
		ray_light = ft_new_ray(hit_pos, ft_sub_fvec3(light->position, hit_pos));

		if (ft_ray_intersect_any(rt, ray_light).distance <= 0)
			color = ft_add_fvec3(color, \
			ft_calc_light(light, ray_light, hit_pos, normal));
		i++;
	}
	return (ft_mul_fvec3(ft_from_rgba(hit->object->color), color));
}
