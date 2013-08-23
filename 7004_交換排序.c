#include <stdio.h>

int n;
int arr[1000];

int main(int argc, char *argv[])
{
    int i, tmp, j;
    int swap_times;
    while (EOF != scanf("%d", &n)) {
        /* input data */
        for (i = 0; i < n; i++) {
            scanf("%d", &arr[i]);
        }

        n--;
        swap_times = 0;
        /* run swap_sort */
        for (i = 0; i < n; i++) {
            for (j = 0; j < n; j++) {
                if (arr[j] > arr[j+1]) {
                    tmp = arr[j];
                    arr[j] = arr[j+1];
                    arr[j+1] = tmp;
                    swap_times++;
                }
            }
        }

        printf("Minimum exchange operations : %d\n", swap_times);
    }
    return 0;
}
