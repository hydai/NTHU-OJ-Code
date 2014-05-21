#include <string>
#include <iostream>
#include <vector>
using namespace std;
int main(int argc, char *argv[])
{
    int n, scoreIn;
    string input;
    while (~scanf("%d", &n)) {
        vector <string> score[100+10];
        while (n--) {
            cin >> input >> scoreIn;
            score[scoreIn].push_back(input);
        }
        for (int i = 0 ; i <= 100; i++) {
            vector <string>::iterator iter = score[i].begin();
            for (; iter != score[i].end(); iter++) {
                cout << *iter << " " << i << endl;
            }
        }
    }
    return 0;
}
