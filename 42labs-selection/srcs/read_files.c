/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_files.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rinacio <rinacio@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 18:55:46 by rinacio           #+#    #+#             */
/*   Updated: 2023/01/15 13:59:41 by rinacio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "labs.h"

void	get_frequency(t_data *data)
{
	int				i;
	unsigned char	c;

	for (i = 0; i < data->nfiles; i++)
	{
		while (read(data->fd[i], &c, sizeof(unsigned char)))
		{
			data->freq[c]++;
			data->shared_data[0]++;
		}
	}
}
