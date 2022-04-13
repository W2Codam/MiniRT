/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   lib3d.h                                            :+:      :+:    :+:   */
/*                                                     +:+                    */
/*   By: lde-la-h <lde-la-h@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/11 17:45:18 by lde-la-h      #+#    #+#                 */
/*   Updated: 2022/04/12 14:30:29 by lde-la-h      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIB3D_H
# define LIB3D_H
# include <stddef.h>
# include <stdint.h>
# include <limits.h>
# include <stdbool.h>
# include <math.h>

//= Vector =//

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

//= Generic =//

// A Ray.
typedef struct s_Ray
{
	t_FVec3	origin;
	t_FVec3	dir;
}	t_Ray;

// Raycast hit result.
typedef struct s_Hit
{
	float	distance;
	t_FVec3	location;
}	t_Hit;

//= Bounds =//

// A sphere.
typedef struct s_Sphere
{
	t_FVec3	center;
	float	radius;
}	t_Sphere;

// An "infinitely" large plane.
typedef struct s_Plane
{
	t_FVec3	center;
	t_FVec3	dir;
}	t_Plane;

// A Cylinder.
typedef struct s_Cylinder
{
	t_FVec3	center;
	t_FVec3	dir;
	float	diameter;
	float	height;
}	t_Cylinder;

typedef struct s_Triangle
{
	struct
	{
		t_FVec3	v1;
		t_FVec3	v2;
		t_FVec3	v3;
	};
	t_FVec3	vertices[3];
}	t_Triangle;

typedef struct s_angle
{
	t_FVec3	k;
	float	angle;
}	t_angle;

//= Functions =//

//= Constructors =//

t_FVec2		ft_new_fvec2(float x, float y);
t_FVec3		ft_new_fvec3(float x, float y, float z);
t_FVec4		ft_new_fvec4(float x, float y, float z, float w);

t_Ray		ft_new_ray(t_FVec3 origin, t_FVec3 direction);

//= FVec3 =//

float		ft_len_fvec3(t_FVec3 vec);
void		ft_normalize_fvec3(t_FVec3 *vec);
float		ft_len_squared_fvec3(t_FVec3 vec);
float		ft_dot_fvec3(t_FVec3 left, t_FVec3 right);

t_FVec3		ft_add_fvec3(t_FVec3 left, t_FVec3 right);
t_FVec3		ft_sub_fvec3(t_FVec3 left, t_FVec3 right);
t_FVec3		ft_mul_fvec3(t_FVec3 left, t_FVec3 right);
t_FVec3		ft_div_fvec3(t_FVec3 left, t_FVec3 right);

t_FVec3		ft_add_fvec3f(t_FVec3 left, float right);
t_FVec3		ft_sub_fvec3f(t_FVec3 left, float right);
t_FVec3		ft_mul_fvec3f(t_FVec3 left, float right);
t_FVec3		ft_div_fvec3f(t_FVec3 left, float right);

//= Ray =//

t_FVec3		ft_ray_at(t_Ray *ray, float distance);

// Intersections

bool		ft_hit_sphere(t_Ray *ray, t_Sphere *sphere, t_Hit *out_hit);
bool		ft_hit_triangle(t_Ray *ray, t_Triangle *triangle, t_Hit *out_hit);
bool		ft_hit_cylinder(t_Ray *ray, t_Cylinder *cylinder, t_Hit *out_hit);
bool		ft_hit_plane(t_Ray *ray, t_Plane *plane, t_Hit *out_hit);

//= Color =//

uint32_t	ft_to_rgba(t_FVec3 linear);

#endif
