#include "commands.h"

void ctemp_help(CTemp_Config *config, char *val){
    printf("\
Usage: ctemp [options]\n\
Options:\n\
\t-h, --help\tPrint this message and exit.\n\
\t-t, --type\tSet compile type. (make, cmake).\n\t\t\tIf this flag is not specified, cmake will be used.\n"
    );

    config->flag_path_override = 0x01;
}