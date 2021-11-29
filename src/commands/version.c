#include "commands.h"

void ctemp_version(CTemp_Config *config, char *val){
    printf("CTemplate 0.00\n");
    config->flag_path_override = 0x01;
}
