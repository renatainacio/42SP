/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rinacio <rinacio@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 13:03:34 by rinacio           #+#    #+#             */
/*   Updated: 2023/03/01 04:06:51 by rinacio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	ft_read(int fd, t_data *data);
char	*ft_find_next_line(char *str);
char	*ft_save_remaining(char *str);

void	get_next_line(int fd, t_data *data)
{
	if (BUFFER_SIZE <= 0 || fd < 0 || BUFFER_SIZE >= 2147483647)
		return ;
	data->keeper = calloc(5, sizeof(char));
	ft_read(fd, data);
	if (!data->keeper)
		return ;
	data->next_line = ft_find_next_line(data->keeper);
	data->keeper = ft_save_remaining(data->keeper);
	free(data->keeper);
}

void	ft_read(int fd, t_data *data)
{
	char	*buf;
	int		read_result;

	buf = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return ;
	read_result = 1;
	while (read_result != 0 && !ft_strchr(data->keeper, '\n'))
	{
		read_result = read(fd, buf, BUFFER_SIZE);
		if (read_result == -1)
		{
			free(buf);
			return ;
		}
		buf[read_result] = '\0';
		if (ft_strlen(data->keeper) > 2)
		{
			free(buf);
			end_gnl(data);
		}
		ft_strlcat(data->keeper, buf, ft_strlen(data->keeper) + 2);
	}
	free(buf);
}

void	end_gnl(t_data *data)
{
	free(data->keeper);
	free_all(data);
	exit (ft_printf("Error\n"));
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
