#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
int main(int argc, char *argv[])
{
    int n, input;
    while (~scanf("%d", &n) && n) {
        vector<int> AA, BB;
        for (int i = 0; i < n; i++) {
            scanf("%d", &input);
            AA.push_back(input);
        }
        for (int i = 0; i < n; i++) {
            scanf("%d", &input);
            BB.push_back(input);
        }
        sort(AA.begin(), AA.end());
        sort(BB.begin(), BB.end());
        int ctA = n-1, ctB = n-1;
        int answer = 0;
        while (ctA >= 0 && ctB >= 0) {
            /*
            printf("#########\n");
            printf("ctA = %d, ctB = %d\n", ctA, ctB);
            printf("AA[ctA] = %d, BB[ctB] = %d\n", AA[ctA], BB[ctB]);
            printf("Answer = %d\n", answer);
            printf("#########\n");
            */
            if (AA[ctA] > BB[ctB]) {
                answer++;
                ctA--;
                ctB--;
            }
            else if (AA[ctA] < BB[ctB]) {
                ctB--;
            }
            else {
                ctA--;
                ctB--;
            }
        }
        printf("%d\n", (answer-ctA+ctB)*200);
    }
    return 0;
}
