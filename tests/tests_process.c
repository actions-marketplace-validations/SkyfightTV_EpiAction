/*
** EPITECH PROJECT, 2022
** BSQ
** File description:
** tests_process
*/

#include "../includes/bsq.h"
#include "../includes/read.h"
#include <criterion/criterion.h>

Test(process, swap_buffer)
{
    int *buffer1 = malloc(2 * sizeof(int));
    int *buffer2 = malloc(2 * sizeof(int));

    buffer1[0] = 1;
    buffer1[1] = 2;
    buffer2[0] = 3;
    buffer2[1] = 4;
    swap_buffer(&buffer1, &buffer2);
    cr_assert_eq(buffer1[0], 3);
    cr_assert_eq(buffer1[1], 4);
    cr_assert_eq(buffer2[0], 1);
    cr_assert_eq(buffer2[1], 2);
    free(buffer1);
    free(buffer2);
}
