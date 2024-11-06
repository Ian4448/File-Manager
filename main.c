#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_COMMAND_LEN 10000

enum Command {
    CREATE,
    DELETE,
    EDIT,
    QUIT
};

char *handle_input(char* command) {
    return strtok(command, " ");
}

void command_system(char* command) {
    for (int i = 0; i < strlen(command); i++) {
        command[i] = (char)tolower(command[i]);
    }

    if (strcmp(command, "quit") == 0) {
        printf("[File Manager] quit command recognized: \n");
    } else {
        printf("[File Manager] Command Unrecognized: \n");
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
        printf("command: %s", command);
        printf("input: %s", handle_input(command));
        command_system(command);
    }

    return 0;
}
