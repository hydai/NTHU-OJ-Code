#include <cstdio>
#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;
int main(int argc, char *argv[])
{
    int n;
    while (~scanf("%d", &n)) {
        while (n--) {
            long double input;
            cin >> input;
            cout << setprecision(0) << setiosflags(ios::fixed) << sqrt(input) << endl;
        }
    }
    return 0;
}
