/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rinacio <rinacio@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 20:42:02 by rinacio           #+#    #+#             */
/*   Updated: 2022/04/02 07:11:58 by rinacio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_recursive_factorial(int nb)
{
	int	fat;

	if (nb < 0 || nb > 12)
		return (0);
	if (nb == 0)
		return (1);
	if (nb == 1)
		fat = 1;
	else if (nb > 1)
		fat = nb * ft_recursive_factorial(nb - 1);
	else
		fat = 0;
	return (fat);
}
