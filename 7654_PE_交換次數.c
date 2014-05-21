#include <stdio.h>
#include <stdlib.h>
long long int ct;
int arr[1000000+10000];
void merge_sort(int *arr, int len);
void merge(int *arr, int *rarr, int *larr, int r, int l);
int main(int argc, char *argv[])
{
    int n, i;
    while (~scanf("%d", &n) && n != 0) {
        ct = 0;
        for (i = 0; i < n; i++) {
            scanf("%d", &arr[i]);
        }
        merge_sort(arr, n);
        printf("%lld\n", ct);
    }
    return 0;
}

void merge_sort(int *arr, int len) {
    int i, r = len/2, l = len - r;
    int rarr[r], larr[l];
    if (len <= 1) {
        return;
    }
    for (i = 0; i < r; i++) {
        rarr[i] = arr[i];
    }
    for (i = 0; i < l; i++) {
        larr[i] = arr[i+r];
    }
    merge_sort(rarr, r);
    merge_sort(larr, l);
    merge(arr, rarr, larr, r, l);
}

void merge(int *arr, int *rarr, int *larr, int r, int l) {
    int RHS = 0, LHS = 0, MID = 0;
    while (RHS < r && LHS < l) {
        if (rarr[RHS] <= larr[LHS]) {
            arr[MID] = larr[LHS++];
        }
        else {
            arr[MID] = rarr[RHS++];
            ct += l-LHS;
        }
        MID++;
    }
    while (RHS < r) {
        arr[MID++] = rarr[RHS++];
    }
    while (LHS < l) {
        arr[MID++] = larr[LHS++];
    }
}
