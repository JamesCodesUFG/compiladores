#include <stdio.h>

#include "stack.h"

int main() {
    Stack* stack = init();

    add_func(stack, "aux", 0, INT);

    return 0;
}