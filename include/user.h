#ifndef USER_H
#define USER_H

#include <stddef.h>
#include <stdio.h>

#include "command.h"

/// @brief The user input structure.
typedef struct
{
    Command command; ///< The command.
    size_t index;    ///< The index.
    char *data;      ///< The data.
} UserInput;

/// @brief Clear the stdin buffer.
void clear_stdin();

/// @brief Create an invalid user input.
/// @return An invalid user input.
UserInput invalid_input();

/// @brief Get the memory size from the user.
/// @return The memory size.
size_t get_user_memory_size();

/// @brief Get a user command from the input.
/// @return The user command input.
UserInput get_user_command();

#endif
