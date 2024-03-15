#include "push_swap.h"

char *test1()
{
    static int x;
    x = 5;

}


char *test2()
{
    static int x;
}
char *test3()
{
    static char *test = NULL;
}

int main()
{
    printf("%s\n", xihaja());
}