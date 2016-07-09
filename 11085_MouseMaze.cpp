#include <iostream>
#include <queue>

struct AA {
    int x, y;
    AA(int a, int b) {
        x = a; y = b;
    }
};

int dir[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
char mmap[501][501];
int step[501][501];

int main() {
    int n, r, c;
    std::cin >> n;
    while (n--) {
        std::queue<AA> Q;
        int ans = 0;
        std::cin >> r >> c;
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                step[i][j] = 0;
            }
        }
        for (int i = 0; i < r; i++) {
            std::cin >> mmap[i];
            for (int j = 0; j < c; j++) {
                if (mmap[i][j] == 'S') {
                    AA st(i, j);
                    Q.push(st);
                }
            }
        }
        while (!Q.empty() && ans == 0) {
            AA cur = Q.front();
            mmap[cur.x][cur.y] = '#';
            for (int i = 0; i < 4; i++) {
                int x = cur.x + dir[i][0];
                int y = cur.y + dir[i][1];
                if (x >= r || x < 0 || y >= c || y < 0) continue;
                if (mmap[x][y] != '#') {
                    AA tmp(x, y);
                    step[x][y] = step[cur.x][cur.y] + 1;
                    Q.push(tmp);
                    if (mmap[x][y] == 'F') {
                        ans = step[x][y];
                        break;
                    }
                    mmap[x][y] = '#';
                }
            }
            Q.pop();
        }
        if (ans) {
            std::cout << ans << "\n";
        } else {
            std::cout << "-1\n";
        }
    }
    return 0;
}
