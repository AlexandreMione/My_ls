/*
** EPITECH PROJECT, 2020
** my_ls
** File description:
** my_ls flag lr
*/

#include "include/my.h"

void ls_maj(struct my_lsf *lsf, char *directory)
{
    struct dirent *dirent;
    struct stat sb;
    DIR *dir;
    char *str;

    my_ls(opendir(directory));
    my_putchar('\n');
    dir = opendir(directory);
    while ((dirent = readdir(dir)) != 0) {
        str = my_strcat(my_strcat(directory, "/"), dirent->d_name);
        stat(str, &sb);
        if (S_ISDIR(sb.st_mode) && dirent->d_name[0] != '.') {
            my_printf("%s:\n", str);
            ls_maj(lsf, str);
        }
    }
}

void ls_rmaj(struct my_lsf *lsf, char *directory)
{
    struct dirent *dirent;
    struct stat sb;
    DIR *dir;
    char *str;

    ls_l(opendir(directory), directory);
    my_putchar('\n');
    dir = opendir(directory);
    while ((dirent = readdir(dir)) != 0) {
        str = my_strcat(my_strcat(directory, "/"), dirent->d_name);
        stat(str, &sb);
        if (S_ISDIR(sb.st_mode) && dirent->d_name[0] != '.') {
            my_printf("%s:\n", str);
            ls_rmaj(lsf, str);
        }
    }
}
