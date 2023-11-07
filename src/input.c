#include "input.h"

void clear_stdin()
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF)
        ;
}

InputData invalid_input()
{
    InputData input;
    input.command = Invalid;
    input.index = 0;
    input.data = NULL;

    return input;
}

size_t get_memory_size()
{
    printf("Input the memory size: \n");
    size_t size;
    scanf("%ld", &size);
    clear_stdin();

    return size;
}

#define MAX_COMMAND_SIZE 5
#define MAX_BINARY_SIZE 64
#define MAX_DATA_SIZE 64
#define MAX_INPUT_SIZE MAX_DATA_SIZE + MAX_BINARY_SIZE + MAX_COMMAND_SIZE

InputData get_command()
{
    system("clear");

    char buffer[MAX_INPUT_SIZE]; // Input buffer.

    // Get the input from terminal.
    printf("Enter the next command: \n");
    if (fgets(buffer, sizeof(buffer), stdin) == NULL)
    {
        printf("Error: STDIN.\n");
        return invalid_input();
    }

    // Remove the new line character.
    buffer[strcspn(buffer, '\n')] = '\0';

    char cmd[MAX_COMMAND_SIZE] = "";   // Command buffer.
    char binary[MAX_BINARY_SIZE] = ""; // Binary buffer.
    char data[MAX_DATA_SIZE] = "";     // Data buffer.

    // Get the command, binary and data.
    int intput_length = sscanf(buffer, "%s %s %s", cmd, binary, data);

    // Upper the command.
    for (size_t i = 0; i < MAX_COMMAND_SIZE; i++)
        cmd[i] = toupper(cmd[i]);

    // Check if the command is valid.
    Command command;

    if (strcmp(cmd, "LD") == 0 && intput_length == 2)
        command = Load;
    else if (strcmp(cmd, "ST") == 0 && intput_length == 3)
        command = Store;
    else if (strcmp(cmd, "EXIT") == 0 && intput_length == 1)
        command = Exit;
    else
        return invalid_input();

    size_t index = strtol(binary, NULL, 2); // Convert a stirng binary to decimal.

    InputData input_data;
    input_data.command = command;
    input_data.index = index;
    input_data.data = (char *)malloc(sizeof(data));
    strcpy(input_data.data, data);

    return input_data;
}