
#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../bonus/get_next_line.h"
# include <limits.h>
# include <stdint.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
typedef struct s_stack
{
	int				value;
	int				index;
	int				pos;
	int				target_pos;
	int				cost_a;
	int				cost_b;
	struct s_stack	*next;
}					t_stack;

/* Stack Functions stack.c */
t_stack				*stack_new(int value);
void				stack_add_back(t_stack **stack, t_stack *new);
t_stack				*stack_last(t_stack *stack);
void				stack_clear(t_stack **stack);
int					stack_size(t_stack *stack);

/* Operations */
void				sa(t_stack **a, int print);
void				sb(t_stack **b, int print);
void				ss(t_stack **a, t_stack **b);
void				pa(t_stack **a, t_stack **b);
void				pb(t_stack **a, t_stack **b);
void				ra(t_stack **a, int print);
void				rb(t_stack **b, int print);
void				rr(t_stack **a, t_stack **b);
void				rra(t_stack **a, int print);
void				rrb(t_stack **b, int print);
void				rrr(t_stack **a, t_stack **b);

/* Position Functions positions.c*/
int					get_target(t_stack **a, int b_idx, int target_idx,
						int target_pos);
void				get_position(t_stack **stack);
void				get_target_position(t_stack **a, t_stack **b);
int					get_highest_index(t_stack *stack);
int					get_lowest_position(t_stack **stack);

/* Sort Functions */
void				push_all_save_three(t_stack **a, t_stack **b);
void				sort_three(t_stack **stack);
void				shift_stack(t_stack **stack_a);
void				sort_stack(t_stack **a, t_stack **b);

/* Cost Functions */
void				get_cost(t_stack **a, t_stack **b);
void				do_rotate_both(t_stack **a, t_stack **b, int *cost_a,
						int *cost_b);
void				do_reverse_rotate_both(t_stack **a, t_stack **b,
						int *cost_a, int *cost_b);
void				do_cheapest_move(t_stack **a, t_stack **b);
void				do_move(t_stack **a, t_stack **b, int cost_a, int cost_b);

/* Utils */
int					ft_atoi(const char *str, char **numbers, t_stack **stack);
void				ft_error(void);
int					is_sorted(t_stack *stack);
int					has_duplicates(t_stack *stack);
void				ft_putnbr(int n);

/* Utils 2*/
int					*stack_to_array(t_stack *stack);
void				sort_array(int *arr, int size);
void				index_stack(t_stack **stack);
int					abs_value(int n);

/* parsing */
int					check_dups(t_stack *stack);
int					check_input(char **strs);
void				init_stack(char **numbers, t_stack **stack);
void				free_strs(char **strs);
t_stack				*check_args(int ac, char **av);

/* split */
char				**ft_split(char *s, char *set);

/* string.c */
int					ft_isdigit(int c);
int					ft_strncmp(char *s1, char *s2, size_t n);
int					ft_intcmp(int a, int b);
void				*ft_memset(void *s, int c, size_t n);

void				print_sorted_stack(t_stack *stack);

#endif