/*
** EPITECH PROJECT, 2022
** BSQ
** File description:
** tests_bsq
*/

#include "../includes/bsq.h"
#include "../includes/read.h"
#include <criterion/criterion.h>
#include <criterion/redirect.h>

void redirect_all_std(void)
{
    cr_redirect_stdout();
    cr_redirect_stderr();
}

Test(bsq, correct_test, .init = redirect_all_std)
{
    char *av[2] = {"bsg", "tests/maps/intermediate_map_100_100"};
    bsq_map map = {0};
    bsq_square square = {0};

    if (parse_file(av[1], &map))
        return;
    solve(&map, &square);
    print_map(&map, &square);
    cr_assert_stdout_eq_str(read_file_content("tests/maps_solved/intermediate_map_100_100"));
    free(map.fc);
}

Test(bsq, wrong_print_test, .init = redirect_all_std)
{
    bsq_map map = {0};
    bsq_square square = {0};

    print_map(&map, NULL);
    print_map(NULL, &square);
    cr_assert_stdout_eq_str("");
}

Test(bsq, wrong_solve_test, .init = redirect_all_std)
{
    bsq_map map = {0};
    bsq_square square = {0};

    solve(&map, NULL);
    solve(NULL, &square);
    cr_assert_stdout_eq_str("");
}