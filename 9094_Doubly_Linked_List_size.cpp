#include <iostream>
#include <cstdio>
#include <cstring>
#include <list>
using namespace std;

list <int> list_member[2];
int list_front, list_tail, list_tmp;

int main(int argc, char *argv[])
{
    int list_size[2]={0}, in;
    char op[10];
    list_front = 0, list_tail = 1;
    while (~scanf("%s", op)) {
            //printf("BEFORE_OP##########LIST_FRONT_SIZE=%d, LIST_TAIL_SIZE=%d\n", list_size[list_front], list_size[list_tail]);
        if (op[0]=='S') {
            /* SWAP */
            list_tmp = list_front, list_front = list_tail, list_tail = list_tmp;
            if (list_size[list_front]>list_size[list_tail]) {
                list_member[list_tail].push_front(list_member[list_front].back());
                list_member[list_front].pop_back();
                list_size[list_front]--, list_size[list_tail]++;
            }
        }
        else if (!strcmp(op, "IH")) {
            scanf("%d", &in);
            list_member[list_front].push_front(in);
            list_size[list_front]++;
            if (list_size[list_front]>list_size[list_tail]) {
                list_member[list_tail].push_front(list_member[list_front].back());
                list_member[list_front].pop_back();
                list_size[list_front]--, list_size[list_tail]++;
            }
        }
        else if (!strcmp(op, "IT")) {
            scanf("%d", &in);
            list_member[list_tail].push_back(in);
            list_size[list_tail]++;
            if (list_size[list_front]<list_size[list_tail]-1) {
                list_member[list_front].push_back(list_member[list_tail].front());
                list_member[list_tail].pop_front();
                list_size[list_front]++, list_size[list_tail]--;
            }
        }
        else if (!strcmp(op, "RH")) {
            if (!list_size[list_front]) {
                list_tmp = list_member[list_tail].front();
                list_member[list_tail].pop_front();
                list_size[list_tail]--;
                //printf("%d %d %d\n", list_tmp, list_size[list_front], list_size[list_tail]);
                printf("%d\n", list_tmp);
            }
            else {
                list_tmp = list_member[list_front].front();
                list_member[list_front].pop_front();
                list_size[list_front]--;
                //printf("%d %d %d\n", list_tmp, list_size[list_front], list_size[list_tail]);
                printf("%d\n", list_tmp);
                if (list_size[list_front]<(list_size[list_tail]+list_size[list_front])/2) {
                    list_member[list_front].push_back(list_member[list_tail].front());
                    list_member[list_tail].pop_front();
                    list_size[list_tail]--, list_size[list_front]++;
                }
            }
            //printf("%d\n", list_tmp);
        }
        else { //RT
            list_tmp = list_member[list_tail].back();
            list_member[list_tail].pop_back();
            list_size[list_tail]--;
                printf("%d\n", list_tmp);
            if (list_size[list_tail]<list_size[list_front]) {
                list_member[list_tail].push_front(list_member[list_front].back());
                list_member[list_front].pop_back();
                list_size[list_front]--, list_size[list_tail]++;
            }
        }
            //printf("AFTER_OP##########LIST_FRONT_SIZE=%d, LIST_TAIL_SIZE=%d\n", list_size[list_front], list_size[list_tail]);
    }
    return 0;
}
