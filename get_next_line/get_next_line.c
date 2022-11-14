/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmarosti <cmarosti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 21:22:14 by cmarosti          #+#    #+#             */
/*   Updated: 2022/11/08 20:41:47 by cmarosti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	check_line_break(char *s)
{
	int	i;

	if (!s)
		return (0);
	i = -1;
	while (s[++i])
		if (s[i] == '\n')
			return (1);
	return (0);
}

char	*read_line(char *str)
{
	char	*new_line;
	int		i;

	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	if (str[i] == '\n')
		i++;
	new_line = (char *)malloc(sizeof(char) * (i + 1));
	if (!new_line)
		return (NULL);
	i = -1;
	while (str[++i] && str[i] != '\n')
		new_line[i] = str[i];
	if (str[i] == '\n')
	{
		new_line[i] = str[i];
		i++;
	}
	new_line[i] = '\0';
	return (new_line);
}

char	*new_rest(char *rest)
{
	int		i;
	int		j;
	char	*new_rest;

	i = 0;
	while (rest[i] && rest[i] != '\n')
		i++;
	if ((rest[i] == '\n' && rest[i + 1] == '\0') || !rest[i])
	{
		free (rest);
		return (NULL);
	}
	new_rest = (char *)malloc(sizeof(char) * (ft_strlen(rest) - i + 1));
	if (!new_rest)
		return (NULL);
	j = 0;
	while (rest[++i] != '\0')
		new_rest[j++] = rest[i];
	new_rest[j] = '\0';
	free (rest);
	return (new_rest);
}

char	*read_file(int fd, char *rest)
{
	ssize_t	bytes;
	char	*buf;

	buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return (NULL);
	bytes = 1;
	while (!(check_line_break(rest)))
	{
		bytes = read(fd, buf, BUFFER_SIZE);
		if (bytes <= 0)
			break ;
		buf[bytes] = '\0';
		rest = ft_strjoin (rest, buf);
		if (!rest)
		{
			free (buf);
			return (NULL);
		}
	}
	free (buf);
	if (bytes == -1)
		return (NULL);
	return (rest);
}

char	*get_next_line(int fd)
{
	static char	*rest_file;
	char		*str;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (NULL);
	rest_file = read_file(fd, rest_file);
	if (!ft_strlen(rest_file))
	{
		free(rest_file);
		return (NULL);
	}
	str = read_line(rest_file);
	rest_file = new_rest(rest_file);
	return (str);
}
