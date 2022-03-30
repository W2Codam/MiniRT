/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   lib3d.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: lde-la-h <lde-la-h@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/28 11:08:26 by lde-la-h      #+#    #+#                 */
/*   Updated: 2022/03/28 21:54:19 by lde-la-h      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIB3D_H
# define LIB3D_H
# include <math.h>
# include <stdint.h>

//= Int =//

// A 2 integer component.
typedef union u_IVec2
{
	struct
	{
		int32_t	x;
		int32_t	y;
	};
	int32_t	raw[2];
}	t_IVec2;

// A 3 integer component.
typedef union u_IVec3
{
	struct
	{
		int32_t	x;
		int32_t	y;
		int32_t	z;
	};
	int32_t	raw[3];
}	t_IVec3;

// A 4 integer component.
typedef union u_IVec4
{
	struct
	{
		int32_t	x;
		int32_t	y;
		int32_t	z;
		int32_t	w;
	};
	int32_t	raw[4];
}	t_IVec4;

//= Float =//

// A 2 float component.
typedef union u_FVec2
{
	struct
	{
		float	x;
		float	y;
	};
	float	raw[2];
}	t_FVec2;

// A 3 float component.
typedef union u_FVec3
{
	struct
	{
		float	x;
		float	y;
		float	z;
	};
	float	raw[3];
}	t_FVec3;

// A 4 float component.
typedef union u_FVec4
{
	struct
	{
		float	x;
		float	y;
		float	z;
		float	w;
	};
	float	raw[4];
}	t_FVec4;

typedef struct s_Ray
{
	t_FVec3	origin;
	t_FVec3	direction;
}	t_Ray;

//= Functions =//

t_FVec2	new_fvec2(float x, float y);
t_FVec3	new_fvec3(float x, float y, float z);
t_FVec4	new_fvec4(float x, float y, float z, float w);

//= FVec3 =//

float	get_length_fvec3(t_FVec3 vec);
float	get_length_squared_fvec3(t_FVec3 vec);
void	normalize_fvec3(t_FVec3 *vec);
float	dot_fvec3(t_FVec3 a, t_FVec3 b);
t_FVec3	cross_fvec3(t_FVec3 a, t_FVec3 b);

#endif
