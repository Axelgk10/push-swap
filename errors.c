#include "../push_swap.h"

void	error_exit(t_stack_node **stack)
{
	if (stack && *stack)
		free_stack (stack);
	write(2, "Error\n", 6);
	exit (EXIT_FAILURE);
}

void	free_stack(t_stack_node **stack)
{
	t_stack_node	*tmp;
	t_stack_node	*current;

	if (!stack || !*stack)
		return ;
	current = *stack;
	while (current)
	{
		tmp = current->next;
		free (current);
		current = tmp;
	}
	*stack = NULL;
}
