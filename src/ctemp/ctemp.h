#ifndef CTEMP_H_
#define CTEMP_H_

#include "../defines/ctemp.h"
#include "../defines/error.h"

void ctemp_init(int argc, char **argv);
int  ctemp_main(CTemp_Config *config);

void ctemp_print_error(Error err, char** argv);

#endif