#include <cstdio>
#include <queue>
#include <functional>
#include <vector>

using namespace std;
int main(int argc, char *argv[])
{
    typedef priority_queue< int, vector<int> > Heap;
    char str[10];

    int Value;
    Heap heap;
    while (~scanf("%s", str)) {
        if (str[0] == 'T') {
            // Top
            if (!heap.empty()) {
                printf("%d\n", heap.top());
            }
            else {
                printf("Null\n");
            }
        }
        else if (str[1] == 'O') {
            if (!heap.empty()) {
                heap.pop();
            }
        }
        else {
            scanf("%d", &Value);
            heap.push(Value);
        }
    }


    return 0;
}
