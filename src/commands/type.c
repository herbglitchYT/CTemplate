#include "commands.h"
#include "../defines/error.h"
#include <string.h>

void ctemp_type(CTemp_Config *config, char* val){
    if(!strcmp(val, "cmake")){
        config->type = CTEMP_CONFIG_TYPE_CMAKE;
        return;
    }

    if(!strcmp(val, "make")){
        config->type = CTEMP_CONFIG_TYPE_CMAKE;
        return;
    }

    config->err.errno = CTemp_Error_Invalid_Type;
}