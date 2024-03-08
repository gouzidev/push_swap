#include <stdlib.h>
#include <string.h>
#include <stdio.h>

typedef struct s_stack {
    struct s_stack *next;
    int n;
}   t_stack;