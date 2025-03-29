/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mekundur <mekundur@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 16:31:00 by mekundur          #+#    #+#             */
/*   Updated: 2024/05/11 14:21:53 by mekundur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	final_pushing_back(t_list **a, t_list **b, int max)
{
	int		i;
	t_list	*pb;

	if (b && *b && !revsort(*b))
	{
		pb = *b;
		i = 0;
		while (pb->num != max)
		{
			pb = pb->next;
			i++;
		}
		if (i <= ft_lstsize(*b) / 2)
		{
			while (!revsort(*b))
				ft_r(*b, 'b');
		}
		else
		{
			while (!revsort(*b))
				ft_revr(*b, 'b');
		}
	}
	while (*b)
		ft_p(b, a, 'a');
}

void	many_numbers_action(t_list **a, t_list **b, int cheap[7])
{
	if (cheap[6] == 0)
		ft_p(a, b, 'b');
	while (cheap[4]-- > 0)
		ft_rr(*a, *b);
	while (cheap[5]-- > 0)
		ft_revrr(*a, *b);
	while (cheap[0]-- > 0)
		ft_r(*a, 'a');
	while (cheap[1]-- > 0)
		ft_r(*b, 'b');
	while (cheap[2]-- > 0)
		ft_revr(*a, 'a');
	while (cheap[3]-- > 0)
		ft_revr(*b, 'b');
}

void	many_numbers(t_list **a, t_list **b)
{
	int	cheap[7];

	if (ft_lstsorted(*a))
		return ;
	ft_p(a, b, 'b');
	ft_p(a, b, 'b');
	while (*a)
	{
		ft_cheapest(cheap, *a, *b, ft_lstlast(*b));
		many_numbers_action(a, b, cheap);
	}
	final_pushing_back(a, b, ft_lstmax(*b));
}
