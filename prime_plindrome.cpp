/*
problem: given a number find the smallest prime number greater than n such that it is also a palindrome
         q_link: https://www.codechef.com/problems/PRPALIN
         
solution: check for prime iteratively (test upto num/2)
          if prime, check for palindorme with reversing the number mathematically
*/

#include <iostream>

using namespace std;

bool check_palindrome(int val){
  int rev = 0, num = val;
  while(num > 0){
    int tmp = num%10;
    rev = rev*10 + tmp;
    num = num/10;
  }
  return rev == val;
}

bool check_prime(int val){
  for(int i = 2; i <= val/2; i++){
    if((val % i) == 0) return false;
  }
  return true;
}

int find_prime_palindrome(int input){
  int ans = 0;

  for(int i = input; ; i++){
    if(check_palindrome(i)){
      if(check_prime(i)) {
        return i;
      }
    }
  }
}

int main(){
  int input;
  cin >> input;
  int ans = find_prime_palindrome(input);
  cout << ans << endl;
  return 0;
}
