/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   conversion.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: lde-la-h <lde-la-h@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/11 19:21:29 by lde-la-h      #+#    #+#                 */
/*   Updated: 2022/04/12 01:32:23 by W2Wizard      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "lib3d.h"

uint32_t	ft_to_rgba(t_FVec3 linear)
{
	const int32_t	red = (int32_t)(linear.x * 255.999f);
	const int32_t	green = (int32_t)(linear.y * 255.999f);
	const int32_t	blue = (int32_t)(linear.z * 255.999f);

	return (red << 24 | green << 16 | blue << 8 | 255);
}
