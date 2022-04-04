/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   rendering.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: lde-la-h <lde-la-h@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/28 19:30:49 by lde-la-h      #+#    #+#                 */
/*   Updated: 2022/04/04 17:29:00 by lde-la-h      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "MiniRT.h"

static uint32_t	ft_to_color(t_FVec3 ray)
{
	const int32_t	red = (int32_t)(ray.x * 255.0f);
	const int32_t	green = (int32_t)(ray.y * 255.0f);
	const int32_t	blue = (int32_t)(ray.z * 255.0f);

	return (red << 24 | green << 16 | blue << 8 | 255);
}

static uint32_t	ft_ray_color(t_Ray ray) 
{
	float	t;
	t_FVec3	a;
	t_FVec3	b;

	normalize_fvec3(&ray.direction);
    t = 0.5 * (ray.direction.y + 1.0);
	a = mul_fvec3(new_fvec3(1.0f, 1.0f, 1.0f), 1.0f - t);
	b = mul_fvec3(new_fvec3(0.0f, 0.0f, 1.0f), t);
	return (ft_to_color(mul_fvec3(add_vec3(a, b), 0.5f)));
}

t_Ray	make_ray(t_FVec3 i_horizontal, t_FVec3 i_vertical, t_FVec3 llc, t_FVec3 origin)
{
	t_FVec3	help1;
	t_FVec3	help2;

	help1 = add_vec3(llc, i_horizontal);
	help2 = sub_vec3(i_vertical, origin);
	
	return ((t_Ray){origin, add_vec3(help1, help2)});
}

static t_Ray	ft_make_ray(t_rt *rt, uint32_t x, uint32_t y)
{
	// Translate screen space to world space.
	const t_Camera	*cam = ft_get_active_camera(rt);
	const float		u = (float)x / (rt->window_img->width - 1);
	const float 	v = (float)y / (rt->window_img->height - 1);
	const t_FVec3	a = mul_fvec3(cam->horizontal, u);
	const t_FVec3	b = mul_fvec3(cam->vertical, v);

	return (make_ray(a, b, cam->top_left, cam->transform.pos));
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
			// Shoot one ray from origin to topleft and move downwards.
			ray = ft_make_ray(rt, x, y);
			mlx_put_pixel(rt->window_img, x, rt->window_img->height - y, ft_ray_color(ray));
			x++;
		}
		y++;
	}
}
