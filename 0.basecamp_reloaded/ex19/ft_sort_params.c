/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rinacio <rinacio@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 01:51:23 by rinacio           #+#    #+#             */
/*   Updated: 2022/03/31 02:19:01 by rinacio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);
int		ft_strcmp(char *s1, char *s2);
int		ft_is_sorted(int argc, char *argv[]);

int	main(int argc, char *argv[])
{
	int		i;
	int		j;
	char	*aux;

	i = ft_is_sorted(argc, argv);
	while (i != 0)
	{
		aux = argv[i];
		argv[i] = argv [i + 1];
		argv[i + 1] = aux;
		i = ft_is_sorted(argc, argv);
	}
		i = 1;
	while (i < argc)
	{
		j = 0;
		while (argv[i][j] != '\0')
		{
			ft_putchar(argv[i][j]);
			j++;
		}
		ft_putchar('\n');
		i++;
	}	
}

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] != '\0' && s2[i] != '\0')
	{
		if (s1[i] == s2[i])
			i++;
		else
			break ;
	}
	return (s1[i] - s2[i]);
}

int	ft_is_sorted(int argc, char *argv[])
{
	int	i;

	i = 1;
	while (i < argc - 1)
	{
		if (ft_strcmp(argv[i], argv[i + 1]) > 0)
			return (i);
		else
			i++;
	}
	return (0);
}
