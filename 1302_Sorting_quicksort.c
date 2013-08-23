#include <stdio.h>
#include <stdlib.h>

#define MAX 1000000+100

void quicksort(int in[], int left, int right)
{
    int i, j, tmp;
    if (left >= right) {
        return ;
    }

    i = left;
    j = right;

    while (1) {
        while (i<=right) {
            if (in[i]>in[right]) {
                break;
            }
            i++;
        }
        while (j>left) {
            if (in[j]<in[left]) {
                break;
            }
            j--;
        }

        if (i>j) {
            break;
        }

        tmp = in[i], in[i] = in[j], in[j] = tmp;
    }

    tmp = in[left], in[left] = in[j], in[j] = tmp;
    quicksort(in, left, j);
    quicksort(in, j, right);
}

int main(int argc, char *argv[])
{
    int T, n, in[MAX], nn, i, j, tmp;

    scanf("%d", &T);
    while (T--) {
        memset(in, 0, sizeof(in));
        scanf("%d", &n);
        for (i = 0; i < n; i++) {
            scanf("%d", &in[i]);
        }

        quicksort(in, 0, n-1);
        for (i = 0; i < n-1; i++) {
            printf("%d ", in[i]);
        }
        printf("%d\n", in[i]);
    }

    return 0;
}
