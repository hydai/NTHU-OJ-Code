#include <stdio.h>
#include <string.h>

#define MAX 100000+100

int max_size, heap_size, max_heap[MAX];

int Pop()
{
    int max_value = max_heap[1];
    int Last = max_heap[heap_size--];
    int parent = 1, child = 2;
    while (child <= heap_size) {
        if (child < heap_size && max_heap[child] < max_heap[child+1]) {child++;}
        if (Last >= max_heap[child]) {break;}
        max_heap[parent] = max_heap[child];
        parent = child; child *= 2;
    }
    max_heap[parent] = Last;
    return max_value;
}

void Insert(int input)
{
    int current = ++heap_size;
    while (current!=1 && max_heap[current/2]<input) {
        max_heap[current] = max_heap[current/2];
        current/=2;
    }
    max_heap[current] = input;
    while (heap_size>max_size) {
        Pop();
    }
}

int main(int argc, char *argv[])
{
    int use_num, insert_num, times, used, first;
    char oper[6];
    while (~scanf("%d%d", &max_size, &times)) {
        heap_size = 0;
        while (times--) {
            scanf("%s", oper);
            if (oper[0]=='P') {
                scanf("%d", &insert_num);
                Insert(insert_num);
            }
            else {
                scanf("%d", &use_num);
                first = 0;
                while (use_num--) {
                    if (first++) {putchar(32);}
                    printf("%d", Pop());
                }
                putchar(10);
            }
        }
    }
    return 0;
}
