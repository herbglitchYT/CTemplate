#ifndef CTEMP_COMMANDS_H_
#define CTEMP_COMMANDS_H_

#include "../ctemp/ctemp.h"
#include "../system/system.h"
#include <stdio.h>

int ctemp_help   (CTemp_Config *config, char *val);
int ctemp_version(CTemp_Config *config, char *val);
int ctemp_type   (CTemp_Config *config, char *val);
int ctemp_lib    (CTemp_Config *config, char *val);

#endif