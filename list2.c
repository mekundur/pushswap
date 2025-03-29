/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mekundur <mekundur@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 16:26:07 by mekundur          #+#    #+#             */
/*   Updated: 2024/04/29 17:32:58 by mekundur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	ft_lstmax(t_list *lst)
{
	int	max;

	max = lst->num;
	while (lst->next)
	{
		if (max < lst->next->num)
			max = lst->next->num;
		lst = lst->next;
	}
	return (max);
}

int	revsort(t_list *b)
{
	while (b->next)
	{
		if (b->num < b->next->num)
			return (0);
		b = b->next;
	}
	return (1);
}

int	ft_lstsorted(t_list *a)
{
	while (a->next)
	{
		if (a->num > a->next->num)
			return (0);
		a = a->next;
	}
	return (1);
}

int	ft_lstlast(t_list *lst)
{
	int		last;
	t_list	*p;

	p = lst;
	while (p->next)
		p = p->next;
	last = p->num;
	return (last);
}
