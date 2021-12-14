/*
** EPITECH PROJECT, 2020
** my_ls
** File description:
** main
*/

#include "include/my.h"

void error(char **str)
{
    DIR	*dir;
    int	x;

    while (str[x]) {
        if ((dir = opendir(str[x])) == NULL) {
            my_printf("cannot acces %s", str[x]);
        }
        closedir(dir);
        x++;
    }
}

void my_ls(DIR *dir)
{
    struct dirent *d;

    while ((d = readdir(dir)) != 0) {
        if ((d->d_name[0] != '.'))
            my_printf("%s\n", d->d_name);
    }
}

void my_lsa(DIR *dir)
{
    struct dirent *d;

    while ((d = readdir(dir)) != 0) {
        if ((d->d_name[0] == '.'))
            my_printf("%s\n", d->d_name);
        else
            my_printf("%s\n", d->d_name);
    }
}

int main(int ac, char **av)
{
    struct my_lsf lsf;

    if (ac == 1) {
        my_ls(opendir("./"));
        return (0);
    }
    init(&lsf);
    command(ac, av, &lsf);
    error(lsf.folder);
    ls(&lsf);
    return (0);
}
