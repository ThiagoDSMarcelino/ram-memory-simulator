#ifndef USER_H
#define USER_H

#include <stddef.h>

#include "command.h"

size_t get_user_memory_size();
Command get_user_input();

#endif