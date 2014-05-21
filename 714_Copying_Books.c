#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 500+50
int t, i;
int m, k;
long long books[SIZE];
int cut[SIZE], cut_ct = 0;
void Print(long long key);
int test(long long key);

int main(int argc, char *argv[])
{
    scanf("%d", &t);
    while (t--) {
        long long L = 0, U = 1e10, mid;
        memset(books, 0, sizeof(books));
        cut_ct = 0;
        scanf("%d%d", &m, &k);
        for (i = 0; i < m; i++) {
            scanf("%lld", &books[i]);
            if (books[i] > L) {
                L = books[i];
            }
        }
        while (L < U) {
            mid = (L+U)/2;
            if (test(mid)) {
                L = mid + 1;
            }
            else {
                U = mid;
            }
        }
        Print(U);
    }
    return 0;
}
void Print(long long key) {
    int i, j;
    long long tmp = 0;
    cut_ct = 0;
    memset(cut, 0, sizeof(cut));
    printf("%lld\n", key);
    for (i = m - 1; i >= 0; i--) {
        if (tmp + books[i] == key) {
            cut_ct++;
            tmp = 0;
            cut[i] = 1;
            continue;
        }
        if (tmp + books[i] > key) {
            cut_ct++;
            tmp = 0;
            cut[++i] = 1;
        }
        else {
            tmp += books[i];
        }
        if (i <  k - cut_ct) {
            i++;
            break;
        }
        else if (i == k - cut_ct) {
            break;
        }
    }
    for (j = 1; j < i; j++) {
        cut[j] = 1;
    }
    printf("%lld", books[0]);
    for (i = 1; i < m ; i++) {
        if (cut[i]) {
            printf(" /");
        }
        printf(" %lld", books[i]);
    }
    putchar(10);
}
int test(long long key) {
    int i, j;
    int index = m-1;
    long long tmp = 0;;
    cut_ct = 0;
    for (i = m-1; i >= 0; i--) {
        if (cut_ct >= k) {
            return 1;
        }
        if (tmp + books[i] > key) {
            tmp = 0;
            i++;
            cut_ct++;
        }
        else {
            if (i + 1 == k - cut_ct - 1) {
                break;
            }
            tmp += books[i];
        }
    }
    return 0;
}
