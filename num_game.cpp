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
