#include <stdio.h>
int main(int argc, char *argv[])
{
    int in, i, sum;
    while (scanf("%d", &in)) {
        if (in == 0) {
            break;
        }

        sum = 0;

        for (i = in; i >= 0; i--) {
            sum += i*i;
        }

        printf("%d\n", sum);
    }
    return 0;
}
