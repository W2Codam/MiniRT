/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   MiniRT.h                                           :+:      :+:    :+:   */
/*                                                     +:+                    */
/*   By: lde-la-h <lde-la-h@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/11 17:44:13 by lde-la-h      #+#    #+#                 */
/*   Updated: 2022/05/19 17:50:12 by dvan-der         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H
# include "lib3d.h"
# include "libft.h"
# include "MLX42/MLX42.h"
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include <pthread.h>
# include <assert.h>
# include <float.h>
# include <errno.h>
# include <math.h>
# define MAX_OBJECTS	100
# define MAX_LIGHTS		100
# define MAX_CAMERAS	10
# define WIN_WIDTH		800
# define SAMPLE_COUNT	10

/*
typedef float t_vec4 __attribute__ ((vector_size (16)));

t_vec4 one = (t_vec4){0,1,1,1};

one = one * 1.f; 
*/

// Types of entities that exist.
typedef enum e_EntityType
{
	SPHERE,
	CYLINDER,
	PLANE,
}	t_EntityType;

// Intersection func
typedef bool	(*t_intersection)(struct s_Object*, t_Ray*, t_Hit *hit);

/**
 * An object is something that can be rendered onto the screen.
 * 
 * @param type The type of entity.
 * @param intersects Does the given ray intersect with the object.
 * @param color The base color of the object.
 * @param as Interprid the object as any of the following entities.
 */
typedef struct s_Object
{
	t_EntityType	type;
	t_FVec3			color;
	t_intersection	intersects;

	union
	{
		t_Sphere	as_sphere;
		t_Cylinder	as_cylinder;
		t_Plane		as_plane;
	};
}	t_Object;

/**
 * A camera is a lense that can shoot rays to trace the pixels
 * at a specific location and rotation.
 */
typedef struct s_Camera
{
	bool	ready;
	float	fov;
	t_FVec3	position;
	t_FVec3	direction;
	t_FVec3	rotation_matrix[3];
}	t_Camera;

/**
 * A light source to brighten up a scene with a specific light color.
 * 
 * @param is_ambient Is this an ambient light.
 * @param intensity The light intensity / how bright.
 * @param color The light color.
 * @param The light position. If Ambient does not matter.
 */
typedef struct s_Light
{
	bool	is_ambient;
	float	intensity;
	t_FVec3	color;
	t_FVec3	position;
}	t_Light;

/**
 * A world consist of various objects, lights and cameras.
 * Together they form the output image.
 */
typedef struct s_World
{
	t_Light		ambient;

	t_Object	objects[MAX_OBJECTS];
	uint16_t	object_count;

	t_Camera	cameras[MAX_CAMERAS];
	uint16_t	camera_count;

	t_Light		lights[MAX_LIGHTS];
	uint16_t	light_count;

}	t_World;

/**
 * MiniRT Instance. This holds the world, camera and render thread
 * data all that an mini rt instance needs to function.
 */
typedef struct s_RT
{
	mlx_t		*mlx;
	mlx_image_t	*canvas;
	mlx_image_t	*meme;

	t_World		world;
	uint16_t	camera_index;

	pthread_t	render_thread;
	bool		update;
	bool		has_ambient;
}	t_RT;

// Jumptable func
typedef void	(*t_func)(t_RT*, char*, int32_t);

typedef struct s_JmpTable
{
	const char	*id;
	t_func		func;
}	t_JmpTable;

//= Functions =//

t_Camera	*ft_get_active_camera(t_RT *rt);
void		ft_update_camera(t_Camera *camera, t_FVec3 pos, \
				t_FVec3 dir[3], float fov);
void		ft_draw_world(t_RT *rt);
t_FVec3		ft_apply_lights(t_RT *rt, t_Ray cur_ray, \
				t_Hit *hit, t_FVec3 *normal);
bool		ft_ray_to_world(t_RT *rt, t_Ray ray, \
				t_FVec3 *normal, t_Hit *hit_out);
t_Hit		ft_ray_intersect_any(t_RT *rt, t_Ray ray, float len);

//= Collision Functions =//

// Wrapper functions to match intersection prototype.

bool		ft_intersect_sp(t_Object *obj, t_Ray *ray, t_Hit *out_hit);
bool		ft_intersect_cl(t_Object *obj, t_Ray *ray, t_Hit *out_hit);
bool		ft_intersect_pl(t_Object *obj, t_Ray *ray, t_Hit *out_hit);

//= Map parser =//

bool		ft_read_map(t_RT *rt, char *file);

t_FVec3		ft_cy_side_normal(t_FVec3 hit_pos, t_Cylinder cylinder);
t_FVec3		ft_plane_normal(t_FVec3 plane_dir, t_FVec3 ray_dir);
t_FVec3		ft_normal_cylinder(t_Ray ray, t_Hit hit);
t_FVec3		ft_normal_sphere(t_Ray ray, t_Hit hit);
t_FVec3		ft_normal_plane(t_Ray ray, t_Hit hit);
float		ft_hit_plane_2(t_Ray *ray, t_FVec3 dir, t_FVec3 pos);

#endif
