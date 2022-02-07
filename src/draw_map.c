/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkosaka <jkosaka@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 10:32:44 by jkosaka           #+#    #+#             */
/*   Updated: 2022/02/06 23:48:44 by jkosaka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void    my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
    char    *dst;

    dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
    *(unsigned int*)dst = color;
}

/*  ratio : 1 - ratio  */
t_vector    get_internal_vector(t_vector start, t_vector end, double ratio)
{
    t_vector    target;

    target.x = start.x + (end.x - start.x) * ratio;
    target.y = start.y + (end.y - start.y) * ratio;
    target.z = start.z + (end.z - start.z) * ratio;
    target.color = start.color + (end.color - start.color) * ratio;
    return (target);
}

/*  draw dot on minilibx window  */
static bool draw_dot(t_vector vec, t_data *img, t_fdf *fdf)
{
    int     mlx_x;
    int     mlx_y;

    mlx_x = vec.x + WIN_CENTER + fdf->shift_x;
    mlx_y = vec.y + WIN_CENTER + fdf->shift_y;
    if (mlx_x <= 0 || WIN_SIZE <= mlx_x)
        return (false);
    if (mlx_y <= 0 || WIN_SIZE <= mlx_y)
        return (false);
    my_mlx_pixel_put(img, mlx_x, mlx_y, vec.color);
    return (true);
}

/*  draw line between two vectors  */
static void draw_line(t_data *img, t_vector start, t_vector end, t_fdf *fdf)
{
    double  ratio;
    double  diff;
    t_vector target;

    if (!draw_dot(start, img, fdf) || !draw_dot(end, img, fdf))
        return ;
    diff = max_abs_3(end.x - start.x, end.y - start.y, end.z - start.z);
    ratio = 0;
    while (ratio <= 1)
    {
        target = get_internal_vector(start, end, ratio);
        draw_dot(target, img, fdf);
        ratio += (double)DELTA_RATIO / diff;
    }
}

/*  draw whole map  */
void    draw_map(t_fdf *fdf)
{
    t_data	    img;
    t_vector    vec;
    int			row_i;
    int			col_i;

    img.img = mlx_new_image(fdf->mlx, WIN_SIZE, WIN_SIZE);
    img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
                                &img.endian);
    row_i = -1;
    while (++row_i < fdf->map_row)
    {
        col_i = -1;
        while (++col_i < fdf->map_col)
        {
            if (row_i)
                draw_line(&img, fdf->vecs[row_i][col_i], fdf->vecs[row_i - 1][col_i], fdf);
            if (col_i)
                draw_line(&img, fdf->vecs[row_i][col_i], fdf->vecs[row_i][col_i - 1], fdf);
        }
    }
    mlx_put_image_to_window(fdf->mlx, fdf->win, img.img, 0, 0);
    mlx_string_put(fdf->mlx, fdf->win, 200, 900, 0xEEAAAA, "Zoom in  : +");
    mlx_string_put(fdf->mlx, fdf->win, 200, 920, 0xEEAAAA, "Zoom out : -");
    mlx_key_hook(fdf->win, key_hook, fdf);
    // mlx_mouse_hook(fdf->win, mouse_hook, fdf);
	mlx_loop(fdf->mlx);
}
