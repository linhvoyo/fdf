/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: linh <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/22 20:10:10 by linh              #+#    #+#             */
/*   Updated: 2018/02/24 06:18:21 by linh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "unistd.h"
#include "libft.h"
//#include "get_next_line.h"
#include <fcntl.h>

/*
int deal_key(int key, void *param)
{
    write(1, "X", 1);
    return (0);
}

*/

void    draw_line(void *mlx_ptr, void *win_ptr)
{
    int i;
    int x;

    x = 0;   
    i = 0;
    while (i < 10)
    {
        mlx_pixel_put(mlx_ptr, win_ptr, 20 + x++, 20 ,  0xFFFFFFF);
        i++;
    }

}


void    parse_line(char *line)
{
    ft_putendl(line)
}

int main()
{
    /*
    void *mlx_ptr;
    void *win_ptr;

    mlx_ptr = mlx_init();
    win_ptr = mlx_new_window(mlx_ptr, 500, 500, "mlx 42");
    mlx_pixel_put(mlx_ptr, win_ptr, 250, 250, 0xFFFFFFF);

//    draw_line(mlx_ptr, win_ptr);
    
*/
    int fd;
    fd = open("./maps/42.fdf", O_RDONLY);

    char *line;

    parse_line(get_next_line(fd, &line));

    


//    mlx_loop(mlx_ptr);
}
