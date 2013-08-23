/* 這題直接拿鐘葉青之前的program作業來改（前身是parser）
 * 每次都拿一個字元進來，判斷他是哪種類型（忽略掉空白換行）
 * 但是不管我怎麼想都會出現多拿走一個字元（在拿數字的地方）
 * 所以只好用上了ungetc
 * 可能之後換成別種寫法才能避免*/

#include <stdio.h>
#include <string.h>

#define Empty               0
#define Left_parenthesis    1
#define Right_parenthesis   2
#define Digit               3
#define Correct             5
#define WrongAnswer         6

int token_value, target;

int token()
{
    char input;
    int token_value_sign;
    input = getchar();
    while (input==' '||input=='\n') {input = getchar();}
    token_value = 0;
    if (input == '(') {
        return Left_parenthesis;
    }
    else if (input == ')') {
        return Right_parenthesis;
    }
    else if (('0' <= input && input <= '9') || input == '-') {
        token_value_sign = 1;
        if (input == '-') {
            token_value_sign = -1;
            input = getchar();
        }
        while (input <= '9' && input >= '0') {
            token_value = token_value*10 + (input-'0');
            input = getchar();
        }
        ungetc(input,stdin);/*實在想不到．．．要怎麼樣才能不多讀一個*/
        token_value *= token_value_sign;
        return Digit;
    }

    return 0; /* impossible case */
}

int parser(int now_sum)
{
    int token_type, left_subtree, right_subtree;
    token_type = token(); /* get ( first */
    token_type = token(); /* 判斷是否為空樹否則為數字相加 */
    if (token_type == Right_parenthesis) {
        return Empty;
    }
    else {
        now_sum += token_value;
    }
    left_subtree = parser(now_sum);
    right_subtree = parser(now_sum);
    token_type = token();
    if (left_subtree == Empty && right_subtree == Empty) {
        if (now_sum == target) {
            return Correct;
        }
    }

    if (left_subtree == Correct || right_subtree == Correct) {
        return Correct;
    }
    return WrongAnswer;
}

int main(int argc, char *argv[])
{
    int now_sum;
    while (~scanf("%d", &target)) {
        now_sum = 0;
        if (parser(now_sum) == Correct) {
            printf("yes\n");
        }
        else {
            printf("no\n");
        }
    }
    return 0;
}
