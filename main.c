#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <dirent.h>
#include <sys/stat.h>
#include <stdbool.h>

#include "files.h"

extern char *optarg;
extern int optind, opterr, optopt;

#define DEBUG_PRINT(X) \
    printf("%s\n", X); \
    printf("FUNC %s ", __func__); \
    printf("LINE %d ", __LINE__); \
    printf("FILE %s ", __FILE__); \
    printf("DATE %s ", __DATE__); \
    printf("TIME %s\n", __TIME__); \

void help(const char *appname);

int main(int argc, char **argv)
{

#ifdef DEBUG
    DEBUG_PRINT("Start of program");
#endif

    int ret;
    
    char *dir;

    if (argc == 1) {
        help(argv[0]);
        return 0;
    }

    while ((ret = getopt(argc, argv, "hf:")) != -1) {
        switch(ret) {
            
            case 'h' : {
                printf("-f<path>=> ls -r\n-h=> help");
                help(argv[0]);
                return 0;
            }
            case 'f' : {
                dir = optarg;
                break;
            }
        }
    }

    print_dir_contents(dir);

#ifdef DEBUG
    DEBUG_PRINT("END of program");
#endif
}


void help(const char *appname)
{
    printf("usage: %s [path]\n", appname);
} 