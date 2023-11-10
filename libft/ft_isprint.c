/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-oual <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 09:21:48 by ael-oual          #+#    #+#             */
/*   Updated: 2021/11/04 09:38:04 by ael-oual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include"libft.h"

int	ft_isprint(int c)
{
	if (c >= 32 && c <= 126)
		return (1);
	else
		return (0);
}
/*
#include <ctype.h>
#include <stdio.h>
int main()
{
             printf(" %d ", ft_isprint(38));
   return 0;
}
*/
