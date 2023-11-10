/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-oual <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 13:11:38 by ael-oual          #+#    #+#             */
/*   Updated: 2021/11/17 06:54:06 by ael-oual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include<stdio.h>
#include<stdlib.h>
#include"libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*node;

	node = (t_list *)malloc(sizeof(t_list *));
	if (node == 0)
		return (0);
	node -> content = content;
	node -> next = NULL;
	return (node);
}
/*
int *f(int a)
{
    int *ptr;
	ptr = (int *)malloc(4);
	*ptr = a;
	return ptr;
}
int main()
{
	t_list *a;
	int *ptr;
    int tab[4] = {0,2,3,4};
	int i = 0;
	while(i<4)
	{
	a = ft_lstnew(f(tab[i]));
	printf(" %d ",*(int *) a-> content);
	i++;
	}
}
*/
