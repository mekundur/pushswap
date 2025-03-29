/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mekundur <mekundur@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 16:31:19 by mekundur          #+#    #+#             */
/*   Updated: 2024/05/09 16:24:05 by mekundur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

static int	limit_check(char **arr)
{
	int	num;
	int	i;

	num = 0;
	while (arr[num])
	{
		i = 0;
		if (arr[num][i] == '-' || arr[num][i] == '+')
		{
			if (arr[num][++i] == '0')
				return (1);
		}
		else if (arr[num][i] != '0' && ft_atoi(arr[num]) == 0)
			return (0);
		num++;
	}
	return (1);
}

static int	doubles_check(char **arr)
{
	int	num;
	int	num2;
	int	tmp;

	num = 0;
	tmp = 0;
	while (arr[num])
	{
		tmp = ft_atoi(arr[num]);
		num2 = num + 1;
		while (arr[num2])
		{
			if (tmp == ft_atoi(arr[num2]))
				return (0);
			num2++;
		}
		num++;
	}
	return (1);
}

static int	minusplus_check(char **arr)
{
	int	num;
	int	i;

	i = 0;
	num = 0;
	while (arr[num])
	{
		i = 0;
		if (arr[num][i] == '-' || arr[num][i] == '+' ||
			(arr[num][i] >= '0' && arr[num][i] <= '9'))
		{
			i++;
			while (arr[num][i])
			{
				if (!(arr[num][i] >= '0' && arr[num][i] <= '9'))
					return (0);
				i++;
			}
		}
		num++;
	}
	return (1);
}

int	input_check(char **arr)
{
	if (!minusplus_check(arr))
		return (-1);
	if (!doubles_check(arr))
		return (-1);
	if (!limit_check(arr))
		return (-1);
	return (0);
}
