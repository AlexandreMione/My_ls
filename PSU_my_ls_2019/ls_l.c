/*
** EPITECH PROJECT, 2020
** my_ls
** File description:
** ls -l
*/

#include "include/my.h"

void right(struct stat sb)
{
    my_printf(S_ISDIR(sb.st_mode) ? "d" : "-");
    my_printf(sb.st_mode & S_IRUSR ? "r" : "-");
    my_printf(sb.st_mode & S_IWUSR ? "w" : "-");
    my_printf(sb.st_mode & S_IXUSR ? "x" : "-");
    my_printf(sb.st_mode & S_IRGRP ? "r" : "-");
    my_printf(sb.st_mode & S_IWGRP ? "w" : "-");
    if ((sb.st_mode & S_ISGID) && !(sb.st_mode & S_IXGRP))
        my_printf("S");
    else if ((sb.st_mode & S_ISGID) && (sb.st_mode & S_IXGRP))
        my_printf("s");
    else
        my_printf((sb.st_mode & S_IXGRP) ? ("x") : ("-"));
    my_printf(sb.st_mode & S_IROTH ? "r" : "-");
    my_printf(sb.st_mode & S_IWOTH ? "w" : "-");
    if ((sb.st_mode & S_ISVTX) && !(sb.st_mode & S_IXOTH))
        my_printf("T ");
    else if ((sb.st_mode & S_ISVTX) && (sb.st_mode & S_IXOTH))
        my_printf("t ");
    else
        my_printf((sb.st_mode & S_IXOTH) ? ("x ") : ("- "));
}

char *inspect(char *s, char *file)
{
    char *str = my_strdup(s);

    if (my_strcmp(str, ".") == 0) {
        str = my_strcat(str, "/");
        str = my_strcat(str, file);
        return (str);
    }
    str = my_strcat(str, "/");
    str = my_strcat(str, file);
    return (str);
}

void ls_l(DIR *dir, char *res)
{
    struct dirent *dirent;
    struct stat s;
    struct passwd *passwd;
    struct group *grp;
    char *str;

    while ((dirent = readdir(dir)) != NULL) {
	if ((dirent->d_name[0] != '.')) {
            str = inspect(res, dirent->d_name);
            stat(str, &s);
            passwd = getpwuid(s.st_uid);
            grp = getgrgid(s.st_gid);
            right(s);
            my_printf("%d %s ", s.st_nlink, passwd->pw_name);
            my_printf("%s %d ", grp->gr_name, s.st_size);
            write(1, (ctime(&s.st_mtime) + 4),
                  (my_strlen(ctime(&s.st_mtime)) - 13));
            my_printf(" %s\n", dirent->d_name);
        }
    }
}
