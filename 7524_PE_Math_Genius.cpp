#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <stack>

using namespace std;

stack <int> ans_b, ans_p;

int main(int argc, char *argv[])
{
    char unuse[1000];
    int in_p, in_b, in_final, power, first, i, half, tmp;

    while (~scanf("%d", &in_b)) {
        in_final = 1, first = 1;
        if (in_b==0) {
            break;
        }
        do {
            scanf("%d", &in_p);
            while (in_p--) {
                in_final *= in_b;
            }
        } while (scanf("%d", &in_b) && in_b!=0);
        in_final--;
        tmp = in_final;
        half = sqrt(in_final);
        gets(unuse);
        for (i = 2; i <= half; i++) {
            power = 0;
            while (tmp%i==0) {
                tmp/=i;
                power++;
            }
            if (power) {
                ans_b.push(i);
                ans_p.push(power);
            }
        }
        if (tmp>=half) {
            ans_b.push(tmp);
            ans_p.push(1);
        }
        while (!ans_b.empty()) {
            if (first) {
                first = 0;
            }
            else {
                printf(" ");
            }
            printf("%d %d", ans_b.top(), ans_p.top());
            ans_b.pop(), ans_p.pop();
        }
        putchar('\n');
    }
    return 0;
}
