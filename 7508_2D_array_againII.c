#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int prime[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101, 103, 107, 109, 113, 127, 131, 137, 139, 149, 151, 157, 163, 167, 173, 179, 181, 191, 193, 197, 199, 211, 223, 227, 229, 233, 239, 241, 251, 257, 263, 269, 271, 277, 281, 283, 293, 307, 311, 313, 317, 331, 337, 347, 349, 353, 359, 367, 373, 379, 383, 389, 397, 401, 409, 419, 421, 431, 433, 439, 443, 449, 457, 461, 463, 467, 479, 487, 491, 499, 503, 509, 521, 523, 541, 547, 557, 563, 569, 571, 577, 587, 593, 599, 601, 607, 613, 617, 619, 631, 641, 643, 647, 653, 659, 661, 673, 677, 683, 691, 701, 709, 719, 727, 733, 739, 743, 751, 757, 761, 769, 773, 787, 797, 809, 811, 821, 823, 827, 829, 839, 853, 857, 859, 863, 877, 881, 883, 887, 907, 911, 919, 929, 937, 941, 947, 953, 967, 971, 977, 983, 991, 997};

int main(int argc, char *argv[])
{
    short arr_prime[1001] = {};
    int time, n, q, i, j, in[1001][1001], prefix[1001][1001], tmp, ans;
    int a1, a2, b1, b2;

    for (i = 0; i <= sizeof(prime)/sizeof(int); i++) {
        arr_prime[prime[i]]=1;
    }

    time = 0;
    while (~scanf("%d%d", &n, &q)) {
        memset(in, 0, sizeof(in)), memset(prefix, 0, sizeof(prefix));
        ans = 0;
        if (n==0 && q==0) {
            break;
        }
        time++;
        printf("Case #%d:\n", time);

        for (i = 0; i < n; i++) {
            for (j = 0; j < n; j++) {
                scanf("%d", &tmp);
                in[i][j] = arr_prime[tmp];
                if (i!=0) {
                    prefix[i][j] += in[i][j]+prefix[i-1][j];
                }
                else {
                    prefix[i][j] += in[i][j];
                }
            }
        }
        for (i = 0; i < n; i++) {
            for (j = 1; j < n; j++) {
                prefix[i][j] += prefix[i][j-1];
            }
        }

        while (q--) {
            scanf("%d%d%d%d", &a1, &a2, &b1, &b2);
            a1--, a2--, b1--, b2--;
            ans = prefix[b1][b2] - (a2-1>=0?prefix[b1][a2-1]:0) - (a1-1>=0?prefix[a1-1][b2]:0) + (((a2-1>=0)&&(a1-1>=0))?prefix[a1-1][a2-1]:0);
            printf("%d\n", ans);
        }

    }

    return 0;
}
