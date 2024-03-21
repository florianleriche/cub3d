/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fleriche <fleriche@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 16:45:38 by fleriche          #+#    #+#             */
/*   Updated: 2024/03/20 19:03:13 by fleriche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

void after_id(t_data *dta, int start)
{
    int i;

    i = 0;
        while (dta->map[start][i] != '1' && dta->map[start][i] != '\0')
        {
            if (dta->map[start][i] == ' ' || dta->map[start][i] == '\t')
                i++;
            else if (dta->map[start][i] == '\0')
                start++;
            else if (dta->map[start][i] == '1')
                break;
            else
                ft_exit(dta, "y'a une couille entre les id et la map\n");
        }
    dta->start_map = start;
}

int structuration(t_data *dta)
{
    int i;
    int i2;
    int stop;

    i = 0;
    stop = 6;
    while (i < stop)
    {
        i2 = 0;
        if (dta->map[i][i2] == 'N' && dta->map[i][i2+1] == 'O')
            dta->NO = dta->map[i];
        else if (dta->map[i][i2] == 'W' && dta->map[i][i2+1] == 'E')
            dta->WE = dta->map[i];
        else if (dta->map[i][i2] == 'S' && dta->map[i][i2+1] == 'O')
            dta->SO = dta->map[i];
        else if (dta->map[i][i2] == 'E' && dta->map[i][i2+1] == 'A')
            dta->EA = dta->map[i];
        else if (dta->map[i][i2] == 'C')
            dta->C = dta->map[i];
        else if (dta->map[i][i2] == 'F')
            dta->F = dta->map[i];
        else if (dta->map[i][i2] == ' ' || dta->map[i][i2] == '\t')
        {
            stop++;
            while (dta->map[i][i2] != '\0')
            {
                if (!(dta->map[i][i2] == ' ' || dta->map[i][i2] == '\t'))
                    ft_exit(dta, "wrong line\n");
                i2++;
            }
        }

        i++;
    }
    after_id(dta, stop);
    return (0); 
}

void noempty(t_data *dta, char *id)
{
    if (id == NULL)
        ft_exit(dta, "there is 2 same id");
}

//12/12/2023
void verif_id(t_data *dta)
{
    if (dta->NO[2] != ' ' && dta->NO[2] != '\t')
        ft_exit(dta, "id not good, or colle au path");
    if (dta->SO[2] != ' ' && dta->SO[2] != '\t')
        ft_exit(dta, "id not good, or colle au path");
    if (dta->EA[2] != ' ' && dta->EA[2] != '\t')
        ft_exit(dta, "id not good, or colle au path");
    if (dta->WE[2] != ' ' && dta->WE[2] != '\t')
        ft_exit(dta, "id not good, or colle au path");
    if (dta->F[1] != ' ' && dta->F[1] != '\t')
        ft_exit(dta, "id not good, or colle au path");
    if (dta->C[1] != ' ' && dta->C[1] != '\t')
        ft_exit(dta, "id not good, or colle au path");
}

char *init_path(char *id, int nbr)
{
    int start;
    int end;
    char *path;

    end = nbr;
    while (id[end] == ' ' || id[end] == '\t')
        end++;
    start = end;
    while (id[end] != '\0')
        end++;
    end -= 1;
    while (id[end] == ' ' || id[end] == '\t')
        end--;
    path = ft_substr(id, start, end - start + 1);
    //verif si leak
    return(path);
}

void verif_color(t_data *dta)
{
    int i;

    i = 0;
    while (dta->texture[4].path[i] != '\0')
    {
        if (!((dta->texture[4].path[i] == ' ' || dta->texture[4].path[i] == '\t' || dta->texture[4].path[i] == ',' ) || (dta->texture[4].path[i] >= '0' && dta->texture[4].path[i] <= '9')))
            ft_exit(dta, "nique bien ta mere\n");
        i++;
    }
    i = 0;
    while (dta->texture[5].path[i] != '\0')
    {
        if (!((dta->texture[5].path[i] == ' ' || dta->texture[5].path[i] == '\t' || dta->texture[5].path[i] == ',' ) || (dta->texture[5].path[i] >= '0' && dta->texture[5].path[i] <= '9')))
            ft_exit(dta, "nique bien ta mere\n");
        i++;
    }
    if (dta->color[0].red == 0 || dta->color[0].green == 0 || dta->color[0].blue == 0 ||
    dta->color[1].red == 0 || dta->color[1].green == 0 || dta->color[1].blue == 0)
        ft_exit(dta, "color pas bon mon copainnn\n");
    if (dta->nbr_comma != 4)
        ft_exit(dta, "pas bon, trop de virgules\n");
    if (dta->color[0].red > 255 || dta->color[0].green > 255 || dta->color[0].blue > 255 ||
    dta->color[1].red > 255 || dta->color[1].green > 255 || dta->color[1].blue > 255)
        ft_exit(dta, "wsh t un ouf a mettre des nombres comme ca gros\n");
}

//13/12/2023
int init_color(t_data *dta, char *id)
{
    int i2;
    char *nbr;

    i2 = dta->i_color;
    while (id[i2] >= '0' && id[i2] <= '9')
        i2++;
    nbr = ft_substr(id, dta->i_color, i2 - dta->i_color + 1);
    dta->i_color = i2;
    while (id[dta->i_color] == ' ' || id[dta->i_color] == '\t' || id[dta->i_color] == ',')
    {
        if (id[dta->i_color] == ',')
            dta->nbr_comma++;
        dta->i_color++;
    }
    i2 = dta->i_color;
    if (dta->nbr_comma == 2 || dta->nbr_comma == 4)
    {
        while (id[i2] >= '0' && id[i2] <= '9')
            i2++;
        while (id[i2] != '\0')
        {
            printf("%c\n",id[i2]);
            if (!(id[i2] == ' ' || id[i2] == '\t' || id[i2] == ',' ))
                ft_exit(dta, "trop de nombres , RVB\n");
            i2++;
        }
    }
    return (ft_atoi(nbr));
}
//dta->texture[4].path
int first_parsing(t_data *dta)
{
    printf("coucouuu");
    noempty(dta, dta->NO);
    noempty(dta, dta->EA);
    noempty(dta, dta->SO);
    noempty(dta, dta->WE);
    noempty(dta, dta->C);
    noempty(dta, dta->F);
    verif_id(dta);
    dta->texture[0].path = init_path(dta->NO, 2);
    dta->texture[1].path = init_path(dta->SO, 2);
    dta->texture[2].path = init_path(dta->EA, 2);
    dta->texture[3].path = init_path(dta->WE, 2);
    dta->texture[4].path = init_path(dta->F, 1);
    dta->texture[5].path = init_path(dta->C, 1);
    printf("%s\n", dta->texture[0].path);
    dta->color[0].red = init_color(dta, dta->texture[4].path);
    dta->color[0].green = init_color(dta, dta->texture[4].path);
    dta->color[0].blue = init_color(dta, dta->texture[4].path);
    printf("%d\n", dta->color[0].red);
    printf("%d\n", dta->color[0].green);
    printf("%d\n", dta->color[0].blue);
    dta->i_color = 0;
    dta->color[1].red = init_color(dta, dta->texture[5].path);
    dta->color[1].green = init_color(dta, dta->texture[5].path);
    dta->color[1].blue = init_color(dta, dta->texture[5].path);
    printf("%d\n", dta->color[1].red);
    printf("%d\n", dta->color[1].green);
    printf("%d\n", dta->color[1].blue);
    verif_color(dta);
    //printf("%s\n", dta->texture[4].path);
    //dta.C_tex->C_path = init_path(dta, dta->C, 1);
    printf("%d", dta->start_map);
    printf("%s", dta->map[dta->start_map]);
	return (0);
}

int all_parsing(t_data *dta)
{
    ft_initialisation(dta);
    structuration(dta);
    first_parsing(dta);
    parsing_map(dta);
    return (0);
}

void	ft_initialisation(t_data *dta)
{
	dta->NO = NULL;
    dta->SO = NULL;
    dta->EA = NULL;
    dta->WE = NULL;
    dta->C = NULL;
    dta->F = NULL;
    dta->i_color = 0;
    dta->nbr_comma = 0;
    dta->nbr_n = 0;
    dta->nbr_s = 0;
    dta->nbr_e = 0;
    dta->nbr_w = 0;
}