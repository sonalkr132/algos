#include <iostream>

using namespace std;


int find_smallest_birthday(int input[]){
  long long int smallest = 10, index, ans=0;
  for(int i=0; i< 10; i++){
    if(input[i] < smallest){
      smallest = input[i];
      index = i;
    }
  }



  //special case of 0
  if(index == 0){
    int num_zero = input[0]+1; //store to append later
    smallest = 10;

    for(int i=1; i< 10; i++){
      if(input[i] < smallest){
        smallest = input[i];
        index = i;
      }
    }

    if(input[0] < smallest){
      long long int num = 1;
      while(num_zero--) num*=10;
      return num;
    }
    else{
      long long int num=0;
      smallest++;
      while(smallest--)num=num*10+index;
      return num;
    }
  }
  // if no candle of particle number
  else if(smallest == 0){
    return index;
  }
  // every number has atleast one candle
  else{
    long long int num=0;
    smallest++;
    while(smallest--)num=num*10+index;
    return num;
  }
}

int main(){
  int cases;
  cin >> cases;

  while(cases--){
    int input[10];
    for(int i=0; i < 10; i++ ) cin >> input[i];

    int ans = find_smallest_birthday(input);
    cout << ans<<endl;
  }
  return 0;
}
