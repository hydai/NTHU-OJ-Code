#include <iostream>
#include <algorithm>
using namespace std;

struct Puzzle {
    int side[6];
};
Puzzle puzzle[7], midPuzzle;
int order[7], sidecheck[6][2];
int main(int argc, char *argv[])
{
    while (cin >> puzzle[0].side[0] >> puzzle[0].side[1] >> puzzle[0].side[2] >> puzzle[0].side[3] >> puzzle[0].side[4] >> puzzle[0].side[5]) {
        // input
        for (int i = 1; i < 7; i++) {
            cin >> puzzle[i].side[0] >> puzzle[i].side[1] >> puzzle[i].side[2] >> puzzle[i].side[3] >> puzzle[i].side[4] >> puzzle[i].side[5];
        }
        for (int i = 0; i < 7; i++) {
            order[i] = i;
        }
        
        bool isCorrect = true;
        do {
            // get mid puzzle at order 6
            for (int i = 0; i < 6; i++) {
                midPuzzle.side[i] = puzzle[order[6]].side[i];
            }
            isCorrect = true;

            // sort by side
            for (int i = 0; i < 6; i++) {
                for (int j = 0; j < 6; j++) {
                    if (puzzle[order[i]].side[j] == midPuzzle.side[i]) {
                        sidecheck[i][0] = puzzle[order[i]].side[(j+1)%6]; 
                        sidecheck[i][1] = puzzle[order[i]].side[(j+5)%6]; // if not %6, get RE
                    }
                }
            }

            // check if isCorrect
            for (int i = 0; i < 6; i++) {
                if (sidecheck[i][1] != sidecheck[(i+1)%6][0]) {
                    isCorrect = false;
                }
            }
            if (isCorrect) {
                break;
            }
            
        } while (next_permutation(order, order+7));
        
        if (isCorrect) {
            cout << "YES\n";
        }
        else {
            cout << "NO\n";
        }
        
    }
    return 0;
}
