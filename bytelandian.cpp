/*
problem: A coin of bytelandian can be exchanged with coins of n/2, n/3 and n/4 (rounded down)
         Also 1 Coin = 1$. Find the maximum you can make from exchange for given coin value.
         q_link: https://www.codechef.com/problems/COINS

solution: with memoization.
          Coin can be as big as 10^9. So save on computation with memoization.
          when calculation n/2, n/3 and n/4, check if those values are already computed in a recursive func.
          Also, you will make profit only on coins > 12 so base case is 12
*/


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
