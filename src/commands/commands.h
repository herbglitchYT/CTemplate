#ifndef COMMANDS_H_
#define COMMANDS_H_

#include "../config.h"

int ctemp_help(CTemp_Config *config, char *val);
int ctemp_type(CTemp_Config *config, char *val);
int ctemp_lib (CTemp_Config *config, char *val);

#define CTEMP_ERR_CONFIG_INIT -1
#define CTEMP_ERR_ARG_SIZE    -2
#define CTEMP_ERR_PATH        -3
#define CTEMP_ERR_TYPE        -4
/*
usage: git [--version] [--help] [-C <path>] [-c <name>=<value>]
           [--exec-path[=<path>]] [--html-path] [--man-path] [--info-path]
           [-p | --paginate | -P | --no-pager] [--no-replace-objects] [--bare]
           [--git-dir=<path>] [--work-tree=<path>] [--namespace=<name>]
           [--super-prefix=<path>] [--config-env=<name>=<envvar>]
           <command> [<args>]
*/
#endif