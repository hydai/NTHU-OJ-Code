#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <list>
#include <ctype.h>
#include <string>

#define MAX_LEN 1000

using namespace std;

list <string> list_string;

int main(int argc, char *argv[])
{
    string tmp_in, tmp_unit;
    int i, length, tmp_number, j;
    while (getline(cin, tmp_in)) {
        if (tmp_in=="0") {
            break;
        }
        length = tmp_in.length();
        for (i = 0; i < length; i++) {
            tmp_unit = "";
            if (isalpha(tmp_in[i])) {
                tmp_unit+=tmp_in[i];
                while (isalpha(tmp_in[++i])) {
                    tmp_unit+=tmp_in[i];
                }
                i--; // minus the for i++
                printf("%s", tmp_unit.c_str());
                //cout << tmp_unit.c_str();
                list_string.push_front(tmp_unit);
            }
            else {
                // number or other thing
                if (isdigit(tmp_in[i])) {
                    tmp_number = 0;
                    do {
                        tmp_number = tmp_number*10 + tmp_in[i] - '0';
                        i++;
                    } while (isdigit(tmp_in[i]));
                    i--; // minus the for i++
                    list<string>::iterator it = list_string.begin();
                    for (j = 1; j < tmp_number; j++) {
                        ++it;
                    }
                    //cout << *it;
                    printf("%s", (*it).c_str());
                    tmp_unit = *it;
                    list_string.remove(*it);
                    list_string.push_front(tmp_unit);
                }
                else {
                    printf("%c", tmp_in[i]);
                    //cout << tmp_in[i];
                }
            }
        }
    putchar('\n');
    //cout<<endl;
    }
    return 0;
}
