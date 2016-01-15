#include <iostream>
#include <algorithm>

using namespace std;

int search(int *arr, int start, int end, int to_find){
  if(start >= end) {
    // while(arr[start-1] == -1 && start != 0){
    //   if(start > 0) start --;
    //   else return 0;
    // }
    // if(start == 0){
    //   if(arr[start] == -1) return 0;
    //   else{
    //     int to_return = arr[start];
    //     arr[start] = -1;
    //     return to_return;
    //   }
    // }


    int to_return = arr[start-1];
    arr[start-1] = -1;
    return to_return;
  }
  int mid = (start+end)/2;
  while(mid >= 0 && arr[mid] == -1)
    mid--;
  if(mid == -1)   return 0;
  if(arr[mid] > to_find) search(arr, start, mid, to_find);
  else if(arr[mid] < to_find) search(arr, mid+1, end, to_find);
  else {
    int to_return = arr[mid];
    arr[mid] = -1;
    return to_return;
  }
}

int main(){
  // int cases;

  // cin >> cases;
  // while(cases--){
  //   int N, K, M;
  //   cin >> N >> K >> M;
  //   int planned[N], completed[N];
  //   for(int i=0; i<N; i++) cin >> planned[i];
  //   for(int i=0; i<N; i++) cin >> completed[i];
  //   int values[K+M-1];
  //   for(int i=0; i<K+M; i++) cin >> values[i];

  //   sort(values, values+K+M);

  //   for(int i=0; i<K+M; i++) cout << values[i]<<" ";
  //   cout << endl;
  //   int ans=0;
  //   for(int i=0; i< N; i++){
  //     int diff= planned[i] - completed[i];
  //     cout << "dif "<<diff<<endl;
  //     int logg = search(values, 0, K+M-1, diff);
  //     cout << logg<<endl;
  //     //ans+= diff - ;
  //   }

  //  // cout << ans <<endl;

  // }

  int values[] = { 40, 40, 10, 100, 90, 20, 25 }, input;
  sort(values, values+7);
  while(1){
    cout<<"value to search: ";
    cin >> input;
    cout << search(values, 0, 7, input)<<endl;
    cout<<endl;
    for(int i=0; i<7;i++){
      cout<<values[i]<<endl;
    }
  }
  return 0;
}