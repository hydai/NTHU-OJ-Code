#include <stdio.h>
#include <math.h>

#define PI 3.141592653589793

double dis(double ax, double ay, double bx, double by)
{
    return pow(pow(ax-bx, 2.0)+pow(ay-by, 2.0), 0.5);
}
double ri(double a, double b, double c)
{
    return a/(sin(acos((pow(b, 2.0)+pow(c, 2.0)-pow(a, 2.0))/(2.0*b*c))));

}
int main(int argc, char *argv[])
{
    double ax, ay, bx, by, cx, cy, a, b, c, r;
    while (~scanf("%lf%lf%lf%lf%lf%lf", &ax, &ay, &bx, &by, &cx, &cy)) {
        a = dis(ax, ay, bx, by);
        b = dis(bx, by, cx, cy);
        c = dis(cx, cy, ax, ay);
        r = ri(a, b, c);
        printf("%.2lf\n", PI*r);
    }
    return 0;
}
