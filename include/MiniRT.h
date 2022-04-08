/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   MiniRT.h                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: lde-la-h <lde-la-h@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/28 11:06:20 by lde-la-h      #+#    #+#                 */
/*   Updated: 2022/04/08 13:07:17 by lde-la-h      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

/*
  __  __                      ____  _____ 
 |  \/  |  ___   __ _   __ _ |  _ \|_   _|
 | |\/| | / _ \ / _` | / _` || |_) | | |  
 | |  | ||  __/| (_| || (_| ||  _ <  | |  
 |_|  |_| \___| \__, | \__,_||_| \_\ |_|  
                |___/                     

Balls to the walls cross-platform, multi-threaded stud Raytracer on the CPU!
Written by W2.Wizard (lde-la-h) & Daan Van Der Plas (dvan-der) @ 2022

Coordinate System: UE5
*/

#ifndef MINIRT_H
# define MINIRT_H
# include <stdio.h>
# include <stddef.h>
# include <stdlib.h>
# include <memory.h>
# include <limits.h>
# include <unistd.h>
# include <pthread.h>
# include <assert.h>
# include <errno.h>
# include <fcntl.h>
# include "libft.h"
# include "lib3d.h"
# include "MLX42/MLX42.h"
# define MAX_OBJS		100
# define MAX_CAMERAS	10
# define WIN_WIDTH		800

//= Types =//

// Types of entities that exist.
typedef enum e_EntityType
{
	CAMERA,
	SPHERE,
	CYLINDER,
	PLANE,
	TRIANGLE,
}	t_EntityType;

// Types of entities that exist.
typedef enum e_MaterialType
{
	DIFFUSE,
	METAL,
	TRANSLUCENT,
}	t_MaterialType;

/**
 * A transform that encompasses both rotation and
 * scale.
 * 
 * X: Forward
 * Y: Right
 * Z: Up
 */
typedef struct s_Transform
{
	t_FVec3	pos;
	t_FVec3	rot;
}	t_Transform;

/**
 * Base entity object, which is anything that exists in 3D space.
 * 
 * @param type The specific type of entity.
 * @param transform 3D transform in world space of the entity.
 * @param color Optional color param.
 */
typedef struct s_Entity
{
	t_Transform	transform;
	t_FVec3		color;
}	t_Entity;

/**
 * Camera object stores, position, orientation and fov, is NOT an entity!
 * 
 * @param pos The position in 3D world space.
 * @param rot The rotation in 3D world space.
 * @param fov The field of view [0 - 180].
 */
typedef struct s_Camera
{
	t_Transform	transform;
	t_FVec2		viewport;
	t_FVec3		top_left;
	t_FVec3		horizontal;
	t_FVec3		vertical;
	float		fov;
}	t_Camera;

/**
 * Ambient light.
 * 
 * @param intensity Scalar value defining intensity of light.
 * @param color Light color.
 */
typedef struct	s_Ambient
{
	float	intensity;
	t_FVec3	color;
	bool	active;
}	t_Ambient;

/**
 * A light source.
 * 
 * @param transform The angle of the light source.
 * @param intensity Scalar value defining intensity of light.
 * @param color Light color.
 */
typedef struct s_Light
{
	t_Transform	transform;
	float		intensity;
	t_FVec3		color;
}	t_Light;

typedef struct s_SphereModel
{
	t_Entity	base;
	float		diameter;
}	t_SphereModel;

typedef struct s_PlaneModel
{
	t_Entity	base;
}	t_PlaneModel;

typedef struct s_TriangleModel
{
	t_FVec3		vertices[3];
	t_FVec3		color;
}	t_TriangleModel;

typedef struct s_CylinderModel
{
	t_Entity	base;
	float		height;
	float		diameter;
}	t_CylinderModel;

/**
 * Instance class of an entity, that is, something that needs to be
 * rendered.
 * 
 * @param type The type of entity.
 * @param material The type of material.
 * @param texture The texture to draw onto the object.
 * @param union The different available types of entities.
 */
typedef struct s_EntityObject
{
	t_EntityType	type;
	t_MaterialType	material;
	mlx_texture_t	*texture;

	bool (*intersect)(t_Ray *ray);

	union
	{
		t_SphereModel	entity_sphere;
		t_PlaneModel	entity_plane;
		t_CylinderModel	entity_cylinder;
		t_TriangleModel	entity_triangle;
	};
}	t_EntityObject;

/**
 * Struct that contains the application state. Including the current level.
 * 
 * @param mlx MLX42 instance handle.
 * @param render_thread The thread that does the pixel updating.
 */
typedef struct s_rt
{
	mlx_t			*mlx;
	mlx_image_t		*window_img;
	pthread_t		render_thread;
	pthread_mutex_t	lock;

	t_Ambient		ambient;

	int32_t			active_camera;
	t_Camera		cameras[MAX_CAMERAS];
	size_t			cameras_size;

	t_Light			lights[MAX_OBJS];
	size_t			lights_size;

	t_EntityObject	objects[MAX_OBJS];
	size_t			objects_size;

	bool			update;
}	t_rt;

//= Functions =//

t_Camera	*ft_get_active_camera(t_rt *rt);
void		ft_draw(t_rt *rt);
void		ft_new_camera(t_Camera *Camera, float FOV, t_FVec3 pos);

int			init_entities(t_rt *rt, char *input);
void		init_camera(t_rt *rt, char *line, int row);
void		init_ambient(t_rt *rt, char *line, int row);
void		init_light(t_rt *rt, char *line, int row);
void		init_sphere(t_rt *rt, char *line, int row);
void		init_plane(t_rt *rt, char *line, int row);
void		init_cylinder(t_rt *rt, char *line, int row);
void		init_triangle(t_rt *rt, char *line, int row);
int			check_range(t_FVec3 vec, float min, float max);
float		init_number(char *line, int row, size_t *i, int atof);
t_FVec3		init_coordinates(char *line, int row, size_t *i, int check);
t_FVec3		init_color(char *line, int row, size_t *i);
void		exit_parser(char *error_line, int row, size_t collumn, char *func);
float		minirt_atof(const char *str, int row, size_t *i);
int			minirt_atoi(const char *str, int row, size_t *i);

#endif // MINIRT_H
