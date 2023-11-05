#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "user.h"
#include "memory.h"

int main()
{
  size_t size = get_user_memory_size();

  Memory *memory = create_memory(size);

  while (true)
  {
    UserInput input = get_user_command();

    if (input.command == Exit)
      break;

    system("clear");
  }

  return 0;
}