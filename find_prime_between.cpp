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
  int cases = 10;
  //cin >> cases;

  clock_t begin, end;
  double time_spent;

  begin = clock();
  while(cases--){
    // long long int first, second;
    // cin >> first >> second;
    find_prime_between(999990000, 999999999);
    cout<<endl;
  }

  end = clock();
  time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
  cout << time_spent<<endl;
  return 0;
}
