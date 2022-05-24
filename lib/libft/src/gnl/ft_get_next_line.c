/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_get_next_line.c                                 :+:      :+:    :+:   */
/*                                                     +:+                    */
/*   By: lde-la-h <lde-la-h@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/10/28 15:27:53 by lde-la-h      #+#    #+#                 */
/*   Updated: 2022/05/19 13:43:18 by dvan-der         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_gets(char *readstr, t_fd_data *remainder)
{
	size_t	len;
	char	*out;
	char	*rem;

	len = ft_strclen(readstr, '\n') + 1;
	if (!readstr[len - 1])
		len--;
	out = ft_substr(readstr, 0, len);
	rem = ft_strdup(readstr + len);
	free(readstr);
	if (!*rem)
	{
		free(rem);
		remainder->data = NULL;
	}
	else
		remainder->data = rem;
	return (out);
}

char	*ft_attach(char *readstr, t_fd_data *remainder)
{
	char	*temp;

	if (remainder->data)
	{
		temp = ft_strapp(remainder->data, readstr);
		remainder->data = NULL;
		free(readstr);
		return (ft_gets(temp, remainder));
	}
	return (ft_gets(readstr, remainder));
}

static char	*ft_try_read(int32_t fd, t_fd_data *remainder)
{
	size_t	b_read;
	char	*readstr;
	char	buff[BUFF_SIZE + 1];

	b_read = 1;
	readstr = NULL;
	while (b_read > 0)
	{
		b_read = read(fd, buff, BUFF_SIZE);
		remainder->read = b_read < BUFF_SIZE;
		if (!b_read)
			break ;
		buff[b_read] = '\0';
		readstr = ft_strapp(readstr, buff);
		if (ft_strchr(readstr, '\n'))
			return (ft_attach(readstr, remainder));
	}
	if (remainder->data)
		return (ft_attach(readstr, remainder));
	if (readstr)
		return (readstr);
	return (NULL);
}

char	*ft_get_next_line(int32_t fd)
{
	static t_fd_data	fd2[FD_MAX];

	if (read(fd, NULL, 0) == -1)
		return (NULL);
	if (fd >= 0 && fd <= FD_MAX && BUFF_SIZE > 0)
	{
		if (fd2[fd].data && (ft_strchr(fd2[fd].data, '\n') || fd2[fd].read))
			return (ft_gets(fd2[fd].data, &fd2[fd]));
		return (ft_try_read(fd, &fd2[fd]));
	}
	return (NULL);
}
