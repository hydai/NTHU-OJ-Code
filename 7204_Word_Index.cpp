/****************************************************************************
 * 使用內建map建表搜尋
 * 感覺上蠻暴力的ˊ_>ˋ
 * 之後再尋找更快速的方法
 ****************************************************************************/



#include <iostream>
#include <cstdio>
#include <map>
#include <string>
#include <cstring>


using namespace std;

map <string, int> m_list;

int main(int argc, char *argv[])
{
    int i, j, k, m, n, count = 1, length;
    char tmp_in[100];
    string str[10];
    string input;
    /* build list */
    // one char
    for (i = 0; i < 26; i++) {
        str[0]='a'+i;
        m_list.insert(pair<string, int>(str[0], count++));
    }
    // two char
    for (i = 0; i < 26; i++) {
        str[0]='a'+i;
        for (j = i+1; j < 26; j++) {
            str[1]='a'+j;
            m_list.insert(pair<string, int>(str[0]+str[1], count++));
        }
    }
    // three char
    for (i = 0; i < 26; i++) {
        str[0]='a'+i;
        for (j = i+1; j < 26; j++) {
            str[1]='a'+j;
            for (k = j+1; k <26; k++) {
                str[2]='a'+k;
                m_list.insert(pair<string, int>(str[0]+str[1]+str[2], count++));
            }
        }
    }
    // four char
    for (i = 0; i < 26; i++) {
        str[0]='a'+i;
        for (j = i+1; j < 26; j++) {
            str[1]='a'+j;
            for (k = j+1; k <26; k++) {
                str[2]='a'+k;
                for (m = k+1; m < 26; m++) {
                    str[3]='a'+m;
                    m_list.insert(pair<string, int>(str[0]+str[1]+str[2]+str[3], count++));
                }
            }
        }
    }
    // five char
    for (i = 0; i < 26; i++) {
        str[0]='a'+i;
        for (j = i+1; j < 26; j++) {
            str[1]='a'+j;
            for (k = j+1; k <26; k++) {
                str[2]='a'+k;
                for (m = k+1; m < 26; m++) {
                    str[3]='a'+m;
                    for (n = m+1; n < 26; n++) {
                        str[4]='a'+n;
                        m_list.insert(pair<string, int>(str[0]+str[1]+str[2]+str[3]+str[4], count++));
                    }
                }
            }
        }
    }

    while (~scanf("%s", tmp_in)) {
        input = "";
        /* c-tyle to string*/
        length = strlen(tmp_in);
        for (i = 0; i < length; i++) {
            input += tmp_in[i];
        }

        map <string, int>::iterator iter;
        iter = m_list.find(input);
        if (iter==m_list.end()) {
            printf("0\n");
        }
        else {
            printf("%d\n", iter->second);
        }
    }
    return 0;
}
