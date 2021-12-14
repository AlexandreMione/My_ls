/*
** EPITECH PROJECT, 2018
** my
** File description:
** task02
*/

#ifndef MY_H
#define MY_H

#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>
#include <stdlib.h>
#include <pwd.h>
#include <grp.h>
#include <time.h>
#include <string.h>
#include <unistd.h>
#include <getopt.h>
#include <fcntl.h>
#include <string.h>
#include <getopt.h>

/*----LIB----*/
char *concat_params(int argc, char **argv);
int my_str_islower(char const *str);
int my_char_isalpha(char c);
int my_compute_factorial_it(int nb);
int my_compute_factorial_rec(int nb);
int my_compute_power_it(int nb, int p);
int my_compute_power_rec(int nb, int power);
int my_compute_square_root(int nb, int power);
char *my_evil_str(char *str);
int my_find_prime_sup(int nb);
int my_getnbr(char const *str);
int my_isneg(int n);
int my_is_prime(int nb);
int my_print_alpha(void);
int my_print_comb(void);
int my_print_digits(void);
int my_print_revalpha(void);
void my_putchar(char c);
void my_putcharerr(char c);
void my_put_nbr(int nb);
int my_putstr(char const *str);
int my_putstrerr(char const *str);
void my_put_unsigned(long nb);
char *my_revstr(char *str);
int my_showmem(char const *str, int size);
int my_showstr(char const *str);
int my_show_word_array(char * const *tab);
void my_sort_int_array(int *tab, int size);
char *my_strcapitalize(char *str);
char *my_strcat(char *dest, char const *src);
int my_strcmp(char const *s1, char const *s2);
char *my_strcpy(char *dest, char const *src);
char *my_strdup(char const *src);
int my_str_isalpha(char const *str);
int my_str_isnum(char const *str);
int my_str_isprintable(char const *str);
int my_str_isupper(char const *str);
char *my_str_only_alpha(char *str);
int my_strlen(char const *str);
char *my_strlowcase(char *str);
char *my_strncat(char *dest, char const *src, int nb);
int my_strncmp(char const *s1, char const *s2, int n);
char *my_strncpy(char *dest, char const *src, int n);
char *my_strstr(char *str, char const *to_find);
char *my_strupcase(char *str);
int my_swap(int *a, int *b);
char *upper_case(char *str);
int my_put_float(double nbr);
int my_put_hexa(unsigned int nb);
void my_put_binary(int nb);
void my_put_octal(int nb);
int my_printf(char *s, ...);
char **my_str_to_word_array(char *str, char *lim);

/*----STRUCT----*/
struct my_lsf
{
    int lr;
    int rr;
    int ld;
    int l_r;
    int lt;
    int la;
    int cpt;
    char *path;
    char **folder;
};

/*----PROGRAM----*/
void error(char **str);
void my_ls(DIR *dir);
void init(struct my_lsf *lsf);
void dos(char *str, struct my_lsf *lsf);
void opt_u(char *str, struct my_lsf *lsf);
void command(int ac, char **av, struct my_lsf *lsf);
void right(struct stat sb);
char *inspect(char *s, char *file);
void block(char *s);
void ls_l(DIR *dir, char *res);
void checkn(struct my_lsf *lsf, int x);
void multi_opt(struct my_lsf *lsf);
void ls_maj(struct my_lsf *lsf, char *directory);
void ls_rmaj(struct my_lsf *lsf, char *directory);
void simple_opt(struct my_lsf *lsf);
void opt(struct my_lsf *lsf, DIR *dir);
void ls(struct my_lsf *lsf);
void my_lsa(DIR *dir);
void ls_t(struct my_lsf *lsf, DIR *dir, char *directory);
char **timels(char **tab, char *directory);
char **elem(int index1, int index2, char **tab);

#endif
