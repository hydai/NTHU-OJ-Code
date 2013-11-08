#include <stdio.h>

int search(int *List) {
    int index = 1, i;
    int ans = 0, times = 0;
    for (i = 1; i < 1000; i++) {
        if (List[i] > times) {
            times = List[i];
            ans = i;
        }
    }
    return ans;
}

int main(int argc, char *argv[])
{
    int N, X;
    while (~scanf("%d", &N) && N) {
        int List[1000] = {0};
        while (N--) {
            scanf("%d", &X);
            List[X]++;
        }
        printf("%d\n", search(List));
    }
    return 0;
}
