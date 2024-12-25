/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrachidi <yrachidi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/25 16:43:14 by yrachidi          #+#    #+#             */
/*   Updated: 2024/12/25 16:55:20 by yrachidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	check_moves(t_stack **A, t_stack **B, char *op)
{
	if (!ft_strncmp(op, "pa\n", 3))
		pa(A, B, 0);
	else if (!ft_strncmp(op, "pb\n", 3))
		pb(A, B, 0);
	else if (!ft_strncmp(op, "sa\n", 3))
		sa(A, 0);
	else if (!ft_strncmp(op, "sb\n", 3))
		sb(B, 0);
	else if (!ft_strncmp(op, "ss\n", 3))
		ss(A, B, 0);
	else if (!ft_strncmp(op, "ra\n", 3))
		ra(A, 0);
	else if (!ft_strncmp(op, "rb\n", 3))
		rb(B, 0);
	else if (!ft_strncmp(op, "rr\n", 3))
		rr(A, B, 0);
	else if (!ft_strncmp(op, "rra\n", 3))
		rra(A, 0);
	else if (!ft_strncmp(op, "rrb\n", 3))
		rrb(B, 0);
	else if (!ft_strncmp(op, "rrr\n", 3))
		rrr(A, B, 0);
	else
		(free(op), stack_clear(A), stack_clear(B), ft_error());
}

int	main(int ac, char **av)
{
	t_stack	*a;
	t_stack	*b;
	char	*op;

	if (ac == 1)
		ft_error();
	a = check_args(ac, av);
	if (!a)
		ft_error();
	b = NULL;
	op = get_next_line(0);
	while (op)
	{
		check_moves(&a, &b, op);
		free(op);
		op = get_next_line(0);
	}
	if (is_sorted(a) && !b)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	stack_clear(&a);
	stack_clear(&b);
}
