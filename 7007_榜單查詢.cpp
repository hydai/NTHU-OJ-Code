#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

int arr[200000+2000] = {0};
using namespace std;
int main(int argc, char *argv[])
{
    int n, q;
    scanf("%d%d", &n, &q);
    vector <string> List[1000+100];
    string tmp;
    int score;
    while (n--) {
        cin >> tmp >> score;
        List[score].push_back(tmp);
    }
    int count = 1;
    for (int i = 1000; i >= 0; i--) {
        if (List[i].size() > 0) {
            arr[count] = i;
            count+=List[i].size();
        }
    }
    for (int i = 1 ; i <= q; i++) {
        int query;
        cin >> query;
        cout << "Query " << i << ": ";
        if (query <= 0 || query > 200000) {
            cout << "null\n";
        }
        else if (arr[query] == 0){
            cout << "null\n";
        }
        else {
            cout << arr[query] << endl;
            for (vector<string>::iterator iter = List[arr[query]].begin();
                    iter != List[arr[query]].end(); iter++) {
                cout << *iter << endl;
            }
        }
    }

    return 0;
}
