/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Vector_Arithmetic_Float.c                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: lde-la-h <lde-la-h@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/28 11:09:06 by lde-la-h      #+#    #+#                 */
/*   Updated: 2022/04/04 14:11:27 by lde-la-h      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "lib3d.h"

t_FVec3	add_fvec3(t_FVec3 a, float b)
{
	return (new_fvec3(a.x + b, a.y + b, a.z + b));
}

t_FVec3	sub_fvec3(t_FVec3 a, float b)
{
	return (new_fvec3(a.x - b, a.y - b, a.z - b));
}

t_FVec3	mul_fvec3(t_FVec3 a, float b)
{
	return (new_fvec3(a.x * b, a.y * b, a.z * b));
}

t_FVec3	div_fvec3(t_FVec3 a, float b)
{
	return (new_fvec3(a.x / b, a.y / b, a.z / b));
}
