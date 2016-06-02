/*
Given an array of numbers, find out how many triplets from them
don't form a triangle. ie a + b <= c
*/
#include <iostream>
#include <algorithm>

using namespace std;

int main(){
  int N;
  cin >> N;
  while(N != 0){
    int arr[N];
    for (int i = 0; i < N; ++i) cin >> arr[i];

    //sort the array, so that if one number is found rest of numbers after
    //that will have same behaviour
    sort(arr, arr+N);

    int ans = 0, sum;
    for (int i = 0; i < N-2; ++i){
      int k = i+2;
      //pair i with all j such that i < j < N
      for (int j = i+1; j < N; ++j){
        sum = arr[i] + arr[j];
        //increment k, until sum of i and j becomes smaller than that of k
        //ie all the numbers [k..N) can't form triangle with i and j
        while(k < N && sum >= arr[k]) k++;
        ans += N-k;
      }
    }

    cout << ans << endl;

    cin >> N;
  }
  return 0;
}
