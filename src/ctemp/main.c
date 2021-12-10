#include "ctemp.h"

int ctemp_init_folder(CTemp_Config *config);
int ctemp_init_cmake (CTemp_Config *config);

int ctemp_main(CTemp_Config *config){
    ctemp_init_folder(config);
    ctemp_init_cmake (config);

    return 0;
}

int ctemp_init_folder(CTemp_Config *config){
    // if()

    
    // if(!S_ISDIR(sb.st_mode)){
        // printf("ret = %d\n", ctemp_mkdir(config->path));
    // }

    return 0;
}

int ctemp_init_cmake(CTemp_Config *config){
    
}