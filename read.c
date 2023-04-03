/*
** EPITECH PROJECT, 2022
** BSQ
** File description:
** read
*/

#include "includes/bsq.h"

char *get_number(char *str, int *number)
{
    if (!str || !number)
        return "\0";
    *number = 0;
    for (; *str && *str != '\n' && *str >= '0' &&
    *str <= '9'; ++str)
        *number = *number * 10 + *str - '0';
    if (*str != '\n' && *str <= '0' && *str >= '9')
        return NULL;
    return str;
}

char *read_file_content(const char *file_path)
{
    struct stat f_stats = {0};
    int fd;
    char *result;
    int read_size;

    if (!file_path || stat(file_path, &f_stats) == -1)
        return 0;
    fd = open(file_path, O_RDONLY);
    result = malloc((f_stats.st_size + 1) * sizeof(char));
    read_size = read(fd, result, f_stats.st_size);
    close(fd);
    if (read_size != f_stats.st_size) {
        free(result);
        return 0;
    }
    return result;
}

int get_line_size(char const *data)
{
    int result;

    if (!data)
        return -1;
    for (result = 0; *data && *data != '\n'; ++data, ++result);
    return result;
}

int parse_file(const char *file_path, bsq_map *map)
{
    if (!file_path || !map)
        return 1;
    map->fc = read_file_content(file_path);
    if (!map->fc)
        return 1;
    map->data = get_number(map->fc, &map->lines);
    if (!map->data || map->data == map->fc) {
        free(map->fc);
        return 1;
    }
    map->data++;
    map->line_size = get_line_size(map->data);
    if (map->line_size == -1) {
        free(map->fc);
        return 1;
    }
    return 0;
}
