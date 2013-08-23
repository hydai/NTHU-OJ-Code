#include <stdio.h>
#include <stdlib.h>

short n_list[1050];
int count, n, m;
int main(int argc, char *argv[])
{
    int tmp_remove, current_count, i, tail;
    while (~scanf("%d%d", &n, &m)) {
        if (!n&&!m) {
            break;
        }
        count = n;
        if (n==1) {
            printf("1\n");
            continue;
        }
        memset(n_list, 0, sizeof(n_list));
        current_count = 0;
        tail = n;
        while (count!=1) {
            tmp_remove = m%count;
            for (i = 0; i < tmp_remove; i++) {
                while (n_list[current_count++]) {current_count%=n;}
                n_list[current_count] = 1;
                current_count++;
                while (n_list[current_count]) {
                    current_count++;
                    current_count%=n;
                }
                current_count%=n;
            }
            if (tmp_remove==0) {
                while (n_list[current_count++]) {
                    current_count++;
                    current_count%=n;
                }
                n_list[current_count] = 1;
                while (n_list[current_count]) {
                    current_count++;
                    current_count%=n;
                }
                current_count%=n;
            }
            count--;
        }
        printf("%d\n", current_count);
    }
    return 0;
}
