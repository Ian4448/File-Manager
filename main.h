#ifndef FILEMANAGER_MAIN_H
#define FILEMANAGER_MAIN_H

#include <stdio.h>
#include <string.h>
#include <windows.h>
#include <conio.h>
#include <stdlib.h>

#define MAX_COMMAND_LEN 10000

// Structure to hold command prefix and suffix
typedef struct {
    char* prefix;
    char* suffix;
} command_struct;

// Function declarations for command_system.c
void command_system(command_struct *cmd);

// Function declarations for file_system.c
void create_user_file(char* file_name);
void overwrite_user_file(char* input);
void delete_user_file(char* input);

#endif // FILEMANAGER_MAIN_H
