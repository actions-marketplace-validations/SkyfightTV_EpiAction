/*
** EPITECH PROJECT, 2022
** BSQ
** File description:
** process
*/

#include "includes/bsq.h"

void swap_buffer(int **buffer1, int **buffer2)
{
    int *temp = *buffer1;

    *buffer1 = *buffer2;
    *buffer2 = temp;
}

void print_map(bsq_map *map, bsq_square *square)
{
    if (!map || !square)
        return;
    for (int l = 0; l < square->size; l++) {
        for (int i = 0; i < square->size; i++)
            *(square->location--) = 'x';
        square->location -= (map->line_size + 1) - square->size;
    }
    write(1, map->data, map->lines * (map->line_size + 1));
}

int solve_fill_buffer(bsq_map *map, bsq_square *square, int line,
int *buffer[2])
{
    int index = line * (map->line_size + 1);

    for (int i = 0; i < map->line_size; ++i, ++index) {
        if (CMP(map->data[index], 'o'))
            buffer[0][i] = (line == 0 || i == 0) ? 1
            : MIN3(buffer[1][i], buffer[1][i - 1], buffer[0][i - 1]) + 1;
        else
            buffer[0][i] = 0;
        if (CMP(map->data[index], '.'))
            return 1;
        if (buffer[0][i] > square->size) {
            square->size = buffer[0][i];
            square->location = map->data + index;
        }
    }
    return 0;
}

int solve(bsq_map *map, bsq_square *square)
{
    int *alloc;
    int *buffer[2];

    if (!map || !square)
        return 84;
    alloc = malloc(map->line_size * 2 * sizeof(int));
    buffer[0] = alloc;
    buffer[1] = alloc + map->line_size;
    for (int l = 0; l < map->lines; ++l) {
        if (solve_fill_buffer(map, square, l, buffer)) {
            free(alloc);
            return 84;
        }
        swap_buffer(&buffer[0], &buffer[1]);
    }
    free(alloc);
    return 0;
}
