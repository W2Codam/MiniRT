/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   constructor.c                                      :+:      :+:    :+:   */
/*                                                     +:+                    */
/*   By: lde-la-h <lde-la-h@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/11 21:17:50 by lde-la-h      #+#    #+#                 */
/*   Updated: 2022/04/11 21:19:02 by lde-la-h      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "lib3d.h"

t_Ray	ft_new_ray(t_FVec3 origin, t_FVec3 direction)
{
	return ((t_Ray){origin, direction});
}
