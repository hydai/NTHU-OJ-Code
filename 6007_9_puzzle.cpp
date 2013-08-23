#include <cstdio>
#include <map>
#include <queue>
#include <string>
#include <cstring>

using namespace std;

map <int, int> last;    // prev state
map <int, string> way;  // state way

void build_list()
{
    queue <int> m_queue;
    char state[9] = {}, swap, tmp_arr[9];
    int front, now, i, j, k, tmp;
    last[123456789] = -1; // let correct answer be -1
    m_queue.push(123456789); // final answer take in
    while (!m_queue.empty()) {
        tmp = front = m_queue.front(); m_queue.pop(); // get the first thing of the queue then build list
        for (i = 0; i < 9; i++) {
            state[9-i-1] = tmp%10; tmp/=10;
        }
        // horizontal move way
        memcpy(tmp_arr, state, sizeof(tmp_arr));
        for (i = 0, k = 0; i < 9; i+=3, k++) {
            memcpy(state, tmp_arr, sizeof(state));
            swap = state[i], state[i] = state[i+1], state[i+1] = state[i+2], state[i+2] = swap;
            now = 0;
            for (j = 0; j < 9; j++) {
                now = now*10 + state[j];
            }
            if (!last.count(now)) last[now] = front, way[now] = string("H") + char(k+'1'), m_queue.push(now);
        }
        // vertical move way
        for (i = 0, k = 0; i < 3; i++, k++) {
            memcpy(state, tmp_arr, sizeof(state));
            swap = state[i+6], state[i+6] = state[i+3], state[i+3] = state[i], state[i] = swap;
            now = 0;
            for (j = 0; j < 9; j++) {
                now = now*10 + state[j];
            }
            if (!last.count(now)) last[now] = front, way[now] = string("V") + char(k+'1'), m_queue.push(now);
        }
    }
}

int main(int argc, char *argv[])
{
    int i, j, input, needed;
    build_list();
    string tmp;
    while (~scanf("%d", &input) && input) {
        needed = input;
        for (i = 1; i < 9; i++) {
            scanf("%d", &input);
            needed = needed*10 + input;
        }
        if (!last.count(needed)) 
            printf("Not solvable\n");
        else
        {
            tmp = "";
            for (i = last[needed]; i != -1; needed = i, i = last[needed]) tmp += way[needed];
            printf("%ld %s\n", tmp.size()/2, tmp.c_str());
        }
    }
    return 0;
}
