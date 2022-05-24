/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                     +:+                    */
/*   By: lde-la-h <lde-la-h@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/10/04 14:53:36 by lde-la-h      #+#    #+#                 */
/*   Updated: 2022/05/19 13:41:39 by dvan-der         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static uint32_t	ft_wcount(const char *str, char c)
{
	uint32_t	w;
	size_t		i;

	i = 0;
	w = 0;
	while (str[i] != '\0')
	{
		if (str[i] != c)
			w++;
		while (str[i] != c && str[i + 1])
			i++;
		i++;
	}
	return (w);
}

static void	ft_cleanup(char **out)
{
	uint32_t	i;

	i = 0;
	while (out[i] != NULL)
		free(out[i++]);
	return ;
}

static bool	ft_allocate(char **out, uint32_t wcount, char const *s, char c)
{
	size_t	windex;
	size_t	sindex;
	size_t	wlen;

	windex = 0;
	sindex = 0;
	while (windex < wcount)
	{
		while (s[sindex] == c)
			sindex++;
		wlen = ft_strclen(&s[sindex], c);
		out[windex] = ft_substr(s, sindex, wlen);
		if (!out[windex])
			return (false);
		windex++;
		sindex += wlen;
	}
	return (true);
}

char	**ft_split(char const *s, char c)
{
	char		**out;
	uint32_t	wcount;

	wcount = ft_wcount(s, c);
	out = (char **)ft_calloc(wcount + 1, sizeof(char *));
	if (!out)
		return (NULL);
	if (!*s || wcount == 0)
		return (out);
	if (!ft_allocate(out, wcount, s, c))
	{
		ft_cleanup(out);
		free(out);
		return (NULL);
	}
	return (out);
}
