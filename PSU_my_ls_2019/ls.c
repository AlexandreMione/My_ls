/*
** EPITECH PROJECT, 2020
** my_ls
** File description:
** handle differents flags
*/

#include "include/my.h"

void checkn(struct my_lsf *lsf, int x)
{
    if ((opendir(lsf->folder[lsf->cpt + x])) != NULL) {
        my_putchar('\n');
        return;
    } else if ((opendir(lsf->folder[lsf->cpt + x])) == NULL) {
        x++;
        if (lsf->folder[lsf->cpt + x] != NULL)
            checkn(lsf, x);
    } else
        return;
}

void multi_opt(struct my_lsf *lsf)
{
    if (lsf->lr == 1 && lsf->rr == 0 && lsf->ld == 0
        && lsf->l_r == 1 && lsf->lt == 0 &&lsf->la == 0) {
        my_printf("%s:\n", lsf->folder[lsf->cpt]);
        ls_rmaj(lsf, lsf->folder[lsf->cpt]);
    }
}

void simple_opt(struct my_lsf *lsf)
{
    if (lsf->lr == 0 && lsf->rr == 0 && lsf->ld == 0
        && lsf->l_r == 1 && lsf->lt == 0 && lsf->la == 0) {
        my_printf("%s:\n", lsf->folder[lsf->cpt]);
        ls_maj(lsf, lsf->folder[lsf->cpt]);
    } else
        multi_opt(lsf);
}

void opt(struct my_lsf *lsf, DIR *dir)
{
    if (lsf->lr == 1 && lsf->rr == 0 && lsf->ld == 0
	&& lsf->l_r == 0 && lsf->lt == 0 && lsf->la == 0)
	ls_l(dir, lsf->folder[lsf->cpt]);
    if (lsf->lr == 0 && lsf->rr == 0 && lsf->ld == 0
        && lsf->l_r == 0 && lsf->lt == 0 && lsf->la == 1)
        my_lsa(dir);
    if (lsf->lr == 0 && lsf->rr == 0 && lsf->ld == 0 &&
        lsf->l_r == 0 && lsf->lt == 1 && lsf->la == 0)
        ls_t(lsf, dir, lsf->folder[lsf->cpt]);
    if (lsf->lr == 0 && lsf->rr == 0 && lsf->ld == 1 &&
        lsf->l_r == 0 && lsf->lt == 0 && lsf->la == 0) {
        my_printf("%s", lsf->folder[lsf->cpt]);
        if (!(lsf->folder[lsf->cpt + 1]))
            my_putchar('\n');
    } else
        simple_opt(lsf);
}

void ls(struct my_lsf *lsf)
{
    DIR *dir;

    while (lsf->folder[lsf->cpt]) {
        if ((dir = opendir(lsf->folder[lsf->cpt])) == NULL) {
            lsf->cpt++;
            continue;
        }
        if (lsf->folder[1] && lsf->ld != 1)
            my_printf("%s:\n", lsf->folder[lsf->cpt]);
        if (lsf->lr == 0 && lsf->rr == 0 && lsf->ld == 0 &&
            lsf->l_r == 0 && lsf->lt == 0) {
            my_ls(dir);
        } else
            opt(lsf, dir);
        if (lsf->folder[lsf->cpt + 1] != NULL)
            checkn(lsf, 1);
        closedir(dir);
        lsf->cpt++;
    }
}
