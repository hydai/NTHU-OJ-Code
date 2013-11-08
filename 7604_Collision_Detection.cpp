#include <cstdio>
#include <cstdlib>
using namespace std;
int main(int argc, char *argv[])
{
    int x, y, z;
    int cx, cy, cz;
    int max_x, max_y, max_z, min_x, min_y, min_z;
    int t, r;
    scanf("%d", &t);
    while (t--) {
        scanf("%d%d%d", &x, &y, &z);
        max_x = min_x = x;
        max_y = min_y = y;
        max_z = min_z = z;
        for (int i = 0; i < 7; i++) {
            scanf("%d%d%d", &x, &y, &z);
            max_x = (x>max_x)?x:max_x;
            min_x = (x<min_x)?x:min_x;
            max_y = (y>max_y)?y:max_y;
            min_y = (y<min_y)?y:min_y;
            max_z = (z>max_z)?z:max_z;
            min_z = (z<min_z)?z:min_z;
        }
        scanf("%d%d%d%d", &cx, &cy, &cz, &r);

        if (cx > max_x) {
            x = max_x;
        }
        else if (cx < min_x) {
            x = min_x;
        }
        else {
            x = cx;
        }
        if (cy > max_y) {
            y = max_y;
        }
        else if (cy < min_y) {
            y = min_y;
        }
        else {
            y = cy;
        }
        if (cz > max_z) {
            z = max_z;
        }
        else if (cz < min_z) {
            z = min_z;
        }
        else {
            z = cz;
        }
        
        double tmp = (x-cx)*(x-cx)+(y-cy)*(y-cy)+(z-cz)*(z-cz);
        if (tmp > r*r) {
            puts("No");
        }
        else {
            puts("Yes");
        }
    }
    return 0;
}
