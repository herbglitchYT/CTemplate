#include "system.h"

#ifdef unix

#include <errno.h>
#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <sys/stat.h>

int ctemp_check_file_permissions(const char* path, CTemp_File_Type type, CTemp_File_Permission perm){
    struct stat sb;
    if(stat(path, &sb)){ return errno; }

    int err = 0;
    if(type & CTEMP_FILE_TYPE_BLK ){ err = (!err)? S_IFBLK (sb.st_mode) : 0; }
    if(type & CTEMP_FILE_TYPE_CHAR){ err = (!err)? S_IFCHR (sb.st_mode) : 0; }
    if(type & CTEMP_FILE_TYPE_FIFO){ err = (!err)? S_ISFIFO(sb.st_mode) : 0; }
    if(type & CTEMP_FILE_TYPE_REG ){ err = (!err)? S_IFREG (sb.st_mode) : 0; }
    if(type & CTEMP_FILE_TYPE_DIR ){ err = (!err)? S_IFDIR (sb.st_mode) : 0; }
    if(type & CTEMP_FILE_TYPE_LNK ){ err = (!err)? S_IFLNK (sb.st_mode) : 0; }
    if(type & CTEMP_FILE_TYPE_SOCK){ err = (!err)? S_IFSOCK(sb.st_mode) : 0; }
    if(err){ return err; }

    if(perm & CTEMP_FILE_PERM_READ){ err = (!err)? S_IFSOCK(sb.st_mode) : 0; }
}

int ctemp_check_file_permissions_wrapper(const char* path, ctemp_check_file_args args){
    args.type = (args.type)? args.type : CTEMP_FILE_TYPE_REG;
    args.perm = (args.type)? args.perm : CTEMP_FILE_PERM_USER | CTEMP_FILE_PERM_READ | CTEMP_FILE_PERM_WRITE | CTEMP_FILE_PERM_EXE;

    return ctemp_check_file_permissions(path, args.type, args.perm);
}

int ctemp_mkdir(const char *dir){
    char tmp[256];

    snprintf(tmp, sizeof(tmp), "%s", dir);
    size_t len = strlen(tmp);

    if (tmp[len - 1] == '/'){ tmp[len - 1] = 0; }

    for(char *path = tmp + 1; *path; path++){
        if(*path == '/'){
            int err = mkdir(tmp, S_IRWXU);
            if(err){ return err; }

            *path = '/';
        }
    }

    return mkdir(tmp, S_IRWXU);
}

#endif