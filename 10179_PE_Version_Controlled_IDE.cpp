#include <iostream>
#include <string>
#include <algorithm>
#include <ext/rope>
using namespace std;
using namespace __gnu_cxx;

#define MAX_LIMIT_versionRope 50000+100
crope versionRope[MAX_LIMIT_versionRope], currentRope, displayRope;

int main(int argc, char *argv[])
{
    int commandNumber;
    while (cin >> commandNumber) {
        int versionRopeID = 0;
        int prefixD = 0;
        while (commandNumber--) {
            int opType, position, cutLength, version, showLength;
            string inputS;
            cin >> opType;
            switch (opType) {
                case 1: // insert
                    cin >> position >> inputS;
                    position -= prefixD; // f**king trap
                    currentRope.insert(position, inputS.c_str());
                    versionRope[++versionRopeID] = currentRope;
                    break;
                case 2: // remove
                    cin >> position >> cutLength;
                    position -= prefixD;
                    cutLength -= prefixD;
                    currentRope.erase(position-1, cutLength); // index start from 0
                    versionRope[++versionRopeID] = currentRope;
                    break;
                default: // display
                    cin >> version >> position >> showLength;
                    version -= prefixD;
                    position -= prefixD;
                    showLength -= prefixD;
                    displayRope = versionRope[version].substr(position-1, showLength);
                    prefixD += count(displayRope.begin(), displayRope.end(), 'c');
                    cout << displayRope << endl;
                    break;
            }
        }
    }
    return 0;
}
