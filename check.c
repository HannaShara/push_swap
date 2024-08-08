/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsharame <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 15:32:49 by hsharame          #+#    #+#             */
/*   Updated: 2024/08/07 15:32:51 by hsharame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
    Return 0 si ce n'est pas trie.
*/

int	check_sorted(t_stack *stack)
{
	while (stack->next != NULL)
	{
		if (stack->nbr > stack->next->nbr)
			return (0);
		stack = stack->next;
	}
	return (1);
}

/*
    Return 0 si ce n'est pas trie dans l'ordre decroissant.
*/
int	check_sorted_reverse(t_stack *stack)
{
	while (stack->next != NULL)
	{
		if (stack->nbr < stack->next->nbr)
			return (0);
		stack = stack->next;
	}
	return (1);
}
