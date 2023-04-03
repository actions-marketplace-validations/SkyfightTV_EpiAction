/*
** EPITECH PROJECT, 2022
** BSQ
** File description:
** tests_read
*/

#include "../includes/read.h"
#include <criterion/criterion.h>

Test(read, get_number)
{
    char *str = "123456789\no";
    int number = 0;

    cr_assert_str_eq(get_number(str, &number), "\no");
    cr_assert_eq(number, 123456789);
}

Test(read, read_file_content)
{
    char *str = read_file_content("tests/test_files/test1.txt");

    cr_assert_str_eq(str, "Hello World\\n");
    free(str);
}

Test(read, get_line_size)
{
    char *str = "Hello World";

    cr_assert_eq(get_line_size(str), 11);
}

Test(read, parse_file)
{
    bsq_map map = {0};

    cr_assert_eq(parse_file("tests/test_files/test2.txt", &map), 0);
    cr_assert_eq(map.lines, 1);
    cr_assert_eq(map.line_size, 11);
    cr_assert_str_eq(map.fc, "1\nHello World");
    cr_assert_str_eq(map.data, "Hello World");
    free(map.fc);
}

Test(read, parse_file_error)
{
    bsq_map map = {0};

    cr_assert_eq(parse_file("tests/test_files/tdzq.txt", &map), 1);
    cr_assert_eq(map.lines, 0);
    cr_assert_eq(map.line_size, 0);
    cr_assert_eq(map.fc, 0);
    cr_assert_eq(map.data, 0);
}

Test(read, get_number_error)
{
    cr_assert_str_eq(get_number(NULL, NULL), "\0");
    cr_assert_str_eq(get_number("", NULL), "\0");
}

Test(read, read_file_content_error)
{
    cr_assert_eq(read_file_content(NULL), 0);
}

Test(read, get_line_size_error)
{
    cr_assert_eq(get_line_size(NULL), -1);
}

Test(read, parse_file_error_params)
{
    bsq_map map = {0};

    cr_assert_eq(parse_file(NULL, NULL), 1);
    cr_assert_eq(parse_file("tests/test_files/test2.txt", NULL), 1);
    cr_assert_eq(parse_file(NULL, &map), 1);
}

Test(read, parse_file_error_file)
{
    bsq_map map = {0};

    cr_assert_eq(parse_file("tests/test_files/test1.txt", &map), 1);
}