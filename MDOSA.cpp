#include <iostream>

using namespace std;

int main(){
  int T;

  cin >> T;
  while(T--){
    unsigned long long int n;
    cin >> n;
    if(n%2 == 0) cout << "YES" <<endl;
    else cout << "NO" <<endl;
  }
  return 0;
}
