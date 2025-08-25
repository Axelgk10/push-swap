#include "../push_swap.h"

static long	ft_atol(const char *s)
{
	long	num;
	int		sign;
	int		i;

	if (is_valid_digit(s) == 0)
		return (LONG_MAX);
	num = 0;
	sign = 1;
	i = 0;
	while (s[i] == ' ' || (s[i] >= '\t' && s[i] <= '\r'))
		i++;
	if (s[i] == '-')
		sign = -1;
	if (s[i] == '-' || s[i] == '+')
		i++;
	while (s[i] >= '0' && s[i] <= '9')
	{
		num = (num * 10 +(s[i] - '0'));
		i++;
	}
	return (num * sign);
}

static void	add_node(t_stack_node **stack, int num)
{
	t_stack_node	*new;
	t_stack_node	*last;

	new = malloc(sizeof(t_stack_node));
	new -> value = num;
	new -> next = NULL;
	if (!new)
		error_exit(stack);
	if (!*stack)
	{
		*stack = new;
		new->prev = NULL;
	}
	else
	{
		last = stack_last(*stack);
		last -> next = new;
		new -> prev = last;
	}
}

static void	process_single_argument(char *arg, t_stack_node **stack)
{
	long	num;
	char	**numbers;
	int		j;

	if (arg[0] == '\0')
		error_exit(stack);
	numbers = ft_split(arg, ' ');
	if (!numbers)
		error_exit(stack);
	j = -1;
	while (numbers[++j])
	{
		num = ft_atol(numbers[j]);
		if (num == LONG_MAX || num > INT_MAX || num < INT_MIN)
		{
			free_split(numbers);
			error_exit(stack);
		}
		add_node(stack, (int)num);
	}
	free_split(numbers);
}

void	parse_args(int argc, char **argv, t_stack_node **stack)
{
	int	i;

	i = 0;
	while (++i < argc)
		process_single_argument(argv[i], stack);
	check_duplicates(*stack);
}

void	check_duplicates(t_stack_node *stack)
{
	t_stack_node	*tmp;
	t_stack_node	*current;

	current = stack;
	while (current)
	{
		tmp = current -> next;
		while (tmp)
		{
			if (current -> value == tmp -> value)
				error_exit(&stack);
			tmp = tmp -> next;
		}
		current = current -> next;
	}
}
