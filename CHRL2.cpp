/*
Given a sequence (ex: CCHHEEEFCCHEEFFC) find a subsequence
CHEF and remove the corresponding characters from given sequence.
How many times this can be done?

subsequence: after removing the char from the sequence order of the
remaining char don't change
*/

#include <iostream>
#include <string.h>

using namespace std;

int main(){
  char s[100000];
  cin >> s;
  int c=0,ch=0,che=0,chef = 0;

  for(int i=0; i< strlen(s); i++){
    if(s[i] == 'C') c++;  //increment C if C is found
    //increment ch if we just found H and we had previously found C ( C > 0)
    else if(s[i] == 'H'){ if(c > 0)   { c--; ch++;}}
    //increment che if we just found E (s[i] == E) and we had previously found CH (CH > 0)
    else if(s[i] == 'E'){ if(ch > 0)  { ch--; che++;}}
    //so on
    else if(s[i] == 'F'){ if(che > 0) { che--; chef++;}}
  }

  cout << chef;
  return 0;
}
