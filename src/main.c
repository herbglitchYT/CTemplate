#include <stdio.h>
#include <stdlib.h>

#include "ctemp.h"

int main(int argc, char **argv){
    int err = ctemp_run(argc, argv);
    if(err == 0){ return 0;}

    switch(err){
        case CTEMP_ERR_ARG_SIZE:
            printf("ctemp: *** No targets specified. Stop.\n");
            break;
        case CTEMP_ERR_PATH:
            printf("ctemp: fatal error: no path defined\nsetup terminated.\n");
            break;
        default:
            printf("ctemp: '%s' is not a ctemp command. See 'ctemp --help'.\n", argv[err]);
            break;
    }
    return err;
}