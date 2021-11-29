#include "ctemp.h"
#include <stdio.h>

void ctemp_print_error(Error err, char** argv){
    if(err.type == CTemp_Flag_Errno){
        printf("ctemp: '%s' is not a ctemp command. See 'ctemp --help'.\n", argv[err.errno]);
        return;
    }

    if(err.type == CTemp_Errno){
        switch(err.errno){
            case CTemp_Error_Config_Init:
                printf("ctemp: fatal error: CTemp_Config failed to init. This should never happen.\nsetup terminated.\n");
                break;
            case CTemp_Error_Arg_Size:
                printf("ctemp: *** No targets specified. Stop.\n");
                break;
            case CTemp_Error_No_Path:
                printf("ctemp: fatal error: no path defined\nsetup terminated.\n");
                break;
            case CTemp_Error_Invalid_Type:
                printf("ctemp: fatal error: type specified was not cmake or make.\nsetup terminated.\n");
                break;
            default:
                printf("ctemp: unknown error.\n");
                break;
        }
    }
}