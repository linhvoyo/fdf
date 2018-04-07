#include "fdf.h"
#include <stdio.h>

int count_x(char *line)
{
    int i;
    int count;
    int len;

    count = 0;
    len = ft_strlen(line);
    i = 0;
    while (line[i])
    {
        if ((ft_isdigit(line[i]) || ft_isalpha(line[i])) && (line[i + 1] == ' ' || line[i + 1] == '\0'))
            count++;
        i++;
    }
    return (count);
}

int **init_arr(int x)
{
    int **line;
    int i;
    line = (int **)malloc(sizeof(int *) * x);

    i = 0;
    if (line)
    {
        while (i < x)
            if ((line[i] = (int *)malloc(sizeof(int) * 3)))
                i++;
            else
                return (NULL);
    }
    return (line);
}


int **parse_line(char *line, int color, int **coords)
{
    int x;

    x = 0;
    char **line_split = ft_strsplit(line, ' ');
    char *split;

    int i = 0;
    while (line_split[i])
    {
        if (!(split = ft_strrchr(line_split[i], ',')))
        {
            coords[i][0] = ft_atoi(line_split[i]);
            coords[i][1] = 255;
            coords[i][2] = 255;
            coords[i][3] = 255;
        }
        else
        {
            coords[i][0] = ft_atoi(line_split[i]);

            //ADD ERROR HANDLING FOR printf("split: %s ", split);
            while (*split != 'x')
                split++;
            coords[i][1] = parse_color(split + 1);
            coords[i][2] = parse_color(split + 3);
            coords[i][3] = parse_color(split + 5);
        }
        // printf("coords[i][0] %d coords[i][1] %d coords[i][2] %d coords[i][3] %d \n", coords[i][0], coords[i][1], coords[i][2], coords[i][3]);
        i++;
    }
    return (coords);
}

// int read_file(int fd, t_map *map)
// {
//     char *line;
//     int x;
//     int ret;
//     ret = get_next_line(fd, &line);
//     if (!ret)
//         return (0);
//     printf("%s\n", line);
//     if (map->height == 0)
//         map->tmp = init_arr(map->width = count_x(line));
//
//     parse_line(line, 0xFFFFFFF, map->tmp);
//     x = 0;
//     while (x < map->width)
//     {
//         // printf("x: %d y: %d z: %d color: %d\n", x, map->height, map->tmp[x][0], map->tmp[x][1]);
//         if (map->height == 0 && (map->d_min = map->tmp[x][0]))
//             map->d_max = map->tmp[x][0];
//         if (map->tmp[x][0] < map->d_min)
//             map->d_min = map->tmp[x][0];
//         else if (map->tmp[x][0] > map->d_max)
//             map->d_max = map->tmp[x][0];
//         x++;
//     }
//     // map->map->tmp = map->tmp;
//     map->height++;
//     return (1);
// }

int build_map(t_mlx *mlx, int **arr, int fd)
{
    char *line;
    int ret;
    int i;
    int j;

    i = 0;
    if (fd <= 0)
        return (0);

    while (get_next_line(fd, &line))
    {
        // printf("%s\n", line);
        j = 0;
        parse_line(line, 0xFFFFFFF, mlx->map->tmp);
        while (j < mlx->map->width)
        {
            // printf("x: %d y: %d z: %d color: %d\n", j, i / mlx->map->width, mlx->map->tmp[j][0], mlx->map->tmp[j][1]);
            mlx->map->coords[i][0] = mlx->map->tmp[j][0];
            mlx->map->coords[i][1] = mlx->map->tmp[j][1];
            mlx->map->coords[i][2] = mlx->map->tmp[j][2];
            mlx->map->coords[i][3] = mlx->map->tmp[j][3];
            i++;
            j++;
        }
    }

    close(fd);
    return (1);
}


int read_file(int fd, t_map *map)
{
    char *line;
    int y;
    int x;

    y = 0;
    while (get_next_line(fd, &line))
    {
        if (y == 0)
            map->tmp = init_arr(map->width = count_x(line));
        printf("%d\n", map->width);
        // printf("%s\n", line);
        parse_line(line, 0xFFFFFFF, map->tmp);
        x = 0;
        while (x < map->width)
        {
            // printf("x: %d y: %d z: %d color: %d\n", x, y, map->tmp[x][0], map->tmp[x][1]);
            if (map->tmp[x][0] < map->d_min)
                map->d_min = map->tmp[x][0];
            else if (map->tmp[x][0] > map->d_max)
                map->d_max = map->tmp[x][0];
            x++;
        }
        y++;
    }
    map->height = y;
    close(fd);
    return (1);
}
