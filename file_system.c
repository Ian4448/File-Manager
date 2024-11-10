#include "main.h"
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
            char ch = (char)_getch();
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