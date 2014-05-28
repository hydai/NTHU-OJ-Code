#include <cstdio>
#include <cstdlib>
#define SZ 1000+100
int Stack[SZ];
int Sct;
void Spush(int);
void Spop();
int Stop();
int Queue[SZ];
int Qhead, Qtail;
void Qpush(int);
void Qpop();
int Qfront();
int main(int argc, char *argv[])
{
    int t;
    scanf("%d", &t);
    for (int ct = 1; ct <= t; ct++) {
        printf("Case %d: ", ct);
        bool isCorrect = true;
        int n;
        scanf("%d", &n);
        Sct = 0;
        Qhead = Qtail = 0;
        for (int i = 0; i < n; i++) {
            scanf("%d", &Queue[Qtail++]);
        }
        Spush(Qfront());
        Qpop();
        isCorrect = true;
        for (int i = 0; i < n; i++) {
            int tmp;
            scanf("%d", &tmp);
            while(Stop() != tmp && Qhead != Qtail) {
                Spush(Qfront());
                Qpop();
            }
            if (Stop() != tmp) {
                isCorrect = false;
            } else {
                Spop();
            }
        }
        if (isCorrect) {
            printf("Yes\n");
        } else {
            printf("No\n");
        }
    }
    return 0;
}
void Spush(int a) {
    Stack[Sct++] = a;
}
void Spop() {
    Sct--;
}
int Stop() {
    return Stack[Sct-1];
}
void Qpush(int a) {
    Queue[Qtail++] = a;
}
void Qpop() {
    Qhead++;
}
int Qfront() {
    return Queue[Qhead];
}
