/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rinacio <rinacio@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 13:07:38 by rinacio           #+#    #+#             */
/*   Updated: 2022/06/24 17:06:54 by rinacio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

char	*get_next_line(int fd);

size_t	ft_strlen(const char *s);

char	*ft_strjoin(char *s1, char *s2);

char	*ft_strdup(const char *s);

char	*ft_strchr(const char *s, int c);

#endif