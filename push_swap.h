
#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include <stdio.h>
# include <stdint.h>
typedef struct s_stack
{
    int				value;
    int				index;
    int				pos;
    int				target_pos;
    int				cost_a;
    int				cost_b;
    struct s_stack	*next;
}	t_stack;

/* Stack Functions */
t_stack	*stack_new(int value);
void	stack_add_back(t_stack **stack, t_stack *new);
t_stack	*stack_last(t_stack *stack);
void	stack_clear(t_stack **stack);
int		stack_size(t_stack *stack);

/* Operations */
void	sa(t_stack **a, int print);
void	sb(t_stack **b, int print);
void	ss(t_stack **a, t_stack **b);
void	pa(t_stack **a, t_stack **b);
void	pb(t_stack **a, t_stack **b);
void	ra(t_stack **a, int print);
void	rb(t_stack **b, int print);
void	rr(t_stack **a, t_stack **b);
void	rra(t_stack **a, int print);
void	rrb(t_stack **b, int print);
void	rrr(t_stack **a, t_stack **b);

/* Position Functions */
void	get_position(t_stack **stack);
void	get_target_position(t_stack **a, t_stack **b);
void	get_cost(t_stack **a, t_stack **b);
void	do_cheapest_move(t_stack **a, t_stack **b);

/* Sort Functions */
void	sort_three(t_stack **stack);
void	sort_stack(t_stack **a, t_stack **b);
int		get_highest_index(t_stack *stack);
int		get_lowest_position(t_stack **stack);

/* Cost Functions */
void	do_move(t_stack **a, t_stack **b, int cost_a, int cost_b);

/* Utils */
long		ft_atoi(const char *str);
void	ft_error(void);
int		is_sorted(t_stack *stack);
int		has_duplicates(t_stack *stack);
void	ft_putnbr(int n);

int *stack_to_array(t_stack *stack);
void sort_array(int *arr, int size);
void index_stack(t_stack **stack);
void	print_sorted_stack(t_stack *stack);

// args 
char	**ft_split(char *s, char *set);
int	check_dups(t_stack *stack);
int	check_input(char **strs);
void	init_stack(char **numbers, t_stack **stack);
void	free_strs(char **strs);
t_stack	*check_args(int ac, char **av);
int	ft_isdigit(int c);
int	ft_strncmp(char *s1, char *s2, size_t n);
int	ft_intcmp(int a, int b);

//libft 
void	*ft_memset(void *s, int c, size_t n);
size_t	ft_strlen(char *str);
void	*ft_calloc(size_t num_elements, size_t element_size);
#endif