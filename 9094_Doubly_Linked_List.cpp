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
        if (op[0]=='S') {
            /* SWAP */
            list_tmp = list_front, list_front = list_tail, list_tail = list_tmp;
            if (list_member[list_front].size()-list_member[list_tail].size()>0) {
                list_tmp = list_member[list_front].back();
                list_member[list_front].pop_back();
                list_member[list_tail].push_front(list_tmp);
            }
        }
        else if (!strcmp(op, "IH")) {
            scanf("%d", &in);
            list_member[list_front].push_front(in);
            if (list_member[list_front].size()>list_member[list_tail].size()) {
                list_tmp = list_member[list_front].back();
                list_member[list_front].pop_back();
                list_member[list_tail].push_front(list_tmp);
            }
        }
        else if (!strcmp(op, "IT")) {
            scanf("%d", &in);
            list_member[list_tail].push_back(in);
            if (list_member[list_front].size()<list_member[list_tail].size()-1) {
                list_tmp = list_member[list_tail].front();
                list_member[list_tail].pop_front();
                list_member[list_front].push_back(list_tmp);
            }
        }
        else if (!strcmp(op, "RH")) {
            if (list_member[list_front].empty()) {
                list_tmp = list_member[list_tail].front();
                list_member[list_tail].pop_front();
                printf("%d\n", list_tmp);
            }
            else {
                list_tmp = list_member[list_front].front();
                list_member[list_front].pop_front();
                printf("%d\n", list_tmp);
                if (list_member[list_front].size()!=list_member[list_tail].size()) {
                    list_tmp = list_member[list_tail].front();
                    list_member[list_tail].pop_front();
                    list_member[list_front].push_back(list_tmp);
                }
            }
            //printf("%d\n", list_tmp);
        }
        else { //RT
            list_tmp = list_member[list_tail].back();
            list_member[list_tail].pop_back();
            printf("%d\n", list_tmp);
            /*
            if (!list_member[list_front].empty()) {
                list_tmp = list_member[list_front].back();
                list_member[list_front].pop_back();
                list_member[list_tail].push_front(list_tmp);
            }*/
            if ((!list_member[list_front].empty())&&list_member[list_front].size()!=list_member[list_tail].size()) {
                list_tmp = list_member[list_front].back();
                list_member[list_front].pop_back();
                list_member[list_tail].push_front(list_tmp);
            }
        }
            //printf("##########LIST_FRONT_SIZE=%d, LIST_TAIL_SIZE=%d\n", list_member[list_front].size(), list_member[list_tail].size());
    }
    return 0;
}
