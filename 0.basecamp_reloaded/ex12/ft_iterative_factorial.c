/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rinacio <rinacio@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 20:23:15 by rinacio           #+#    #+#             */
/*   Updated: 2022/04/02 07:19:40 by rinacio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_factorial(int nb)
{
	int	i;

	if (nb < 0 || nb > 12)
		return (0);
	if (nb == 0)
		return (1);
	i = nb - 1;
	while (i > 1)
	{
		nb = nb * i;
		i--;
	}
	return (nb);
}
