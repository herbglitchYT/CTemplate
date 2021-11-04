#include "commands.h"
#include "../config.h"
#include <string.h>

int ctemp_type(CTemp_Config *config, char* val){
    if(!strcmp(val, "cmake")){
        config->type = CTEMP_CONFIG_TYPE_CMAKE;
        return 0;
    }
    if(!strcmp(val, "make")){
        config->type = CTEMP_CONFIG_TYPE_CMAKE;
        return 0;
    }

    return CTEMP_ERR_PATH;
}