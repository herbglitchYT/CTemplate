#ifndef CTEMP_ERROR_H_
#define CTEMP_ERROR_H_

typedef enum CTemp_Error {
    CTemp_Error_Config_Init  = 0x01,
    CTemp_Error_Arg_Size     = 0x02,
    CTemp_Error_No_Path      = 0x04,
    CTemp_Error_Invalid_Type = 0x08,
    CTemp_Error_Invalid_Path = 0x10,
    CTemp_Error_Permissions  = 0x20,
}

#endif