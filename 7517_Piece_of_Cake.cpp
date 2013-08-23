#include <cstdio>
#include <list>
#include <cstdlib>
using namespace std;
list <int> num_list;
int main(int argc, char *argv[])
{
    int n, m, count, tmp_remove, current_count, i;
    while (~scanf("%d%d", &n, &m)) {
        if (!n&!m) {
            break;
        }
        count = n;
        if (n==1) {
            printf("1\n");
            continue;
        }
        num_list.clear();
        for (i = 0; i < n; i++) {
            num_list.push_back(i+1);
        }
        list <int> :: iterator it = num_list.begin();
        while (count!=1) {
            tmp_remove = m % count;
            for (i = 0; i < tmp_remove-1; i++) {
                it++;
            }
            num_list.remove(*it);
            it++;
            count--;
        }
        printf("%d\n", num_list.front());
    }
    return 0;
}
