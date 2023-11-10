/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-oual <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 15:34:19 by ael-oual          #+#    #+#             */
/*   Updated: 2021/11/15 12:01:43 by ael-oual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include<stdio.h>
#include"libft.h"

void	ft_bzero(void *s, size_t n)
{
	size_t	i;
	char	*ptr;

	ptr = s;
	i = 0;
	while (i < n)
	{
		ptr[i] = '\0';
		i++;
	}
}
/*
int main()
{
   char tab[] = "al8+mi";
    bzero(tab,2);
    //ft_bzero(tab,2);

    printf("%c",tab[2]);
}
*/
