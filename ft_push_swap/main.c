/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvrignon <rvrignon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 17:19:15 by rvrignon          #+#    #+#             */
/*   Updated: 2022/06/23 01:02:14 by rvrignon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	makejob(t_board *board)
{
	if (check_stack(board->a))
		return ;
	if (lstsize(board->a) > 5)
		big_stack_solver(board);
	else
		little_stack_solver(board);
}

int	main(int ac, char **av)
{
	t_board	*board;

	board = NULL;
	if (ac < 2)
		return (error());
	else if (ac == 2)
	{
		av = ft_split(av[1], ' ');
		board = create_board(board, av, 0);
		free_split(av);
	}
	else if (ac > 2)
		board = create_board(board, av, 1);
	if (!board)
		return (error());
	get_rank(board->a);
	makejob(board);
	free_board(board);
	return (0);
}
