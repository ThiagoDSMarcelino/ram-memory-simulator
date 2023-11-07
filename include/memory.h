#ifndef MEMORY_H
#define MEMORY_H

#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

// Define function pointers for store and load functions
typedef struct Memory Memory; // Forward declaration of the Memory struct

/// @brief Structure representing RAM Memory
struct Memory
{
  char **data;         ///< Array of data elements
  size_t size;         ///< Size of the memory
  void (*store)(Memory *memory, size_t index, char *value); ///< Function pointer to store data
  char *(*load)(Memory *memory, size_t index);   ///< Function pointer to load data
};

/// @brief Creates a new memory structure
/// @param size Size of the memory
/// @return A pointer to the newly created memory structure
Memory *create_memory(size_t size);

/// @brief Releases the memory allocated for the Memory structure
/// @param memory Pointer to the Memory structure to release
void drop_memory(Memory *memory);

/// @brief Stores data in the memory
/// @param memory Pointer to the Memory structure
/// @param index Index at which to store the data
/// @param value Data to be stored
static void store_memory(Memory *memory, size_t index, char *value);

/// @brief Loads data from the memory
/// @param memory Pointer to the Memory structure
/// @param index Index from which to load the data
/// @return A pointer to the loaded data
static char *load_memory(Memory *memory, size_t index);

#endif
