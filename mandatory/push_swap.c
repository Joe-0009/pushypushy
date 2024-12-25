#include "push_swap.h"

void	print_sorted_stack(t_stack *stack)
{
	t_stack	*tmp;

	tmp = stack;
	while (tmp)
	{
		ft_putnbr(tmp->value);
		if (tmp->next)
			write(1, " ", 1);
		tmp = tmp->next;
	}
	write(1, "\n", 1);
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;

	a = NULL;
	b = NULL;
	if (argc == 1)
		ft_error();
	a = check_args(argc, argv);
	if (!a)
		ft_error();
	if (!is_sorted(a))
	{
		if (stack_size(a) == 2)
			sa(&a, 1);
		else if (stack_size(a) == 3)
			sort_three(&a);
		else
			sort_stack(&a, &b);
	}
	print_sorted_stack(a);
	stack_clear(&a);
	stack_clear(&b);
	return (0);
}
