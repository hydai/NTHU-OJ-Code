#include <stdio.h>

#define SIZE 1000000+10
short ans[SIZE] = {0};

int main(int argc, char *argv[])
{
    int count, input_n, tmp_in;
    while (~scanf("%d", &input_n)) {
        count = 0;
        if (ans[input_n] != 0) {
            printf("%d\n", ans[input_n]);
        }
        else {
            tmp_in = input_n;
            while (input_n != 1) {
                if ((input_n & 0x1) == 0) {
                    count++;
                    input_n /= 2;
                }
                else {
                    count+=2;
                    input_n *= 3;
                    input_n++;
                    input_n /= 2;
                }
                if (input_n < 1000000 && ans[input_n] != 0) {
                    count += ans[input_n];
                    break;
                }
            }
            ans[tmp_in] = (short) count;
            printf("%d\n", count);
        }
    }
    return 0;
}
