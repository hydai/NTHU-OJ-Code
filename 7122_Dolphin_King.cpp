#include <cstdio>
#include <map>
#include <cstring>

#define MAX 50010

using namespace std;

map <int, int> m_map;
//key, times;

void merge(int in[], int left[], int front, int right[], int back)
{
    int i, j, k, tmp;
    i = j = k = 0;
    while (i<front && j<back) {
        if (left[i]<right[j]) {
            in[k] = left[i++];
        }
        else {
            m_map.find(right[j])->second+=(i);
            in[k] = right[j++];
        }
        k++;
    }
    while (i<front) {
        in[k++] = left[i++];
    }
    while (j<back) {
        m_map.find(right[j])->second+=i;
        in[k++] = right[j++];
    }
}

void merge_sort(int in[], int size)
{
    if (size <= 1) {return;}
    int front = size/2, back = size-front, index;
    int *left = new int[front], *right = new int[back];
    for (int i = 0; i < front; i++) {left[i] = in[i];}
    for (int i = 0; i < back; i++) {right[i] = in[i+front];}

    merge_sort(left, front);
    merge_sort(right, back);
    
    merge(in, left, front, right, back);

    delete [] left;
    delete [] right;
}

int main(int argc, char *argv[])
{
    int n, q, input[MAX], for_sort[MAX], want;
    int ct = 1;
    while (~scanf("%d", &n)) {
        printf("Case %d:\n", ct++);
        m_map.clear();
        for (int i = 0; i < n; i++) {
            scanf("%d", &input[i]);
            m_map[input[i]] = 0;
        }
        memcpy(for_sort, input, sizeof(input));
        merge_sort(for_sort, n);
        
        scanf("%d", &q);
        for (int i = 0; i < q; i++) {
            scanf("%d", &want);
            printf("%d\n", m_map.find(input[want])->second);
        }
        putchar(10);
    }
    return 0;
}
