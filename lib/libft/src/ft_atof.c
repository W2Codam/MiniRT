/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvan-der <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 16:20:52 by dvan-der          #+#    #+#             */
/*   Updated: 2022/04/04 17:47:09 by dvan-der         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <math.h>
#include <stdio.h>

float	make_float(const char *str, float nbr, size_t *i, bool decimal) 
{
	int		dec_point;

	dec_point = 0;
	while (ft_isdigit(str[*i]))
	{
		nbr = (nbr * 10) + (str[(*i)] - '0');
		(*i)++;
		dec_point++;
	}
	if (str[*i] == '.' && !decimal)
	{
		(*i)++;
		nbr += make_float(str, 0, i, true);
	}
	if (decimal)
		return (nbr / (float)pow(10, dec_point));
	else
		return (nbr);
}

float	ft_atof(const char *str, size_t *i)
{
	float	nbr;
	float	pos_neg;

	pos_neg = 1;
	nbr = 0;
	while (ft_isspace(str[*i]))
		(*i)++;
	if (str[*i] == '-' || str[*i] == '+')
	{
		if (str[*i] == '-')
			pos_neg = -1;
		(*i)++;
	}
	nbr = make_float(str, nbr, i, false);
	return (nbr * pos_neg);
}



