/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   lib3d.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: lde-la-h <lde-la-h@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/11 17:45:18 by lde-la-h      #+#    #+#                 */
/*   Updated: 2022/05/23 14:02:18 by lde-la-h      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIB3D_H
# define LIB3D_H
# include <stddef.h>
# include <stdint.h>
# include <limits.h>
# include <stdbool.h>
# include <math.h>
# include <float.h>
# include <stdlib.h>

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
	float	radius;
	float	height;
}	t_Cylinder;

// Angle
typedef struct s_angle
{
	t_FVec3	k;
	float	angle;
}	t_angle;

// Raycast hit result.
typedef struct s_Hit
{
	float			distance;
	bool			is_inside;
	bool			cy_side;
	struct s_Object	*object;
}	t_Hit;

typedef enum e_Axis
{
	X,
	Y,
	Z
}	t_Axis;

//= Functions =//

//= Constructors =//

t_FVec2		ft_new_fvec2(float x, float y);
t_FVec3		ft_new_fvec3(float x, float y, float z);
t_FVec4		ft_new_fvec4(float x, float y, float z, float w);

t_Ray		ft_new_ray(t_FVec3 origin, t_FVec3 direction);

//= FVec3 =//

float		ft_len_fvec3(t_FVec3 vec);
void		ft_normalize_fvec3(t_FVec3 *vec);
t_FVec3		ft_normalize_fvec3_2(t_FVec3 vec);
float		ft_len_squared_fvec3(t_FVec3 vec);
float		ft_dot_fvec3(t_FVec3 left, t_FVec3 right);
t_FVec3		ft_cross_fvec3(t_FVec3 left, t_FVec3 right);
bool		ft_equal_fvec3(t_FVec3 left, t_FVec3 right);
t_FVec3		ft_rotate(t_FVec3 vec, t_FVec3 k, float angle);
t_angle		ft_get_angle_to(t_FVec3 dir, t_FVec3 desired_angle);
float		ft_distance(t_FVec3 p1, t_FVec3 p2);

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
t_Ray		ft_rotate_ray(t_Ray *ray, t_FVec3 center, t_FVec3 dir);
bool		ft_ray_in_right_dir(t_Ray *ray, t_Cylinder *cylinder);

//= Intersections =//

bool		ft_hit_sphere(t_Ray *ray, t_Sphere *sphere, t_Hit *out_hit);
bool		ft_hit_cylinder(t_Ray *ray, t_Cylinder *cylinder, t_Hit *out_hit);
bool		ft_hit_plane(t_Ray *ray, t_Plane *plane, t_Hit *out_hit);

//= Color =//

uint32_t	ft_to_rgba(t_FVec3 linear);
t_FVec3		ft_to_color(t_FVec3 linear);
t_FVec3		ft_from_rgba(t_FVec3 color);
uint32_t	ft_from_color(t_FVec3 color);

t_FVec3		ft_muls_color(t_FVec3 a, t_FVec3 b, float s);

//= Generic =//

bool		ft_abc(float a, float b, float c, float *distance);
float		ft_signf(float a);
float		ft_randf(void);
float		ft_randf_r(float min, float max);
float		ft_clamp(float x, float min, float max);
float		ft_to_rad(float deg);
float		ft_to_deg(float rad);

//= Matrices =//

t_FVec3		ft_rotate_vec(t_FVec3 cam_mat[3], t_FVec3 vec, \
		float angle, t_Axis axis);

#endif
