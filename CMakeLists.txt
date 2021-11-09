cmake_minimum_required(VERSION 3.10)

project(ctemp)

add_executable(${PROJECT_NAME}
    src/main.c
    src/ctemp.c

    src/commands/help.c
    src/commands/lib.c
    src/commands/main.c
    src/commands/type.c
    src/commands/version.c
)