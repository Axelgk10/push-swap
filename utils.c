#include "../push_swap.h"

t_stack_node	*stack_last(t_stack_node *stack)
{
	if (!stack)
		return (NULL);
	while (stack->next != NULL)
		stack = stack->next;
	return (stack);
}

int	stack_size(t_stack_node *stack)
{
	int	size;

	size = 0;
	while (stack != NULL)
	{
		size++;
		stack = stack->next;
	}
	return (size);
}

bool	is_sorted(t_stack_node *stack)
{
	if (!stack)
		return (true);
	while (stack->next != NULL)
	{
		if (stack->value > stack->next->value)
			return (false);
		stack = stack->next;
	}
	return (true);
}

void	assign_indexes(t_stack_node *stack)
{
	t_stack_node	*current;
	t_stack_node	*runner;
	int				index;
	int				size;

	if (!stack)
		return ;
	size = stack_size(stack);
	current = stack;
	while (current)
	{
		index = 0;
		runner = stack;
		while (runner)
		{
			if (runner->value < current->value)
				index++;
			runner = runner->next;
		}
		current->index = index;
		current = current->next;
	}
}
