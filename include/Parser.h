/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Parser.h                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: lde-la-h <lde-la-h@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/12 16:13:42 by lde-la-h      #+#    #+#                 */
/*   Updated: 2022/04/12 16:14:20 by lde-la-h      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H
# include "MiniRT.h"

void	ft_add_sphere(t_RT *rt, char *line, int32_t row);
void	ft_add_plane(t_RT *rt, char *line, int32_t row);
void	ft_add_cylinder(t_RT *rt, char *line, int32_t row);
void	ft_add_triangle(t_RT *rt, char *line, int32_t row);
void	ft_add_ambient(t_RT *rt, char *line, int32_t row);
void	ft_add_light(t_RT *rt, char *line, int32_t row);
void	ft_add_camera(t_RT *rt, char *line, int32_t row);

float	minirt_atof(const char *str, int32_t row, size_t *i);
int32_t	minirt_atoi(const char *str, int32_t row, size_t *i);

t_FVec3	ft_init_coordinates(char *line, int32_t row, size_t *i, int32_t check);
t_FVec3	ft_init_color(char *line, int32_t row, size_t *i);
float	ft_init_number(char *line, int32_t row, size_t *i, int32_t atof);

void	ft_exit_parser(char *error_line, int32_t row, size_t column, \
char *func);

#endif