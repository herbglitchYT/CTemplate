#ifndef CTEMP_DEFINES_H_
#define CTEMP_DEFINES_H_

#include "base.h"

/**
 * @brief a type to determine what ctemp should build for
*/
typedef enum CTemp_ConfigType {
    CTEMP_CONFIG_TYPE_CMAKE,
    CTEMP_CONFIG_TYPE_MAKE
} CTemp_ConfigType;

/**
 * @brief the main ctemp structure. Used to store all settings during parsing
*/
typedef struct CTemp_Config {
    Error err;
    CTemp_ConfigType type;
    uint8_t flag_path_override;
    char **libs;
    char *path;
} CTemp_Config;

/**
 * @brief a structure to make creating commands easier
*/
typedef struct CTemp_Command {
    char abrv;
    char *full;
    void (*func)(CTemp_Config *config, char *val);
} CTemp_Command;

#endif