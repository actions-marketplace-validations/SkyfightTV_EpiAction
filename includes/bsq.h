/*
** EPITECH PROJECT, 2022
** BSQ
** File description:
** bsq
*/

#ifndef _BSQ_H_
    #define _BSQ_H_
    #include <sys/stat.h>
    #include <unistd.h>
    #include <fcntl.h>
    #include <stdlib.h>
    #include <stdio.h>

    #define MIN(v1, v2) ((v1) <= (v2) ? (v1) : (v2))
    #define MIN3(v1, v2, v3) MIN(MIN(v1, v2), v3)
    #define CMP(c, c1) ((~c & c1)) // 0 == equal and 1 == not equal

typedef struct map_s {
    char *fc;
    char *data;
    int lines;
    int line_size;
} bsq_map;

typedef struct square_s {
    char *location;
    int size;
} bsq_square;

void swap_buffer(int **buffer1, int **buffer2);
void print_map(bsq_map *map, bsq_square *square);
int solve_fill_buffer(bsq_map *map, bsq_square *square, int line,
int *buffer[2]);
int solve(bsq_map *map, bsq_square *square);
#endif
