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
	while (s1[i] != '\0' && s2[i] != '\0' && s1[i] == s2[i])
	{
		i++;
		j++;
	}
	return ((unsigned char)s1[i] - (unsigned char)s2[j]);
}

int	ft_error(t_stack **stack_a, t_stack **stack_b)
{
	if (*stack_a != NULL)
		free_stack(stack_a);
	if (*stack_b != NULL)
		free_stack(stack_b);
	write(2, "Error\n", 6);
	return (2);
}

int	abs_value(int i)
{
	if (i < 0)
		i *= -1;
	return (i);
}
