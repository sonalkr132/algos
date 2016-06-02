#include <iostream>

using namespace std;

int main(){
  int T;
  cin >> T;
  while(T--){
    int n;
    cin >> n;

    if(n%2 == 0) cout << "JACK" <<endl;
    else cout << "JENNY" <<endl;
  }
  return 0;
}
