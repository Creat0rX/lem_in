/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verify_map_functions_three.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svan-nie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/23 20:37:48 by svan-nie          #+#    #+#             */
/*   Updated: 2020/06/23 20:37:48 by svan-nie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

void    ft_check_one(char **twodarray, int *i)
{
    int j;

    j = *i;
    while (twodarray[j])
    {
        j++;
    }
    if (j < 2)
    {
        ft_putendl("Error: wrong");
        exit(1);
    }
}

void    ft_check_for_ant_amount(char **twodarray, int *i, int *ant_amount)
{
    int j;

    j = *i;
    while (twodarray[j])
    {
        if (twodarray[j][0] == '#') {
            if (ft_strequ(twodarray[j], "##start") || ft_strequ(twodarray[j], "##end")){

            }
            else
            j++;
        }
        if (check_int(twodarray[j]) == 1)
        {
            *ant_amount = ft_check_ants(twodarray[j]);
            break;
        }
        j++;
    }
    if (*ant_amount == 0)
    {
        ft_putstr("Error: please enter ant's\n");
        exit(1);
    }
    j++;
    *i = j;
}

void ft_check_start_room(char **twodarray, int *i)
{
    int j;
    int strlen;

    j = *i;
    strlen = 0;
    if (twodarray[j + 1])
    j++;
    else
    {
        ft_putendl("ERROR");
        exit(1);
    }
    while ((twodarray[j][0] == '#' && (twodarray[j][1] != '#' || twodarray[j][1] == '\0')) || (twodarray[j][0] == '#' && twodarray[j][1] == '#'))
    j++;
    if ((strlen = ft_strlen_space(twodarray[j])) && twodarray[j][strlen] == ' ' && twodarray[j][strlen + 1])
    {
    }
    else
    {
        ft_putendl("Error: starting room invalid");
        exit(1);
    }
    *i = j;
}

void ft_check_end_room(char **twodarray, int *i)
{
    int j;
    int strlen;

    j = *i;
    strlen = 0;
    if (twodarray[j + 1])
    j++;
    else
    {
        ft_putendl("ERROR");
        exit(1);
    }
    while ((twodarray[j][0] == '#' && (twodarray[j][1] != '#' || twodarray[j][1] == '\0')) || (twodarray[j][0] == '#' && twodarray[j][1] == '#'))
    j++;
    if ((strlen = ft_strlen_space(twodarray[j])) && twodarray[j][strlen] == ' ' && twodarray[j][strlen + 1])
    {
    }
    else
    {
        ft_putendl("Error: ending room invalid");
        exit(1);
    }
    *i = j;
}

void    ft_check_valid_room(t_room *lem_tmp, char **twodarray, int *ij, unsigned char *dip_Switch)
{
            char    **check_rooms;
            ft_strlen_space_count(twodarray[ij[0]]);
            check_rooms = ft_strsplit(twodarray[ij[0]], ' ');
            ft_strlen_space_error(check_rooms[0]);
            if (check_int(check_rooms[1]) == 1 && check_int(check_rooms[2]) == 1)
            {
                if ((*dip_Switch & 32) == 32){
                    *dip_Switch ^= 32;
                    ft_add_start_room(lem_tmp, check_rooms, &ij[1]);
                }else if ((*dip_Switch & 64) == 64)
                {
                    *dip_Switch ^= 64;
                    ft_add_end_room(lem_tmp, check_rooms, &ij[1]);
                }else
                {
                    ft_add_rooms(lem_tmp, check_rooms, &ij[1]);
                }
            }else
            {
                ft_putstr("Error: Badly Formatted Map X Y not integer \n");
                exit(1);
            }
            *dip_Switch |= 16;
            free2dArray(check_rooms);
}

// line 32
// ft_check_for_ant_amount
// looking for ant_amount once found breaks out and returns ant amount  if not found returns error
// j++ incrementing past the ant_amount

// line 118
// ft_strlen_space_count
// counting the amount of spaces more or less than 2 displays error
// line 120
// ft_strlen_space_error
// checks for name starting with L and - inside the name