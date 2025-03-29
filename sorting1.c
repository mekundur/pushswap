/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mekundur <mekundur@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 20:32:23 by mekundur          #+#    #+#             */
/*   Updated: 2024/05/11 13:40:21 by mekundur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	five_numbers(t_list **a, t_list **b)
{
	int		max;

	max = ft_lstmax(*a);
	if ((*a)->num == max)
		ft_r(*a, 'a');
	ft_p(a, b, 'b');
	if ((*a)->num == max)
		ft_r(*a, 'a');
	ft_p(a, b, 'b');
	three_numbers(*a);
	while (*b)
	{
		if ((*b)->num < (*a)->num)
			ft_p(b, a, 'a');
		else
			ft_r(*a, 'a');
	}
	while (!ft_lstsorted(*a))
		ft_r(*a, 'a');
}

void	three_numbers(t_list *a)
{
	if (ft_lstsize(a) == 2)
	{
		if (a->num > a->next->num)
			ft_s(a, 'a');
	}
	else if (ft_lstsize(a) == 3)
	{
		while (a)
		{
			if ((a->num < a->next->num) && (a->next->num > a->next->next->num))
				ft_revr(a, 'a');
			else if ((a->num > a->next->num) && (a->num < a->next->next->num))
				ft_s(a, 'a');
			else if ((a->num > a->next->next->num)
				&& (a->next->num > a->next->next->num))
				ft_r(a, 'a');
			else if ((a->num > a->next->num)
				&& (a->next->num < a->next->next->num))
				ft_r(a, 'a');
			else if (ft_lstsorted(a))
				break ;
		}
	}
}

void	ft_sorting(t_list **a, t_list **b)
{
	if (ft_lstsorted(*a))
		return ;
	else if (ft_lstsize(*a) <= 3)
		three_numbers(*a);
	else if (ft_lstsize(*a) <= 5)
		five_numbers(a, b);
	else
		many_numbers(a, b);
}
