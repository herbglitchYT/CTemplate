#include "ctemp.h"

void ctemp_print_error(int err, char** argv){
    if(err > 0){
        printf("ctemp: '%s' is not a ctemp command. See 'ctemp --help'.\n", argv[err]);
        return;
    }

    switch(-err){
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