#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "input.h"
#include "memory.h"
#include "command.h"

int main()
{
  size_t size = get_memory_size();

  Memory *memory = create_memory(size);

  char *loaded_data;
  while (true)
  {
    InputData input = get_command();

    switch (input.command)
    {
    case Store:
      memory->store(memory, input.index, input.data);
      break;

    case Load:
      loaded_data = memory->load(memory, input.index);
      printf("%s\n", loaded_data);
      break;

    case Exit:
      drop_memory(memory);
      return 0;

    default:
      printf("Invalid input.\n");
      break;
    }

    // Wait user to press any key.
    getchar();
  }
}