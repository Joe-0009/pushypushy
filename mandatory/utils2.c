/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrachidi <yrachidi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/25 16:44:11 by yrachidi          #+#    #+#             */
/*   Updated: 2024/12/25 16:50:23 by yrachidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*stack_to_array(t_stack *stack)
{
	int	*arr;
	int	size;
	int	i;

	if (!stack)
		return (NULL);
	size = stack_size(stack);
	arr = (int *)malloc(sizeof(int) * size);
	if (!arr)
		return (NULL);
	i = 0;
	while (stack)
	{
		arr[i++] = stack->value;
		stack = stack->next;
	}
	sort_array(arr, i);
	return (arr);
}

void	sort_array(int *arr, int size)
{
	int	i;
	int	j;
	int	temp;

	i = 0;
	while (i < size - 1)
	{
		j = 0;
		while (j < size - i - 1)
		{
			if (arr[j] > arr[j + 1])
			{
				temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
			j++;
		}
		i++;
	}
}

void	index_stack(t_stack **stack)
{
	int		*arr;
	int		i;
	int		size;
	t_stack	*tmp;

	size = stack_size(*stack);
	if (size == 0)
		return ;
	arr = stack_to_array(*stack);
	tmp = *stack;
	i = 0;
	while (++i < size)
	{
		tmp = *stack;
		while (tmp)
		{
			if (tmp->value == arr[i] && tmp->index == 0)
			{
				tmp->index = i + 1;
				break ;
			}
			tmp = tmp->next;
		}
	}
	free(arr);
}

int	abs_value(int n)
{
	if (n < 0)
		return (n * -1);
	return (n);
}
