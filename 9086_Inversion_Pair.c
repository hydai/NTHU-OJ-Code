#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 1000000+10

long long int count;

void Merge(int * Array, int *LeftArray, int LeftSize, int *RightArray, int RightSize) {
    static int CC = 0;
    int i, j, k;
    i = j = k = 0;

    while (i < LeftSize && j < RightSize) {
        if (LeftArray[i] > RightArray[j]) {
            Array[k++] = RightArray[j++];
            count+=LeftSize - i;
        }
        else {
            Array[k++] = LeftArray[i++];
        }
    }

    while (i < LeftSize) {
        Array[k++] = LeftArray[i++];
    }
    while (j < RightSize) {
        Array[k++] = RightArray[j++];
    }
}

void MergeSort(int *Array, int Size) {
    int LeftSize = Size/2, RightSize = Size - LeftSize, i;
    int *LeftArray, *RightArray;

    if (Size <= 1) {
        return ;
    }
    LeftArray = (int *) malloc (LeftSize*sizeof(int));
    RightArray = (int *) malloc (RightSize*sizeof(int));

    for (i = 0; i < LeftSize; i++) {
        LeftArray[i] = Array[i];
    }
    for (i = 0; i < RightSize; i++) {
        RightArray[i] = Array[i+LeftSize];
    }

    MergeSort(LeftArray, LeftSize);
    MergeSort(RightArray, RightSize);

    Merge(Array, LeftArray, LeftSize, RightArray, RightSize);
    free(LeftArray);
    free(RightArray);
}

int main(int argc, char *argv[])
{
    int N, Array[MAX];
    while (~scanf("%d", &N) && N) {
        int i;
        for (i = 0; i < N; i++) {
            scanf("%d", &Array[i]);
        }
        count = 0;
        MergeSort(Array, N);
        printf("%lld\n", count);
    }
    return 0;
}

