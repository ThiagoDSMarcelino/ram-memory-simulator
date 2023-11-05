#ifndef COMMAND_H
#define COMMAND_H

/// @brief The commands that the user can give to the program.
typedef enum
{
    Store,  /// @brief Store a value in the memory.
    Load,   /// @brief Load a value from the memory.
    Exit,   /// @brief Exit the program.
    Invalid /// @brief Invalid command.
} Command;

#endif