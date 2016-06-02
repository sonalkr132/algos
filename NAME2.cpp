/*
Given w and m, check if w is subsequence of m
or m is subsequence of w.
*/

#include <iostream>
#include <string.h>

using namespace std;

int main(){
  int T;
  cin >> T;
  while(T--){
    char m[25005], w[25005];
    cin >> m >> w;
    int i = 0, j = 0;

    //check if w is subsequence of m
    while(i < strlen(m)){
      if(m[i] == w[j]) j++;
      i++;
    }
    //if j has reached end of w then all string in w matched with one in m
    if(j == strlen(w)){ cout << "YES"<<endl; continue; }
    i = 0, j = 0;
    //check if m is subsequence of w
    while(j < strlen(w)){
      if(m[i] == w[j]) i++;
      j++;
    }
    //if i has reached end of m then all string in m matched with one in w
    if(i == strlen(m)){ cout << "YES"<<endl; continue; }
    cout << "NO" << endl;
  }
  return 0;
}
