#include <iostream>

using namespace std;

int find_turns(int n){
  int l = 0;
  while (n >>= 1) { ++l; }
  return l;
}

int no_of_opr(int a, int b){
  int count = 0;

  while ((a & -a) != a) a >>= 1, count++;
  while (a < b) a <<= 1, count++;
  while (a > b) a >>= 1, count++;

  return count;
}

int main(){
  int T;
  cin >> T;

  while(T--){
    int a, b;
    cin >> a >> b;
    cout << no_of_opr(a, b) <<endl;
  }
  return 0;
}
