#include<stdio.h>
#include<list>
using namespace std;
bool compare (char c1, char c2)
{ return true;}
int main(){
	char c;
	list<char> s, temp;
	int mode = 0;
	while((c = getchar()) != EOF){
		if((mode == 1 && c == ']') || (mode == 1 && c == '[')  || (mode == 1 && c == 10)){
			s.merge(temp, compare);
			temp.clear();	
		}
		if(c == '[')
			mode = 1;
		if(c == ']')
			mode = 2;
		if(c == 10){
			temp.clear();
			while(!s.empty())
				putchar(s.front()), s.pop_front();
			putchar(10);
		}
		if(c != 10 && c != '[' && c != ']'){
			if(mode == 0 || mode == 2)
				s.push_back(c);
			if(mode == 1)
				temp.push_back(c);
		}
	}
	return 0;
}
