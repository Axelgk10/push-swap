#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include <stdbool.h>
# include "./libft/libft.h"

typedef struct s_stack_node
{
	int					value;
	int					index;
	struct s_stack_node	*next;
	struct s_stack_node	*prev;
}	t_stack_node;
//PARSING
void			parse_args(int argc, char **argv, t_stack_node **stack_a);
void			check_duplicates(t_stack_node *stack);
//PARSING2
void			free_split(char **split);
int				is_valid_digit(const char *s);
//OPERATIONS
void			push(t_stack_node **dest, t_stack_node **src, char *operations);
void			swap(t_stack_node **head, char *operations);
void			rotate(t_stack_node **head, char *operation);
void			reverse_rotate(t_stack_node **head, char *operation);
void			double_operation(t_stack_node **a, t_stack_node **b,
					void (*op)(t_stack_node**, char*), char *op_name);
//UTILS
t_stack_node	*stack_last(t_stack_node *stack);
int				stack_size(t_stack_node *stack);
bool			is_sorted(t_stack_node *stack);
void			assign_indexes(t_stack_node *stack);
//ALGORITHMS
void			sort_three(t_stack_node **stack);
void			sort_small(t_stack_node **a, t_stack_node **b);
void			sort_large(t_stack_node **a, t_stack_node **b);
void			sort_and_push_back(t_stack_node **a, t_stack_node **b);
//ALGORITHMS2
int				find_min_position(t_stack_node *stack);
int				find_max_position(t_stack_node *stack);
//ERRORS
void			error_exit(t_stack_node **stack);
void			free_stack(t_stack_node **stack);

#endif
