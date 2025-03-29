/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops1.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mekundur <mekundur@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 14:36:27 by mekundur          #+#    #+#             */
/*   Updated: 2024/04/30 18:37:49 by mekundur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	ft_s(t_list *lst, int flag)
{
	int	tmp;

	if (ft_lstsize(lst) > 1)
	{
		tmp = lst->num;
		lst->num = lst->next->num;
		lst->next->num = tmp;
		if (flag == 'a')
			write(1, "sa\n", 3);
		else if (flag == 'b')
			write(1, "sb\n", 3);
	}
}

void	ft_ss(t_list *a, t_list *b)
{
	ft_s(a, 0);
	ft_s(b, 0);
	write(1, "ss\n", 3);
}

void	ft_p(t_list **lst1, t_list **lst2, int flag)
{
	t_list	*tmp1;
	t_list	*tmp2;

	if (ft_lstsize(*lst1) > 0)
	{
		if (lst1 && !lst2)
		{
			*lst2 = ft_lstnew((*lst1)->num);
			tmp1 = (*lst1)->next;
			free(lst1);
			*lst1 = tmp1;
		}
		else if (lst1 && lst2)
		{
			tmp1 = ft_lstnew((*lst1)->num);
			ft_lstadd_front(lst2, tmp1);
			tmp2 = (*lst1)->next;
			free(*lst1);
			*lst1 = tmp2;
		}
		if (flag == 'a')
			write(1, "pa\n", 3);
		else if (flag == 'b')
			write(1, "pb\n", 3);
	}
}
