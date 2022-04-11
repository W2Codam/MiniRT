/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Vector_NewF.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: lde-la-h <lde-la-h@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/28 11:17:01 by lde-la-h      #+#    #+#                 */
/*   Updated: 2022/03/28 19:38:26 by lde-la-h      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "lib3d.h"

t_FVec2	new_fvec2(float x, float y)
{
	return ((t_FVec2){{x, y}});
}

t_FVec3	new_fvec3(float x, float y, float z)
{
	return ((t_FVec3){{x, y, z}});
}

t_FVec4	new_fvec4(float x, float y, float z, float w)
{
	return ((t_FVec4){{x, y, z, w}});
}
