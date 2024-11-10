#include "main.h"

int main() {
    char command[MAX_COMMAND_LEN];

    printf("[File Manager] Welcome! To get started please type 'help'\n");

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
