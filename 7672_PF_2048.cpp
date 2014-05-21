#include <cstdio>
#include <cstdlib>
#include <cstring>
int currentState[4][4];
int nextState[4][4];
void printG();
void up();
void down();
void left();
void right();
void merge();
int main(int argc, char *argv[])
{
    int t, ct = 0;
    char op[100];
    scanf("%d", &t);
    while (t--) {
        printf("Case #%d:\n", ++ct);
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                scanf("%d", &currentState[i][j]);
            }
        }
        scanf("%s", op);
        memset(nextState, 0, sizeof(nextState));
        switch(op[0]) {
            case '>':
                right();
                break;
            case '<':
                left();
                break;
            case 'v':
                down();
                break;
            case '^':
                up();
                break;
            default:
                break;
        }
        printG();
    }
    return 0;
}

void up() {
    for (int i = 3; i >= 0; i--) {
        int bd = 0;
        for (int j = 0; j < 4; j++) {
            if (currentState[j][i] != 0) {
                nextState[bd++][i] = currentState[j][i];
            }
        }
        for (int j = 0; j < 3; j++) {
            if (nextState[j][i] == nextState[j+1][i]) {
                nextState[j][i] *= 2;
                for (int k = j+1; k < 3; k++) {
                    nextState[k][i] = nextState[k+1][i];
                }
                nextState[3][i] = 0;
            }
        }
    }
}
void down() {
    for (int i = 0; i < 4; i++) {
        int bd = 3;
        for (int j = 3; j >= 0; j--) {
            if (currentState[j][i] != 0) {
                nextState[bd--][i] = currentState[j][i];
            }
        }
        for (int j = 3; j > 0; j--) {
            if (nextState[j][i] == nextState[j-1][i]) {
                nextState[j][i] *= 2;
                for (int k = j-1; k > 0; k--) {
                    nextState[k][i] = nextState[k-1][i];
                }
                nextState[0][i] = 0;
            }
        }
    }
}
void left() {
    for (int i = 0; i < 4; i++) {
        int bd = 0;
        for (int j = 0; j < 4; j++) {
            if (currentState[i][j] != 0) {
                nextState[i][bd++] = currentState[i][j];
            }
        }
        for (int j = 0; j < 3; j++) {
            if (nextState[i][j] == nextState[i][j+1]) {
                nextState[i][j] *= 2;
                for (int k = j+1; k < 3; k++) {
                    nextState[i][k] = nextState[i][k+1];
                }
                nextState[i][3] = 0;
            }
        }
    }
}
void right() {
    for (int i = 0; i < 4; i++) {
        int bd = 3;
        for (int j = 3; j >= 0; j--) {
            if (currentState[i][j] != 0) {
                nextState[i][bd--] = currentState[i][j];
            }
        }
        for (int j = 3; j > 0; j--) {
            if (nextState[i][j] == nextState[i][j-1]) {
                nextState[i][j] *= 2;
                for (int k = j-1; k > 0; k--) {
                    nextState[i][k] = nextState[i][k-1];
                }
                nextState[i][0] = 0;
            }
        }
    }
}
void printG() {
    printf("+----+----+----+----+\n");
    for (int i = 0; i < 4; i++) {
        printf("|    |    |    |    |\n");
        for (int j = 0; j < 4; j++) {
            if (nextState[i][j] == 0) {
                printf("|    ");
            }
            else {
                printf("|%4d", nextState[i][j]);
            }
        }
        printf("|\n");
        printf("|    |    |    |    |\n");
        printf("+----+----+----+----+\n");
    }
}
