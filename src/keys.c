#include "fdf.h"
#include <stdio.h>


int deal_key(int key, t_mlx *mlx)
{
    if (key == 53)
        exit(EXIT_SUCCESS);
    else if ((key == 24 || key == 69) && mlx->map->scale_factor++)
        render(mlx);
    else if ((key == 78 || key == 27) && mlx->map->scale_factor--)
        render(mlx);
    else
        printf("%d\n", key);
    return (0);
}
