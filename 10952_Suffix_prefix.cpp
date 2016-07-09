#include <iostream>
#include <cstring>

int t, n;
char str[35][35];

int test(int a, int b) {
    int lena = strlen(str[a]);
    int lenb = strlen(str[b]);
    int minlen = lena < lenb ? lena : lenb;
    int testidx = 0;
    while (minlen > 0) {
        int aidx = lena - minlen;
        bool flag = true;
        for (int i = 0; i < minlen; i++) {
            if (str[a][i+aidx] != str[b][i]) {
                flag = false;
                break;
            }
        }
        if (flag) {
            return minlen;
        } else {
            minlen--;
        }
    }
    return 0;
}

int calc() {
    int ans = 0;
    for (int i = 0; i != n; i++) {
        for (int j = 0; j != n; j++) {
            if (i == j) continue;
            int tmp = test(i, j);
            ans = (ans > tmp)?ans:tmp;
        }
    }
    return ans;
}

int main() {
    std::cin >> t;
    while (t--) {
        std::cin >> n;
        for (int i = 0; i < n; i++) {
            std::cin >> str[i];
        }
        std::cout << calc() << std::endl;
    }
}
