#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int height[100010];

int main(int argc, char *argv[])
{
    int n, i, tmp_h, tmp_w, tmp_max, max_ans, tmp_min;
    while (scanf("%d", &n)) {
        memset(height, 0, sizeof(height));
        if (!n) { break; }
        for (i = 0; i < n; i++) {
            scanf("%d", &height[i]);
        }
        tmp_min = tmp_h = height[0], tmp_w = 1, max_ans = tmp_h*tmp_w;
        for (i = 1; i < n; i++) {
            if (height[i]>=tmp_h) {
                tmp_w++;
            }
            else {
                tmp_max = tmp_h*tmp_w;
                max_ans = (tmp_max>max_ans)?tmp_max:max_ans;
                tmp_h = height[i], tmp_w = 1;
            }
            tmp_min = (tmp_min<height[i])?tmp_min:height[i];
        }
        tmp_max = tmp_h*tmp_w;
        tmp_min = tmp_min*n;
        max_ans = (tmp_max>max_ans)?tmp_max:max_ans;
        max_ans = (tmp_min>max_ans)?tmp_min:max_ans;
        printf("%d\n", max_ans);
    }
    return 0;
}
