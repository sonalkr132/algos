#include <iostream>
#include <algorithm>
#include <bits/stdc++.h>


using namespace std;

int set_start(int val, int multiple){
  int ans;
  for(int i = val; ; i++){
    if(i % multiple == 0) return i;
  }
}

void find_prime_between(long long int first, long long int second){
  int range = second - first;
  bool prime[range+1];

  memset(prime, true, sizeof(prime));

  if(first == 1) prime[0] = false;

  for(long long int i=2; i<=sqrt(second); i++){
    int start = set_start(first, i);
    for(long long int j=start; j<=second; j+=i){
      prime[j-first] = false;
    }
  }

  for (int i = 0; i <= range; i++){
    if(prime[i]) cout<< first+i<<endl;
  }
}

int main(){
  int cases;
  cin >> cases;

  while(cases--){
    long long int first, second;
    cin >> first >> second;
    find_prime_between(first, second);
    cout<<endl;
  }
  return 0;
}
