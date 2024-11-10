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
        printf("[File Manager] delete command recognized: \n");
    } else if (strcasecmp(cmd->prefix, "edit") == 0) {
        printf("[File Manager] edit command recognized: \n");
    } else if (strcasecmp(cmd->prefix, "help") == 0) {
        printf("[File Manager] List of Current Commands:\n");
        printf("Create, Delete, Edit, Help, Quit\n");
    } else if (strcasecmp(cmd->prefix, "quit") == 0) {
        printf("Quitting the program, thank you for using Ian's File Manager!\n");
        exit(0);
    } else {
        printf("[File Manager] '%s' Command Unrecognized: \n", cmd->prefix);
        printf("[File Manager] try 'quit' command.\n");
    }
}