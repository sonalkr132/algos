#include <iostream>
#include <algorithm>
#include <bits/stdc++.h>


using namespace std;

int set_start(int val, int multiple, int second){
  if(val%multiple == 0) return val;
  int rem = val%multiple;
  if(val+multiple-rem > second ) return -1;
  else return val+multiple-rem;
}

void find_prime_between(long long int first, long long int second){
  int range = second - first;
  bool prime[range+1];

  memset(prime, true, sizeof(prime));

  if(first == 1) prime[0] = false;

  for(long long int i=2; i<=sqrt(second); i++){
    int start = set_start(first, i, second);

    if(start == -1) continue;
    //cout<<"start "<<start<<" multiple "<< i<<endl;



    for(long long int j=start; j<=second; j+=i){
      if(j == 2 || j == 3 || j == 5 || j == 7) continue;
      //cout<<j<<endl;
      prime[j-first] = false;
    }
  }

  for (int i = 0; i <= range; i++){
    if(prime[i]) cout<< first+i<<endl;
  }
}

int main(){
  int cases = 10;
  cin >> cases;

  // clock_t begin, end;
  // double time_spent;

  // begin = clock();
  while(cases--){
    long long int first, second;
    cin >> first >> second;
    find_prime_between(first, second);
    cout<<endl;
  }

  // end = clock();
  // time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
  // cout << time_spent<<endl;
  return 0;
}
