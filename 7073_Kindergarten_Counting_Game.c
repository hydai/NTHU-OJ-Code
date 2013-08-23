#include <stdio.h>
#include <string.h>
#define MAX_LEN 100000
int main(int argc, char *argv[])
{
    int word, i, length, flag;
    char words[MAX_LEN], *pt;
    
    while (fgets(words, sizeof(words), stdin)) {
        words[strlen(words)-1] = ' ';

        word = 0;
        for (pt = words; *pt != '\0'; pt++)
        {
            if ((*pt<='Z' && *pt>='A') || (*pt<='z' && *pt>='a')) {
                flag = 1; 
            }
            else {
                if (flag == 1) {
                    word++;
                }
                flag = 0;
            }
        }
        printf("%d\n", word);
    }
    return 0;
}
