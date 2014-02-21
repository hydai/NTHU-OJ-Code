#include <cstdio>
int main(int argc, char *argv[])
{
    int tmp;
    while (~scanf("%d", &tmp)) {
        int ttt = ((tmp/100 + tmp%100/10)/10 + (tmp/100 + tmp%100/10)%10 + (tmp%100/10 + tmp%10)/10 + (tmp%100/10 + tmp%10)%10);
        printf("%d\n", ttt/10 + ttt%10);
    }
    return 0;
}
