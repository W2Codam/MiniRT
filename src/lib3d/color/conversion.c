/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   conversion.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: lde-la-h <lde-la-h@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/11 19:21:29 by lde-la-h      #+#    #+#                 */
/*   Updated: 2022/04/14 20:03:57 by lde-la-h      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "lib3d.h"

uint32_t	ft_to_rgba(t_FVec3 linear)
{
	const int32_t	r = (int32_t)(256 * ft_clamp(linear.x, 0.0f, 0.999f));
	const int32_t	g = (int32_t)(256 * ft_clamp(linear.y, 0.0f, 0.999f));
	const int32_t	b = (int32_t)(256 * ft_clamp(linear.z, 0.0f, 0.999f));

	return (r << 24 | g << 16 | b << 8 | 255);
}

t_FVec3		ft_from_rgba(t_FVec3 color)
{
	const int32_t	r = roundf(color.x / 255.999f);
	const int32_t	g = roundf(color.y / 255.999f);
	const int32_t	b = roundf(color.z / 255.999f);

	return (ft_new_fvec3(r, g, b));
}
