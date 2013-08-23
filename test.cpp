#include<iostream>
#include<cstdio>
using namespace std;
 
int main(){
  int ugly_number[1505] = {1};
  int n2 = 0, n3 = 0, n5 = 0;
 
  for( int i = 1 ; i < 1500 ; i++ ){
      for( ; n2 < i ; n2++ )
                if( ugly_number[n2]*2 > ugly_number[i-1] ) break;
           
          for( ; n3 < i ; n3++ )
                    if( ugly_number[n3]*3 > ugly_number[i-1] ) break;
           
              for( ; n5 < i ; n5++ )
                        if( ugly_number[n5]*5 > ugly_number[i-1] ) break;
               
                  ugly_number[i] = min( ugly_number[n2]*2, ugly_number[n3]*3 );
                      ugly_number[i] = min( ugly_number[i], ugly_number[n5]*5 );
                        }
     
    printf( "The 1500'th ugly number is %d.\n", ugly_number[1499] );
      return 0;
}
