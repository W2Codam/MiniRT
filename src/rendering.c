/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   rendering.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: lde-la-h <lde-la-h@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/28 19:30:49 by lde-la-h      #+#    #+#                 */
/*   Updated: 2022/04/05 10:48:37 by lde-la-h      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "MiniRT.h"

static t_FVec3	ft_ray_color(t_Ray ray)
{
	float	t;
	t_FVec3	a;
	t_FVec3	b;

	if (intersect_sphere(new_fvec3(0, 0, -10), 0.1f, &ray))
		return (new_fvec3(1.0f, 0.0f, 0.0f));
	normalize_fvec3(&ray.direction);
	t = 0.5 * (ray.direction.y + 1.0);
	a = mul_fvec3(new_fvec3(1.0f, 1.0f, 1.0f), 1.0f - t);
	b = mul_fvec3(new_fvec3(0.5f, 0.7f, 1.0f), t);
	return (add_vec3(a, b));
}

static uint32_t	ft_linear_to_rgb(t_FVec3 linear)
{
	const int32_t	red = (int32_t)(linear.x * 255.0f);
	const int32_t	green = (int32_t)(linear.y * 255.0f);
	const int32_t	blue = (int32_t)(linear.z * 255.0f);

	return (red << 24 | green << 16 | blue << 8 | 255);
}

static t_Ray	ft_make_ray(t_rt *rt, uint32_t x, uint32_t y)
{
	t_Camera *const	camera = ft_get_active_camera(rt);
	const float		u = (double)x / (rt->window_img->width - 1);
	const float		v = (double)y / (rt->window_img->height - 1);
	const t_FVec3	a = add_vec3(camera->top_left, \
						mul_fvec3(camera->horizontal, u));
	const t_FVec3	b = sub_vec3(mul_fvec3(camera->vertical, v), \
						camera->transform.pos);

	return ((t_Ray){camera->transform.pos, add_vec3(a, b)});
}

/**
 * Draws the frame by raytracing each pixel.
 * 
 * TODO: // Do with iterations that is, every xth pixel then the rest.
 * 
 * @param rt 
 */
void	ft_draw(t_rt *rt)
{
	uint32_t	x;
	uint32_t	y;
	t_Ray		ray;

	y = 0;
	while (y < rt->window_img->height)
	{
		x = 0;
		while (x < rt->window_img->width)
		{
			ray = ft_make_ray(rt, x, y);
			mlx_put_pixel(rt->window_img, x, y, \
			ft_linear_to_rgb(ft_ray_color(ray)));
			x++;
		}
		y++;
	}
}
