/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvrignon <rvrignon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 17:19:15 by rvrignon          #+#    #+#             */
/*   Updated: 2022/06/03 14:54:08 by rvrignon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "stdio.h"

void	makejob(t_board *board)
{
	swap_sa(board);
	swap_pb(board);
	swap_pb(board);
	swap_pb(board);
	swap_ra(board);
	swap_rb(board);
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
	makejob(board);
	ft_printf("--A--\n");
	print_stack(board->a);
	ft_printf("--B--\n");
	print_stack(board->b);
	free_board(board);
	return (1);
}
