#ifndef MEMORY_H
#define MEMORY_H

#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

// Define function pointers for store and load functions
typedef void (*StoreFunction)(struct Memory *memory, size_t index, char *value);
typedef char *(*LoadFunction)(struct Memory *memory, size_t index);

/// @brief Structure representing RAM Memory
typedef struct
{
  char **data;        ///< Array of data elements
  size_t size;        ///< Size of the memory
  StoreFunction store;///< Function pointer to store data
  LoadFunction load;  ///< Function pointer to load data
} Memory;

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
