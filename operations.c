#include "../push_swap.h"

void	push(t_stack_node **dest, t_stack_node **src, char *operations)
{
	t_stack_node	*tmp;

	if (!src || !*src)
		return ;
	tmp = *src;
	*src = (*src)->next;
	if (*src)
		(*src)->prev = NULL;
	tmp->next = *dest;
	if (*dest)
		(*dest)->prev = tmp;
	*dest = tmp;
	ft_printf ("%s\n", operations);
}

void	swap(t_stack_node **head, char *operations)
{
	t_stack_node	*tmp;

	if (!*head || !(*head)->next)
		return ;
	tmp = *head;
	*head = (*head)->next;
	tmp->next = (*head)->next;
	(*head)->next = tmp;
	(*head)->prev = tmp->prev;
	tmp->prev = *head;
	if (tmp->next)
		tmp->next->prev = tmp;
	ft_printf ("%s\n", operations);
}

void	rotate(t_stack_node **head, char *operation)
{
	t_stack_node	*first;
	t_stack_node	*last;

	if (!*head || !(*head)->next)
		return ;
	first = *head;
	last = stack_last(*head);
	*head = first->next;
	(*head)->prev = NULL;
	last->next = first;
	first->prev = last;
	first->next = NULL;
	ft_printf ("%s\n", operation);
}

void	reverse_rotate(t_stack_node **head, char *operation)
{
	t_stack_node	*last;
	t_stack_node	*second_last;

	if (!*head || !(*head)->next)
		return ;
	last = *head;
	second_last = NULL;
	while (last->next != NULL)
	{
		second_last = last;
		last = last->next;
	}
	second_last->next = NULL;
	last->prev = NULL;
	last->next = *head;
	(*head)->prev = last;
	*head = last;
	if (operation)
		ft_printf ("%s\n", operation);
}

void	double_operation(t_stack_node **a, t_stack_node **b,
	void (*op)(t_stack_node**, char*), char *op_name)
{
	if (!a || !b || !op)
		return ;
	op (a, NULL);
	op (b, NULL);
	if (op_name)
		ft_printf ("%s\n", op_name);
}
