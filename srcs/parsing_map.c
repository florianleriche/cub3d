/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fleriche <fleriche@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 13:08:30 by fleriche          #+#    #+#             */
/*   Updated: 2023/12/14 23:04:15 by fleriche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

// int parsingcar(t_data *dta)
// {
//     int i;

//     i = 0;
//     while (dta->map_str[i] != '\0')
//     {
//         if (dta->map_str[i] != '0' && dta->map_str[i] != '1' && dta->map_str[i] != 'N' && dta->map_str[i] != 'S' && dta->map_str[i] != 'E' && dta->map_str[i] != 'W' && dta->map_str[i] != '\n' && dta->map_str[i] != ' '&& dta->map_str[i] != '\t')
//         {
//             printf("non\n");
//             return 1;
//         }
//         i++;
//     }
//     printf("oui\n");
//     return 0;
// }

void verif_char(t_data *dta, int i, int i2)
{
    if (!(dta->map[i][i2] == '0' || dta->map[i][i2] == '1' || dta->map[i][i2] == 'N'
     || dta->map[i][i2] == 'S' || dta->map[i][i2] == 'E' || dta->map[i][i2] == 'W' 
     || dta->map[i][i2] == ' ' || dta->map[i][i2] == '\t'))
        ft_exit(dta, "map pas bon\n");
}

void verif_doublon(t_data *dta)
{
    int nbr_all;
        
    nbr_all = dta->nbr_n + dta->nbr_s + dta->nbr_e + dta->nbr_w;
    printf("%d\n", nbr_all);
    if (nbr_all != 1)
        ft_exit(dta, "trop ou pas de N,S,E,W");
}
void nbr_char(t_data *dta, int i, int i2)
{  
    if (dta->map[i][i2] == 'N')
        dta->nbr_n++;
    if (dta->map[i][i2] == 'S')
        dta->nbr_s++;
    if (dta->map[i][i2] == 'W')
        dta->nbr_w++;
    if (dta->map[i][i2] == 'E')
        dta->nbr_e++;
}

int parsing_map(t_data *dta)
{
    int i;
    int i2;

    i = dta->start_map;
    while (dta->map[i])
    {
        i2 = 0;
        while (dta->map[i][i2] != '\0')
        {
            verif_char(dta, i, i2);
            nbr_char(dta, i, i2);
            i2++;
        }
        i++;
    }
    verif_doublon(dta);
    return (0);
}