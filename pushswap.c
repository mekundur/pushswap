/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mekundur <mekundur@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 14:19:10 by mekundur          #+#    #+#             */
/*   Updated: 2024/05/11 13:36:26 by mekundur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	push_swap(char **arr)
{
	int		num;
	t_list	*a;
	t_list	*b;
	t_list	*new;

	num = 0;
	a = 0;
	b = 0;
	while (arr && arr[num])
	{
		new = ft_lstnew(ft_atoi(arr[num]));
		ft_lstadd_back(&a, new);
		num++;
	}
	ft_sorting(&a, &b);
	if (a)
		ft_lstclear(&a);
	if (b)
		ft_lstclear(&b);
	return (0);
}

int	main(int argc, char **argv)
{
	int		i;
	char	**arr;

	i = 0;
	if (argc < 2)
		return (0);
	if (argc == 2)
	{
		if (ft_white_space(argv[1]) == 0)
			return (0);
		arr = ft_split(argv[1], ' ');
	}
	else
		arr = &argv[1];
	if (input_check(arr) < 0)
		return (write(1, "Error\n", 6));
	push_swap(arr);
	if (argc == 2)
	{
		while (arr[i])
			free(arr[i++]);
		free (arr);
	}
	return (0);
}
