#include "files.h"
#include <sys/stat.h>

void print_type(struct stat *st, char *name)
{
    DIR *dir1;
    struct dirent *entry1;
    struct stat file_info1;
    char *full_name1;
    //dir1 = opendir(name);

    switch (st->st_mode & S_IFMT) {
       case S_IFBLK:  printf("block device ");            break;
       case S_IFCHR:  printf("character device ");        break;
       case S_IFDIR:  printf("directory "); {
        if (dir1 != NULL) {
        while ((entry1 = readdir(name)) != NULL) {
            }
            sprintf(full_name1, "%s/%s", name, entry1->d_name);
            full_name1[254] = '\0';
            if (stat(full_name1, &file_info1) == 0) {
                print_type(&file_info1,full_name1);
                printf("sz %10ld ", file_info1.st_size);
            }
            printf(" %s\n", full_name1);
              
            
        }
    

       
              break;}
       case S_IFIFO:  printf("FIFO/pipe ");               break;
       case S_IFLNK:  printf("symlink ");                 break;
       case S_IFREG:  printf("regular file ");            break;
       case S_IFSOCK: printf("socket ");                  break;
       default:       printf("unknown? ");                break;
    }
}



void print_dir_contents(const char *strdir)
{
    DIR *dir;
    struct dirent *entry;
    struct stat file_info;
    char *full_name;

    full_name = (char*)malloc(255);

    dir = opendir(strdir);

    if (dir != NULL) {
        while ((entry = readdir(dir)) != NULL) {
            if (entry->d_name[0] == '.') {
                continue;
            }
            memset(full_name, 0, 255);
            sprintf(full_name, "%s/%s", strdir, entry->d_name);
            full_name[254] = '\0';
            if (stat(full_name, &file_info) == 0) {
                print_type(&file_info, full_name);
                printf("sz %10ld ", file_info.st_size);
            }
            printf(" %s\n", full_name);
        
        }
    }

    //free(full_name);
}