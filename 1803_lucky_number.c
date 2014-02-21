#include <stdio.h>
#include <stdlib.h>
int main(int argc, char *argv[])
{
    int tmp;
    while (~scanf("%d", &tmp)) {
        int arr[3];
        arr[0] = tmp/100; arr[1] = (tmp%100)/10; arr[2] = tmp%10;
        arr[0] += arr[1]; arr[1] += arr[2];
        while (arr[0]>9) arr[0] = arr[0]/10 + arr[0]%10;
        while (arr[1]>9) arr[1] = arr[1]/10 + arr[1]%10;
        arr[0] += arr[1];
        while (arr[0]>9) arr[0] = arr[0]/10 + arr[0]%10;
        printf("%d\n", arr[0]);
    }
    return 0;
}
