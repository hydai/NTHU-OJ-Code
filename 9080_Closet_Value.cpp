#include <cstdio>
#include <map>
#define DEBUG
using namespace std;

long long int ABS(long long int input) {
    return ((input > 0)?input:-input);
}

int main(int argc, char *argv[])
{
    int N, space;
    long long int X;
    while (~scanf("%d", &N)) {
        map<long long int, int> Map;
        space = 0;
        while (N--) {
            scanf("%lld", &X);
#ifndef DEBUG
                printf("\n Insert: %lld\n", X);
#endif
            if (space++) {
                putchar(' ');
            }
            else {
                putchar('0');
                Map.insert(pair<long long int, int>(X, 1));
                Map[X] = 1;
                continue;
            }

            if (Map[X]) {
                printf("0");
            }
            else {
                map<long long int, int>::iterator it = Map.insert(pair<long long int, int>(X, 1)).first;
                Map[X] = 1;
                map<long long int, int>::iterator front = it, back = it;
                long long int min = 2147483647LL*2147483647LL;
                if (it != Map.begin()) {
                    front--;
                    min = ABS(it->first - front->first);
#ifndef DEBUG
                    printf("\nfront : %lld\n", front->first);
                    printf("itera : %lld\n", it->first);
                    printf("front min : %lld\n", min);
#endif
                }
                if (++back != Map.end()) {
#ifndef DEBUG
                    printf("iter : %lld\n", it->first);
                    printf("\nback : %lld\n", back->first);
                    printf("back min : %lld\n", min);
#endif
                    if (min > ABS(back->first - it->first)) {
                        min = ABS(back->first - it->first);
                    }
                }
#ifndef DEBUG
                printf("END\n");
#endif
                printf("%lld", min);
            }
        }
        putchar(10);
    }
    return 0;
}
