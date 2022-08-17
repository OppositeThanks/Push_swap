/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lperrin <lperrin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 12:09:42 by lperrin           #+#    #+#             */
/*   Updated: 2022/08/17 11:39:07 by lperrin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include "push_swap.h"
# include "../get_next_line/get_next_line.h"

void	ft_select_instruction(char *line, t_stacks *stacks);
void	ft_print(t_stacks *stacks);
void	ft_print_stack_b(t_stacks *stacks);
void	ft_print_stack_a(t_stacks *stacks);
#endif