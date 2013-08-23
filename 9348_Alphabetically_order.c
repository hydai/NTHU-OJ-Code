#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[])
{
    char str1[35], str2[35];
    char *s1, *s2;
    int max = 0;
    while (~scanf("%s%s", str1, str2)) {
        s1 = str1; s2 = str2;
        while (*s1 != '\0' && *s2 != '\0') {
            if (*s1 == *s2) {
                s1++;s2++;
                continue;
            }
            if (*s1 >= 'A' && *s1 <= 'Z' && *s2 >= 'A' && *s2 <= 'Z') {
                if (*s1 > *s2) {
                    max = 1;
                    break;
                }
                max = 2;
                break;
            }
            else if (*s1 >= 'a' && *s1 <= 'z' && *s2 >= 'a' && *s2 <= 'z') {
                if (*s1 > *s2) {
                    max = 1;
                    break;
                }
                max = 2;
                break;
            }
            else {
                if (*s1 >= 'A' && *s1 <= 'Z') {
                    if (*s1+32 == *s2) {
                        s1++; s2++;
                        continue;
                    }
                    else if (*s1+32 > *s2) {
                        max = 1;
                        break;
                    }
                    max = 2;
                    break;
                }
                else {
                    if (*s1 == *s2+32) {
                        s1++; s2++;
                        continue;
                    }
                    else if (*s1 > *s2+32) {
                        max = 1;
                        break;
                    }
                    max = 2;
                    break;
                    
                }
            }
        }
        if (max == 1) {
            printf("%s %s\n", str1, str2);
        }
        else {
            printf("%s %s\n", str2, str1);
        }
    }
    return 0;
}
