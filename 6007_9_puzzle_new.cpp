#include <cstdio>
#include <map>
#include <queue>
#include <string>

using namespace std;
struct arr{char array[3][3];};
map <int, int> last;    // prev state
map <int, string> way;  // state way

void build_list()
{
    queue <int> m_queue;
    char swap;
    arr state, tmp_arr;
    int front, now, i, j, k, tmp;
    last[123456789] = -1; // let correct answer be -1
    m_queue.push(123456789); // final answer take in
    while (!m_queue.empty()) {
        tmp = front = m_queue.front(); m_queue.pop(); // get the first thing of the queue then build list
        for (i = 0; i < 3; i++) {for (j = 0; j < 3; j++) {state.array[i][j] = tmp%10; tmp/=10;}}
        // horizontal move way
        for (i = 0; i < 3; i++) {
            tmp_arr = state;
            swap = tmp_arr.array[i][0], tmp_arr.array[i][0] = tmp_arr.array[i][1], tmp_arr.array[i][1] = tmp_arr.array[i][2], tmp_arr.array[i][2] = swap;
            now = 0;
            for (j = 0; j < 3; j++) {for (k = 0; k < 3; k++) {now = now*10 + state.array[j][k];}}
            if (!last.count(now)) last[now] = front, way[now] = string("H") + char(i+'1'), m_queue.push(now);
        }
        // vertical move way
        for (i = 0; i < 3; i++) {
            swap = state.array[2][i], state.array[2][i] = state.array[1][i], state.array[1][i] = state.array[0][i], state.array[0][i] = swap;
            now = 0;
            for (j = 0; j < 3; j++) {for (k = 0; k < 3; k++) {now = now*10 + state.array[j][k];}}
            if (!last.count(now)) last[now] = front, way[now] = string("H") + char(i+'1'), m_queue.push(now);
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
