#include <iostream>
#include <cstdlib>
#include <cstring>

using namespace std;
typedef unsigned long long T;
const T MOD = 100000007;
class Matrix {
public:
    T data[2][2];
    void init() {
        data[0][0] = 1;
        data[0][1] = 1;
        data[1][0] = 1;
        data[1][1] = 0;
    }
    void unit() {
        data[0][0] = 1;
        data[0][1] = 0;
        data[1][0] = 0;
        data[1][1] = 1;
    }
    Matrix operator* (const Matrix &mul) {
        Matrix ret;
        ret.data[0][0] = (this->data[0][0]*mul.data[0][0]+this->data[0][1]*mul.data[1][0])%MOD;
        ret.data[0][1] = (this->data[0][0]*mul.data[0][1]+this->data[0][1]*mul.data[1][1])%MOD;
        ret.data[1][0] = (this->data[1][0]*mul.data[0][0]+this->data[1][1]*mul.data[1][0])%MOD;
        ret.data[1][1] = (this->data[1][0]*mul.data[0][1]+this->data[1][1]*mul.data[1][1])%MOD;
        return ret;
    }
};
T fib(T n) {
    Matrix ans, tmp;
    ans.unit();
    tmp.init();
    while(n) {
        if (n & 1) {
            ans = ans*tmp;
        }
        tmp = tmp*tmp;
        n = n >> 1;
    }
    return ans.data[0][1];
}
int main(int argc, char *argv[])
{
    T n;
    while (cin >> n) {
        cout << fib(n) << endl;
    }
    return 0;
}
