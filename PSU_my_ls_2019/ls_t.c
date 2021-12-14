/*
** EPITECH PROJECT, 2020
** my_ls
** File description:
** ls_t
*/

#include "include/my.h"

char **elem(int index1, int index2, char **tab)
{
    char *tmp = my_strdup(tab[index1]);

    tab[index1] = my_strdup(tab[index2]);
    tab[index2] = my_strdup(tmp);
    free(tmp);
    return (tab);
}

char **timels(char **tab, char *directory)
{
    int	y = 0;
    char *str = NULL;
    char *str2 = NULL;
    long tmp = 0;
    struct stat sb;

    while (tab[y + 1]) {
        str = inspect(directory, tab[y]);
        str2 = inspect(directory, tab[y + 1]);
        stat(str, &sb);
        tmp = sb.st_mtime;
        stat(str2, &sb);
        if (tmp < sb.st_mtime) {
            elem(y, y + 1, tab);
            y = 0;
            continue;
        } else
            y++;
    }
    return (tab);
}

void ls_t(struct my_lsf *lsf, DIR *dir, char *directory)
{
    struct dirent *dirent;
    char **tab;
    char *names = "\0";

    while ((dirent = readdir(dir)) != 0) {
        if ((dirent->d_name[0] != '.')) {
            names = my_strcat(names, dirent->d_name);
            names = my_strcat(names, "\n");
        }
    }
    tab = my_str_to_word_array(names, "\n");
    tab = timels(tab, directory);
    my_show_word_array(tab);
}
