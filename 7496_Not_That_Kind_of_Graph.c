#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 60

int main(int argc, char *argv[])
{
    int n, times, length, i, j, max_y, min_y, current_y, flag;
    char string[MAX_LEN], arr[120][MAX_LEN];

    scanf("%d", &n);
    getchar();
    times = n;
    while (n--) {
        memset(arr, ' ', sizeof(arr));
        max_y = 60;
        min_y = 60;
        current_y = 60;

        printf("Case #%d:\n", times-n);
        
        gets(string);
        length = strlen(string);

        for (i = 0; i < length; i++) {
            if (string[i]=='C') {
                arr[current_y][i] = '_';
            }
            if (string[i]=='F') {
                arr[--current_y][i] = '\\';
                min_y = (min_y > current_y)?current_y:min_y;
            }
            if (string[i]=='R') {
                arr[current_y++][i] = '/';
                max_y = (max_y < current_y)?current_y:max_y;
            }
        }
        for (i = max_y; i >= min_y; i--) {
            for (j = MAX_LEN-1; j >= 0; j--) {
                if (arr[i][j]==' ') {
                    if (j==0) {
                        break;
                    }
                    arr[i][j] = '\0';
                }
                else {
                    printf("| %s\n", arr[i]);
                    break;
                }
            }
        }
        printf("+-");
        for (i = 0; i < length+1; i++) {
            putchar('-');
        }
        printf("\n\n");
    }
    return 0;
}
