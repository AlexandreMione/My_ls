/*
** EPITECH PROJECT, 2020
** my_ls
** File description:
** flags
*/

#include "include/my.h"

void init(struct my_lsf *lsf)
{
    lsf->rr = 0;
    lsf->cpt = 0;
    lsf->l_r = 0;
    lsf->lr = 0;
    lsf->lt = 0;
    lsf->rr = 0;
    lsf->la = 0;
    lsf->folder = my_str_to_word_array(".", "\n");
}

void dos(char *str, struct my_lsf *lsf)
{
    static int x = 0;

    lsf->folder[x] = my_strdup(str);
    x++;
    lsf->folder[x] = NULL;
}

void opt_u(char *str, struct my_lsf *lsf)
{
    int x = 0;

    if (str[x] == '-')
        x++;
    if (str[x] != 'l' && str[x] != 'r' && str[x] != 'd'
        && str[x] != 'R' && str[x] != 't' && str[x] != 'a') {
        my_printf("Invalid options");
        exit(84);
    }
    while (str[x]) {
        str[x] == 'l' ? lsf->lr = 1 : 0;
        str[x] == 'r' ? lsf->rr = 1 : 0;
        str[x] == 'd' ? lsf->ld = 1 : 0;
        str[x] == 't' ? lsf->lt = 1 : 0;
        str[x] == 'R' ? lsf->l_r = 1 : 0;
        str[x] == 'a' ? lsf->la = 1 : 0;
        x++;
    }
}

void command(int ac, char **av, struct my_lsf *lsf)
{
    int x = 1;

    if (x == ac)
        return;
    while (x < ac) {
        if (av[x][0] == '-')
            opt_u(av[x], lsf);
        else
            dos(av[x], lsf);
        x++;
    }
}
