#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <windows.h>
#include <conio.h>

#define MAX_COMMAND_LEN 10000

typedef struct {
    char* prefix;
    char* suffix;
} command_struct;

void create_user_file(char* file_name) {
    FILE *fptr;
    int capacity = 10;
    int length = 0;
    char* user_text = malloc(capacity * sizeof(char));
    strcat(file_name, ".txt");

    while (TRUE) {
        if (GetAsyncKeyState(VK_F10) & 0x8000) {
            printf("\n[F10 Pressed] Ending input...\n");
            break;
        }

        if (_kbhit()) {
            char ch = _getch();
            if (length >= capacity) {
                capacity *= 2;
                user_text = realloc(user_text, capacity * sizeof(char));
                if (!user_text) {
                    printf("memory allocation failed");
                    return;
                }
            }

            user_text[length++] = ch;
            user_text[length] = '\0';

            fflush(stdout);
        }
    }

    // create/override user set file
    fptr = fopen(file_name, "w");

    // write to file and close
    fprintf(fptr, "%s", user_text);
    fclose(fptr);

    free(user_text);
    printf("[File Manager] File Creation has ended successfully.");
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
