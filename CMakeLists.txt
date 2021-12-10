cmake_minimum_required(VERSION 3.10)

project(ctemp)

add_executable(ctemp
    src/main.c

    src/commands/help.c
    src/commands/lib.c
    src/commands/type.c
    src/commands/version.c

    src/ctemp/error.c
    src/ctemp/main.c
    src/ctemp/parse.c

    src/system/linux/sys.c
)

target_link_libraries(ctemp PRIVATE -Wall -Werror)