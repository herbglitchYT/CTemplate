#include "commands.h"
#include "../config.h"
#include <stdlib.h>
#include <sys/stat.h>


int ctemp_main(CTemp_Config *config){
    struct stat sb;
    if(stat(config->path, &sb) == 0 && S_ISDIR(sb.st_mode)){

    }
}


/*
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>

static void _mkdir(const char *dir) {
    char tmp[256];
    char *p = NULL;
    size_t len;

    snprintf(tmp, sizeof(tmp),"%s",dir);
    len = strlen(tmp);
    if (tmp[len - 1] == '/')
        tmp[len - 1] = 0;
    for (p = tmp + 1; *p; p++)
        if (*p == '/') {
            *p = 0;
            mkdir(tmp, S_IRWXU);
            *p = '/';
        }
    mkdir(tmp, S_IRWXU);
}

int main(){
    const char* folder = "/home/herbglitch/programs/c/CTemplate1";


    // _mkdir("./TEMPTest/one/two/three/");
    return 0;
}
*/