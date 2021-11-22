#include "system.h"

int ctemp_mkdir(const char *dir){
    char tmp[256];

    snprintf(tmp, sizeof(tmp), "%s", dir);
    size_t len = strlen(tmp);

    if (tmp[len - 1] == '/'){ tmp[len - 1] = 0; }

    for(char *path = tmp + 1; *path; path++){
        if(*path == '/'){
            int err = mkdir(tmp, S_IRWXU);
            if(err){ return err; }

            *path = '/';
        }
    }

    return mkdir(tmp, S_IRWXU);
}