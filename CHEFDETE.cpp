#include <iostream>

using namespace std;

int main(){
  int n;

  cin >> n;
  int arr[n + 1] = { 0 };

  for(int i = 0; i < n; i++){
    int input;
    cin >> input;
    arr[input]++;
  }

  for(int i = 1; i <= n ; i++){
    if(arr[i] == 0) cout << i <<" ";
  }
  cout << endl;
}
