#include "../push_swap.h"

int	find_min_position(t_stack_node *stack)
{
	int	min_value;
	int	min_position;
	int	current_position;

	if (!stack)
		return (0);
	min_value = stack->value;
	min_position = 0;
	current_position = 0;
	while (stack)
	{
		if (stack->value < min_value)
		{
			min_value = stack->value;
			min_position = current_position;
		}
		current_position++;
		stack = stack->next;
	}
	return (min_position);
}

int	find_max_position(t_stack_node *stack)
{
	int	max_value;
	int	max_position;
	int	current_position;

	if (!stack)
		return (0);
	max_value = stack->value;
	max_position = 0;
	current_position = 0;
	while (stack)
	{
		if (stack->value > max_value)
		{
			max_value = stack->value;
			max_position = current_position;
		}
		current_position++;
		stack = stack->next;
	}
	return (max_position);
}
