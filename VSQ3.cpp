#include <iostream>

using namespace std;
long long int maxSubArraySum(int a[], int size, int q1, int q2, int q3, int q4)
{
  long long int max_so_far = 0, curr_max = 0;

  for (int i = 0; i < size; i++){
      if( a[i] == q1 || a[i] == q2 || a[i] == q3 || a[i] == q4){
        curr_max = 0;
      } else {
        curr_max += a[i];
        if(curr_max < a[i]) curr_max = a[i];
        if(max_so_far < curr_max) max_so_far = curr_max;
      }
   }
   return max_so_far;
}

int main(){
  int T;
  cin >> T;
  while(T--){
    int n, q1, q2, q3, q4;
    cin >> n >> q1 >> q2 >>q3 >> q4;
    int arr[n];

    for (int i = 0; i < n; ++i) cin >> arr[i];
    for (int i = 0; i < n; ++i) cout << arr[i] <<" ";
    cout << endl;
    cout << maxSubArraySum(arr, n, q1, q2, q3, q4) << endl;
  }
  return 0;
}
