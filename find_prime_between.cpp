#include <iostream>
#include <algorithm>
#include <bits/stdc++.h>


using namespace std;

long long int set_start(long long int val, int multiple,long long int second){
  if(val%multiple == 0) return val;
  long long int rem = val%multiple;
  int return_val = val+multiple-rem;
  if( return_val > second ) return -1;
  else if (return_val == multiple ) return return_val+=multiple;
  else return return_val;
}

void find_prime_between(long long int first, long long int second){
  long long int range = second - first;
  bool prime[range+1];

  memset(prime, true, sizeof(prime));

  if(first == 1) prime[0] = false;

  for(long long int i=2; i<=sqrt(second); i++){
    long long int start = set_start(first, i, second);

    if(start == -1) continue;
    //cout<<"start "<<start<<" multiple "<< i<<endl;



    for(long long int j=start; j<=second; j+=i){
      if(j == 2 || j == 3 || j == 5 || j == 7) continue;
      //cout<<j<<endl;
      prime[j-first] = false;
    }
  }

  for (long long int i = 0; i <= range; i++){
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
