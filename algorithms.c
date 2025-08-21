#include "../push_swap.h"

void	sort_three(t_stack_node **stack)
{
	int	top;
	int	mid;
	int	bot;

	top = (*stack)->value;
	mid = (*stack)->next->value;
	bot = (*stack)->next->next->value;
	if (top > mid && mid < bot && top < bot)
		swap(stack, "sa");
	else if (top > mid && mid > bot)
	{
		swap(stack, "sa");
		reverse_rotate(stack, "rra");
	}
	else if (top > mid && mid < bot && top > bot)
		rotate (stack, "ra");
	else if (top < mid && mid > bot && top < bot)
	{
		swap (stack, "sa");
		rotate (stack, "ra");
	}
	else if (top < mid && mid > bot && top > bot)
		reverse_rotate (stack, "rra");
}

void	sort_small(t_stack_node **a, t_stack_node **b)
{
	int	size;
	int	min_pos;

	size = stack_size(*a);
	while (--size >= 3)
	{
		min_pos = find_min_position(*a);
		while (min_pos != 0)
		{
			if (min_pos <= stack_size(*a) / 2)
				rotate (a, "ra");
			else
				reverse_rotate(a, "rra");
			min_pos = find_min_position(*a);
		}
		push(b, a, "pb");
	}
	sort_three (a);
	while (*b)
		push (a, b, "pa");
}

static void	push_chunks(t_stack_node **a, t_stack_node **b, int chunk_size)
{
	int	pushed;
	int	i;
	int	target;

	i = 0;
	while (*a)
	{
		pushed = 0;
		target = i + chunk_size;
		while (pushed < chunk_size && *a)
		{
			if ((*a)->index <= target)
			{
				push(b, a, "pb");
				pushed++;
				if (*b && (*b)->next && (*b)->index < (*b)->next->index)
					swap(b, "sb");
			}
			else
				rotate(a, "ra");
		}
		i += chunk_size;
	}
}

void	sort_and_push_back(t_stack_node **a, t_stack_node **b)
{
	int	max_pos;
	int	size_b;

	while (*b)
	{
		max_pos = find_max_position(*b);
		size_b = stack_size(*b);
		if (max_pos == 0)
			push(a, b, "pa");
		else if (max_pos <= size_b / 2)
			rotate(b, "rb");
		else
			reverse_rotate(b, "rrb");
	}
}

void	sort_large(t_stack_node **a, t_stack_node **b)
{
	int	size;
	int	chunk_size;

	size = stack_size(*a);
	if (size <= 100)
		chunk_size = 20;
	else
		chunk_size = 45;
	assign_indexes(*a);
	push_chunks(a, b, chunk_size);
	sort_and_push_back(a, b);
}
