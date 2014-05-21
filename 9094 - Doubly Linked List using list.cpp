#include<stdio.h>
#include<list>
#include<string.h>
using namespace std;
char s[10];
list<int> head, tail;
int num, headct = 0, tailct = 0;
void adjust(){
	while((headct + tailct) && headct > (headct + tailct)/2){
		headct--, tailct++;
		tail.push_front(head.back());
		head.pop_back();
	}
}
int main(){
	
	while(scanf("%s", s) > 0){
		if(strcmp(s, "IH") == 0){
			scanf("%d", &num);
			headct++;
			head.push_front(num);
			adjust();
		}
		else if(strcmp(s, "IT") == 0){
			scanf("%d", &num);
			tailct++;
			tail.push_back(num);
			adjust();
		}
		else if(strcmp(s, "RH") == 0){
			headct--;
			printf("%d\n", head.front()), head.pop_front();
			adjust();
		}
		else if(strcmp(s, "RT") == 0){
			tailct--;
			printf("%d\n", tail.back()), tail.pop_back();
			adjust();
		}
		else if(strcmp(s, "S") == 0){
			list<int> temp;
			if(tailct > headct){
				temp = head, head = tail, tail = temp;
				adjust();
			}
			else
				temp = head, head = tail, tail = temp;
		}
        printf("op = %s headct= %d,tailct= %d\n", s, headct, tailct);
	}
	return 0;
}
