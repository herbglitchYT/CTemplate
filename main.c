#include <stdio.h>
#include <string.h>
#include <stdlib.h>

const char *help_txt = "\
Usage: ctemp [options]\n\
Options:\n\
\n"; 

int main(int argc, char **argv){
    if(argc < 2){
        printf("ctemp: *** No targets specified. Stop. \n");
        return 0;
    }

    printf("argv[1] = %s\n", argv[1]);
    if(argv[1][0] == '-'){    
        if(!strcmp(argv[1], "-g")){
            printf("HERE\n");
            system("git --help");
            return 0;
        }

        if(!strcmp(argv[1], "--help")){
            printf(help_txt);
            return 0;
        }
    }

    return 0;
}