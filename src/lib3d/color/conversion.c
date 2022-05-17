/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   conversion.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: lde-la-h <lde-la-h@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/11 19:21:29 by lde-la-h      #+#    #+#                 */
/*   Updated: 2022/05/17 09:10:23 by lde-la-h      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "lib3d.h"

// Linear to int
uint32_t	ft_to_rgba(t_FVec3 linear)
{
	const int32_t	r = (int32_t)(256 * ft_clamp(linear.x, 0.0f, 0.999f));
	const int32_t	g = (int32_t)(256 * ft_clamp(linear.y, 0.0f, 0.999f));
	const int32_t	b = (int32_t)(256 * ft_clamp(linear.z, 0.0f, 0.999f));

	return (r << 24 | g << 16 | b << 8 | 255);
}

// 0-255 Vec3 to int
uint32_t	ft_from_color(t_FVec3 color)
{
	const int32_t	r = (int32_t)color.x;
	const int32_t	g = (int32_t)color.y;
	const int32_t	b = (int32_t)color.z;

	return (r << 24 | g << 16 | b << 8 | 255);
}

// 0 - 255 to linear
t_FVec3	ft_from_rgba(t_FVec3 color)
{
	const float	r = (color.x / 255.999f);
	const float	g = (color.y / 255.999f);
	const float	b = (color.z / 255.999f);

	return (ft_new_fvec3(r, g, b));
}

// linear to 0-255
t_FVec3	ft_to_color(t_FVec3 linear)
{
	const uint32_t	color = ft_to_rgba(linear);
	const int32_t	r = roundf((color >> 24) & 0xFF);
	const int32_t	g = roundf((color >> 16) & 0xFF);
	const int32_t	b = roundf((color >> 8) & 0xFF);

	return (ft_new_fvec3(r, g, b));
}
