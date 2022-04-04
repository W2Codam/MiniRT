/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Vector_Arithmetic_Vec3.c                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: lde-la-h <lde-la-h@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/28 11:09:06 by lde-la-h      #+#    #+#                 */
/*   Updated: 2022/04/04 14:11:52 by lde-la-h      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "lib3d.h"

t_FVec3	add_vec3(t_FVec3 a, t_FVec3 b)
{
	return (new_fvec3(a.x + b.x, a.y + b.y, a.z + b.z));
}

t_FVec3	sub_vec3(t_FVec3 a, t_FVec3 b)
{
	return (new_fvec3(a.x - b.x, a.y - b.y, a.z - b.z));
}

t_FVec3	mul_vec3(t_FVec3 a, t_FVec3 b)
{
	return (new_fvec3(a.x * b.x, a.y * b.y, a.z * b.z));
}

t_FVec3	div_vec3(t_FVec3 a, t_FVec3 b)
{
	return (new_fvec3(a.x / b.x, a.y / b.y, a.z / b.z));
}
