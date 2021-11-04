#include "ctemp.h"
#include "config.h"
#include "commands/commands.h"
#include <string.h>
#include <stdio.h>

CTemp_Command ctemp_commands[] = {
    { 'h', "--help", &ctemp_help },
    { 't', "--type", &ctemp_type },
    { 'l', "--lib" , &ctemp_lib  },
};
unsigned int ctemp_commands_size = sizeof(ctemp_commands) / sizeof(CTemp_Command);

int ctemp_check_command(char *command){
    for(unsigned int i = 0; i < ctemp_commands_size; i++){
        if((command[0] == '-' && command[1] == ctemp_commands[i].abrv) || !strcmp(command, ctemp_commands[i].full)){ return (int)i + 1; }
    }
    return (command[0] == '-')? -1 : 0;
}

int ctemp_init(CTemp_Config *config){
    config->type = CTEMP_CONFIG_TYPE_CMAKE;
    config->path = NULL;
}

int ctemp_run(int argc, char **argv){
    if(argc < 2){ return CTEMP_ERR_ARG_SIZE; }

    CTemp_Config config;
    if(ctemp_init(&config)){ return CTEMP_ERR_CONFIG_INIT; }

    int command;
    char *val = NULL;
    for(int i = 1; i < argc; i++){
        command = ctemp_check_command(argv[i]);
        if(command > 0){
            if(argv[i][1] != '-' && strlen(argv[i]) > 2){ val = argv[i] + 2; }

            if(!val){
                i++;
                val = argv[i];
            }

            int err = ctemp_commands[command - 1].func(&config, val);
            if(err){ return err; }

            val = NULL;
            continue;
        }

        if(config.path && !command){
            config.path = argv[i];
            continue;
        }

        return i;
    }

    return 0;
}