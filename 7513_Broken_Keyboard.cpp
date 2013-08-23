#include <cstdio>
#include <string>
#include <list>
#include <cstring>

using namespace std;

list <string> word_buffer;

int main(int argc, char *argv[])
{
    string tmp_str="";
    char tmp_in[100010];
    int length, i;
    bool ishead=true, pre_ishead=true;
    while (~scanf("%s", tmp_in)) {
        ishead=true, pre_ishead=true;
        length = strlen(tmp_in);
        for (i = 0; i < length; i++) {
            while (tmp_in[i]!='['&&tmp_in[i]!=']') {
                tmp_str+=tmp_in[i++];
                if (i>=length) {
                    break;
                }
            }
            if (tmp_in[i]=='[') {
                ishead=true;
            }
            else if (tmp_in[i]==']') {
                ishead=false;
            }

            if (!tmp_str.empty()) {
                if (pre_ishead) {
                    word_buffer.push_front(tmp_str), tmp_str="";
                }
                else {
                    word_buffer.push_back(tmp_str), tmp_str="";
                }
            }
            pre_ishead = ishead;
        }
        while (!word_buffer.empty()) {
            printf("%s", word_buffer.front().c_str());
            word_buffer.pop_front();
        }
        putchar('\n');
    }
    return 0;
}
