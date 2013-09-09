#include <cstdio>
#include <cmath>
#include <vector>
#include <algorithm>
#include <utility>

#define PI 3.14159265

using namespace std;

bool Rule(pair<double, int> A, pair<double, int> B) {
    return (A.first < B.first);
}

int main(int argc, char *argv[])
{
    int N, index, space;
    pair<double, int> tmp;
    double angle, X, Y, OX, OY;
    while (~scanf("%d", &N)) {
        scanf("%lf%lf", &OX, &OY);
        index = 0; space = 0;
        vector < pair<double, int> > Vec;
        while (N--) {
            index++;
            scanf("%lf%lf", &X, &Y);
            X -= OX;
            Y -= OY;
            angle = atan2(Y, X);
            if (angle < 0) {
                angle = 2*PI + angle;
            }
            tmp.first = angle; 
            tmp.second = index;
            Vec.push_back(tmp);
        }
        sort(Vec.begin(), Vec.end(), Rule);
        for(vector<pair<double, int> >::iterator it = Vec.begin(); it != Vec.end(); ++it) {
            if (space++) {
                putchar(' ');
            }
            printf("%d", it->second);
        }
        putchar('\n');
    }
    return 0;
}
