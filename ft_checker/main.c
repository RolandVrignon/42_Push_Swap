/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvrignon <rvrignon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 15:28:41 by rvrignon          #+#    #+#             */
/*   Updated: 2022/06/13 17:55:46 by rvrignon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static void	return_value(t_board *board, int size)
{
	if (check_stack(board->a) && lstsize(board->a) == size)
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
}

static void	make_move(char *tmp, t_board *board)
{
	if (!ft_strncmp(tmp, "sa", 2))
		swap_sa(board);
	else if (!ft_strncmp(tmp, "rra", 3))
		swap_rra(board);
	else if (!ft_strncmp(tmp, "rrb", 3))
		swap_rrb(board);
	else if (!ft_strncmp(tmp, "rrr", 3))
		swap_rrr(board);
	else if (!ft_strncmp(tmp, "sb", 2))
		swap_sb(board);
	else if (!ft_strncmp(tmp, "ss", 2))
		swap_ss(board);
	else if (!ft_strncmp(tmp, "pa", 2))
		swap_pa(board);
	else if (!ft_strncmp(tmp, "pb", 2))
		swap_pb(board);
	else if (!ft_strncmp(tmp, "ra", 2))
		swap_ra(board);
	else if (!ft_strncmp(tmp, "rb", 2))
		swap_rb(board);
	else if (!ft_strncmp(tmp, "rr", 2))
		swap_rr(board);
}

static void	makejob(t_board *board)
{
	char	*tmp;
	int		size;

	size = lstsize(board->a);
	tmp = get_next_line(0);
	if (!tmp)
		return ;
	while (tmp != NULL)
	{
		make_move(tmp, board);
		free(tmp);
		tmp = get_next_line(0);
	}
	free(tmp);
	return_value(board, size);
}

int	main(int ac, char **av)
{
	t_board	*board;

	board = NULL;
	if (ac < 2)
		return (1);
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
	free_board(board);
	return (1);
}
