#include "ctemp.h"
#include "../commands/commands.h"
#include <string.h>
#include <stdio.h>

CTemp_Command ctemp_commands[] = {
    { 'h', "--help",    &ctemp_help    },
    { 'v', "--version", &ctemp_version },
    { 't', "--type",    &ctemp_type    },
    { 'l', "--lib" ,    &ctemp_lib     },
};

void ctemp_init_config(CTemp_Config *config){
    config->err  = (Error){ 0, 0 };
    config->type = CTEMP_CONFIG_TYPE_CMAKE;

    config->flag_path_override = 0x00;

    config->path = NULL;
}

int ctemp_check_command(char *command){
    for(unsigned int i = 0; i < sizeof(ctemp_commands) / sizeof(CTemp_Command); i++){
        if((command[0] == '-' && command[1] == ctemp_commands[i].abrv) || !strcmp(command, ctemp_commands[i].full)){ return (int)i + 1; }
    }
    return (command[0] == '-')? -1 : 0;
}

void ctemp_init(int argc, char **argv){
    CTemp_Config config;
    ctemp_init_config(&config);

    if(argc < 2){ config.err = (Error){ CTemp_Errno, CTemp_Error_Arg_Size }; }

    int command;
    char *val = NULL;
    for(int i = 1; i < argc; i++){
        if(config.err.errno){ break; }

        command = ctemp_check_command(argv[i]);
        if(command > 0){
            if(argv[i][1] != '-' && strlen(argv[i]) > 2){ val = argv[i] + 2; }

            if(!val){
                i++;
                val = argv[i];
            }

            ctemp_commands[command - 1].func(&config, val);
            val = NULL;
            continue;
        }

        if(!config.path && !command){
            config.path = argv[i];
            continue;
        }

        config.err = (Error){ CTemp_Flag_Errno, i };
    }

    if(!config.err.errno && !config.path && !config.flag_path_override){ config.err = (Error){ CTemp_Errno, CTemp_Error_No_Path }; }

    if(!config.err.errno){ ctemp_main(&config); }

    if(config.err.errno){ ctemp_print_error(config.err, argv); }
}