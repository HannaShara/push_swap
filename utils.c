/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsharame <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 16:21:04 by hsharame          #+#    #+#             */
/*   Updated: 2024/07/15 16:21:06 by hsharame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_nbrcmp(const char *s1, const char *s2)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (s1[i] == '+')
		i++;
	if (s2[j] == '+')
		j++;
	while (s1 && s2 && s1[i] == s2[i])
    {
		i++;
		j++;
    }
	return ((unsigned char)s1[i] - (unsigned char)s2[j]);
}

void	ft_error(t_stack **stack_a, t_stack **stack_b)
{
	if (*stack_a != NULL)
		free_stack(stack_a);
	if (*stack_b != NULL)
		free_stack(stack_b);
	write(2, "Error\n", 6);
}

int	check_argv(char *s1)
{
	int	i;

	i = 0;
	while (s1[i] !='\0')
	{
		if (!ft_isdigit(s1[i]) && s1[i] != ' ' &&
			s1[i] != '+' && s1[i] != '-')
			return (0);
		i++;
	}
	return (1);
}

int	stack_is_empty(t_stack *stack)
{
	if (stack == NULL || stack->next == NULL)
		return (1);
	else
		return (0);
}