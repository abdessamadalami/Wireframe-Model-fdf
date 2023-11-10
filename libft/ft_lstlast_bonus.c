/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-oual <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 12:55:24 by ael-oual          #+#    #+#             */
/*   Updated: 2021/11/17 07:22:25 by ael-oual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
#include <stdio.h>

t_list	*ft_lstlast(t_list *lst)
{
	t_list	*list;

	list = lst;
	while (list)
	{
		if (list -> next == NULL)
			return (list);
		list = list -> next;
	}
	return (0);
}
/*
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
	t_list *node;
    t_list *n;
	int *ptr;
    int tab1[4] = {1, 2, 3, 4};
          int tab = 1337;
        a = ft_lstnew(&tab);
    int i = 0;
    while (i<4)
	{
        node = ft_lstnew(f(tab1[i]));
      //  printf("the content of node is = %d \n", *(int *)a -> content);
        ft_lstadd_back(&a,node);
        i++;
    }
	printList(a);
	n = ft_lstlast(a);
	printf(" %d ",*(int *) n -> content);
   // printf("\nthe content of node is = %d \n", *(int *)a -> content);

}
*/
