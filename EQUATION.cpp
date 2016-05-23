#include <iostream>
#include <cstdlib>

using namespace std;
int min(int a,int b){
  if(a<=b)
    return a;
  else
    return b;
}

int main(){
  int cases;

  cin >> cases;
  while(cases--){
    int N, a, b, c;
    cin >> N >> a >> b >> c;
    long long int count = 0;
    for(int i = 0; i <= a; i++){
      for(int j = 0; j <= b; j++){
        if(i + j <= N){
          int possible_c = N - i - j;
          if(possible_c < c) count+=possible_c+1;
          else count+=c+1;
        }
      }
    }
    cout << count <<endl;
  }
  return 0;
}
