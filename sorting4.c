/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting4.c	                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mekundur <mekundur@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 12:34:39 by mekundur          #+#    #+#             */
/*   Updated: 2024/05/11 14:08:43 by mekundur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

static int	current_final_flag(int arr[7])
{
	int	flag;
	int	min;

	flag = 1;
	min = arr[0] + arr[1] - arr[4];
	if ((arr[2] + arr[3] - arr[5]) < min)
	{
		min = arr[2] + arr[3] - arr[5];
		flag = 2;
	}
	if ((arr[0] + arr[3]) < min)
	{
		min = arr[0] + arr[3];
		flag = 3;
	}
	if ((arr[1] + arr[2]) < min)
	{
		min = arr[1] + arr[2];
		flag = 4;
	}
	return (flag);
}

static void	current_final_state1(int arr[7])
{
	if (arr[0] && arr[1] && (arr[0] >= arr[1]))
	{
		arr[4] = arr[1];
		arr[0] = arr[0] - arr[4];
		arr[1] = 0;
	}
	else if (arr[0] && arr[1] && (arr[0] < arr[1]))
	{
		arr[4] = arr[0];
		arr[0] = 0;
		arr[1] = arr[1] - arr[4];
	}
	arr[2] = 0;
	arr[3] = 0;
	arr[5] = 0;
}

static void	current_final_state2(int arr[7])
{
	if (arr[2] && arr[3] && (arr[2] >= arr[3]))
	{
		arr[5] = arr[3];
		arr[2] = arr[2] - arr[5];
		arr[3] = 0;
	}
	else if (arr[2] && arr[3] && (arr[2] < arr[3]))
	{
		arr[5] = arr[2];
		arr[2] = 0;
		arr[3] = arr[3] - arr[5];
	}
	arr[0] = 0;
	arr[1] = 0;
	arr[4] = 0;
}

static void	current_final_state34(int arr[7], int flag)
{
	if (flag == 3)
	{
		arr[1] = 0;
		arr[2] = 0;
		arr[4] = 0;
		arr[5] = 0;
	}
	else if (flag == 4)
	{
		arr[0] = 0;
		arr[3] = 0;
		arr[4] = 0;
		arr[5] = 0;
	}
}

void	ft_current_final(int arr[7])
{
	int	flag;

	if (arr[0] && arr[1] && (arr[0] >= arr[1]))
		arr[4] = arr[1];
	else if (arr[0] && arr[1] && (arr[0] < arr[1]))
		arr[4] = arr[0];
	if (arr[2] && arr[3] && (arr[2] >= arr[3]))
		arr[5] = arr[3];
	else if (arr[2] && arr[3] && (arr[2] < arr[3]))
		arr[5] = arr[2];
	flag = current_final_flag(arr);
	if (flag == 1)
		current_final_state1(arr);
	else if (flag == 2)
		current_final_state2(arr);
	else if (flag == 3)
		current_final_state34(arr, 3);
	else if (flag == 4)
		current_final_state34(arr, 4);
}
