#include "memory.h"

Memory *create_memory(size_t size)
{
  Memory *memory = malloc(sizeof(Memory));
  memory->size = size;
  memory->data = (char **)malloc(size);
  memory->store = store_memory;
  memory->load = load_memory;
  return memory;
}

void drop_memory(Memory *memory)
{
  free(memory->data);
  free(memory);
}

void store_memory(Memory *memory, size_t index, char *value)
{
  if (index >= memory->size || index < 0)
  {
    fprintf(stderr, "Error: Index out of bounds\n");
    return;
  }

  memory->data[index] = (char *)malloc(sizeof(value));
  strcpy(memory->data[index], value);
}

char *load_memory(Memory *memory, size_t index)
{
  if (index >= memory->size || index < 0)
  {
    fprintf(stderr, "Error: Index out of bounds\n");
    return NULL;
  }

  return memory->data[index];
}