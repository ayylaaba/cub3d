/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parcing_char_extention.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayylaaba <ayylaaba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 16:41:59 by ayylaaba          #+#    #+#             */
/*   Updated: 2023/08/19 18:21:34 by ayylaaba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int     player_space( char **map, int i, int j)
{
    if (map[i + 1][j] == ' ')
        return (1);
    else if (map[i  - 1][j] == ' ')
        return (1);
    else if (map[i][j + 1] == ' ')
        return (1);
    else if (map[i + 1][j - 1] == ' ')
        return (1);
    return (0);
}

int     check_player_pos(char **str, t_inf *info)
{
    int i;
    int j;

    i = -1;
    info->count = 0;
    while (str[++i])
    {
        j = -1;
        info->trim = ft_strtrim(str[i], " ");
        while (info->trim[++j])
        {
            if ((info->trim [0] == '0' || info->trim [0] == '1') && info->trim [j] == 'N')
                 info->count++;
            else  if ((info->trim [0] == '0' || info->trim [0] == '1') && info->trim [j] == 'S')
                 info->count++;
            else  if ((info->trim [0] == '0' || info->trim [0] == '1') && info->trim [j] == 'W')
                 info->count++;
            else  if ((info->trim [0] == '0' || info->trim [0] == '1') && info->trim [j] == 'E')
                 info->count++;
        }
        free(info->trim);
    }
    if (info->count== 1)
        return (0);
    return (1);
}

int     character(char **map)
{
    int     i;
    int     j;
    char    *trim;

    i = -1;
    while (map[++i])
    {
        j = -1;
        trim = ft_strtrim(map[i], " ");
        if (trim[0] == '1')
        {
            while (map[i][++j])
            {
                if (map[i][j] != '1' && map[i][j] != '0' && map[i][j] != 'W' && map[i][j] != 'E' && map[i][j] != ' ' && map[i][j] != 'N' && map[i][j] != 'S')
                {
                    free (trim);
                    return (1);
                }
                if (map[i][j] == 'W' || map[i][j] == 'E' || map[i][j] == 'N' || map[i][j] == 'S')
                {
                    if (player_space(map, i, j))
                    {
                        free(trim);
                        return (1);
                    }
                }
            }
        }
        free(trim);
    }
    return (0);
}

int    front_end_wall(char *str)
{
    int i;

    i = 0;
    while (str[i])
    {
        if (str[i] != '1')
            return (1);
        i++;
    }
    return (0);
}
int     check_wall(char **map)
{
    int     i;
    int     j;
    char    *trim;

    j = 0;
    i = 0;
    
    while (map[j]) // wall first and last char
    {
        trim = ft_strtrim(map[j], " ");
        if (trim[0] != '1' || trim[ft_strlen(trim) - 1] != '1')
        {
            free(trim);
            return (1);
        }
        free(trim);
        j++;
    }
    i = 0;
    while (map[i])
        i++;
    i--;
    if (front_end_wall(map[0]) || front_end_wall(map[i]))
        return (1);
    return (0);
}

int    test(t_picture *data, char **s)
{
    while (s[++data->i])
    {
        data->trim = ft_strtrim(s[data->i], " ");
        if (data->trim[0] == '1')
        {
            data->j = -1;
            while (s[data->i][++data->j])
            {
                    if (s[data->i][data->j] == '0' && (s[data->i][data->j- 1] == ' ' || s[data->i][data->j + 1] == ' '))
                    {
                        free(data->trim);
                        return (1);
                    }
                    else if (s[data->i][data->j] == '0' && (s[data->i - 1][data->j] == ' ' || s[data->i + 1][data->j] == ' '))
                    {
                        free(data->trim);
                        return (1);
                    } 

            }
        }
        free(data->trim);
    }
    return (0);
}

int     check_character(char **s, char **s2, t_picture *data)
{

    if (check_wall(s2))
        ft_perror("Wall Is Not Valid\n");
    if (/*check_player_pos(s, data->inf) || character(s2) || check_color(s, data) ||*/ check_text_ext(s, data)) // add texture handling
    {
        printf ("here\n");
        // if (check_player_pos(s, data->inf))
        //     ft_perror("Issue In Player\n");
        // if (character(s2))
        //     ft_perror("Character Is Not Valid\n");
    }
    data->i = -1;
    if(test(data, s))
        return (1);
    return (0);
}

