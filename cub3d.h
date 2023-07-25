/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayylaaba <ayylaaba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 19:04:51 by ayylaaba          #+#    #+#             */
/*   Updated: 2023/07/25 17:40:27 by ayylaaba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define  CUB3D_H

# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <math.h>
# include <mlx.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 2147
# endif

typedef struct creat_data
{
    // int         x;
    // int         y;
    // int         color;
    // int         wigth;
    // int         hight;
    // void        *image;
}	t_data;

typedef struct creat_picture
{
    t_data  *data;
    float         x_p;
    float         y_p;
    int         color;
    int         wigth;
    int         hight;
    void        *image;
    void    *ptr;
    void    *wind;
    void    *mlx;
    int     y;
    int     x;
    int     len;
    int     end;
    int     bit_pixl;
    void    *image_adrr;
    char    *adrr;
}	t_picture;

char	*get_next_line(int fd);
int	    ft_sreach(char *str);
int	    ft_strlen(char *str);
char	*ft_strdup(char *s1);
char	**ft_split(char *s, char c);
char	*ft_substr(char *s, int start, int len);
int	    ft_strcmp(char *s1, char *s2);
char	*ft_strtrim(char *s1,  char *set);
int	    ft_isdigit(char *str);
char	*ft_strrchr(char *s, int c);
void    ft_perror();
int     check_map_extantion(char *map);
int     character(char **map);
int     check_double_element(char **map);
int     check_wall_text(char **src);
int     check_character(char **s);
int     check_color(char **map);
int     check_text_ext(char **map);
char    *get_content(char *str, char c);



#endif