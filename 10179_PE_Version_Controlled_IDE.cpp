#include <iostream>
#include <string>
#include <algorithm>
#include <ext/roap>
using namespace std;
using namespace __gnu_cxx;

crope versionRope[MAX_LIMIT_versionRope], currentRope, tmpRope;

int main(int argc, char *argv[])
{
    int commandNumber;
    while (cin >> commandNumber) {
        int versionRopeID = 0;
        int prefixD = 0;
        while (commandNumber--) {
            int opType;
            cin >> opType;
            switch (opType) {
                case 1: // insert
                    int position;
                    string inputS;
                    cin >> position >> inputS;
                    position -= prefixD; // f**king trap
                    currentRope.insert(position, inputS.c_str());
                    versionRope[++versionRopeID] = currentRope;
                    break;
                case 2: // remove
                    int position, cutLength;
                    cin >> position >> cutLength;
                    position -= prefixD;
                    cutLength -= prefixD;
                    currentRope.erase(position-1, cutLength); // index start from 0
                    versionRope[++versionRopeID];
                    break;
                default: // display
                    int version, position, showLength;
                    cin >> version >> position >> showLength;
                    version -= prefixD;
                    position -= prefixD;
                    showLength -= prefixD;
                    string displayStr = versionRope[version].substr(position-1, showLength);
                    prefixD += count(displayStr.begin(), displayStr.end(), 'c');
                    cout << displayStr << endl;
                    break;
            }
        }
    }
    return 0;
}
