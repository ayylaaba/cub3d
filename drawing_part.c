/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing_part.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayylaaba <ayylaaba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 00:33:33 by ayylaaba          #+#    #+#             */
/*   Updated: 2023/08/19 02:29:47 by ayylaaba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	put_player(t_picture *data, int color)
{
	data->color = 0x0ff0000; //red;
	data->inf->angle = data->deta + 30;
	int i;
	i = 0;
	data->f = 0;
	while (data->f < 640)
	{
			hor_int(data, data->inf->angle, data->inf->x, data->inf->y); // just to get distance horizontal
			ver_int(data, data->inf->angle, data->inf->x, data->inf->y); // just to get distance vertical
			if (data->ray_distance_hor <= data->ray_distance_ver)
				i = 1;
			else if (data->ray_distance_ver <= data->ray_distance_hor)
				i = 0;
			data->inf->cur_angl = (data->deta - data->inf->angle);
			if (!i)
				data->new_ray_distance = data->ray_distance_ver * cos(((data->inf->cur_angl) * M_PI / 180));
			else 
				data->new_ray_distance = data->ray_distance_hor * cos(((data->inf->cur_angl) * M_PI / 180));
			data->dist_p_screen	= 320 / tan(30 * M_PI / 180);
			data->wall_tall	= ((64 / data->new_ray_distance) * data->dist_p_screen);
			draw_walls(data);
			data->f++;
			data->inf->angle -= 64.0 / 640.0;
	}
}

void	draw_map(char **map, t_picture *test)
{
	put_player(test, 0x00FDFD55);
	mlx_put_image_to_window(test->ptr, test->wind, test->image_adrr, 0, 0);
}

void	draw_squar(t_picture *test, int old_x, int old_y, int color)
{
	int	x;
	int	y;

	x = old_x;
	while (x <= old_x + 62)
	{
		y = old_y;
		while (y <= old_y + 62)
			my_put_pixl(test, x, y++, color);
		x++;
	}
}
