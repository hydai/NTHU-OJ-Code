#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <list>
using namespace std;
struct data {
    char text[100];
};

list <data> list_member;

int main(){
	char in[100], c, i;
	data tmp_in;
	while((c = getchar()) != EOF){
		if(c == 48) return 0;
		if((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z')){
			i = 0;
			while((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z')){
				tmp_in.text[i++] = c;
				putchar(c);
				c = getchar();
			}
			tmp_in.text[i] = 0;
			list_member.push_front(tmp_in);
		}
		if(c >= 48 && c <= 57){
			i = 0;
			while(c >= 48 && c <= 57){
				tmp_in.text[i++] = c;
				c = getchar();
			}
			tmp_in.text[i] = 0;
			list <data> :: iterator it = list_member.begin();
			for (i = 0; i < atoi(tmp_in.text); i++) {
			    ++it;
			}
			printf("%s", (*it).text);
		    list_member.remove(*it);
		    list_member.push_front(*it);
		}
		putchar(c);
	}
	return 0;
}
