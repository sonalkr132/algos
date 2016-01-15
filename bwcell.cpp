/*
problem: a string of "BBWBBB" is given (only one W in string). Aleksa and Chef will remove B's (one of more)
         from one side of string. Aleksa starts first and they take turns. One who can't
         remove anymore B's will lose.
         q_link: https://www.codechef.com/problems/BWCELL

Solution: if number of B's are not equal on both side of W, Aleksa will win. (solution found by checking all cases on copy)
*/

#include <iostream>

using namespace std;


int main(){
  int cases;
  cin >> cases;
  char input[10001];

  while(cases--){
    cin >> input;

    int left = 0, right = 0;
    bool found = false;
    for(int i=0; input[i] != '\0'; i++){
      if(input[i] == 'W') {
        found = true;
        continue;
      }

      if(found) right++;
      else left++;
    }

    if(left != right) cout << "Aleksa" << endl;
    else cout << "Chef" <<endl;
  }
}
