/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rinacio <rinacio@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 13:03:34 by rinacio           #+#    #+#             */
/*   Updated: 2022/06/24 17:18:41 by rinacio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_read(int fd, char *keeper);
char	*ft_find_next_line(char *str);
char	*ft_save_remaining(char *str);

char	*get_next_line(int fd)
{
	char		*next_line;
	static char	*keeper;

	if (BUFFER_SIZE <= 0 || fd < 0 || BUFFER_SIZE >= 2147483647)
		return (NULL);
	keeper = ft_read(fd, keeper);
	if (!keeper)
		return (NULL);
	next_line = ft_find_next_line(keeper);
	keeper = ft_save_remaining(keeper);
	return (next_line);
}

char	*ft_read(int fd, char *keeper)
{
	char	*buf;
	int		read_result;

	buf = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return (NULL);
	read_result = 1;
	while (read_result != 0 && !ft_strchr(keeper, '\n'))
	{
		read_result = read(fd, buf, BUFFER_SIZE);
		if (read_result == -1)
		{
			free(buf);
			return (NULL);
		}
		buf[read_result] = '\0';
		keeper = ft_strjoin(keeper, buf);
	}
	free(buf);
	return (keeper);
}

char	*ft_find_next_line(char *str)
{
	int		i;
	int		len;
	char	*next_line;

	i = 0;
	if (!str[0])
		return (NULL);
	while (str[i] != '\0' && str[i] != '\n')
		i++;
	if (str[i] == '\n')
		i++;
	len = i;
	next_line = malloc(sizeof(char) * (i + 1));
	if (!next_line)
		return (NULL);
	i = 0;
	while (i < len)
	{
		next_line[i] = str[i];
		i++;
	}
	next_line[i] = '\0';
	return (next_line);
}

char	*ft_save_remaining(char *str)
{
	char	*remaining;
	int		i;
	int		count;

	i = 0;
	while (str[i] != '\0' && str[i] != '\n')
		i++;
	if (str[i] == '\0')
	{
		free(str);
		return (NULL);
	}
	i++;
	remaining = (char *)malloc((ft_strlen(str) - i + 1) * sizeof(char));
	if (remaining == NULL)
		return (NULL);
	count = 0;
	while (str[i] != '\0')
		remaining[count++] = str[i++];
	remaining[count] = '\0';
	free(str);
	return (remaining);
}
