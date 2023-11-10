/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-oual <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 07:49:35 by ael-oual          #+#    #+#             */
/*   Updated: 2021/11/17 07:55:21 by ael-oual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include<stdio.h>
#include<stdlib.h>
#include"libft.h"

void	ft_lstdelone(t_list *lst, void (*del)(void*))
{
	del(lst -> content);
	free(lst);
}
/*
void del(void *ptr)
{
	printf("i am here");
//	*(int*)ptr = 5;
	 free(ptr);
}

void printList(t_list *a) {

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
int *ptr_allocat(int a)
{
   int *ptr;
   ptr = (int *)malloc(4);
   *ptr = a;
   return ptr;
}
int main()
{
	t_list *a;
	t_list *node;
    t_list *n;
	int *ptr;
    int tab1[4] = {1, 2, 3, 4};
          int tab = 1337;
		  ptr_allocat(tab);
        a = ft_lstnew(ptr_allocat(tab));
    int i = 0;
    while (i<4)
	{
        node = ft_lstnew( ptr_allocat(tab1[i]));
        printf("the content of node is = %d \n", *(int *)a -> content);
        ft_lstadd_back(&a,node);
        i++;
    }
	ft_lstdelone(ft_lstlast(a), del);
	printList(a);
   	t_list *h  = ft_lstnew(ptr_allocat(12)); 
   printList(a);	
}
*/
