

/*
int get_pivot(t_stack *stack, int i)
{
    while (stack->index != i)
    {
        stack = stack->next;
        i--;
    }
    return (stack->index);
}


    Fais la trie dans l'ordre decroissant pour pouvoir apres utiliser pa.


void   quicksort_b(t_stack **stack_a, t_stack **stack_b)
{
    int pivot;
    int size;
 
    size = stack_size(*stack_b);
    if (check_sorted_reverse(*stack_b) || size <= 1)
        return;
    pivot = get_pivot(*stack_b, size / 2);
    if (stack_b && !check_sorted_reverse(*stack_b))
    {
        if (size == 2)
            sb(stack_b);
        else if (size == 3)
            sort_three_reverse(stack_b);
        else
            {
                if ((*stack_b)->index >= pivot)
                    pa(stack_a, stack_b);
                else
                    rb(stack_b);
            }
    }
    if ((*stack_b)->index < (*stack_b)->next->index)
        sb(stack_b); 
   if (check_sorted(*stack_b))
    {
        while (!check_sorted_reverse(*stack_b))
            rrb(stack_b);
    }
    quicksort_b(stack_a, stack_b);
}


    Fait la premiere partition, remplit le stack b des nombres inferieures au pivot.


void    quicksort_a(t_stack **stack_a, t_stack **stack_b)
{
    int pivot;
    int size;
    int count = 0;

    size = stack_size(*stack_a);
    if (check_sorted(*stack_a) || size <= 1 )
        return;
    pivot = get_pivot(*stack_a, size / 2);
    while (size)
    {        
        if (size == 2)
            sa(stack_a);
        else if (size == 3)
            sort_three(stack_a);
        else
        {
            if ((*stack_a)->index <= pivot)
            {
                pb(stack_a, stack_b);
                count++;
            }
            else
            ra(stack_a);
        size--;
    }
    if ((*stack_a)->index > (*stack_a)->next->index)
       sa(stack_a);
    if (check_sorted_reverse(*stack_a))
    {
        while (!check_sorted(*stack_a))
            rra(stack_a);
    }
}

void    quicksort(t_stack **stack_a, t_stack **stack_b)
{
    while (!check_sorted(*stack_a))
    {
    quicksort_a(stack_a, stack_b);
    quicksort_b(stack_a, stack_b);
    while (*stack_b != NULL)
        pa(stack_a, stack_b);
    }
}

int find_smallest(t_stack *stack)
{
    int smallest;

    smallest = stack->index;
    while(stack)
    {
        if (smallest > stack->index)
            smallest = stack->index;
        stack = stack->next;
    }
    return (smallest);
}
void    sort_three_reverse(t_stack **stack)
{
    int smallest;

    if (check_sorted_reverse(*stack))
        return;
    smallest = find_smallest(*stack);
    if ((*stack)->index == smallest)
        rb(stack);
    else if ((*stack)->next->index == smallest)
        rrb(stack);
    if ((*stack)->index < (*stack)->next->index)
        sb(stack);
}

/*int	get_target(t_stack **stack, int until)
{
	t_stack	*temp;

	temp = *stack;
	while (temp->index > until)
		temp = temp->next;
	return (temp->index);
}

int	get_target_bottom(t_stack **stack, int until)
{
	t_stack	*temp;
	int		index_bottom;

	temp = *stack;
	while (temp != NULL)
	{
		if (temp->index <= until)
			index_bottom = temp->index;
		temp = temp->next;
	}
	return (index_bottom);
}

void	chunk(t_stack **stack_a, t_stack **stack_b, int until)
{
	t_stack	*pointer_top;
	int		index_top;
	int		index_bottom;
	int		top;
	int		bottom;

	if (!check_chunk(stack_a, until))
		return ;
	position_update(stack_a);
	pointer_top = *stack_a;
	index_top = get_target(stack_a, until);
	index_bottom = get_target_bottom(stack_a, until);
	top = 0;
	bottom = 0;
	if (stack_b != NULL && (*stack_b) != NULL)
	{
		top = abs_value((*stack_b)->index - index_top);
		bottom = abs_value((*stack_b)->index - index_bottom);
	}
	if (top < bottom)
	{
		while ((*stack_a)->index != index_top)
			ra(stack_a);
	}
	else
	{
		while ((*stack_a)->index != index_bottom)
			rra(stack_a);
	}
	pb(stack_a, stack_b);
	chunk(stack_a, stack_b, until);
}*/

