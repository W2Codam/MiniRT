/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Vector_Arithmetic.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: lde-la-h <lde-la-h@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/28 11:09:06 by lde-la-h      #+#    #+#                 */
/*   Updated: 2022/03/28 11:29:04 by lde-la-h      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Vector.h"

t_FVec3	add_fvec3(t_FVec3 a, t_FVec3 b)
{
	return (new_fvec3(a.x + b.x, a.y + b.y, a.z + b.z));
}

t_FVec3	sub_fvec3(t_FVec3 a, t_FVec3 b)
{
	return (new_fvec3(a.x - b.x, a.y - b.y, a.z - b.z));
}

t_FVec3	mul_fvec3(t_FVec3 a, t_FVec3 b)
{
	return (new_fvec3(a.x * b.x, a.y * b.y, a.z * b.z));
}

t_FVec3	div_fvec3(t_FVec3 a, t_FVec3 b)
{
	return (new_fvec3(a.x / b.x, a.y / b.y, a.z / b.z));
}
