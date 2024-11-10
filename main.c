#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <windows.h>

#define MAX_COMMAND_LEN 10000

typedef struct {
    char* prefix;
    char* suffix;
} command_struct;

void create_user_file(char* file_name) {
    int count = 0;
    while (!(GetAsyncKeyState(VK_ESCAPE) & 0x8000)) {
        if (count == 0)
            printf("we made it");
        count++;
    }
    printf("[File Manager] File Creation has ended.");
}

void overwrite_user_file(char* input) {

}

void delete_user_file(char* input) {

}

/*
 * @params Command entered by user in stdin, char* command.
 * Call methods for each identified command, prompt user to error/help message
 * if command entered incorrectly.
 * */
void command_system(command_struct *cmd) {
    if (strcasecmp(cmd->prefix, "create") == 0) {
        printf("[File Manager] File Creation has begun (to exit press P): \n");
    } else if (strcasecmp(cmd->prefix, "delete") == 0) {
        printf("[File Manager] delete command recognized: \n");
    } else if (strcasecmp(cmd->prefix, "edit") == 0) {
        printf("[File Manager] edit command recognized: \n");
    } else if (strcasecmp(cmd->prefix, "help") == 0) {
        printf("[File Manager] List of Current Commands:\n");
        printf("Create, Delete, Edit, Help, Quit\n");
    } else if (strcasecmp(cmd->prefix, "quit") == 0) {
        printf("[File Manager] quit command recognized: \n");
    } else {
        printf("[File Manager] '%s' Command Unrecognized: \n", cmd->prefix);
        printf("[File Manager] try 'quit' command.\n");
    }
}

int main() {
    char command[MAX_COMMAND_LEN];

    while (fgets(command, MAX_COMMAND_LEN, stdin)) {
        int len = (int)strlen(command);
        if(command[len-1] == '\n'){
            command[len-1] = '\0';
            len--;
        }
        char* prefix = strtok(command, " ");
        char* suffix = strtok(NULL, "");

        command_struct cmd = {prefix, suffix};

        command_system(&cmd);
    }

    return 0;
}
