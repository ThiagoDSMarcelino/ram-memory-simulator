#include "user.h"

void clear_stdin()
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

UserInput invalid_input()
{
    UserInput input;
    input.command = Invalid;
    input.index = 0;
    input.data = NULL;

    return input;
}

size_t get_user_memory_size()
{
    printf("Input the memory size: \n");
    size_t size;
    scanf("%ld", &size);
    clear_stdin();

    return size;
}

UserInput get_user_command()
{
    char input[100];
    char str[3];
    char binary[64];
    size_t index;

    printf("Input the data: \n");
    if (fgets(input, sizeof(input), stdin) == NULL)
    {
        printf("Error: STDIN.\n");
        return invalid_input();
    }
    clear_stdin();

    input[strcspn(input, "\n")] = '\0';

    if (sscanf(input, "%s %s", str, binary) != 2)
    {
        printf("Invalid format.\n");
        return invalid_input();
    }

    Command command;

    if (strcmp(str, "LV") == 0)
        command = Load;
    else if (strcmp(str, "ST") == 0)
        command == Store;
    else if (strcmp(str, "EXIT") == 0)
        command = Exit;
    else
        command = Invalid;


    index = strtol(binary, NULL, 2);


    UserInput user_input;
    user_input.command = command;
    user_input.index = index;
    user_input.data = NULL;

    return user_input;
}