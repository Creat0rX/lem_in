/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_ants.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svan-nie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/06 12:00:53 by svan-nie          #+#    #+#             */
/*   Updated: 2020/06/06 12:00:53 by svan-nie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

int    ft_check_ants(char *base)
{
    long ant;

    ant = ft_atoi(base);
    if(ant > 2147483647 || ant < 1){
        ft_putstr("error\n");
    }
    return (ant);
}
