#include <stdlib.h>

#include "ctemp/ctemp.h"

int main(int argc, char **argv){
    int err = ctemp_run(argc, argv);
    if(err){ ctemp_print_error(err, argv); }
    return 0;
}