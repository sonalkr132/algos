#include <iostream>
#include <stdlib.h>

using namespace std;

int main(){
  long long int N, H;
  cin >> N >> H;

  long long int arr[N];
  for (long long int i = 0; i < N; ++i) cin >> arr[i];

  long long int pos = 0, input;
  bool occupied = false;

  cin >> input;
  while(input != 0){
    //move left
    if(input == 1 && pos > 0) pos--;
    //move right
    else if(input == 2 && pos < N-1) pos++;
    //pick up
    else if(input == 3 && arr[pos] != 0 && !occupied){
      arr[pos]--;
      occupied = true;
    }
    //drop box
    else if(input == 4 && arr[pos] < H && occupied){
      arr[pos]++;
      occupied = false;
    }

    cin >> input;
  }
  for (long long int i = 0; i < N; ++i) cout << arr[i] << " ";

  return 0;
}
