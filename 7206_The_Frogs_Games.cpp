#include <cstdio>
#include <algorithm>

using namespace std;

int L, N, M, arr[500050];

int is_good(int mid)
{
    // if jump length * times < river length, then it must be false 
    //if (mid*M < L) {return 0;} without this line, wa->ac amazing
    int right_stone = 1, left_stone = 0, jump_time = 0;
    while (right_stone <= N+1) {
        jump_time++;
        if (mid < arr[right_stone] - arr[left_stone]) {return 0;}
        while (mid >= arr[right_stone] - arr[left_stone] && right_stone <= N+1) {right_stone++;}
        left_stone = right_stone - 1;
    }
    if (jump_time > M) {return 0;}
    return 1;
}

int main(int argc, char *argv[])
{
    
    while (~scanf("%d%d%d", &L, &N, &M)) {
        arr[0] = 0; //set the initail location is 0
        arr[N+1] = L; //set the final location to be the last stone
        for (int i = 0; i < N; i++) {scanf("%d", &arr[i+1]);}
        sort(arr+1, arr+N+1);

        int left = 0, right = L, mid, ans;
        while (left <= right) {
            mid = (left+right)/2;
            // use binary cut for searching the temp max length
            if (is_good(mid)) {
                ans = mid;
                right = mid - 1; // cut half part
            }
            else {
                left = mid + 1; // finally we'll find that left must be the answer
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}
