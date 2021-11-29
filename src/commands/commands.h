#ifndef CTEMP_COMMANDS_H_
#define CTEMP_COMMANDS_H_

#include "../ctemp/ctemp.h"
#include "../system/system.h"
#include <stdio.h>

void ctemp_help   (CTemp_Config *config, char *val);
void ctemp_version(CTemp_Config *config, char *val);
void ctemp_type   (CTemp_Config *config, char *val);
void ctemp_lib    (CTemp_Config *config, char *val);

#endif