/*
problem: each player subtracts a proper divisior of a number from it.
         player who can't subtract anymore will lose. Alicse starts first
         q_link: https://www.codechef.com/problems/NUMGAME/
         
solution: found with checking all the smaller cases on copy
          optimum move is just to subtract one (1) each time.
          Alice wins if number is even.
*/

#include <iostream>

using namespace std;

int main(){
  int cases;
  cin >> cases;
  while(cases--){
    long long int input;
    cin >> input;
    if(input%2 == 0) cout << "ALICE"<<endl;
    else cout << "BOB"<<endl;
  }
  return 0;
}
