#ifndef CTEMP_SYSTEM_H_
#define CTEMP_SYSTEM_H_

/**
 * @brief File type, is set to allow passing mutiple values together
 */
typedef enum CTemp_File_Type {
    CTEMP_FILE_TYPE_BLK  = 0x01,
    CTEMP_FILE_TYPE_CHAR = 0x02,
    CTEMP_FILE_TYPE_FIFO = 0x04,
    CTEMP_FILE_TYPE_REG  = 0x08,
    CTEMP_FILE_TYPE_DIR  = 0x10,
    CTEMP_FILE_TYPE_LNK  = 0x20,
    CTEMP_FILE_TYPE_SOCK = 0x40,
    CTEMP_FILE_TYPE_ALL  = 0xFF
} CTemp_File_Type;

/**
 * @brief File Permssions, is set to allow passing mutiple values together
 */
typedef enum CTemp_File_Permission {
    /** User file permissions */
    CTEMP_FILE_PERM_USER  = 0x01,
    CTEPM_FILE_PERM_GROUP = 0x02,
    CTEMP_FILE_PERM_OTHER = 0x04,
    CTEMP_FILE_PERM_SUDO  = 0x08,
    /** Access permissions */
    CTEMP_FILE_PERM_READ  = 0x10,
    CTEMP_FILE_PERM_WRITE = 0x20,
    CTEMP_FILE_PERM_EXE   = 0x40,
} CTemp_File_Permission;

/**
 * @brief Check File (type and read perissions)
 * 
 * checks file from given path (the last value after the slash)
 * 
 * @param path String to path of file or name of file
 * @param type Type of file to check
 * @param perm File permissions to check
 * 
 * 
 * @return returns 0 in case of success, or a <errno.h> error on failure
 */
int ctemp_check_file_permissions(const char* path, CTemp_File_Type type, CTemp_File_Permission perm);

/**
 * @brief Helper type to to allow defaults in ctemp_check_file
 */
typedef struct {
    CTemp_File_Type type;
    CTemp_File_Permission perm;
} ctemp_check_file_args;

/**
 * @brief Check File (type and read perissions)
 *
 * @note Defaults for CTemp_File_Type is CTEMP_FILE_TYPE_REG, and
 * Defaults for CTemp_File_Permission is CTEMP_FILE_PERM_USER |
 * (CTEMP_FILE_PERM_READ | CTEMP_FILE_PERM_WRITE | CTEMP_FILE_PERM_EXE)
 * 
 * @param path String to path of file or name of file
 * @param args ctemp_check_file_args, this struct may be empty
 * 
 * @return returns 0 in case of success, or a <errno.h> error on failure
 */
int ctemp_check_file_permissions_wrapper(const char* path, ctemp_check_file_args args);

/**
 * @brief Small helper function for ctemp_check_file_permissions_wrapper
 */
#define ctemp_check_file(path, args...)\
    ctemp_check_file_permissions_wrapper(path, (ctemp_check_file_args){ args });

/**
 * @brief Create directory
 *
 * @note rn, I am too lazy to do much error checking.
 * After good error checks are written, this note should be deleted
 * 
 * creates directories in given path if they don't exist
 * 
 * @param dir String to path of directory or name of new direcotry
 * 
 * @return returns 0 in case of success, or a <errno.h> error on failure
 */
int ctemp_mkdir(const char *dir);

#endif