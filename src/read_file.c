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
            if ((line[i] = (int *)malloc(sizeof(int) * 4)))
                i++;
            else
                return (NULL);
    }
    return (line);
}


int **parse_line(char *line, char *hex_color, int **coords)
{
    char *split;
    char **line_split;
    int x;
    int i;

    x = 0;
    line_split = ft_strsplit(line, ' ');
    i = 0;
    while (line_split[i])
    {
        if (!(split = ft_strrchr(line_split[i], ',')))
        {
            coords[i][0] = ft_atoi(line_split[i]);
            while (*hex_color != 'x')
                hex_color++;
            coords[i][1] = parse_color(hex_color + 1);
            coords[i][2] = parse_color(hex_color + 3);
            coords[i][3] = parse_color(hex_color + 5);
        }
        else
        {
            coords[i][0] = ft_atoi(line_split[i]);
            while (*split != 'x')
                split++;
            coords[i][1] = parse_color(split + 1);
            coords[i][2] = parse_color(split + 3);
            coords[i][3] = parse_color(split + 5);
        }
        free(line_split[i++]);
    }
    free(line_split);
    return (coords);
}

int build_map(t_mlx *mlx, int fd, char *hex_color)
{
    char *line;
    int i;
    int j;

    i = 0;
    if (fd <= 0)
        return (0);
    while (get_next_line(fd, &line))
    {
        j = 0;
        parse_line(line, hex_color, mlx->map->tmp);
        while (j < mlx->map->width)
        {
            mlx->map->coords[i][0] = mlx->map->tmp[j][0];
            mlx->map->coords[i][1] = mlx->map->tmp[j][1];
            mlx->map->coords[i][2] = mlx->map->tmp[j][2];
            mlx->map->coords[i++][3] = mlx->map->tmp[j++][3];
        }
        free(line);
    }
    close(fd);
    return (1);
}

int read_file(int fd, t_map *map, char *hex_color)
{
    char *line;
    int ret;
    int x;

    while ((ret = get_next_line(fd, &line)))
    {
        if (ret < 0)
            return (0);
        if (map->height == 0)
            map->tmp = init_arr(map->width = count_x(line));
        parse_line(line, hex_color, map->tmp);
        x = -1;
        while (++x < map->width)
        {
            if (map->tmp[x][0] < map->d_min)
                map->d_min = map->tmp[x][0];
            else if (map->tmp[x][0] > map->d_max)
                map->d_max = map->tmp[x][0];
        }
        free(line);
        map->height++;
    }
    close(fd);
    return (1);
}
