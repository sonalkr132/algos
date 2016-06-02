#include <iostream>

using namespace std;

int rev_num(int num){
  while( num % 10 == 0) num = num / 10;
  int rev_num = 0;
  while(num != 0){
    rev_num = rev_num * 10 + (num % 10);
    num= num/10;
  }

  return rev_num;
}

int main(){
  int T;
  cin >> T;
  while(T--){
    int a, b;
    cin >> a >> b;
    int rev_a = rev_num(a);
    int rev_b = rev_num(b);

    int sum = rev_b + rev_a;

    int rev_sum = rev_num(sum);

    cout << rev_sum << endl;
  }
  return 0;
}