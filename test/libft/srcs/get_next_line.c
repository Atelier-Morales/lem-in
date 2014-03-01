/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmerlier <tmerlier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/03 13:29:31 by tmerlier          #+#    #+#             */
/*   Updated: 2014/01/18 16:54:55 by tmerlier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <libft.h>

static int	gnl_copy(char **line, char *str, int ret);
static int	gnl_read(int fd, char **str);

int			get_next_line(int const fd, char **line)
{
	static char			*str;
	int					ret;

	*line = (char *) malloc(sizeof(char));
	if (str == NULL)
		str = ft_strnew(1);
	ret = gnl_read(fd, &str);
	if (ret == -1)
		return (-1);
	else if (ret == 0 && *str == 0)
		return (0);
	else
		return (gnl_copy(line, str, ret));
}

static int	gnl_copy(char **line, char *str, int ret)
{
	int		len;

	if (*line != NULL)
		ft_strdel(line);
	if (ft_strchr(str, '\n'))
	{
		*line = ft_strcdup(str, '\n');
		len = ft_strlen(*line);
		ft_memmove(str, str + len + 1, ft_strlen(str) - len);
	}
	else if (ret == 0)
	*line = ft_strdup(str);
	return (1);
}

static int	gnl_read(int fd, char **str)
{
	char		buf[BUFF_SIZE + 1];
	int			ret;
	char		*tmp;

	while (!ft_strchr(*str, '\n') && (ret = read(fd, buf, BUFF_SIZE)) >= 1)
	{
		buf[ret] = 0;
		tmp = *str;
		*str = ft_strjoin(tmp, buf);
		free(tmp);
	}
	return (ret);
}
