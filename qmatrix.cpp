#include <iostream>

using namespace std;


int main(){
  int size_n, count = 0;
  int lower[100001] = {0}, upper[100001] = {0};

  cin >> size_n;
  for(int i=0; i<size_n; i++){
    int l, u;
    cin >> l >> u;
    lower[i] = l;
    upper[i] = u;

    //update count
    count+= (u-l+1);
  }

  int query;
  cin >> query;
  while(query--){
    int i, j;
    cin >> i >> j;

    //check for 1
    int check_parity=count;
    if(lower[i-1] <= j && upper[i-1] >= j) check_parity = count -1;

    if(check_parity%2 == 0) cout<<'E'<<endl;
    else cout << 'O'<<endl;
  }

  return 0;
}
