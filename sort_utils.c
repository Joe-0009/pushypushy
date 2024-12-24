
#include "push_swap.h"

int	get_highest_index(t_stack *stack)
{
    int	highest;

    if (!stack)
        return (0);
    highest = stack->index;
    while (stack)
    {
        if (stack->index > highest)
            highest = stack->index;
        stack = stack->next;
    }
    return (highest);
}

int	get_lowest_position(t_stack **stack)
{
    t_stack	*tmp;
    int		lowest_index;
    int		lowest_pos;

    tmp = *stack;
    lowest_index = 2147483647;
    get_position(stack);
    lowest_pos = tmp->pos;
    while (tmp)
    {
        if (tmp->index < lowest_index)
        {
            lowest_index = tmp->index;
            lowest_pos = tmp->pos;
        }
        tmp = tmp->next;
    }
    return (lowest_pos);
}