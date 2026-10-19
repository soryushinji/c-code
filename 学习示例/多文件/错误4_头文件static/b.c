#include <stdio.h>
#include "shared.h"
void show_b(void) { printf("b.c 看到 s_counter = %d\n", s_counter); bump(); }
