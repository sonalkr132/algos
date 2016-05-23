#include <iostream>

using namespace std;

int main(){
  int cases;

  cin >> cases;
  while(cases--){
    long long int N, K;
    cin >> N >> K;

    if(K == 0) cout << K <<" "<< N <<endl;
    else{
      long long int rem = N%K;
      long long int fact = N/K;
      cout << fact <<" "<< rem << endl;
    }
  }

  return 0;
}
