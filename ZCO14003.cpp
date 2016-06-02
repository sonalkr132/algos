#include <iostream>
#include <algorithm>    // std::sort

using namespace std;

int main(){
  int N;
  cin >> N;

  long long int arr[N];
  for (int i = 0; i < N; ++i) cin >> arr[i];

  sort(arr, arr+N);
  for (int i = 0; i < N; ++i) arr[i] = arr[i] * (N - i);

  //find max
  long long int max = 0;
  for (int i = 0; i < N; ++i) if(max < arr[i]) max = arr[i];

  cout << max;

  return 0;
}
