#include <stdio.h>
#include <stdlib.h>

#include "memory.h"
#include "user.h"

int main()
{
  size_t size = get_user_memory_size();

  Memory *memory = create_memory(size);

  return 0;
}