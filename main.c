/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvrignon <rvrignon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 17:19:15 by rvrignon          #+#    #+#             */
/*   Updated: 2022/06/12 18:04:53 by rvrignon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "stdio.h"

static unsigned int	makejob(t_board *board)
{
	unsigned int	steps;

	// steps = solve_main(board);
	swap_sa(board);
	swap_pb(board);
	swap_pb(board);
	swap_pb(board);
	swap_rr(board);
	swap_rrr(board);
	swap_sa(board);
	swap_pa(board);
	swap_pa(board);
	swap_pa(board);
	steps = 11;
	return (steps);
}

int	main(int ac, char **av)
{
	t_board	*board;
	unsigned int	steps;

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
	get_gap(board->a);
	ft_printf("--A--\n");
	print_stack(board->a);
	steps = makejob(board);
	ft_printf("--A--\n");
	print_stack(board->a);
	// ft_printf("--B--\n");
	// print_stack(board->b);
	// ft_printf("--B--\n");
	// print_stack(board->b);
	ft_printf("Commands : %d\n", steps);
	free_board(board);
	return (1);
}
