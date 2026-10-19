#include <stdio.h>
#include "shared.h"
void show_a(void) { printf("a.c 看到 s_counter = %d\n", s_counter); bump(); }
