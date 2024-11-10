#include "main.h"
/*
 * Creates a text file with the given name, allowing user input until F10 is pressed.
 * @param file_name Name of the file to be created (".txt" is appended).
 *
 * Functionality:
 * - Continuously reads keyboard input, resizing the buffer as needed.
 * - Ends input on F10 press and writes collected text to the file.
 */

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
    printf("[File Manager] File Creation has ended successfully.\n");
}

/*
 * Opens and reads the content of a specified text file, printing it to the console.
 * @param file_name Name of the file to be read (".txt" is appended).
 *
 * Functionality:
 * - Reads file content into a dynamically resized buffer.
 * - Prints the entire content to the console once reading is complete.
 */

void view_user_file(char* file_name) {
    char full_file_name[256];
    int length = 0;
    int capacity = 10;
    char* user_text = malloc(capacity * sizeof(char));

    if (!user_text) {
        printf("Memory allocation failed\n");
        return;
    }

    snprintf(full_file_name, sizeof(full_file_name), "%s.txt", file_name);

    FILE *fptr = fopen(full_file_name, "r");
    if (fptr == NULL) {
        printf("[File Manager] Error opening the file.\n");
        free(user_text);
        return;
    }

    printf("[File Manager] Reading contents:\n");

    int ch;
    while ((ch = fgetc(fptr)) != EOF) {
        if (length >= capacity) {
            capacity *= 2;
            char* new_user_text = realloc(user_text, capacity * sizeof(char));
            if (!new_user_text) {
                printf("Memory allocation failed\n");
                free(user_text);
                fclose(fptr);
                return;
            }
            user_text = new_user_text;
        }
        user_text[length++] = (char) ch;
        fflush(stdout);
    }

    user_text[length] = '\0';

    printf("%s", user_text);

    fclose(fptr);
    free(user_text);
    printf("\n[File Manager] File has finished reading.\n");
}

/*
 * Deletes file requested by user. (any type)
 * */
void delete_user_file(char* file_name) {
    if (remove(file_name) == 0) {
        printf("Removed File Successfully!");
    } else {
        printf("Error removing file %s", file_name);
    }
}