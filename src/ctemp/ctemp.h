#ifndef CTEMP_H_
#define CTEMP_H_

#include "error.h"
#include "types.h"
#include "../commands/commands.h"
#include <stdio.h>
#include <string.h>

int  ctemp_parse(int argc, char **argv);
int  ctemp_main (CTemp_Config *config);
void ctemp_print_error(int err, char** argv);

#endif