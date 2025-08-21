#include "../push_swap.h"

int	main(int argc, char **argv)
{
	t_stack_node	*stack_a;
	t_stack_node	*stack_b;

	if (argc < 2)
		return (0);
	stack_a = NULL;
	stack_b = NULL;
	parse_args (argc, argv, &stack_a);
	if (is_sorted(stack_a))
	{
		free_stack(&stack_a);
		return (0);
	}
	assign_indexes(stack_a);
	if (stack_size(stack_a) == 2)
		swap(&stack_a, "sa");
	else if (stack_size(stack_a) == 3)
		sort_three(&stack_a);
	else if (stack_size(stack_a) <= 5)
		sort_small(&stack_a, &stack_b);
	else
		sort_large(&stack_a, &stack_b);
	free_stack(&stack_a);
	free_stack(&stack_b);
	return (0);
}
