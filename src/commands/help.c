#include "commands.h"
#include <stdio.h>

int ctemp_help(){

    printf(
"\
Usage: ctemp [options]\n\
Options:\n\
\t-h, --help\tPrint this message and exit.\n\
"
    );

    return 0;
}