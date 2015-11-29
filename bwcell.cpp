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
