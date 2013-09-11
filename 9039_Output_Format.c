#include <stdio.h>

int main(int argc, char *argv[])
{
    char input[30];
    int line_count;
    int TS, N;
    scanf("%d", &TS);
    while (TS--) {
        scanf("%d", &N);
        for (line_count = 1; line_count <= N; line_count++) {
            scanf("%s", input);
            printf("%20s", input);
            if (line_count % 4 == 0) {
                putchar('\n');
            }
        }
        if (N % 4 != 0) {
            putchar('\n');
        }
        putchar('\n');
    }
    return 0;
}
