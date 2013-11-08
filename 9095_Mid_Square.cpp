#include <cstdio>
#include <bitset>

unsigned int Hash[65536];
unsigned short int getHashValue(unsigned long long int input) {
    unsigned long long int X= input*input;
    unsigned short int returnValue = 0, P = 1;
    bitset<64> key(X);

    for (int i = 8; i < 24; i++) {
        returnValue += key[i]*P;
        P *= (unsigned short int) 2;
    }
    return returnValue;
}

int main(int argc, char *argv[])
{
    char cmd[10];
    while (~scanf("%s", cmd)) {
        if (cmd[0] == 'I') {
            unsigned long long int input;
            scanf("%llu", &input);
            Hash[getHashValue(input)] = input;
        }
        else if (cmd[0] == 'D') {
            Hash[getHashValue(input)] = 
        }
    }
    return 0;
}
