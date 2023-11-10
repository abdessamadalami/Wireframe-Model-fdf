/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-oual <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 09:37:06 by ael-oual          #+#    #+#             */
/*   Updated: 2021/11/18 18:21:32 by ael-oual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include<stdlib.h>
#include<stdio.h>
#include"libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	t_list	*list;

	list = *lst;
	new -> next = list;
	*lst = new;
}
/*
int *f(int a)
{
    int *ptr;
	ptr = (int *)malloc(4);
	*ptr = a;
	return ptr;
}

void print_f(t_list *a) {

   t_list *ptr = a;
   printf("\n[ ");

   //start from the beginning
   while(ptr)
   {
      printf("( %d ) ",*(int *)ptr -> content);
      ptr = ptr->next;
   }
   printf(" ]");
}
int main()
{
	t_list *a;
	t_list *node;
    t_list *n;
	int *ptr;
    int tab1[4] = {1, 2, 3, 4};
          int tab = 1337;
        a = ft_lstnew(f(tab));
    int i = 0;
    
    while (i<4) {
        node = ft_lstnew(f(tab1[i]));
       // printf("the content of node is = %d \n", *(int *)a -> content);
        ft_lstadd_front(&a,node);
        i++;
    }

   print_f(a);
}
*/
