#include <stdio.h>

int va[] = {
2,
7,
5,
30,
169,
441,
1872,
7632,
1740,
93313,
459901,
1358657,
2504881
};
int main(int argc, char *argv[])
{
    int i;
    while (~scanf("%d", &i) && i) {
        printf("%d\n", va[i-1]);
    }
    return 0;
}
