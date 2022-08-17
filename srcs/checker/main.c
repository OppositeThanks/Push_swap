/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lperrin <lperrin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 17:00:30 by lperrin           #+#    #+#             */
/*   Updated: 2022/08/17 15:00:15 by lperrin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/checker.h"

int	main(int argc, char **argv)
{
	char		*line;
	t_stacks	stacks;
	char		*string;
	int			ret;

	argc--;
	if (argc == 0)
		return (0);
	string = ft_av_to_string(argv);
	stacks = ft_store_numbers(string);
	line = NULL;
	ret = 0;
	while (get_next_line(0, &line) == 1)
	{
		if (ft_strcmp(line, " ") == 0)
			return (ft_put_err(&stacks, NULL, 0));
		ft_select_instruction(line, &stacks);
		free(line);
	}
	free(line);
	if (ft_issorted(&stacks.stack_a) && !stacks.stack_b.used_size)
		ft_putendl_fd("OK", 1);
	else
		ft_putendl_fd("KO", 1);
	return (ft_put_err(&stacks, NULL, 0));
}
