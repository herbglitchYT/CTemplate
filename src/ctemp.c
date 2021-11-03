#include "ctemp.h"
#include "commands/commands.h"
#include <string.h>
#include <stdio.h>

struct Command {
    char abbrev;
    char *full;
    int (*func)(void);
};

const struct Command commands[] = {
    { 'h', "--help", &ctemp_help }
};
const unsigned int c_size = sizeof(commands) / sizeof(struct Command);


int ctemp_check_command(char *temp){
    for(unsigned int i = 0; i < c_size; i++){
        if((temp[0] == '-' && temp[1] == commands[i].abbrev) || !strcmp(temp, commands[i].full)){ return (int)i + 1; }
    }
    return (temp[0] == '-')? -1 : 0;
}

int ctemp_run(int argc, char **argv){
    if(argc < 2){ return CTEMP_ERR_ARG_SIZE; }

    int command;
    char *path;
    for(int i = 1; i < argc; i++){
        command = ctemp_check_command(argv[i]);
        if(command > 0){
            int err = commands[command - 1].func();
            if(err){ return err; }
            continue;
        }

        if(command){ return i; }

        if(path){ return i; }

        path = argv[i];
    }

    return 0;
}