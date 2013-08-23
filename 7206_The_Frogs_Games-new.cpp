#include <cstdio>
#include <algorithm>

using namespace std;

int L, N, M, arr[500050];

int is_good(int mid)
{
    // if jump length * times < river length, then it must be false 
    if (mid*M < L) {return 0;}
    int right_stone = 0, jump_time = 0, now = 0;
    while (right_stone <= N) {
        jump_time++;
        if (mid < arr[right_stone] - now || jump_time > M) {return 0;}
        while (mid >= arr[right_stone] - now && right_stone <= N) {right_stone++;}
        now = arr[right_stone - 1];
    }
    return 1;
}

int main(int argc, char *argv[])
{
    
    while (~scanf("%d%d%d", &L, &N, &M)) {
        arr[N] = L; //set the final location to be the last stone
        for (int i = 0; i < N; i++) {scanf("%d", &arr[i]);}
        sort(arr, arr+N);

        int left = 0, right = L, mid, ans;
        while (left < right) {
            mid = (left+right)/2;
            // use binary cut for searching the temp max length
            if (is_good(mid)) {
                right = mid; // finally we'll find this must be the answer
            }
            else {
                left = mid + 1; // cut half part
            }
        }
        printf("%d\n", right);
    }
    return 0;
}
