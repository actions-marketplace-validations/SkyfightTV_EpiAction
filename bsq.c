/*
** EPITECH PROJECT, 2022
** BSQ
** File description:
** bsq
*/

#include "includes/bsq.h"
#include "includes/read.h"

void generate_line(bsq_map *data, int *index, int size, char *key)
{
    int size_key = 0;

    for (size_key = 0; key[size_key] != '\0'; size_key++);
    for (int x = 0; x < size && (key[*index] == '.' || key[*index] == 'o');
    x++) {
        data->fc[data->lines * size + x + data->lines] = key[(*index)++];
        *index = *index >= size_key ? 0 : *index;
    }
    if (!(key[*index] == '.' || key[*index] == 'o'))
        return;
    data->fc[(data->lines + 1) * size + data->lines] = '\n';
}

void generate_map(char *size_str, char *key, bsq_map *data)
{
    int size = 0;
    int size_key = 0;
    int index = 0;

    for (int i = 0; size_str[i] != '\0'; i++) {
        if (size_str[i] > '9' || size_str[i] < '0')
            return;
        size = size * 10 + (size_str[i] - '0');
    }
    data->fc = malloc(sizeof(char) * (size * size) + size);
    for (data->lines = 0; data->lines < size; data->lines++)
        generate_line(data, &index, size, key);
    data->data = data->fc;
    data->line_size = data->lines;
}

int main(int ac, char **av)
{
    bsq_map map = {0};
    bsq_square square = {0};

    if (ac < 2 || ac > 3)
        return 84;
    if (ac == 2 && parse_file(av[1], &map))
        return 84;
    if (ac == 3) {
        map.data = NULL;
        generate_map(av[1], av[2], &map);
        if (map.data == NULL)
            return 84;
    }
    if (solve(&map, &square) == 84) {
        free(map.fc);
        return 84;
    }
    print_map(&map, &square);
    free(map.fc);
    return 0;
}
