#include <stdio.h>
#include <string.h>

#define MAX_LEN 4050

int check_table[MAX_LEN][MAX_LEN];
char str_1[MAX_LEN], str_2[MAX_LEN];
int min(int a, int b)
{
    return (a<b)?a:b;
}
int main(int argc, char *argv[])
{
    int a, length_1, length_2, i, j;
    while (NULL!=gets(str_1)) {
        gets(str_2);
        for (i = 0; i < MAX_LEN; i++) {
            check_table[0][i] = i;
        }
        for (i = 0; i < MAX_LEN; i++) {
            check_table[i][0] = i;
        }

        length_1 = strlen(str_1);
        length_2 = strlen(str_2);
        for (i = 0; i < length_1; i++) {
            for (j = 0; j < length_2; j++) {
                if (str_1[i]!=str_2[j]) {
                    a = 1;
                }
                else {
                    a = 0;
                }
                check_table[i+1][j+1] = min(min(check_table[i][j+1]+1, check_table[i+1][j]+1), check_table[i][j]+a);
            }
        }
        printf("%d\n", check_table[length_1][length_2]);
    }
    
    return 0;
}
