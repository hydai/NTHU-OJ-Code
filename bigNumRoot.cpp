#include <cstdio>
#include <cstdlib>
#include <cstring>

#define SIZE 1000

using namespace std;

class BM {
public:
    /* data */
    char digit[SIZE];
    int len;
    /* Methods */
    BM() {
        memset(digit, 0, sizeof(digit));
        len = 0;
    }
    BM(char input[]) {
        strcpy(digit, input);
        len = strlen(digit);
    }
    bool operator< (const BM next) const {
        if (len < next.len) {
            return true;
        }
        else if (len > next.len){
            return false;
        }
        else {
            for (int i = len-1; i >= 0; i--) {
                if (digit[i] < next.digit[i]) {
                    return true;
                }
            }
            return false;
        }
    }
    void operator- (const BM next) {
        /* must be big minus little */
        for (int i = len-1; i >= 0) {
            digit[i] -= next.digit[i];
            if (digit[i] < 0) {
                digit[i+1] -= 1;
                digit[i] += 10;
            }
        }
    }
}
int main(int argc, char *argv[])
{
    
    return 0;
}
