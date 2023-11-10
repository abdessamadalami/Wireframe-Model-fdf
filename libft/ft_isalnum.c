/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-oual <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 14:07:10 by ael-oual          #+#    #+#             */
/*   Updated: 2021/11/12 06:47:05 by ael-oual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include<stdio.h>
#include"libft.h"

int	ft_isalnum(int c)
{
	if (ft_isalpha(c) || ft_isdigit(c))
		return (1);
	return (0);
}
/*
int main()
{
   printf(" %d %d ", ft_isalnum(-12),isalnum(-12));
}
*/
