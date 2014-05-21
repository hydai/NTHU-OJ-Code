#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double pp, qq, rr, ss, tt, uu;

double func(double x) {
    return pp*exp(-x) + qq*sin(x) + rr*cos(x) + ss*tan(x) + tt*x*x + uu;
}

int main(int argc, char *argv[])
{
    const char NOANS[] = "No solution";
    double eps = 1e-8;
    while (~scanf("%lf%lf%lf%lf%lf%lf", &pp, &qq, &rr, &ss, &tt, &uu)) {
        int hasSolution = 1;
        double L = 0.0, U = 1.0;

        while (U - L >= eps) {
            double M = (U+L)/2.0;
            double fl, fu, fm;
            fl = func(L);
            fu = func(U);
            fm = func(M);
            if (fl * fu > 0) {
                hasSolution = 0;
                break;
            }
            if (fl * fm > 0) {
                L = M;
            }
            if (fm * fu > 0) {
                U = M;
            }
        }
        if (hasSolution == 0) {
            printf("%s\n", NOANS);
        }
        else {
            printf("%.4lf\n", U);
        }
    }
    return 0;
}
