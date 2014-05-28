#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int cmp (const void *s1, const void *s2) {
    int a = *(int *)s1;
    int b = *(int *)s2;
    return (a > b) ? 1 : (a == b) ? 0 : -1;
}
int main(int argc, char *argv[])
{
   
    return 0;
}
