/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lights.c                                        :+:      :+:    :+:   */
/*                                                     +:+                    */
/*   By: lde-la-h <lde-la-h@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/14 15:10:46 by lde-la-h      #+#    #+#                 */
/*   Updated: 2022/04/26 11:37:34 by dvan-der         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MiniRT.h"

//= Private =//

static float ft_max_float(float a, float b)
{
	return (a * (a >= b) + b * (b > a));
}

t_FVec3	ft_apply_lights(t_RT *rt, t_Ray cur_ray, t_Hit *hit, t_FVec3 *normal)
{
	uint16_t		i;
	t_Light			*light;
	t_Ray			ray_light;
	t_FVec3			output_color;
	const t_FVec3	hit_pos = ft_ray_at(&cur_ray, hit->distance);
	const t_FVec3	ambient_col = ft_mul_fvec3f(ft_from_rgba\
			(rt->world.ambient.color), rt->world.ambient.intensity);

	t_FVec3	new;
	new.x = hit_pos.x + normal->x * 0.0001;
	new.y = hit_pos.y + normal->y * 0.0001;
	new.z = hit_pos.z + normal->z * 0.0001;

	i = 0;
	output_color = ft_mul_fvec3(ft_from_rgba(hit->object->color), ambient_col);
	while (i < rt->world.light_count)
	{
		light = &rt->world.lights[i];
		ray_light = ft_new_ray(new, ft_sub_fvec3(light->position, new));
	
		t_Hit l_hit = ft_ray_intersect_any(rt, ray_light);
		if (l_hit.distance <= 0)
		{
			t_FVec3 light_color = ft_from_rgba(light->color);
			const float shade = ft_max_float(ft_dot_fvec3(*normal, ray_light.dir), 0.0f) \
			/ ft_distance(hit_pos, light->position);
	
			light_color = ft_mul_fvec3f(ft_mul_fvec3f(light_color, shade), light->intensity);
			output_color = ft_add_fvec3(output_color, light_color);
		}
		i++;
	}
	output_color = ft_mul_fvec3(ft_from_rgba(hit->object->color), output_color);
	return (output_color); 
}
