/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lights.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: lde-la-h <lde-la-h@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/14 15:10:46 by lde-la-h      #+#    #+#                 */
/*   Updated: 2022/04/14 15:17:52 by lde-la-h      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "MiniRT.h"

uint32_t	ft_apply_lights(t_RT *rt, t_Hit *hit, t_FVec3 *normal)
{
	size_t	i;

	(void) rt;
	(void) hit;
	(void) normal;
	i = 0;
	/*
	while (i < rt->world.light_count)
	{
		// 1. Make ray to light
		// 2. Use ft_hittables to detect if we intersect anything
		// 3. If false draw color, 
	}
	*/
	return (0);
}
