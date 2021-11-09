#ifndef CTEMP_COMMANDS_H_
#define CTEMP_COMMANDS_H_

#include "../config.h"

int ctemp_main(CTemp_Config *config);

int ctemp_help   (CTemp_Config *config, char *val);
int ctemp_version(CTemp_Config *config, char *val);
int ctemp_type   (CTemp_Config *config, char *val);
int ctemp_lib    (CTemp_Config *config, char *val);

#define CTEMP_ERR_CONFIG_INIT -1
#define CTEMP_ERR_ARG_SIZE    -2
#define CTEMP_ERR_PATH        -3
#define CTEMP_ERR_TYPE        -4

#endif