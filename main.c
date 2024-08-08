/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsharame <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 13:08:43 by hsharame          #+#    #+#             */
/*   Updated: 2024/07/16 13:08:45 by hsharame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char *argv[])
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	int		size;

	if (argc < 2)
		return (0);
	if (argc > 2 && !check_input(argv))
		return (write(2, "Error\n", 6));
	if (argc == 2 && check_argv(argv[1]))
	{
		argv = ft_split(argv[1],' ');
		argc = 0;
		while (argv[argc] != NULL)
			argc++;
		if (!check_input(argv))
			return (write(2, "Error\n", 6));
	}
	stack_a = fill_stack(argc, argv);
	stack_b = NULL;
	size = stack_size(stack_a);
	stack_index(stack_a, size + 1);
	push_swap(&stack_a, &stack_b, size);
	free_stack(&stack_a);
	free_stack(&stack_b);
	return (0);
}
