#ifndef CONFIG_H_
#define CONFIG_H_

typedef enum CTemp_ConfigType {
    CTEMP_CONFIG_TYPE_CMAKE,
    CTEMP_CONFIG_TYPE_MAKE
} CTemp_ConfigType;

typedef struct CTemp_Config {
    CTemp_ConfigType type;
    char **libs;
    char *path;
} CTemp_Config;

typedef struct CTemp_Command {
    char abrv;
    char *full;
    int (*func)(CTemp_Config *config, char *val);
} CTemp_Command;

#endif