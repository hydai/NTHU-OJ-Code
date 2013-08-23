#include <stdio.h>
#include <string.h>

int data[1001][500];

int main(int argc, char *argv[])
{
    int n, i, j;
    memset(data, 0, sizeof(data));

    data[1][0] = 1;
    data[2][0] = 1;
    i = 3;
    while(i < 1001)
    {
        for (j = 0; j < 500; j++) {
            data[i][j] = data[i-1][j]+data[i-2][j];
        }
        for (j = 0; j < 499; j++) {
            data[i][j+1] += data[i][j]/10;
            data[i][j] %= 10;
        }
        i++;
    }
    while (~scanf("%d", &n)&&n) {
        int first = 0;
        for (i = 499; i >= 0; i--) {
            if (!first && data[n][i]==0)
            {
                continue;
            }
            else
                first = 1;
            putchar(data[n][i]+'0');
        }
        putchar(10);
    }
    return 0;
}
