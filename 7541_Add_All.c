#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 5005
int min_heap[MAX], heap_size;

int TopDelete(void)
{
    int Last = min_heap[heap_size--], root_value = min_heap[1];
    int parent = 1, child = 2;
    while (child <= heap_size) {
        /* choose the smaller one */
        if (child < heap_size && min_heap[child] > min_heap[child+1]) {child++;}
        if (Last <= min_heap[child]) {break;}

        min_heap[parent] = min_heap[child];
        parent = child; child *=2;
    }
    min_heap[parent] = Last;
    return root_value;
}

void Insert(int input)
{
    int current = ++heap_size;
    while (current!=1 && min_heap[current/2]>input) {
        min_heap[current] = min_heap[current/2];
        current/=2;
    }
    min_heap[current] = input;
}

int cmp(const void *s1, const void *s2)
{
    int a = *(int *)s1, b = *(int *)s2;
    if (a>b) {
        return 1;
    }
    else if (a<b) {
        return -1;
    }
    return 0;
}

int main(int argc, char *argv[])
{
    int n, i, ans, front, back, tmp;
    while (~scanf("%d", &n)&&n) {
        for (i = 1; i <= n; i++) {
            scanf("%d", &min_heap[i]);
        }
        qsort(min_heap+1, n, sizeof(min_heap[1]), cmp);
        /* build default min heap, just sort it */
        ans = 0;heap_size = n;
        while (heap_size!=1) {
            front = TopDelete();
            back = TopDelete();
            tmp = front+back;
            ans += tmp;
            Insert(tmp);
        }
        printf("%d\n", ans);
    }
    return 0;
}
