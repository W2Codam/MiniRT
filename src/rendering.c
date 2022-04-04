/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   rendering.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: lde-la-h <lde-la-h@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/28 19:30:49 by lde-la-h      #+#    #+#                 */
/*   Updated: 2022/04/04 14:45:05 by lde-la-h      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "MiniRT.h"

static int32_t	create_rgba(int32_t r, int32_t g, int32_t b, int32_t a)
{
	return (r << 24 | g << 16 | b << 8 | a);
}

static t_FVec3	ft_ray_color(t_Ray ray) 
{
	normalize_fvec3(&ray.direction);
    const float t = 0.5 * (ray.direction.y + 1.0);

    //return (1.0f - t) * new_fvec3(1.0f, 1.0f, 1.0f) + t * new_fvec3(0.5, 0.7, 1.0);
	
}

static t_Ray	ft_make_ray(t_rt *rt, uint32_t x, uint32_t y)
{
	// Translate screen space to world space.
	const float		u = (float)x / (rt->window_img->width - 1);
	const float 	v = (float)y / (rt->window_img->height - 1);
	const float		a = u * rt->window_img->width;
	const float		b = v * rt->window_img->height;
	const t_Camera	*cam = ft_get_active_camera(rt);

	// Make the ray. cam->top_left + a + b - origin
	return ((t_Ray) {
	cam->transform.pos,
	sub_vec3(add_fvec3(add_fvec3(cam->top_left, a), b), cam->transform.pos)
	});
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
			//printf("Ray: POS: %f %f %f | DIR: %f %f %f\n", \
			//ray.origin.x, ray.origin.y, ray.origin.z, \
			//ray.direction.x, ray.direction.y, ray.direction.z);
			const int32_t color = create_rgba(rand() % 255, rand() % 255, rand() % 255, 255);
			mlx_put_pixel(rt->window_img, x, y, color);
			x++;
		}
		y++;
	}
	/*
    auto horizontal = vec3(rt->window_img., 0, 0);
    auto vertical = vec3(0, viewport_height, 0);
    auto lower_left_corner = origin - (horizontal / 2 - vertical / 2) - vec3(0, 0, );

	*/
}

/*
	for (size_t y = 0; y < rt->window_img->height; y++)
		for (size_t x = 0; x < rt->window_img->width; x++)
		{
			const int32_t color = create_rgba(rand() % 255, rand() % 255, rand() % 255, 255);
			mlx_put_pixel(rt->window_img, x, y, color);
		}
*/