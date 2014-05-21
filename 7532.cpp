#include <cstdio>
void re(int n) {
    if (n <= 3) {
        printf("%d", n);
    } else if (n & 1) {
        re((n-1)/2);
        re((n+1)/2);
    } else {
        re(n/2 - 1);
        re(n/2 + 1);
    }
}
int main(int argc, char *argv[])
{
    int n;
    while(~scanf("%d", &n)) {
        re(n);
        printf("\n");
    }
    return 0;
}
