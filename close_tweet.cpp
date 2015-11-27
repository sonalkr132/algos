#include <iostream>
#include <bits/stdc++.h>


using namespace std;

int find_open(bool tweet_arr[], int tweets){
  int count=0;
  for(int i=0; i<tweets; i++){
    //cout<<"i "<< i<<" status "<<tweet_arr[i]<<endl;
    if(tweet_arr[i]) count++;
  }
  return count;
}

int main(){
  int cases, tweets;
  cin >> tweets >> cases;

  bool tweet_arr[tweets];
  memset(tweet_arr, false, sizeof(tweet_arr));

  while(cases--){
    char action[9]; int tweet_no;
    cin >> action;
    if(strcmp("CLICK", action) == 0){
      cin >> tweet_no;
      tweet_arr[tweet_no-1] = !tweet_arr[tweet_no-1];
    }
    else if(strcmp("CLOSEALL", action) == 0) memset(tweet_arr, false, sizeof(tweet_arr));

    int open = find_open(tweet_arr, tweets);
    cout << open<<endl;
  }
  return 0;
}
