#include "main.h"
/*
 * @params Command entered by user in stdin, char* command.
 * Call methods for each identified command, prompt user to error/help message
 * if command entered incorrectly.
 * */
void command_system(command_struct *cmd) {
    if (strcasecmp(cmd->prefix, "create") == 0) {
        if (cmd->suffix == NULL || (int)strlen(cmd->suffix) < 1) {
            printf("Invalid command usage (proper usage: 'create file_name')\n");
            return;
        }
        printf("[File Manager] File Creation has begun (to exit press ESC): \n");
        create_user_file(cmd->suffix);
    } else if (strcasecmp(cmd->prefix, "delete") == 0) {
        if (cmd->suffix == NULL || (int)strlen(cmd->suffix) < 1) {
            printf("Invalid command usage (proper usage: 'create file_name')\n");
            return;
        }
        delete_user_file(cmd->suffix);
    } else if (strcasecmp(cmd->prefix, "view") == 0) {
        if (cmd->suffix == NULL || (int)strlen(cmd->suffix) < 1) {
            printf("Invalid command usage (proper usage: 'create file_name')\n");
            return;
        }
        view_user_file(cmd->suffix);
    } else if (strcasecmp(cmd->prefix, "help") == 0) {
        printf("[File Manager] List of Current Commands:\n");
        printf("Create, Delete, View, Help, Quit\n");
    } else if (strcasecmp(cmd->prefix, "quit") == 0) {
        printf("Quitting the program, thank you for using Ian's File Manager!\n");
        exit(0);
    } else {
        printf("[File Manager] '%s' Command Unrecognized: \n", cmd->prefix);
        printf("[File Manager] try 'quit' command.\n");
    }
}