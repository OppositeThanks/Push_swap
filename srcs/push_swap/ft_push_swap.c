/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lperrin <lperrin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 12:12:38 by lperrin           #+#    #+#             */
/*   Updated: 2022/08/17 14:09:52 by lperrin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"

char	**ft_stacks_init(char *string, t_stacks *stacks)
{
	int		size;
	char	**numbers;

	numbers = ft_split(string, ' ');
	size = ft_count_numbers(string);
	stacks->stack_a.vector = (int *)malloc(sizeof(int) * size);
	stacks->stack_b.vector = (int *)malloc(sizeof(int) * size);
	stacks->stack_a.size = size;
	stacks->stack_b.size = size;
	stacks->stack_a.used_size = 0;
	stacks->stack_b.used_size = 0;
	free(string);
	return (numbers);
}

t_stacks	ft_store_numbers(char *string)
{
	t_stacks	stacks;
	char		**numbers;
	long		number;
	int			i;

	i = 0;
	numbers = ft_stacks_init(string, &stacks);
	while (numbers[i])
	{
		if (!ft_isnumber(numbers[i]))
			exit(ft_put_err(&stacks, "Error", 0));
		number = ft_atoi(numbers[i]);
		/* if (number < "-2147483648" || number > "2147483647")
			exit(ft_put_err(&stacks, "Error", 0)); */
		if (!ft_isduplicate(&stacks, number))
			exit(ft_put_err(&stacks, "Error", 0));
		stacks.stack_a.vector[i] = number;
		stacks.stack_a.used_size++;
		free(numbers[i]);
		i++;
	}
	free(numbers);
	return (stacks);
}

int	ft_av_size(char **argv)
{
	int	size;
	int	i;

	i = 0;
	size = 0;
	while (argv[i])
		size += ft_strlen(argv[i++]) + 1;
	return (size);
}

int	ft_check_arg(char *argv)
{
	int	i;

	i = 0;
	while (argv[i])
	{
		if (ft_isdigit(argv[i]))
			return (1);
		i++;
	}
	return (0);
}

char	*ft_av_to_string(char **argv)
{
	char	*string;
	char	*tmp;
	int		size;
	int		i;

	i = 1;
	size = ft_av_size(argv);
	string = (char *)malloc(1);
	while (argv[i])
	{
		if (!ft_check_arg(argv[i]))
			exit(ft_put_err(NULL, "Error", 0));
		else
		{
			tmp = ft_strjoin(string, argv[i]);
			free(string);
			string = ft_strjoin(tmp, " ");
			free(tmp);
			i++;
		}
	}
	return (string);
}
