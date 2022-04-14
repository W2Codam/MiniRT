/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_rendering.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: lde-la-h <lde-la-h@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/11 19:20:35 by lde-la-h      #+#    #+#                 */
/*   Updated: 2022/04/14 12:47:47 by lde-la-h      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "MiniRT.h"

//= Private =//

static t_FVec3	ft_hit_nothing(t_Ray ray)
{
	float		t;
	t_FVec3		a;
	t_FVec3		b;

	ft_normalize_fvec3(&ray.dir);
	t = 0.5f * (ray.dir.y + 1.0f);
	a = ft_mul_fvec3f(ft_new_fvec3(1.0f, 1.0f, 1.0f), 1.0f - t);
	b = ft_mul_fvec3f(ft_new_fvec3(0.5f, 0.7f, 1.0f), t);
	return (ft_add_fvec3(a, b));
}

// Kd * DOT(N, L) * Od * Ld
static uint32_t	ft_ray_color(t_RT *rt, t_Ray ray)
{
	t_Hit		hit;
	t_FVec3		normal;
	uint32_t	out_color;
	const bool	is_hit = ft_ray_to_world(rt, ray, &normal, &hit);

	// TODO: LET THERE BE LIGHT!
	if (is_hit)
	{
		// 1. Diffuse
		// 2. (Specular)
		// 3. Ambient
		// Ka * Od * Ld
		out_color = ft_to_rgba(hit.object->color);

		return (out_color);
	}
	return (ft_to_rgba(ft_hit_nothing(ray)));
}

static t_Ray	ft_fire_ray(t_RT *rt, t_Camera *camera, uint32_t x, uint32_t y)
{
	const float		u = (float)x / (rt->canvas->width - 1);
	const float		v = (float)y / (rt->canvas->height - 1);
	const t_FVec3	a = ft_add_fvec3(camera->llc, \
						ft_mul_fvec3f(camera->horizontal, u));
	const t_FVec3	b = ft_sub_fvec3(ft_mul_fvec3f(camera->vertical, v), \
						camera->position);

	return (ft_new_ray(camera->position, ft_add_fvec3(a, b)));
}

//= Public =//

void	ft_draw_world(t_RT *rt)
{
	int32_t		x;
	int32_t		y;
	t_Ray		ray;
	uint32_t	color;

	y = ((int32_t)rt->canvas->height) - 1;
	while (y >= 0)
	{
		x = 0;
		while (x < ((int32_t)rt->canvas->width))
		{
			ray = ft_fire_ray(rt, ft_get_active_camera(rt), x, y);
			color = ft_ray_color(rt, ray);
			mlx_put_pixel(rt->canvas, x, rt->canvas->height - y, color);
			x++;
		}
		y--;
	}
}

/*
    for (int j = image_height-1; j >= 0; --j) {
        std::cerr << "\rScanlines remaining: " << j << ' ' << std::flush;
        for (int i = 0; i < image_width; ++i) {
            color pixel_color(0, 0, 0);
            for (int s = 0; s < samples_per_pixel; ++s) {
                auto u = (i + random_double()) / (image_width-1);
                auto v = (j + random_double()) / (image_height-1);
                ray r = cam.get_ray(u, v);
                pixel_color += ray_color(r, world);
            }
            write_color(std::cout, pixel_color, samples_per_pixel);
        }
    }
*/