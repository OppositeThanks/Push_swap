/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lperrin <lperrin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 12:13:26 by lperrin           #+#    #+#             */
/*   Updated: 2022/08/17 11:33:23 by lperrin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"

int	main(int argc, char **argv)
{
	t_stacks	stacks;
	char		*string;

	argc--;
	if (argc == 0)
		return (0);
	string = ft_av_to_string(argv);
	stacks = ft_store_numbers(string);
	if (ft_issorted(&stacks.stack_a))
		return (ft_put_err(&stacks, NULL, 0));
	if (stacks.stack_a.size == 2)
		ft_swap_a_or_b(&stacks.stack_a, YES, 'a');
	if (stacks.stack_a.size == 3)
		ft_sort_three_numbers(&stacks.stack_a);
	if (stacks.stack_a.size == 5 || stacks.stack_a.size == 4)
		ft_sort_five_numbers(&stacks);
	if (stacks.stack_a.size > 5 && stacks.stack_a.size <= 10)
		ft_sort_ten_numbers(&stacks);
	if (stacks.stack_a.size > 10 && stacks.stack_a.size <= 100)
		ft_one_hundred(&stacks);
	if (stacks.stack_a.size > 100)
		ft_five_hundred(&stacks);
	return (ft_put_err(&stacks, NULL, 0));
}
