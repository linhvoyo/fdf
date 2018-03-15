/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coord_struct.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: linh <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/24 07:15:43 by linh              #+#    #+#             */
/*   Updated: 2018/02/24 07:18:26 by linh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>

void add_to_list(t_coord **list, t_coord *new)
{
    new->next = *list;
    *list = new;
    // t_coord *head;
    // head = *list;
    // if (head == NULL)
    //     list = &new;
    // else
    // {
    //
    // }
    // // if (head)
    // // {
    // //     while(head->next)
    // //         head = head->next;
    // //     head->next = new;
    // // }
    // // else
    // //     *list = new;
}

// void add_to_list(t_coord **list, t_coord *new)
// {
//     t_coord *head;
//     head = *list;
//
//     if (head)
//     {
//         while(head->next)
//             head = head->next;
//         head->next = new;
//     }
//     else
//         *list = new;
// }

t_coord *get_coord(int size)
{
    t_coord *tmp;

    tmp = malloc(sizeof(t_coord));
    if (tmp)
    {
        tmp->arr = init_arr(size);
        tmp->next = NULL;
    }
    return (tmp);
}
