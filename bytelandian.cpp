#include <iostream>
#include <map>
#include <math.h>

using namespace std;

map <long long int, long long int> mem_hash;

long long int find_max_val(long long int input){
  if(input < 12){
    mem_hash[input] = input;
    return input;
  }
  if(mem_hash[input]) return mem_hash[input];
  // max value is not calculated so far
  else {
    long long int max_val = find_max_val(floor(input/4)) + find_max_val(floor(input/3)) + find_max_val(floor(input/2));
    mem_hash[input] = max_val;
    return max_val;
  }
}

int main(){
  long long int input, count =1;
  while( count <=10 && (cin >> input)){
    long long int ans = find_max_val(input);
    cout << ans<<endl;
    count++;
  }
  return 0;
}
