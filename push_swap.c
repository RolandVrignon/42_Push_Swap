/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvrignon <rvrignon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 17:19:15 by rvrignon          #+#    #+#             */
/*   Updated: 2022/06/02 16:44:14 by rvrignon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "stdio.h"

int		main(int ac, char **av)
{
	t_board	*board;

	board = NULL;
	if (ac < 2)
		return (error());
	board = create_board(board, av);
	if (!board)
		return (error());
	print_stack(board->a);
	print_stack(board->b);
	free_board(board);
	return (1);
}