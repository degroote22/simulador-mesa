#include <stdio.h>
#include <emscripten.h>
#define true 1
#define false 0

extern void light(int i, int j, int r, int g, int b);
extern void reset();

#include "custom.c"

int main(int argc, char **argv)
{
    emscripten_set_main_loop(loop, 60, 1);
}
