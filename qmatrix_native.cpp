#include <iostream>

using namespace std;

int main(){
  int n, count = 0;
  int arr[1001][1001];
  cin >> n;
  int i=0;
  while(n--){
    int l, u;
    cin >> l >> u;
    for(int k=l-1; k<u; k++) arr[i][k] = 1;
    count+= (u-l+1);
    i++;
  }

  int q;
  cin >> q;

  while(q--){
    int i, j;
    cin >> i>>j;
    int check_parity = count;
    if(arr[i-1][j-1] == 1) check_parity--;

    if(check_parity%2 == 0) cout << 'E'<<endl;
    else cout << 'O'<<endl;
  }

  return 0;
}
