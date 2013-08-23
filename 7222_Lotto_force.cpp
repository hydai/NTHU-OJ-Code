/****************************************************************************
 * I have no idea!!!!!!!!!!!
 * 還是沒有體會遞迴的精髓，然後看起來又可以暴力來
 * 本程式碼使用完全的暴力法ˊ_>ˋ
 ****************************************************************************/

#include <cstdio>
#include <cstring>

#define MAX_LEN 15
int main(int argc, char *argv[])
{
    int in, tmp_in[MAX_LEN], i, j, k, m, n, p;
    bool new_line_flag = false;
    while (~scanf("%d", &in)&&in) {
        if (new_line_flag) {
            printf("\n");
        }
        else {
            new_line_flag = true;
        }
        memset(tmp_in, 0, sizeof(tmp_in));
        for (i = 0; i < in; i++) {
            scanf("%d", &tmp_in[i]);
        }

        for (i = 0; i < in; i++) {
            for (j = i+1; j < in; j++) {
                for (k = j+1; k < in; k++) {
                    for (m = k+1; m < in; m++) {
                        for (n = m+1; n < in; n++) {
                            for (p = n+1; p < in; p++) {
                                printf("%d %d %d %d %d %d\n", tmp_in[i], tmp_in[j], tmp_in[k], tmp_in[m], tmp_in[n], tmp_in[p]);
                            }
                        }
                    }
                }
            }
        }
    }
    return 0;
}
