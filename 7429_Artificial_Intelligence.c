#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>


#define MAX_LEN 100000

char string[MAX_LEN];

typedef struct {
    double unit;
    int prefix;
    int bool;
}obj;

obj I, U, P;

int get_prefix(char prefix)
{
    if (prefix == 'm') {
        return -3;
    }
    else if (prefix == 'k'){
        return 3;
    }
    else if (prefix == 'M'){
        return 6;
    }
    else {
        return 0;
    }
}
void check_value(void)
{
    char *pt, prefix, *px;
    int fix = 0;
    double answer;
    /*0 = P, 1 = I, 2 = U*/
    obj ans;
    I.bool = U.bool = P.bool = 0;

    prefix = '0';
    pt = strstr(string, "U=");
    if (pt != NULL) {
        U.bool = 1;
        U.prefix = 0;
        sscanf(pt+2, "%lf", &U.unit);
        px = strstr(pt+2, "mV");
        if (px!=NULL) {
            U.prefix = -3;
        }
        px = strstr(pt+2, "kV");
        if (px!=NULL) {
            U.prefix = 3;
        }
        px = strstr(pt+2, "MV");
        if (px!=NULL) {
            U.prefix = 6;
        }
    }
    prefix = '0';

    pt = strstr(string, "I=");
    if (pt != NULL) {
        I.bool = 1;
        sscanf(pt+2, "%lf", &I.unit);
        I.prefix = 0;
        px = strstr(pt+2, "mA");
        if (px!=NULL) {
            I.prefix = -3;
        }
        px = strstr(pt+2, "kA");
        if (px!=NULL) {
            I.prefix = 3;
        }
        px = strstr(pt+2, "MA");
        if (px!=NULL) {
            I.prefix = 6;
        }
    }
    prefix = '0';


    pt = strstr(string, "P=");
    if (pt != NULL) {
        P.bool = 1;
        sscanf(pt+2, "%lf", &P.unit);
        P.prefix = 0;
        px = strstr(pt+2, "mW");
        if (px!=NULL) {
            P.prefix = -3;
        }
        px = strstr(pt+2, "kW");
        if (px!=NULL) {
            P.prefix = 3;
        }
        px = strstr(pt+2, "MW");
        if (px!=NULL) {
            P.prefix = 6;
        }
    }


    if (P.bool) {
        if (U.bool) {
            ans.unit = P.unit/U.unit;
            printf("I=");
            answer = ans.unit*pow(10, P.prefix-U.prefix);
            printf("%.2lfA\n", answer);
        }
        else {
            ans.unit = P.unit/I.unit;
            printf("U=");
            answer = ans.unit*pow(10, P.prefix-I.prefix);
            printf("%.2lfV\n", answer);
        }
    }
    else {
        ans.unit = U.unit*I.unit;
        printf("P=");
        answer = ans.unit*pow(10, I.prefix+U.prefix);
        printf("%.2lfW\n", answer);
    }
}

int main(int argc, char *argv[])
{
    int times, i;
    scanf("%d", &times);
    i = times;
    while (i--) {
        getchar();
        gets(string);
        printf("Problem #%d\n", times-i);
        check_value();
        printf("\n");
    }
    return 0;
}
